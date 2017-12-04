/*
  ==============================================================================

    Misc.cpp
    Created: 2 Dec 2017 3:46:28pm
    Author:  jdown

  ==============================================================================
*/

#include "Misc.h"


AdxTransportSource::AdxTransportSource(AudioFormatReader* reader) 
	: super()
{
	ScopedPointer<AudioFormatReaderSource> newReader = new AudioFormatReaderSource(reader, false);
	super::setSource(newReader, 0, nullptr, reader->sampleRate);
	formatReader = newReader.release();
}

