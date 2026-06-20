#pragma once

#include "PluginProcessor.h"
#include "Square.h"

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
    Square square;    

    juce::Slider frequencySlider;
    juce::TextButton playButton;
    juce::Label frequencyLabel {"FrequencyLabel", "Frequency"};

    juce::Slider volumeSlider;
    

    AudioPluginAudioProcessor& processorRef;

    juce::AudioProcessorValueTreeState::SliderAttachment freqSliderAttachment;


    juce::AudioProcessorValueTreeState::ButtonAttachment playButtonAttachment;

    juce::AudioProcessorValueTreeState::SliderAttachment volumeAttachment;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPluginAudioProcessorEditor)
};
