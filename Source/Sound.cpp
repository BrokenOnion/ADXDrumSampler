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

#include "Sound.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Sound::Sound ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (openDirectButton = new TextButton ("OpenDirectButton"));
    openDirectButton->setButtonText (TRANS("Open..."));
    openDirectButton->addListener (this);

    addAndMakeVisible (directLabel = new Label ("DirectLabel",
                                                TRANS("Direct:")));
    directLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    directLabel->setJustificationType (Justification::centredLeft);
    directLabel->setEditable (false, false, false);
    directLabel->setColour (TextEditor::textColourId, Colours::black);
    directLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (clearDirectButton = new TextButton ("ClearDirectButton"));
    clearDirectButton->setButtonText (TRANS("Clear"));
    clearDirectButton->addListener (this);

    addAndMakeVisible (roomLabel = new Label ("RoomLabel",
                                              TRANS("Room:")));
    roomLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    roomLabel->setJustificationType (Justification::centredLeft);
    roomLabel->setEditable (false, false, false);
    roomLabel->setColour (TextEditor::textColourId, Colours::black);
    roomLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (openRoomButton = new TextButton ("OpenRoomButton"));
    openRoomButton->setButtonText (TRANS("Open..."));
    openRoomButton->addListener (this);

    addAndMakeVisible (clearRoomButton = new TextButton ("ClearRoomButton"));
    clearRoomButton->setButtonText (TRANS("Clear"));
    clearRoomButton->addListener (this);

    addAndMakeVisible (deleteSoundButton = new TextButton ("DeleteButton"));
    deleteSoundButton->setButtonText (TRANS("Delete Sound"));
    deleteSoundButton->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (568, 360);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

Sound::~Sound()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    openDirectButton = nullptr;
    directLabel = nullptr;
    clearDirectButton = nullptr;
    roomLabel = nullptr;
    openRoomButton = nullptr;
    clearRoomButton = nullptr;
    deleteSoundButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Sound::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    {
        float x = 19.0f, y = 42.0f, width = 533.0f, height = 100.0f;
        Colour fillColour = Colour (0xff46525b);
        Colour strokeColour = Colour (0xff2d383e);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
        g.setColour (strokeColour);
        g.drawRoundedRectangle (x, y, width, height, 10.000f, 2.000f);
		/*
		if (directThumbnail.getNumChannels() != 0) 
		{
			const Rectangle<int> thumbnailBounds(x+5, y, width-10, height);
			g.setColour(Colours::white);
			directThumbnail.drawChannels(g, thumbnailBounds, 0.0, directThumbnail.getTotalLength(), 1.0f);
		}
		*/
    }

    {
        float x = 19.0f, y = 194.0f, width = 533.0f, height = 100.0f;
        Colour fillColour = Colour (0xff46525b);
        Colour strokeColour = Colour (0xff2d383e);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
        g.setColour (strokeColour);
        g.drawRoundedRectangle (x, y, width, height, 10.000f, 2.000f);
		/*
		if (roomThumbnail.getNumChannels() != 0)
		{
			const Rectangle<int> thumbnailBounds(x+5, y, width-10, height);
			g.setColour(Colours::white);
			roomThumbnail.drawChannels(g, thumbnailBounds, 0.0, roomThumbnail.getTotalLength(), 1.0f);
		}
		*/
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void Sound::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    openDirectButton->setBounds (168, 8, 184, 24);
    directLabel->setBounds (16, 8, 150, 24);
    clearDirectButton->setBounds (376, 8, 174, 24);
    roomLabel->setBounds (16, 160, 150, 24);
    openRoomButton->setBounds (168, 160, 184, 24);
    clearRoomButton->setBounds (376, 160, 174, 24);
    deleteSoundButton->setBounds (160, 304, 264, 48);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void Sound::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == openDirectButton)
    {
        //[UserButtonCode_openDirectButton] -- add your button handler code here..
        //[/UserButtonCode_openDirectButton]
    }
    else if (buttonThatWasClicked == clearDirectButton)
    {
        //[UserButtonCode_clearDirectButton] -- add your button handler code here..
        //[/UserButtonCode_clearDirectButton]
    }
    else if (buttonThatWasClicked == openRoomButton)
    {
        //[UserButtonCode_openRoomButton] -- add your button handler code here..
        //[/UserButtonCode_openRoomButton]
    }
    else if (buttonThatWasClicked == clearRoomButton)
    {
        //[UserButtonCode_clearRoomButton] -- add your button handler code here..
        //[/UserButtonCode_clearRoomButton]
    }
    else if (buttonThatWasClicked == deleteSoundButton)
    {
        //[UserButtonCode_deleteSoundButton] -- add your button handler code here..
        //[/UserButtonCode_deleteSoundButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="Sound" componentName="" parentClasses="public Component"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="568"
                 initialHeight="360">
  <BACKGROUND backgroundColour="ff323e44">
    <ROUNDRECT pos="19 42 533 100" cornerSize="10" fill="solid: ff46525b" hasStroke="1"
               stroke="2, mitered, butt" strokeColour="solid: ff2d383e"/>
    <ROUNDRECT pos="19 194 533 100" cornerSize="10" fill="solid: ff46525b" hasStroke="1"
               stroke="2, mitered, butt" strokeColour="solid: ff2d383e"/>
  </BACKGROUND>
  <TEXTBUTTON name="OpenDirectButton" id="10122a427c69c352" memberName="openDirectButton"
              virtualName="" explicitFocusOrder="0" pos="168 8 184 24" buttonText="Open..."
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="DirectLabel" id="ee91ffe89aed965" memberName="directLabel"
         virtualName="" explicitFocusOrder="0" pos="16 8 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Direct:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="ClearDirectButton" id="58766068f47bdf67" memberName="clearDirectButton"
              virtualName="" explicitFocusOrder="0" pos="376 8 174 24" buttonText="Clear"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="RoomLabel" id="e2242111c6372b3c" memberName="roomLabel"
         virtualName="" explicitFocusOrder="0" pos="16 160 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Room:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="OpenRoomButton" id="a39142e59d2042db" memberName="openRoomButton"
              virtualName="" explicitFocusOrder="0" pos="168 160 184 24" buttonText="Open..."
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="ClearRoomButton" id="52f062384222b78d" memberName="clearRoomButton"
              virtualName="" explicitFocusOrder="0" pos="376 160 174 24" buttonText="Clear"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="DeleteButton" id="eb79fa7c85c8752c" memberName="deleteSoundButton"
              virtualName="" explicitFocusOrder="0" pos="160 304 264 48" bgColOff="ffa82b2b"
              buttonText="Delete Sound" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
