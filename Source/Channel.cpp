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
}

Channel::~Channel()
{
	clearQueue();
}

void Channel::addToQueue(Array<AdxTransportSource*> sources)
{
	for (int i = 0; i < sources.size(); i++)
	{
		AdxTransportSource* currentSource = sources.getUnchecked(i);
		currentSource->prepareToPlay(samplesPerBlock, sampleRate);
		currentSource->start();
		currentSource->addChangeListener(this);
		queue.addInputSource(currentSource, true);
	}
}

void Channel::clearQueue()
{
	queue.removeAllInputs();
}
void Channel::setOutput(int left)
{
	outL = left;
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
	AdxTransportSource* audioSource = dynamic_cast<AdxTransportSource*>(source);
	if (audioSource != nullptr)
	{
		if (audioSource->hasStreamFinished())
		{
			queue.removeInputSource(audioSource);
			OutputDebugString("Removed");
		}
	}
}
