/*
  ==============================================================================

    Drum.h
    Created: 20 Nov 2017 1:28:42pm
    Author:  BrokenOnion

  ==============================================================================
*/

#pragma once

#include "VelocityLayer.h"
#include "Channel.h"
class AdxAudioProcessor;

class Drum 
{
public:
	Drum(AdxAudioProcessor& processorRef);
	~Drum();

	void createVelocityLayer();
	void setChannel(Channel* newChannel);

private:
	Array<VelocityLayer*> velocityLayers;
	AdxAudioProcessor& processor;
	Channel* channel;
	int note;
	String name;
	float volume;

};
