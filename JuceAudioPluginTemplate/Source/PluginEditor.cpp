#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p), freqSliderAttachment(processorRef.getState(), "freqhz", frequencySlider), playButtonAttachment(processorRef.getState(), "play", playButton)
{
    juce::ignoreUnused (processorRef);
    //addAndMakeVisible(square);

    frequencySlider.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    frequencySlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 50);
    addAndMakeVisible(frequencySlider);
    
    playButton.setButtonText("Playing");
    playButton.setToggleState(true, juce::NotificationType::dontSendNotification);
    playButton.setClickingTogglesState(true);
    
    playButton.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::green);
    playButton.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::red);

    playButton.onClick = [this](){

        const bool isPlaying = playButton.getToggleState();
        playButton.setButtonText(isPlaying ? "Playing" : "Bypassed");
        
    };
    addAndMakeVisible(playButton);


    frequencyLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(frequencyLabel);

    setSize (800, 600);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::black);
    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    //g.drawFittedText ("Gang", getLocalBounds(), juce::Justification::centred, 1);
}

void AudioPluginAudioProcessorEditor::resized()
{
    frequencyLabel.setBounds(getWidth()/2-50, getHeight()/2-120, 100, 20);
    frequencySlider.setBounds(getWidth() / 2 -50 , getHeight()/2 - 100, 100, 200);
    playButton.setBounds(getWidth()/2-50, getHeight()/2+150, 100, 20);
    
}
