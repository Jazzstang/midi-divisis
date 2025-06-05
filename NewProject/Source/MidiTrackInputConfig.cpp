#include "MidiTrackInputConfig.h"

MidiTrackInputConfig::MidiTrackInputConfig()
{
    addAndMakeVisible(portName);
    portName.setText("Track");

    addAndMakeVisible(channel);
    channel.addItem("All", 17); // ID = 17 pour éviter 0
    for (int i = 1; i <= 16; ++i)
        channel.addItem("Ch " + juce::String(i), i);
    channel.setSelectedId(17); // sélectionne "All"

    addAndMakeVisible(voiceCount);
    voiceCount.setRange(1, 8, 1);
    voiceCount.setValue(4);
}

void MidiTrackInputConfig::resized()
{
    auto area = getLocalBounds().reduced(5);
    portName.setBounds(area.removeFromLeft(150));
    channel.setBounds(area.removeFromLeft(100));
    voiceCount.setBounds(area);
}
