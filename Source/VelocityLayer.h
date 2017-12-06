/*
  ==============================================================================

    VelocityLayer.h
    Created: 20 Nov 2017 1:29:00pm
    Author:  jdown

  ==============================================================================
*/

#pragma once
#include "VelocityLayerGUI.h"
#include "Sound.h"
#include "Misc.h"
class Drum;

class VelocityLayer
{
public:
	VelocityLayer(Drum& parentRef);

	void createNewSound();
	Sound* getNextSound();
	float calculateCrossfade(int velocity);
	void setUpperBound(int velocity);
	void setLowerBound(int velocity);
	Component* getGui();

private:
	Drum& parent;
	Array<Sound*> sounds;
	int upperBound, lowerBound, counter;
	CrossfadeFunction function;

	VelocityLayerGUI gui;
};
