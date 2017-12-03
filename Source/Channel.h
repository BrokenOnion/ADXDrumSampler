/*
  ==============================================================================

    Channel.h
    Created: 24 Oct 2017 12:08:51am
    Author:  jdown

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Misc.h"

#pragma once

class Channel : ChangeListener
{
public:
	Channel();
	~Channel();

	void addToQueue(Array<AdxTransportSource*> sources);
	void clearQueue();
	void setOutputs(int left, int right);
	int getNextAudioBlock(AudioSourceChannelInfo &bufferToFill);
	void prepareToPlay(int samplesPerBlock, double sampleRate);
	void releaseResources();
	void changeListenerCallback(ChangeBroadcaster* source);
private:
	MixerAudioSource queue;
	int outL;
	int outR;
	int samplesPerBlock;
	double sampleRate;
};
