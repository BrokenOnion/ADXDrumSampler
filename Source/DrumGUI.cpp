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

//[Headers] You can add your own extra header files here...
#include "PluginEditor.h"
#include "PluginProcessor.h"
#include "Drum.h"
//[/Headers]

#include "DrumGUI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
DrumGUI::DrumGUI (Drum& parentRef)
    : parent(parentRef)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (addVelocityButton = new TextButton ("AddVelocityButton"));
    addVelocityButton->setButtonText (TRANS("Add Velocity Layer..."));
    addVelocityButton->addListener (this);

    addAndMakeVisible (noteSlider = new Slider ("NoteSlider"));
    noteSlider->setRange (0, 127, 1);
    noteSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    noteSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 60, 24);
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
                                                TRANS("Volume")));
    volumeLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    volumeLabel->setJustificationType (Justification::centred);
    volumeLabel->setEditable (false, false, false);
    volumeLabel->setColour (TextEditor::textColourId, Colours::black);
    volumeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (gainSlider = new Slider ("gainSlider"));
    gainSlider->setRange (-100, 6, 0.1);
    gainSlider->setSliderStyle (Slider::LinearVertical);
    gainSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 20);
    gainSlider->addListener (this);
    gainSlider->setSkewFactor (4);

    addAndMakeVisible (panSlider = new Slider ("PanSlider"));
    panSlider->setRange (-90, 90, 1);
    panSlider->setSliderStyle (Slider::RotaryHorizontalDrag);
    panSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 60, 24);
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

    addAndMakeVisible (setNameButton = new TextButton ("SetNameButton"));
    setNameButton->setButtonText (TRANS("OK"));
    setNameButton->addListener (this);

    addAndMakeVisible (deleteButton = new TextButton ("DeleteButton"));
    deleteButton->setButtonText (TRANS("Delete Drum"));
    deleteButton->addListener (this);
    deleteButton->setColour (TextButton::buttonColourId, Colour (0xffb22929));

    addAndMakeVisible (velocityLayers = new TabbedComponent (TabbedButtonBar::TabsAtTop));
    velocityLayers->setTabBarDepth (30);
    velocityLayers->setCurrentTabIndex (-1);

    addAndMakeVisible (outputLabel = new Label ("OutputLabel",
                                                TRANS("Output:")));
    outputLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    outputLabel->setJustificationType (Justification::centredLeft);
    outputLabel->setEditable (false, false, false);
    outputLabel->setColour (TextEditor::textColourId, Colours::black);
    outputLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (comboBox = new ComboBox ("new combo box"));
    comboBox->setEditableText (false);
    comboBox->setJustificationType (Justification::centredLeft);
    comboBox->setTextWhenNothingSelected (String());
    comboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox->addListener (this);

    addAndMakeVisible (chokeCombo = new ComboBox ("ChokeCombo"));
    chokeCombo->setEditableText (false);
    chokeCombo->setJustificationType (Justification::centredLeft);
    chokeCombo->setTextWhenNothingSelected (String());
    chokeCombo->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    chokeCombo->addListener (this);

    addAndMakeVisible (chokeLabel = new Label ("ChokeLabel",
                                               TRANS("Choke Group:")));
    chokeLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    chokeLabel->setJustificationType (Justification::centredLeft);
    chokeLabel->setEditable (false, false, false);
    chokeLabel->setColour (TextEditor::textColourId, Colours::black);
    chokeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (940, 660);


    //[Constructor] You can add your own custom stuff here..
	comboBox->addItem("Out 1 + 2", 1);
	comboBox->addItem("Out 3 + 4", 2);
	comboBox->addItem("Out 5 + 6", 3);
	comboBox->addItem("Out 7 + 8", 4);
	comboBox->addItem("Out 9 + 10", 5);
	comboBox->addItem("Out 11 + 12", 6);
	comboBox->addItem("Out 13 + 14", 7);
	comboBox->addItem("Out 15 + 16", 8);

	comboBox->setSelectedId(1);

	chokeCombo->addItem("<None>", 1);
	chokeCombo->addItem("Group 1", 2);
	chokeCombo->addItem("Group 2", 3);
	chokeCombo->addItem("Group 3", 4);
	chokeCombo->addItem("Group 4", 5);

	chokeCombo->setSelectedId(1);
    //[/Constructor]
}

DrumGUI::~DrumGUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	velocityLayers->clearTabs();
    //[/Destructor_pre]

    addVelocityButton = nullptr;
    noteSlider = nullptr;
    midiNoteLabel = nullptr;
    name = nullptr;
    nameEditor = nullptr;
    volumeLabel = nullptr;
    gainSlider = nullptr;
    panSlider = nullptr;
    panLabel = nullptr;
    testButton = nullptr;
    setNameButton = nullptr;
    deleteButton = nullptr;
    velocityLayers = nullptr;
    outputLabel = nullptr;
    comboBox = nullptr;
    chokeCombo = nullptr;
    chokeLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void DrumGUI::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff313a3f));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void DrumGUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    addVelocityButton->setBounds (640, 48, 264, 56);
    noteSlider->setBounds (760, 160, 192, 56);
    midiNoteLabel->setBounds (632, 168, 80, 40);
    name->setBounds (632, 120, 56, 40);
    nameEditor->setBounds (736, 128, 128, 24);
    volumeLabel->setBounds (824, 616, 88, 24);
    gainSlider->setBounds (840, 368, 56, 240);
    panSlider->setBounds (760, 256, 192, 56);
    panLabel->setBounds (632, 264, 40, 40);
    testButton->setBounds (640, 416, 160, 96);
    setNameButton->setBounds (872, 128, 32, 24);
    deleteButton->setBounds (640, 536, 160, 96);
    velocityLayers->setBounds (16, 16, 600, 632);
    outputLabel->setBounds (632, 224, 64, 24);
    comboBox->setBounds (760, 224, 144, 24);
    chokeCombo->setBounds (760, 320, 142, 24);
    chokeLabel->setBounds (632, 320, 150, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void DrumGUI::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
	//int currentIndex = editor.getDrumsList().getCurrentTabIndex();
	//Component* current = editor.getDrumsList().getTabContentComponent(currentIndex);
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == addVelocityButton)
    {
        //[UserButtonCode_addVelocityButton] -- add your button handler code here..
		parent.createVelocityLayer();
        //[/UserButtonCode_addVelocityButton]
    }
    else if (buttonThatWasClicked == testButton)
    {
        //[UserButtonCode_testButton] -- add your button handler code here..
        //[/UserButtonCode_testButton]
    }
    else if (buttonThatWasClicked == setNameButton)
    {
        //[UserButtonCode_setNameButton] -- add your button handler code here..
		//if (current == this)
		{
		//	editor.getDrumsList().setTabName(currentIndex, nameEditor->getText());
		}
        //[/UserButtonCode_setNameButton]
    }
    else if (buttonThatWasClicked == deleteButton)
    {
        //[UserButtonCode_deleteButton] -- add your button handler code here..
		//if (current == this)
		{
			//editor.getDrumsList().removeTab(currentIndex);
		}
        //[/UserButtonCode_deleteButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void DrumGUI::sliderValueChanged (Slider* sliderThatWasMoved)
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

void DrumGUI::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == comboBox)
    {
        //[UserComboBoxCode_comboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_comboBox]
    }
    else if (comboBoxThatHasChanged == chokeCombo)
    {
        //[UserComboBoxCode_chokeCombo] -- add your combo box handling code here..
        //[/UserComboBoxCode_chokeCombo]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void DrumGUI::addTab(Component* componentToAdd)
{
	velocityLayers->addTab(" ", Colour(Colours::grey), componentToAdd, true);
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="DrumGUI" componentName=""
                 parentClasses="public Component" constructorParams="Drum&amp; parentRef"
                 variableInitialisers="parent(parentRef)" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="940"
                 initialHeight="660">
  <BACKGROUND backgroundColour="ff313a3f"/>
  <TEXTBUTTON name="AddVelocityButton" id="9da359f4875ffb71" memberName="addVelocityButton"
              virtualName="" explicitFocusOrder="0" pos="640 48 264 56" buttonText="Add Velocity Layer..."
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="NoteSlider" id="a7c169d7c7b15a0f" memberName="noteSlider"
          virtualName="" explicitFocusOrder="0" pos="760 160 192 56" min="0"
          max="127" int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="24" skewFactor="1"
          needsCallback="1"/>
  <LABEL name="MidiNoteLabel" id="aafc2dc8e39e1b8c" memberName="midiNoteLabel"
         virtualName="" explicitFocusOrder="0" pos="632 168 80 40" edTextCol="ff000000"
         edBkgCol="0" labelText="Midi Note:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="Name" id="43ab4fd4d4ba132c" memberName="name" virtualName=""
         explicitFocusOrder="0" pos="632 120 56 40" edTextCol="ff000000"
         edBkgCol="0" labelText="Name:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="NameEditor" id="986d6185f4aef912" memberName="nameEditor"
              virtualName="" explicitFocusOrder="0" pos="736 128 128 24" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <LABEL name="VolumeLabel" id="e0d919758dae5f" memberName="volumeLabel"
         virtualName="" explicitFocusOrder="0" pos="824 616 88 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Volume" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <SLIDER name="gainSlider" id="889d4391f08c0476" memberName="gainSlider"
          virtualName="" explicitFocusOrder="0" pos="840 368 56 240" min="-100"
          max="6" int="0.10000000000000000555" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="20" skewFactor="4"
          needsCallback="1"/>
  <SLIDER name="PanSlider" id="58c1292f4128d0fb" memberName="panSlider"
          virtualName="" explicitFocusOrder="0" pos="760 256 192 56" min="-90"
          max="90" int="1" style="RotaryHorizontalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="24" skewFactor="1"
          needsCallback="1"/>
  <LABEL name="PanLabel" id="d774f9122e77b0e4" memberName="panLabel" virtualName=""
         explicitFocusOrder="0" pos="632 264 40 40" edTextCol="ff000000"
         edBkgCol="0" labelText="Pan:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="TestButton" id="b9d16aec31ec8a21" memberName="testButton"
              virtualName="" explicitFocusOrder="0" pos="640 416 160 96" buttonText="Test Drum"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="SetNameButton" id="19ee7a70bff1e712" memberName="setNameButton"
              virtualName="" explicitFocusOrder="0" pos="872 128 32 24" buttonText="OK"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="DeleteButton" id="8a6a2a43b0a6659b" memberName="deleteButton"
              virtualName="" explicitFocusOrder="0" pos="640 536 160 96" bgColOff="ffb22929"
              buttonText="Delete Drum" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TABBEDCOMPONENT name="VelocityLayers" id="bc7af05bb72aa53a" memberName="velocityLayers"
                   virtualName="" explicitFocusOrder="0" pos="16 16 600 632" orientation="top"
                   tabBarDepth="30" initialTab="-1"/>
  <LABEL name="OutputLabel" id="964c07fdc0b890e1" memberName="outputLabel"
         virtualName="" explicitFocusOrder="0" pos="632 224 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Output:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="4ad08c1d9b2f59aa" memberName="comboBox"
            virtualName="" explicitFocusOrder="0" pos="760 224 144 24" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="ChokeCombo" id="e7a9d58bb25cbd9a" memberName="chokeCombo"
            virtualName="" explicitFocusOrder="0" pos="760 320 142 24" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="ChokeLabel" id="fbe6d5217e58fe51" memberName="chokeLabel"
         virtualName="" explicitFocusOrder="0" pos="632 320 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Choke Group:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
