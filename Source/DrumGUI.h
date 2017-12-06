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
#include "PluginEditor.h"
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class DrumGUI  : public Component,
                 public Button::Listener,
                 public Slider::Listener,
                 public ComboBox::Listener
{
public:
    //==============================================================================
    DrumGUI (Drum& parentRef);
    ~DrumGUI();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void addTab(Component* componentToAdd);
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	Drum& parent;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<TextButton> addVelocityButton;
    ScopedPointer<Slider> noteSlider;
    ScopedPointer<Label> midiNoteLabel;
    ScopedPointer<Label> name;
    ScopedPointer<TextEditor> nameEditor;
    ScopedPointer<Label> volumeLabel;
    ScopedPointer<Slider> gainSlider;
    ScopedPointer<Slider> panSlider;
    ScopedPointer<Label> panLabel;
    ScopedPointer<TextButton> testButton;
    ScopedPointer<TextButton> setNameButton;
    ScopedPointer<TextButton> deleteButton;
    ScopedPointer<TabbedComponent> velocityLayers;
    ScopedPointer<Label> outputLabel;
    ScopedPointer<ComboBox> comboBox;
    ScopedPointer<ComboBox> chokeCombo;
    ScopedPointer<Label> chokeLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DrumGUI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
