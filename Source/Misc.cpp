/*
  ==============================================================================

    Misc.cpp
    Created: 2 Dec 2017 3:46:28pm
    Author:  jdown

  ==============================================================================
*/

#include "Misc.h"


AdxTransportSource::AdxTransportSource(AudioFormatReader* reader) 
{
	ScopedPointer<AudioFormatReaderSource> newReader = new AudioFormatReaderSource(reader, false);
	transport.setSource(newReader, 0, nullptr, reader->sampleRate);
	formatReader = newReader.release();
}

void AdxTransportSource::start()
{
	transport.start();
}

void AdxTransportSource::stop()
{
	transport.stop();
}

void AdxTransportSource::setGain(float gain)
{
	transport.setGain(gain);
}

void AdxTransportSource::prepareToPlay(int samplesPerBlock, double sampleRate)
{
	transport.prepareToPlay(samplesPerBlock, sampleRate);
}

void AdxTransportSource::releaseResources()
{
	transport.releaseResources();
}

void AdxTransportSource::getNextAudioBlock(const AudioSourceChannelInfo& buffer)
{
	transport.getNextAudioBlock(buffer);
}

void AdxTransportSource::changeListenerCallback(ChangeBroadcaster* source)
{
	if (source == &transport)
	{
		if (transport.hasStreamFinished())
		{
			sendChangeMessage();
		}
	}
}

