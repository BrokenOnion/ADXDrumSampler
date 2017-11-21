/*
  ==============================================================================

    Sound.h
    Created: 20 Nov 2017 1:29:08pm
    Author:  jdown

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class Sound
{
public:
	Sound();
	~Sound();

	void setDirectSource();
	void setRoomSource();
	AudioTransportSource* getDirectSource();
	AudioTransportSource* getRoomSource();

private:
	AudioFormatReader* directSound;
	AudioFormatReader* roomSound;

};
