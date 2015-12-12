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

#ifndef __JUCE_HEADER_419FC5D7D3F5212A__
#define __JUCE_HEADER_419FC5D7D3F5212A__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    The GUI editor for this plugin.
                                                                    //[/Comments]
*/
class PluginAudioProcessorEditor  : public AudioProcessorEditor,
                                    public Timer,
                                    public SliderListener
{
public:
    //==============================================================================
    PluginAudioProcessorEditor (PluginAudioProcessor& p);
    ~PluginAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback ();
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    PluginAudioProcessor& processor;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Label> label;
    ScopedPointer<Slider> bitDepthSlider;
    ScopedPointer<Slider> sampleRateSlider;
    ScopedPointer<Label> bitDepthLabel;
    ScopedPointer<Label> sampleRateLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_419FC5D7D3F5212A__
