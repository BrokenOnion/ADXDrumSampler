/*
  ==============================================================================

    VelocityLayer.cpp
    Created: 20 Nov 2017 1:29:00pm
    Author:  jdown

  ==============================================================================
*/

#include "VelocityLayer.h"
#include "Drum.h"

VelocityLayer::VelocityLayer(Drum& parentRef)
	: parent(parentRef), gui(*this)
{
	counter = 0;
	function = linearOne;
}

void VelocityLayer::createNewSound()
{
	Sound* newSound = new Sound(*this);
	sounds.add(newSound);
	gui.addTab(newSound->getGui());
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
	if (function == linearOne)
	{
		if (velocity > upperBound - 10)
		{
			return -((velocity - (upperBound + 10)) / 20);
		}
		else if (velocity < lowerBound + 10)
		{
			return ((velocity - (lowerBound - 10)) / 20);
		}
		else
		{
			return 1.0f;
		}
	}
}

void VelocityLayer::setUpperBound(int velocity) 
{
	upperBound = velocity;
}

void VelocityLayer::setLowerBound(int velocity)
{
	lowerBound = velocity;
}

Component* VelocityLayer::getGui()
{
	return &gui;
}
