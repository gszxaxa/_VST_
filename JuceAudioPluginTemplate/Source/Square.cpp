#include "Square.h"


void Square::paint (juce::Graphics& g){
    
    g.fillAll (juce::Colours::orange);
    g.setColour (juce::Colours::white);
    g.setFont (11.0f);
    g.drawFittedText ("kock", getLocalBounds(), juce::Justification::centred, 1);
}

void Square::resized(){

}