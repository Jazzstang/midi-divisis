#pragma once

#include <JuceHeader.h>

class MidiTrackOutputRouting : public juce::Component
{
public:
    MidiTrackOutputRouting();
    void resized() override;

    /** Updates visibility of output channel widgets based on the selected
        output count and resizes the component accordingly. */
    void updatePairVisibility();

    juce::Slider outputCount;
    juce::ComboBox mode;
    juce::OwnedArray<juce::ComboBox> outputChannels;
    juce::OwnedArray<juce::TextEditor> splitRanges;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MidiTrackOutputRouting)
};
