/*
  ==============================================================================

    Drum.cpp
    Created: 20 Nov 2017 1:28:42pm
    Author:  BrokenOnion

  ==============================================================================
*/

#include "Drum.h"

Drum::Drum(AdxAudioProcessor& processorRef) 
	: processor(processorRef)
{

}

Drum::~Drum()
{

}

void Drum::createVelocityLayer()
{
	velocityLayers.add(new VelocityLayer());
}

void Drum::setChannel(Channel* newChannel)
{
	channel = newChannel;
}