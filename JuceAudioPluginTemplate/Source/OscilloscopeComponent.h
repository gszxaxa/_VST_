#pragma once
#include "sinewave.h"

class OscilloscopeComponent : public juce::Component, public juce::Timer
{
public:
    OscilloscopeComponent(SineWave& sineWaveRef) : sinewave(sineWaveRef) 
    {
        startTimerHz(30);
    }
    
    void timerCallback() override { repaint(); }

    void paint(juce::Graphics& g) override
    {
        //g.fillAll(juce::Colours::orange);
        g.setColour(juce::Colours::white);

        juce::Path wave;
        auto width = getWidth();
        auto height = getHeight();

        for(int i = 0; i < sinewave.ringbuffer.getNumSamples(); ++i)
        {
            float sample = sinewave.ringbuffer.getSample(0, i);
            float x = juce::jmap((float)i, 0.0f, (float)sinewave.ringbuffer.getNumSamples(), 0.0f, (float)width);
            float y = juce::jmap(sample, -1.0f, 1.0f, (float)height, 0.0f);

            if(i == 0) wave.startNewSubPath(x, y);
            else wave.lineTo(x, y);
        }
        g.strokePath(wave, juce::PathStrokeType(1.0f));
    }

private:
    SineWave& sinewave;
};