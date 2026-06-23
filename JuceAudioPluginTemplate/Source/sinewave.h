//..


#ifndef SINEWAVE_H
#define SINEWAVE_H
#include <juce_audio_basics/juce_audio_basics.h>
class SineWave{
    
    public:
        
        void prepare (double sampleRate, int numChannels);
        void process (juce::AudioBuffer<float>& buffer);
        
        juce::AudioBuffer<float> ringbuffer;
        int ringBufferWritePos = 0;


        float getAmplitude() { return smoothedAmp.getCurrentValue(); }
        float getFrequency() { return smoothedFreq.getCurrentValue(); }
        
        void setAmplitude(const float newAmplitude) { smoothedAmp.setTargetValue(newAmplitude); }
        void setFrequency(const float newFrequency) { smoothedFreq.setTargetValue(newFrequency); }
                                             
    
    private:
        
        float amplitude = 0.2f;
        float currentSampleRate = 0.0f;
        std::vector<float> phases;
        juce::SmoothedValue<float , juce::ValueSmoothingTypes::Multiplicative> smoothedFreq;
        juce::SmoothedValue<float , juce::ValueSmoothingTypes::Linear> smoothedAmp;


};


#endif //SINEWAVE_H