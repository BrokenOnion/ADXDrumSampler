/*
  ==============================================================================

    Sound.h
    Created: 20 Nov 2017 1:29:08pm
    Author:  jdown

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "Misc.h"
#include "SoundGUI.h"
class VelocityLayer;

class Sound
{
public:
	Sound(VelocityLayer& parentRef);
	//~Sound();

	void setDirectSource(File soundFile);
	void setRoomSource(File soundFile);
	AdxTransportSource* getDirectSource();
	AdxTransportSource* getRoomSource();
	Component* getGui();

private:
	VelocityLayer& parent;
	AudioFormatReader* directSound;
	AudioFormatReader* roomSound;
	AudioFormatManager formatManager;

	SoundGUI gui;
};
