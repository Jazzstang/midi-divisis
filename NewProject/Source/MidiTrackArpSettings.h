#pragma once

#include <JuceHeader.h>

class MidiTrackArpSettings : public juce::Component
{
public:
    MidiTrackArpSettings();
    void resized() override;

    juce::ToggleButton hold;
    juce::ComboBox syncMode;
    juce::Slider division;
    juce::Slider bpm;
    juce::Slider shuffle;
    juce::Slider gate;
    juce::Slider velocity;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MidiTrackArpSettings)
};
