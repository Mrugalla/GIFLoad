#include "MainComponent.h"

MainComponent::MainComponent() :
    images(),
    rIdx(-1)
{
    //BinaryData::dance_gif, BinaryData::dance_gifSize, true);
    //BinaryData::drinkLove_gif, BinaryData::drinkLove_gifSize, true);
    //BinaryData::installationFailed_gif, BinaryData::installationFailed_gifSize, true);
    juce::MemoryInputStream memoryInputStream(BinaryData::installationFailed_gif, BinaryData::installationFailed_gifSize, true);
    GIFImageFormat imageFormat;
    if(imageFormat.readHeader(memoryInputStream))
        while (!memoryInputStream.isExhausted()) {
            const auto img = imageFormat.decodeImage();
            if (img.image.isValid())
                images.push_back(img);
        }

    setOpaque(true);
    setSize(600, 400);
    startTimerHz(8);
}

void MainComponent::paint (juce::Graphics& g) {
    if (rIdx >= images.size()) {
        rIdx = 0;
        g.fillAll(juce::Colours::white);
    }
    images[rIdx].paint(g, getLocalBounds());
}
void MainComponent::timerCallback() {
    ++rIdx;
    repaint();
}