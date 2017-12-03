/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
AdxAudioProcessor::AdxAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

AdxAudioProcessor::~AdxAudioProcessor()
{
	channels.clear();
}

//==============================================================================
const String AdxAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool AdxAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool AdxAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool AdxAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double AdxAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int AdxAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int AdxAudioProcessor::getCurrentProgram()
{
    return 0;
}

void AdxAudioProcessor::setCurrentProgram (int index)
{
}

const String AdxAudioProcessor::getProgramName (int index)
{
    return {};
}

void AdxAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void AdxAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
	for (int i = 0; i < channels.size(); i++)
	{
		channels.getUnchecked(i)->prepareToPlay(samplesPerBlock, sampleRate);
	}
	this->sampleRate = sampleRate;
	this->samplesPerBlock = samplesPerBlock;
}

void AdxAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
	for (int i = 0; i < channels.size(); i++)
	{
		channels.getUnchecked(i)->releaseResources();
	}
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool AdxAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void AdxAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    const int totalNumInputChannels  = getTotalNumInputChannels();
    const int totalNumOutputChannels = getTotalNumOutputChannels();

	if (!midiMessages.isEmpty())
	{
		MidiBuffer::Iterator iterator(midiMessages);
		MidiMessage message;
		int sampleNum;

		while (iterator.getNextEvent(message, sampleNum)) 
		{
			if (message.isNoteOn()) 
			{
				sendActionMessage(message.getNoteNumber() + ":" + message.getVelocity());
			}
		}
	}

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (int i = 0; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...

}

//==============================================================================
bool AdxAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* AdxAudioProcessor::createEditor()
{
    return new AdxAudioProcessorEditor (*this);
}

//==============================================================================
void AdxAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void AdxAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new AdxAudioProcessor();
}

//==============================================================================
Channel* AdxAudioProcessor::createChannel() 
{
	Channel* newChannel = new Channel();
	newChannel->prepareToPlay(samplesPerBlock, sampleRate);
	channels.add(newChannel);
	return newChannel;
}

Channel* AdxAudioProcessor::getRoomChannel() const
{
	return roomChannel;
}
