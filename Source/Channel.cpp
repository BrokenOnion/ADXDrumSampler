/*
  ==============================================================================

    Channel.cpp
    Created: 24 Oct 2017 12:08:51am
    Author:  jdown

  ==============================================================================
*/

#include "Channel.h"
#include "Windows.h"

Channel::Channel()
{
	outL = 0;
	outR = 1;
}

Channel::~Channel()
{
	clearQueue();
}

void Channel::addToQueue(Array<AudioTransportSource*> sources)
{
	for (int i = 0; i < sources.size(); i++)
	{
		queue.addInputSource(sources.getUnchecked(i), false);
		sources.getUnchecked(i)->prepareToPlay(samplesPerBlock, sampleRate);
		sources.getUnchecked(i)->start();
		sources.getUnchecked(i)->addChangeListener(this);
	}
}

void Channel::clearQueue()
{
	queue.removeAllInputs();
}
void Channel::setOutputs(int left, int right)
{
	outL = left;
	outR = right;
}
int Channel::getNextAudioBlock(AudioSourceChannelInfo &bufferToFill) 
{
	queue.getNextAudioBlock(bufferToFill);
	return outL;
}

void Channel::prepareToPlay(int samplesPerBlock, double sampleRate)
{
	queue.prepareToPlay(samplesPerBlock, sampleRate);
	this->samplesPerBlock = samplesPerBlock;
	this->sampleRate = sampleRate;
}
void Channel::releaseResources()
{
	queue.releaseResources();
}

void Channel::changeListenerCallback(ChangeBroadcaster* source)
{
	AudioTransportSource* audioSource = dynamic_cast<AudioTransportSource*>(source);
	if (audioSource != nullptr)
	{
		if (audioSource->hasStreamFinished())
		{
			queue.removeInputSource(audioSource);
			audioSource->setPosition(0.0);
			OutputDebugString("Removed");
		}
	}
}
