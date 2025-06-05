#pragma once

#include <JuceHeader.h>
#include "MidiTrackComponent.h"

//==============================================================================
class MainComponent : public juce::Component
{
public:
    MainComponent();
    ~MainComponent() override;

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    juce::TextButton addTrackButton { "Ajouter une piste" };

    // Important : trackContainer doit être détruit **après** les composants qui l’utilisent (comme trackViewport)
    std::unique_ptr<juce::Component> trackContainer;

    juce::Viewport trackViewport;

    juce::OwnedArray<MidiTrackComponent> midiTracks;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
