#pragma once

#include <JuceHeader.h>
#include "MidiTrackComponent.h"

class MainComponent : public juce::Component
{
public:
    MainComponent();
    void resized() override;

private:
    // Declare members in an order that ensures safe destruction. The container
    // must outlive its dependents to avoid dangling pointers when the component
    // hierarchy is torn down.
    juce::Component trackContainer;                 // owns track components
    juce::Viewport trackViewport;                   // references trackContainer
    juce::OwnedArray<MidiTrackComponent> tracks;    // child track components
    juce::TextButton addTrackButton { "+" };

    void addNewTrack();

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
