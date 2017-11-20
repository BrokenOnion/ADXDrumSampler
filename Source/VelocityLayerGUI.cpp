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

#include "VelocityLayerGUI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
VelocityLayerGUI::VelocityLayerGUI ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (soundsList = new TabbedComponent (TabbedButtonBar::TabsAtTop));
    soundsList->setTabBarDepth (40);
    soundsList->setCurrentTabIndex (-1);

    addAndMakeVisible (addSoundButton = new TextButton ("AddSoundButton"));
    addSoundButton->setButtonText (TRANS("Add Sound..."));
    addSoundButton->addListener (this);

    addAndMakeVisible (deleteLayerButton = new TextButton ("DeleteLayerButton"));
    deleteLayerButton->setButtonText (TRANS("Delete Layer"));
    deleteLayerButton->addListener (this);
    deleteLayerButton->setColour (TextButton::buttonColourId, Colour (0xff9e2525));

    addAndMakeVisible (upperLabel = new Label ("UpperLabel",
                                               TRANS("Upper Bound:")));
    upperLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    upperLabel->setJustificationType (Justification::centredLeft);
    upperLabel->setEditable (false, false, false);
    upperLabel->setColour (TextEditor::textColourId, Colours::black);
    upperLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (lowerLabel = new Label ("LowerLabel",
                                               TRANS("Lower Bound:")));
    lowerLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    lowerLabel->setJustificationType (Justification::centredLeft);
    lowerLabel->setEditable (false, false, false);
    lowerLabel->setColour (TextEditor::textColourId, Colours::black);
    lowerLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (upperSlider = new Slider ("UpperSlider"));
    upperSlider->setRange (0, 127, 1);
    upperSlider->setSliderStyle (Slider::LinearHorizontal);
    upperSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 50, 20);
    upperSlider->addListener (this);

    addAndMakeVisible (lowerSlider = new Slider ("LowerSlider"));
    lowerSlider->setRange (0, 127, 1);
    lowerSlider->setSliderStyle (Slider::LinearHorizontal);
    lowerSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 50, 20);
    lowerSlider->addListener (this);

    addAndMakeVisible (functionLabel = new Label ("FunctionLabel",
                                                  TRANS("Crossfade Function:")));
    functionLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    functionLabel->setJustificationType (Justification::centredLeft);
    functionLabel->setEditable (false, false, false);
    functionLabel->setColour (TextEditor::textColourId, Colours::black);
    functionLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (functionCombo = new ComboBox ("FunctionCombo"));
    functionCombo->setEditableText (false);
    functionCombo->setJustificationType (Justification::centredLeft);
    functionCombo->setTextWhenNothingSelected (String());
    functionCombo->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    functionCombo->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 592);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

VelocityLayerGUI::~VelocityLayerGUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    soundsList = nullptr;
    addSoundButton = nullptr;
    deleteLayerButton = nullptr;
    upperLabel = nullptr;
    lowerLabel = nullptr;
    upperSlider = nullptr;
    lowerSlider = nullptr;
    functionLabel = nullptr;
    functionCombo = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void VelocityLayerGUI::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void VelocityLayerGUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    soundsList->setBounds (16, 176, 568, 400);
    addSoundButton->setBounds (16, 112, 272, 48);
    deleteLayerButton->setBounds (312, 112, 272, 48);
    upperLabel->setBounds (16, 16, 120, 24);
    lowerLabel->setBounds (16, 56, 120, 24);
    upperSlider->setBounds (144, 16, 200, 24);
    lowerSlider->setBounds (144, 56, 200, 24);
    functionLabel->setBounds (408, 16, 128, 24);
    functionCombo->setBounds (368, 56, 208, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void VelocityLayerGUI::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == addSoundButton)
    {
        //[UserButtonCode_addSoundButton] -- add your button handler code here..
        //[/UserButtonCode_addSoundButton]
    }
    else if (buttonThatWasClicked == deleteLayerButton)
    {
        //[UserButtonCode_deleteLayerButton] -- add your button handler code here..

        //[/UserButtonCode_deleteLayerButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void VelocityLayerGUI::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == upperSlider)
    {
        //[UserSliderCode_upperSlider] -- add your slider handling code here..
        //[/UserSliderCode_upperSlider]
    }
    else if (sliderThatWasMoved == lowerSlider)
    {
        //[UserSliderCode_lowerSlider] -- add your slider handling code here..
        //[/UserSliderCode_lowerSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void VelocityLayerGUI::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == functionCombo)
    {
        //[UserComboBoxCode_functionCombo] -- add your combo box handling code here..
        //[/UserComboBoxCode_functionCombo]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="VelocityLayerGUI" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="600" initialHeight="592">
  <BACKGROUND backgroundColour="ff323e44"/>
  <TABBEDCOMPONENT name="SoundsList" id="30f73db64cf179b3" memberName="soundsList"
                   virtualName="" explicitFocusOrder="0" pos="16 176 568 400" orientation="top"
                   tabBarDepth="40" initialTab="-1"/>
  <TEXTBUTTON name="AddSoundButton" id="4b02f8459d2cf300" memberName="addSoundButton"
              virtualName="" explicitFocusOrder="0" pos="16 112 272 48" buttonText="Add Sound..."
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="DeleteLayerButton" id="e627433dd1e34075" memberName="deleteLayerButton"
              virtualName="" explicitFocusOrder="0" pos="312 112 272 48" bgColOff="ff9e2525"
              buttonText="Delete Layer" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <LABEL name="UpperLabel" id="5e5d43d798fe25b4" memberName="upperLabel"
         virtualName="" explicitFocusOrder="0" pos="16 16 120 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Upper Bound:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="LowerLabel" id="3a0d358b87a75664" memberName="lowerLabel"
         virtualName="" explicitFocusOrder="0" pos="16 56 120 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Lower Bound:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <SLIDER name="UpperSlider" id="464797bc256eed32" memberName="upperSlider"
          virtualName="" explicitFocusOrder="0" pos="144 16 200 24" min="0"
          max="127" int="1" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="LowerSlider" id="3306f108b75b71c4" memberName="lowerSlider"
          virtualName="" explicitFocusOrder="0" pos="144 56 200 24" min="0"
          max="127" int="1" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <LABEL name="FunctionLabel" id="4d9d63027844be01" memberName="functionLabel"
         virtualName="" explicitFocusOrder="0" pos="408 16 128 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Crossfade Function:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="FunctionCombo" id="6b58333a2ea25037" memberName="functionCombo"
            virtualName="" explicitFocusOrder="0" pos="368 56 208 24" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
