#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "OscilloscopeComponent.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p), freqSliderAttachment(processorRef.getState(), "freqhz", frequencySlider), playButtonAttachment(processorRef.getState(), "play", playButton), volumeAttachment(processorRef.getState(), "volume", volumeSlider)
{
    juce::ignoreUnused (processorRef);
    //addAndMakeVisible(square);

    frequencySlider.setSliderStyle (juce::Slider::SliderStyle::RotaryVerticalDrag);
    frequencySlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 50);
    addAndMakeVisible(frequencySlider);
    
    playButton.setButtonText("Playing");
    playButton.setToggleState(true, juce::NotificationType::dontSendNotification);
    playButton.setClickingTogglesState(true);
    
    playButton.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::black);
    playButton.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::grey);


    volumeSlider.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    volumeSlider.setTextBoxStyle(juce::Slider::NoTextBox,false,300,100);

    addAndMakeVisible(volumeSlider);

    addAndMakeVisible(oscilloscope);


    playButton.onClick = [this](){

        const bool isPlaying = playButton.getToggleState();
        playButton.setButtonText(isPlaying ? "Playing" : "Bypassed");
        
    };
    addAndMakeVisible(playButton);


    frequencyLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(frequencyLabel);

    setSize (400, 700);
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
    frequencyLabel.setBounds(getWidth() / 2 - 50, getHeight()/2 - 120, 100, 20);
    frequencySlider.setBounds(getWidth() / 2 - 50 , getHeight()/2 - 100, 100, 200);
    playButton.setBounds(getWidth() / 2 - 50, getHeight()/2 + 150, 100, 20);
    
    volumeSlider.setBounds(getWidth() / 2 - 150, getHeight()/2 - 100, 100, 175);

    oscilloscope.setBounds(0,0,getWidth(),getHeight()/2-150);
    
}
