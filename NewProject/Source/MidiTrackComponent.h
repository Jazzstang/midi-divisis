#pragma once

#include <JuceHeader.h>
#include "MidiTrackInputConfig.h"
#include "MidiTrackProcessingConfig.h"
#include "MidiTrackArpSettings.h"
#include "MidiTrackArpAdvanced.h"
#include "MidiTrackOutputRouting.h"

class MidiTrackComponent : public juce::Component
{
public:
    MidiTrackComponent();
    void resized() override;

private:
    MidiTrackInputConfig inputConfig;
    MidiTrackProcessingConfig processingConfig;
    MidiTrackArpSettings arpSettings;
    MidiTrackArpAdvanced arpAdvanced;
    MidiTrackOutputRouting outputRouting;

    void updateVisibility();

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MidiTrackComponent)
};
