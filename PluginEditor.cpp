#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================

AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p), preGainSliderAttachment(processorRef.getState(), "preGain", preGain)
{
    juce::ignoreUnused (processorRef);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (300, 200);

    preGain.setValue(0.0f);
    preGain.setSliderStyle (juce::Slider::SliderStyle::Rotary);
    preGain.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50,20);
    addAndMakeVisible(preGain);
}


AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
    setLookAndFeel(nullptr);
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
}

void AudioPluginAudioProcessorEditor::resized()
{
    preGain.setBounds(getLocalBounds().reduced(20));
}
