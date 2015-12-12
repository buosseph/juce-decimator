/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 4.0.2

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PluginAudioProcessorEditor::PluginAudioProcessorEditor (PluginAudioProcessor& p)
    : AudioProcessorEditor(&p), processor(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("Decimator")));
    label->setFont (Font (35.00f, Font::plain));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (Label::textColourId, Colours::white);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (bitDepthSlider = new Slider ("new slider"));
    bitDepthSlider->setRange (1, 32, 0);
    bitDepthSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    bitDepthSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    bitDepthSlider->setColour (Slider::rotarySliderFillColourId, Colour (0x7f888888));
    bitDepthSlider->addListener (this);

    addAndMakeVisible (sampleRateSlider = new Slider ("new slider"));
    sampleRateSlider->setRange (0, 1, 0);
    sampleRateSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    sampleRateSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    sampleRateSlider->setColour (Slider::rotarySliderFillColourId, Colour (0x7f888888));
    sampleRateSlider->addListener (this);

    addAndMakeVisible (bitDepthLabel = new Label ("new label",
                                                  TRANS("Bit Depth")));
    bitDepthLabel->setFont (Font (15.00f, Font::plain));
    bitDepthLabel->setJustificationType (Justification::centred);
    bitDepthLabel->setEditable (false, false, false);
    bitDepthLabel->setColour (Label::textColourId, Colours::white);
    bitDepthLabel->setColour (TextEditor::textColourId, Colours::black);
    bitDepthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (sampleRateLabel = new Label ("new label",
                                                    TRANS("Sample Rate")));
    sampleRateLabel->setFont (Font (15.00f, Font::plain));
    sampleRateLabel->setJustificationType (Justification::centred);
    sampleRateLabel->setEditable (false, false, false);
    sampleRateLabel->setColour (Label::textColourId, Colours::white);
    sampleRateLabel->setColour (TextEditor::textColourId, Colours::black);
    sampleRateLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (180, 160);


    //[Constructor] You can add your own custom stuff here..
    startTimer (30);
    //[/Constructor]
}

PluginAudioProcessorEditor::~PluginAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    label = nullptr;
    bitDepthSlider = nullptr;
    sampleRateSlider = nullptr;
    bitDepthLabel = nullptr;
    sampleRateLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PluginAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff222222));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PluginAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    label->setBounds (0, 0, 180, 40);
    bitDepthSlider->setBounds (10, 70, 70, 80);
    sampleRateSlider->setBounds (100, 70, 70, 80);
    bitDepthLabel->setBounds (0, 50, 90, 20);
    sampleRateLabel->setBounds (90, 50, 90, 20);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PluginAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == bitDepthSlider)
    {
        //[UserSliderCode_bitDepthSlider] -- add your slider handling code here..
        processor.bit_depth_parameter
            ->setValueNotifyingHost( (bitDepthSlider->getValue() - 1.f) / (31.f) );
        //[/UserSliderCode_bitDepthSlider]
    }
    else if (sliderThatWasMoved == sampleRateSlider)
    {
        //[UserSliderCode_sampleRateSlider] -- add your slider handling code here..
        processor.sample_rate_parameter->setValueNotifyingHost(sampleRateSlider->getValue());
        //[/UserSliderCode_sampleRateSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void PluginAudioProcessorEditor::timerCallback () {
    bitDepthSlider->setValue(processor.bit_depth_parameter->get());
    sampleRateSlider->setValue(processor.sample_rate_parameter->get());
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PluginAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="PluginAudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor(&amp;p), processor(p)"
                 snapPixels="10" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="180" initialHeight="160">
  <BACKGROUND backgroundColour="ff222222"/>
  <LABEL name="new label" id="3ed10ccd714e0746" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="0 0 180 40" textCol="ffffffff" edTextCol="ff000000"
         edBkgCol="0" labelText="Decimator" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="35"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="af827f4f1e556834" memberName="bitDepthSlider"
          virtualName="" explicitFocusOrder="0" pos="10 70 70 80" rotarysliderfill="7f888888"
          min="1" max="32" int="0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="5a913fd7078e4a27" memberName="sampleRateSlider"
          virtualName="" explicitFocusOrder="0" pos="100 70 70 80" rotarysliderfill="7f888888"
          min="0" max="1" int="0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="889e4b7dfd2d0a9f" memberName="bitDepthLabel"
         virtualName="" explicitFocusOrder="0" pos="0 50 90 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Bit Depth" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="70424814261e7a45" memberName="sampleRateLabel"
         virtualName="" explicitFocusOrder="0" pos="90 50 90 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Sample Rate" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
