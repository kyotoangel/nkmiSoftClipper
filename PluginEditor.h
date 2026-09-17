#pragma once

#include "PluginProcessor.h"

//==============================================================================
class AudioPluginAudioProcessorEditor final : public juce::AudioProcessorEditor
{
public:
    explicit AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor&);
    ~AudioPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AudioPluginAudioProcessor& processorRef;

    juce::Slider preGain;
    juce::Slider outputGain;

    juce::AudioProcessorValueTreeState::SliderAttachment preGainSliderAttachment;
    juce::AudioProcessorValueTreeState::SliderAttachment postGainSliderAttachment;
    juce::ComboBox oversamplingComboBox;

    juce::AudioParameterChoice* oversamplingParam = nullptr;
    juce::AudioProcessorValueTreeState::ComboBoxAttachment oversamplingAttachment;

    juce::Label preGainLabel;
    juce::Label postGainLabel;
    juce::Label oversamplingLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPluginAudioProcessorEditor)
};
