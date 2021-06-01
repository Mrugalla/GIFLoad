#include "MainComponent.h"

MainComponent::MainComponent() :
    jif()
{
    // things to copy into the memoryInputStream:
    //BinaryData::dance_gif, BinaryData::dance_gifSize, true);
    //BinaryData::drinkLove_gif, BinaryData::drinkLove_gifSize, true);
    //BinaryData::installationFailed_gif, BinaryData::installationFailed_gifSize, true);
    juce::MemoryInputStream memoryInputStream(BinaryData::dance_gif, BinaryData::dance_gifSize, true);
    GIFImageFormat imageFormat;
    if(imageFormat.readHeader(memoryInputStream))
        while (!memoryInputStream.isExhausted()) {
            const auto img = imageFormat.decodeImage();
            if (img.image.isValid())
                jif.addImg(img);
        }
    setOpaque(true);
    setSize(600, 400);
    startTimerHz(8);
}

void MainComponent::paint (juce::Graphics& g) { jif.paint(g, getLocalBounds().toFloat()); }
void MainComponent::timerCallback() { ++jif; repaint(); }
void MainComponent::resized() { jif.resetAnimation(); }