/*
  ==============================================================================

    Drum.h
    Created: 20 Nov 2017 1:28:42pm
    Author:  BrokenOnion

  ==============================================================================
*/

#pragma once

#include "VelocityLayer.h"
#include "DrumGUI.h"
#include "Channel.h"
class AdxAudioProcessor;

class Drum : public ActionListener
{
public:
	Drum(AdxAudioProcessor& processorRef);
	//~Drum();

	void createVelocityLayer();
	void setChannel(Channel* newChannel);
	void setName(String name);
	void playDrum(int velocity);
	void actionListenerCallback(const String& message);
	Component* getGui();

private:
	Array<VelocityLayer*> velocityLayers;
	AdxAudioProcessor& processor;
	Channel* channel;
	int note;
	String name;

	DrumGUI gui;
};
