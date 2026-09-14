#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================

AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p), preGainSliderAttachment(processorRef.getState(), "preGain", preGain),
postGainSliderAttachment(processorRef.getState(), "outputGain", outputGain)
{
    juce::ignoreUnused (processorRef);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (300, 200);

    preGain.setSliderStyle (juce::Slider::SliderStyle::LinearHorizontal);
    preGain.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50,20);
    addAndMakeVisible(preGain);

    outputGain.setSliderStyle(juce::Slider::LinearHorizontal);
    outputGain.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50,20);
    addAndMakeVisible(outputGain);
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
    auto area = getLocalBounds();
    auto headerFooterHeight = 36;
    preGain.setBounds(area.removeFromBottom(headerFooterHeight));
    outputGain.setBounds(area.removeFromBottom(headerFooterHeight));
}