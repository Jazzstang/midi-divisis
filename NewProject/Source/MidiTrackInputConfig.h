#pragma once

#include <JuceHeader.h>

class MidiTrackInputConfig : public juce::Component
{
public:
    MidiTrackInputConfig();
    void resized() override;

    juce::TextEditor portName;
    juce::ComboBox channel;
    juce::Slider voiceCount;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MidiTrackInputConfig)
};
