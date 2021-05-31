#include "MainComponent.h"

MainComponent::MainComponent() :
    images(),
    rIdx(-1)
{
    juce::MemoryInputStream memoryInputStream(BinaryData::dance_gif, BinaryData::dance_gifSize, true);
    GIFImageFormat imageFormat;
    if(imageFormat.readHeader(memoryInputStream))
        while (!memoryInputStream.isExhausted()) {
            auto img = imageFormat.decodeImage(memoryInputStream);
            if (img.isValid())
                images.push_back(img.createCopy());
        }

    setOpaque(true);
    setSize (600, 400);
    startTimerHz(8);
}

void MainComponent::paint (juce::Graphics& g) {
    ++rIdx;
    if (rIdx >= images.size())
        rIdx = 0;
    g.fillAll(juce::Colours::white);
    g.drawImage(images[rIdx], getLocalBounds().toFloat());
}
void MainComponent::timerCallback() { repaint(); }