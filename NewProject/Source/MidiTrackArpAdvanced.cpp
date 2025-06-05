#include "MidiTrackArpAdvanced.h"

MidiTrackArpAdvanced::MidiTrackArpAdvanced()
{
    addAndMakeVisible(direction);
    direction.addItemList({ "Up", "Down", "Converge", "Diverge", "As Played", "Random" }, 1);
    direction.setSelectedId(1);

    addAndMakeVisible(accent);
    accent.setButtonText("Accent");

    addAndMakeVisible(accentPattern);
    accentPattern.setText(juce::String("x--x--"), juce::dontSendNotification);  // ✅ sécurisé

    addAndMakeVisible(groove);
    groove.setText(juce::String("Swing"), juce::dontSendNotification);         // ✅ sécurisé

    addAndMakeVisible(groovePattern);
    groovePattern.setText(juce::String("10100101"), juce::dontSendNotification); // ✅ sécurisé

    addAndMakeVisible(variation);
    variation.setRange(0, 100);
    variation.setValue(10);
}

void MidiTrackArpAdvanced::resized()
{
    auto area = getLocalBounds().reduced(5);
    direction.setBounds(area.removeFromLeft(120));
    accent.setBounds(area.removeFromLeft(80));
    accentPattern.setBounds(area.removeFromLeft(100));
    groove.setBounds(area.removeFromLeft(100));
    groovePattern.setBounds(area.removeFromLeft(100));
    variation.setBounds(area);
}
