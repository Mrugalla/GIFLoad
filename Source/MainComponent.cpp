#include "MainComponent.h"

MainComponent::MainComponent() :
    jif(BinaryData::drinkLove_gif, BinaryData::drinkLove_gifSize)
{
    /* things to copy into the jif constructor:
     
    BinaryData::dance_gif, BinaryData::dance_gifSize
    BinaryData::drinkLove_gif, BinaryData::drinkLove_gifSize
    BinaryData::installationFailed_gif, BinaryData::installationFailed_gifSize

    */
    
    setOpaque(true);
    setSize(600, 400);
    startTimerHz(8);
}

void MainComponent::paint (juce::Graphics& g) { jif.paint(g, getLocalBounds().toFloat()); }
void MainComponent::timerCallback() { ++jif; repaint(); }
void MainComponent::resized() { jif.resetAnimation(); }