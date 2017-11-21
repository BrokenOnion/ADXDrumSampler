/*
  ==============================================================================

    VelocityLayer.h
    Created: 20 Nov 2017 1:29:00pm
    Author:  jdown

  ==============================================================================
*/

#pragma once
#include "Sound.h"
class Drum;

class VelocityLayer
{
public:
	VelocityLayer(Drum parentRef);
	~VelocityLayer();

	void createNewSound();
	Sound* getNextSound();
	float calculateCrossfade(int velocity);

private:
	Drum& parent;
	Array<Sound*> sounds;
	int upperBound, lowerBound, counter;
};
