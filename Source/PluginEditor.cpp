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
#include "Drum.h"
#include "Windows.h"
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
AdxAudioProcessorEditor::AdxAudioProcessorEditor (AdxAudioProcessor& ownerProc)
    : AudioProcessorEditor(ownerProc), processor(ownerProc)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (drumsList = new TabbedComponent (TabbedButtonBar::TabsAtLeft));
    drumsList->setTabBarDepth (50);
    drumsList->setCurrentTabIndex (-1);

    addAndMakeVisible (addDrumButton = new TextButton ("Add Drum Button"));
    addDrumButton->setButtonText (TRANS("Add new drum..."));
    addDrumButton->addListener (this);
    addDrumButton->setColour (TextButton::buttonColourId, Colour (0xffa45c94));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (1024, 768);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

AdxAudioProcessorEditor::~AdxAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	drumsList->clearTabs();
    //[/Destructor_pre]

    drumsList = nullptr;
    addDrumButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void AdxAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void AdxAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    drumsList->setBounds (16, 96, 990, 660);
    addDrumButton->setBounds (24, 16, 256, 56);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void AdxAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == addDrumButton)
    {
        //[UserButtonCode_addDrumButton] -- add your button handler code here..
        //[/UserButtonCode_addDrumButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
TabbedComponent& AdxAudioProcessorEditor::getDrumsList()
{
	return *drumsList;
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="AdxAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor"
                 constructorParams="AdxAudioProcessor&amp; ownerProc" variableInitialisers="AudioProcessorEditor(ownerProc), processor(ownerProc)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="1024" initialHeight="768">
  <BACKGROUND backgroundColour="ff323e44"/>
  <TABBEDCOMPONENT name="Drums List" id="6ead998e4b627b9d" memberName="drumsList"
                   virtualName="" explicitFocusOrder="0" pos="16 96 990 660" orientation="left"
                   tabBarDepth="50" initialTab="-1"/>
  <TEXTBUTTON name="Add Drum Button" id="fed69c8000d479aa" memberName="addDrumButton"
              virtualName="" explicitFocusOrder="0" pos="24 16 256 56" bgColOff="ffa45c94"
              buttonText="Add new drum..." connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
