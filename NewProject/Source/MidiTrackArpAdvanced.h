#pragma once

#include <JuceHeader.h>

class MidiTrackArpAdvanced : public juce::Component
{
public:
    MidiTrackArpAdvanced();
    void resized() override;

    juce::ComboBox direction;
    juce::ToggleButton accent;
    juce::TextEditor accentPattern;
    juce::TextEditor groove;
    juce::TextEditor groovePattern;
    juce::Slider variation;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MidiTrackArpAdvanced)
};
