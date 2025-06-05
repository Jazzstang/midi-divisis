#include "MidiTrackArpSettings.h"

MidiTrackArpSettings::MidiTrackArpSettings()
{
    addAndMakeVisible(hold);
    hold.setButtonText("Hold");

    addAndMakeVisible(syncMode);
    syncMode.addItemList({ "Sync", "Free" }, 1);
    syncMode.setSelectedId(1);

    addAndMakeVisible(division);
    division.setRange(1, 16, 1);
    division.setValue(4);

    addAndMakeVisible(bpm);
    bpm.setRange(30, 300, 1);
    bpm.setValue(120);

    addAndMakeVisible(shuffle);
    shuffle.setRange(0, 100);
    shuffle.setValue(20);

    addAndMakeVisible(gate);
    gate.setRange(0, 100);
    gate.setValue(75);

    addAndMakeVisible(velocity);
    velocity.setRange(1, 127);
    velocity.setValue(100);
}

void MidiTrackArpSettings::resized()
{
    auto area = getLocalBounds().reduced(5);
    hold.setBounds(area.removeFromLeft(60));
    syncMode.setBounds(area.removeFromLeft(80));
    division.setBounds(area.removeFromLeft(80));
    bpm.setBounds(area.removeFromLeft(80));
    shuffle.setBounds(area.removeFromLeft(80));
    gate.setBounds(area.removeFromLeft(80));
    velocity.setBounds(area);
}
