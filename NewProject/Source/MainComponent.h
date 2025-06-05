#pragma once

#include <JuceHeader.h>
#include "MidiTrackComponent.h"

class MainComponent : public juce::Component
{
public:
    MainComponent();
    void resized() override;

private:
    juce::OwnedArray<MidiTrackComponent> tracks;
    juce::TextButton addTrackButton { "+" };
    juce::Viewport trackViewport;
    juce::Component trackContainer;

    void addNewTrack();

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
