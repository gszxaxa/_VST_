//..


#ifndef SINEWAVE_H
#define SINEWAVE_H
#include <juce_audio_basics/juce_audio_basics.h>
class SineWave{
    
    public:
        
        void prepare (double sampleRate, int numChannels);
        void process (juce::AudioBuffer<float>& buffer);
        
        float getAmplitude() const { return amplitude; }
        float getFrequency() { return smoothedFreq.getNextValue(); }
        void setAmplitude(const float newAmplitude) { amplitude = newAmplitude; }
        void setFrequency(const float newFrequency) { smoothedFreq.setTargetValue(newFrequency); }
                                             
    
    private:
        
        float amplitude = 0.1f;
        float currentSampleRate = 0.0f;
        std::vector<float> phases;
        juce::SmoothedValue<float , juce::ValueSmoothingTypes::Multiplicative> smoothedFreq;


};


#endif //SINEWAVE_H