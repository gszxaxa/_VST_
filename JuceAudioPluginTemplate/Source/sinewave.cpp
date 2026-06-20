#include "sinewave.h"

void SineWave::prepare(const double sampleRate, const int numChannels){

    currentSampleRate = static_cast<float>(sampleRate);
    phases.resize(numChannels, 0.0f);
    smoothedFreq.reset(sampleRate, 0.05f);
    smoothedFreq.setCurrentAndTargetValue(getFrequency());
}

void SineWave::process (juce::AudioBuffer<float>& buffer){

    if (phases.size() != buffer.getNumChannels()){
        return;
    }
    
    
    for(int channel = 0; channel < buffer.getNumChannels(); ++channel){
       
        auto* output = buffer.getWritePointer(channel);
        auto& phase = phases[channel];


        for(int sample = 0; sample< buffer.getNumSamples(); ++sample){

            float frequency = smoothedFreq.getNextValue();

            const float phaseInc = ((2.0f*juce::MathConstants<float>::pi * frequency) / currentSampleRate);

            output[sample] = amplitude * std::sinf(phase);
            
            phase += phaseInc;

            if (phase >= 2.0f * juce::MathConstants<float>::pi){
                
                phase -= 2.0f * juce::MathConstants<float>::pi;
            }

       } 
    }
}