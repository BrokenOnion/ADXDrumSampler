/*
  ==============================================================================

    Sound.cpp
    Created: 20 Nov 2017 1:29:08pm
    Author:  jdown

  ==============================================================================
*/

#include "Sound.h"

Sound::Sound(VelocityLayer& parentRef) 
	: parent(parentRef)
{
	formatManager.registerBasicFormats();
}

void Sound::setDirectSource(File soundFile)
{
	directSound = formatManager.createReaderFor(soundFile);
}

void Sound::setRoomSource(File soundFile)
{
	roomSound = formatManager.createReaderFor(soundFile);
}

AdxTransportSource* Sound::getDirectSource()
{
	return new AdxTransportSource(directSound);
}

AdxTransportSource* Sound::getRoomSource()
{
	return new AdxTransportSource(roomSound);
}

Component* Sound::getGui()
{
	return &gui;
}