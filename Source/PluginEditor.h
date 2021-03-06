/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.2.0

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
class AdxAudioProcessor;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class AdxAudioProcessorEditor  : public AudioProcessorEditor,
                                 public Button::Listener,
                                 public ComboBox::Listener
{
public:
    //==============================================================================
    AdxAudioProcessorEditor (AdxAudioProcessor& ownerProc);
    ~AdxAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	TabbedComponent& getDrumsList();
	void addTab(Component* componentToAdd);
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	AdxAudioProcessor& processor;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<TabbedComponent> drumsList;
    ScopedPointer<TextButton> addDrumButton;
    ScopedPointer<Label> roomOutputLabel;
    ScopedPointer<ComboBox> roomOutputCombo;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AdxAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
