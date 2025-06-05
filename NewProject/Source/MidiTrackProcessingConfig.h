#pragma once

#include <JuceHeader.h>

class MidiTrackProcessingConfig : public juce::Component
{
public:
    MidiTrackProcessingConfig();
    void resized() override;

    juce::ComboBox priority;
    juce::ComboBox scale;
    juce::ComboBox trackType;
    juce::ToggleButton arpEnabled;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MidiTrackProcessingConfig)
};
