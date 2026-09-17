#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================

AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p),
    preGainSliderAttachment(processorRef.getState(), "preGain", preGain),
    postGainSliderAttachment(processorRef.getState(), "outputGain", outputGain),
    oversamplingAttachment(processorRef.getState(),"oversampling",oversamplingComboBox)
{
    juce::ignoreUnused (processorRef);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 160);

    // Sliders de Pre-Gain et Post-Gain

    preGain.setSliderStyle (juce::Slider::SliderStyle::LinearHorizontal);
    preGain.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50,20);
    preGain.setTextValueSuffix(" dB");
    addAndMakeVisible(preGain);

    outputGain.setSliderStyle(juce::Slider::LinearHorizontal);
    outputGain.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50,20);
    outputGain.setTextValueSuffix(" dB");
    addAndMakeVisible(outputGain);

    // ComboBox (oversampling)

    oversamplingParam = dynamic_cast<juce::AudioParameterChoice*>(processorRef.parameters.getParameter("oversampling"));

    addAndMakeVisible(oversamplingComboBox);
    oversamplingComboBox.addItem("x1", 1);
    oversamplingComboBox.addItem("x2", 2);
    oversamplingComboBox.addItem("x4", 3);

    oversamplingComboBox.setSelectedItemIndex(oversamplingParam->getIndex(), juce::dontSendNotification);

    // --- Labels

    addAndMakeVisible (preGainLabel);
    addAndMakeVisible(postGainLabel);
    addAndMakeVisible (oversamplingLabel);

    preGainLabel.attachToComponent (&preGain, true);
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
    const int marge_x = 10;
    const int marge_y = 20;
    preGain.setBounds(marge_x, marge_y, getWidth() - 2 * marge_x , marge_y * 2);
    outputGain.setBounds(marge_x, marge_y * 3, getWidth() - 2 * marge_x, marge_y * 2);
    oversamplingComboBox.setBounds(getWidth() - 50, getHeight()-30, 40, 20);
}