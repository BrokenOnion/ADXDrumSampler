/*
  ==============================================================================

    Misc.h
    Created: 2 Dec 2017 3:46:28pm
    Author:  jdown

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class AdxTransportSource : public AudioTransportSource
{
public:
	AdxTransportSource(AudioFormatReader* reader);
	//~AdxTransportSource();

private:
	typedef AudioTransportSource super;

	ScopedPointer<AudioFormatReaderSource> formatReader;
};

enum CrossfadeFunction
{
	linearOne, logOne
};