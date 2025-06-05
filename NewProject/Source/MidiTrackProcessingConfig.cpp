#include "MidiTrackProcessingConfig.h"

MidiTrackProcessingConfig::MidiTrackProcessingConfig()
{
    addAndMakeVisible(priority);
    priority.addItemList({ "Last", "Lowest", "Highest" }, 1);
    priority.setSelectedId(1);

    addAndMakeVisible(scale);
    scale.addItemList({ "None", "Major", "Minor", "Pentatonic" }, 1);
    scale.setSelectedId(1);

    addAndMakeVisible(trackType);
    trackType.addItemList({ "Free", "Master", "Slaved" }, 1);
    trackType.setSelectedId(1);

    addAndMakeVisible(arpEnabled);
    arpEnabled.setButtonText("Enable Arp");
}

void MidiTrackProcessingConfig::resized()
{
    auto area = getLocalBounds().reduced(5);
    priority.setBounds(area.removeFromLeft(120));
    scale.setBounds(area.removeFromLeft(120));
    trackType.setBounds(area.removeFromLeft(120));
    arpEnabled.setBounds(area);
}
