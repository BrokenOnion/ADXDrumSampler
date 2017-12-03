/*
  ==============================================================================

    Drum.cpp
    Created: 20 Nov 2017 1:28:42pm
    Author:  BrokenOnion

  ==============================================================================
*/

#include "Drum.h"
#include "PluginProcessor.h"

Drum::Drum(AdxAudioProcessor& processorRef) 
	: processor(processorRef)
{

}

void Drum::createVelocityLayer()
{
	velocityLayers.add(new VelocityLayer(*this));
}

void Drum::setChannel(Channel* newChannel)
{
	channel = newChannel;
}

void Drum::playDrum(int velocity)
{
	Array<AdxTransportSource*> directMix;
	Array<AdxTransportSource*> roomMix;

	for (int i = 0; i < velocityLayers.size(); ++i)
	{
		Sound* nextSound = velocityLayers.getUnchecked(i)->getNextSound();
		float gain = velocityLayers.getUnchecked(i)->calculateCrossfade(velocity);
		if (gain == 0.0f)
		{
			continue;
		}
		AdxTransportSource* direct = nextSound->getDirectSource();
		AdxTransportSource* room = nextSound->getRoomSource();
		direct->setGain(gain);
		room->setGain(gain);
		directMix.add(direct);
		roomMix.add(room);
	}

	channel->addToQueue(directMix);
	processor.getRoomChannel()->addToQueue(roomMix);
}

void Drum::actionListenerCallback(const String& message)
{
	int colonPos = message.indexOf(":");
	if (colonPos)
	{
		int note = atoi(message.substring(0, colonPos).toStdString().c_str());
		if (note != this->note)
		{
			return;
		}
		int velocity = atoi(message.substring(colonPos + 1).toStdString().c_str());
		playDrum(velocity);
	}
}