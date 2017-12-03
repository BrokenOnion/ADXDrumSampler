/*
  ==============================================================================

    Misc.h
    Created: 2 Dec 2017 3:46:28pm
    Author:  jdown

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class AdxTransportSource : public ChangeBroadcaster, public ChangeListener
{
public:
	AdxTransportSource(AudioFormatReader* reader);
	//~AdxTransportSource();

	void start();
	void stop();
	void setGain(float gain);
	void prepareToPlay(int samplesPerBlock, double sampleRate);
	void releaseResources();
	void getNextAudioBlock(const AudioSourceChannelInfo& buffer);

	void changeListenerCallback(ChangeBroadcaster* source);

private:
	AudioTransportSource transport;
	ScopedPointer<AudioFormatReaderSource> formatReader;
};