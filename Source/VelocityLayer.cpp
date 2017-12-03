/*
  ==============================================================================

    VelocityLayer.cpp
    Created: 20 Nov 2017 1:29:00pm
    Author:  jdown

  ==============================================================================
*/

#include "VelocityLayer.h"
#include "Drum.h"

VelocityLayer::VelocityLayer(Drum parentRef)
	: parent(parentRef)
{
	counter = 0;
}

void VelocityLayer::createNewSound()
{
	sounds.add(new Sound(*this));
}

Sound* VelocityLayer::getNextSound()
{
	if (sounds.isEmpty()) 
	{
		return nullptr;
	}

	if (counter >= sounds.size()) 
	{
		counter = 0;
	}
	return sounds.getUnchecked(counter);
	counter++;
}

float VelocityLayer::calculateCrossfade(int velocity)
{

}

void VelocityLayer::setUpperBound(int velocity) 
{
	upperBound = velocity;
}

void VelocityLayer::setLowerBound(int velocity)
{
	lowerBound = velocity;
}
