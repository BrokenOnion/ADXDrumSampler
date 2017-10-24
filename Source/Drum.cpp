/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.1.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "Drum.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Drum::Drum ()
{
    //[Constructor_pre] You can add your own custom stuff here..
	nameEditor->addListener(this);
    //[/Constructor_pre]

    addAndMakeVisible (addVelocityButton = new TextButton ("AddVelocityButton"));
    addVelocityButton->setButtonText (TRANS("Add Velocity Layer..."));
    addVelocityButton->addListener (this);

    addAndMakeVisible (velocityLayers = new TabbedComponent (TabbedButtonBar::TabsAtLeft));
    velocityLayers->setTabBarDepth (50);
    velocityLayers->setCurrentTabIndex (-1);

    addAndMakeVisible (noteSlider = new Slider ("NoteSlider"));
    noteSlider->setRange (0, 127, 1);
    noteSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    noteSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 60, 30);
    noteSlider->addListener (this);

    addAndMakeVisible (midiNoteLabel = new Label ("MidiNoteLabel",
                                                  TRANS("Midi Note:")));
    midiNoteLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    midiNoteLabel->setJustificationType (Justification::centredLeft);
    midiNoteLabel->setEditable (false, false, false);
    midiNoteLabel->setColour (TextEditor::textColourId, Colours::black);
    midiNoteLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (name = new Label ("Name",
                                         TRANS("Name:")));
    name->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    name->setJustificationType (Justification::centredLeft);
    name->setEditable (false, false, false);
    name->setColour (TextEditor::textColourId, Colours::black);
    name->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (nameEditor = new TextEditor ("NameEditor"));
    nameEditor->setMultiLine (false);
    nameEditor->setReturnKeyStartsNewLine (false);
    nameEditor->setReadOnly (false);
    nameEditor->setScrollbarsShown (true);
    nameEditor->setCaretVisible (true);
    nameEditor->setPopupMenuEnabled (true);
    nameEditor->setText (String());

    addAndMakeVisible (volumeLabel = new Label ("VolumeLabel",
                                                TRANS("Gain")));
    volumeLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    volumeLabel->setJustificationType (Justification::centred);
    volumeLabel->setEditable (false, false, false);
    volumeLabel->setColour (TextEditor::textColourId, Colours::black);
    volumeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (gainSlider = new Slider ("gainSlider"));
    gainSlider->setRange (-156, 6, 0.1);
    gainSlider->setSliderStyle (Slider::LinearVertical);
    gainSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 20);
    gainSlider->addListener (this);
    gainSlider->setSkewFactor (5);

    addAndMakeVisible (panSlider = new Slider ("PanSlider"));
    panSlider->setRange (-90, 90, 1);
    panSlider->setSliderStyle (Slider::RotaryHorizontalDrag);
    panSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 60, 20);
    panSlider->addListener (this);

    addAndMakeVisible (panLabel = new Label ("PanLabel",
                                             TRANS("Pan:")));
    panLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    panLabel->setJustificationType (Justification::centredLeft);
    panLabel->setEditable (false, false, false);
    panLabel->setColour (TextEditor::textColourId, Colours::black);
    panLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (testButton = new TextButton ("TestButton"));
    testButton->setButtonText (TRANS("Test Drum"));
    testButton->addListener (this);

    addAndMakeVisible (deleteButton = new TextButton ("DeleteButton"));
    deleteButton->setButtonText (TRANS("Delete"));
    deleteButton->addListener (this);
    deleteButton->setColour (TextButton::buttonColourId, Colour (0xffbc3333));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (940, 660);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

Drum::~Drum()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	velocityLayers->clearTabs();
    //[/Destructor_pre]

    addVelocityButton = nullptr;
    velocityLayers = nullptr;
    noteSlider = nullptr;
    midiNoteLabel = nullptr;
    name = nullptr;
    nameEditor = nullptr;
    volumeLabel = nullptr;
    gainSlider = nullptr;
    panSlider = nullptr;
    panLabel = nullptr;
    testButton = nullptr;
    deleteButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Drum::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff313a3f));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void Drum::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    addVelocityButton->setBounds (16, 16, 264, 56);
    velocityLayers->setBounds (16, 88, 600, 550);
    noteSlider->setBounds (760, 168, 160, 56);
    midiNoteLabel->setBounds (632, 176, 104, 40);
    name->setBounds (632, 104, 104, 40);
    nameEditor->setBounds (752, 112, 150, 24);
    volumeLabel->setBounds (824, 608, 88, 24);
    gainSlider->setBounds (840, 336, 56, 248);
    panSlider->setBounds (760, 248, 154, 56);
    panLabel->setBounds (640, 256, 144, 40);
    testButton->setBounds (640, 448, 168, 80);
    deleteButton->setBounds (640, 552, 168, 80);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void Drum::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == addVelocityButton)
    {
        //[UserButtonCode_addVelocityButton] -- add your button handler code here..
		velocityLayers->addTab("", Colour(0xffa45c94), new VelocityLayer(), true, -1);
        //[/UserButtonCode_addVelocityButton]
    }
    else if (buttonThatWasClicked == testButton)
    {
        //[UserButtonCode_testButton] -- add your button handler code here..
        //[/UserButtonCode_testButton]
    }
    else if (buttonThatWasClicked == deleteButton)
    {
        //[UserButtonCode_deleteButton] -- add your button handler code here..
        //[/UserButtonCode_deleteButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void Drum::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == noteSlider)
    {
        //[UserSliderCode_noteSlider] -- add your slider handling code here..
        //[/UserSliderCode_noteSlider]
    }
    else if (sliderThatWasMoved == gainSlider)
    {
        //[UserSliderCode_gainSlider] -- add your slider handling code here..
        //[/UserSliderCode_gainSlider]
    }
    else if (sliderThatWasMoved == panSlider)
    {
        //[UserSliderCode_panSlider] -- add your slider handling code here..
        //[/UserSliderCode_panSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void Drum::textEditorTextChanged(TextEditor& editorThatWasChanged) 
{
	
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="Drum" componentName="" parentClasses="public Component"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="940"
                 initialHeight="660">
  <BACKGROUND backgroundColour="ff313a3f"/>
  <TEXTBUTTON name="AddVelocityButton" id="9da359f4875ffb71" memberName="addVelocityButton"
              virtualName="" explicitFocusOrder="0" pos="16 16 264 56" buttonText="Add Velocity Layer..."
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TABBEDCOMPONENT name="VelocityLayers" id="1cfb7f0539cc49e0" memberName="velocityLayers"
                   virtualName="" explicitFocusOrder="0" pos="16 88 600 550" orientation="left"
                   tabBarDepth="50" initialTab="-1"/>
  <SLIDER name="NoteSlider" id="a7c169d7c7b15a0f" memberName="noteSlider"
          virtualName="" explicitFocusOrder="0" pos="760 168 160 56" min="0"
          max="127" int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="30" skewFactor="1"
          needsCallback="1"/>
  <LABEL name="MidiNoteLabel" id="aafc2dc8e39e1b8c" memberName="midiNoteLabel"
         virtualName="" explicitFocusOrder="0" pos="632 176 104 40" edTextCol="ff000000"
         edBkgCol="0" labelText="Midi Note:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="Name" id="43ab4fd4d4ba132c" memberName="name" virtualName=""
         explicitFocusOrder="0" pos="632 104 104 40" edTextCol="ff000000"
         edBkgCol="0" labelText="Name:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="NameEditor" id="986d6185f4aef912" memberName="nameEditor"
              virtualName="" explicitFocusOrder="0" pos="752 112 150 24" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <LABEL name="VolumeLabel" id="e0d919758dae5f" memberName="volumeLabel"
         virtualName="" explicitFocusOrder="0" pos="824 608 88 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Gain" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <SLIDER name="gainSlider" id="889d4391f08c0476" memberName="gainSlider"
          virtualName="" explicitFocusOrder="0" pos="840 336 56 248" min="-156"
          max="6" int="0.10000000000000000555" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="20" skewFactor="5"
          needsCallback="1"/>
  <SLIDER name="PanSlider" id="58c1292f4128d0fb" memberName="panSlider"
          virtualName="" explicitFocusOrder="0" pos="760 248 154 56" min="-90"
          max="90" int="1" style="RotaryHorizontalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <LABEL name="PanLabel" id="d774f9122e77b0e4" memberName="panLabel" virtualName=""
         explicitFocusOrder="0" pos="640 256 144 40" edTextCol="ff000000"
         edBkgCol="0" labelText="Pan:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="TestButton" id="b9d16aec31ec8a21" memberName="testButton"
              virtualName="" explicitFocusOrder="0" pos="640 448 168 80" buttonText="Test Drum"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="DeleteButton" id="c6af0e0a14d21ed1" memberName="deleteButton"
              virtualName="" explicitFocusOrder="0" pos="640 552 168 80" bgColOff="ffbc3333"
              buttonText="Delete" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
