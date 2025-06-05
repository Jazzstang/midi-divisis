#include "MidiTrackOutputRouting.h"

MidiTrackOutputRouting::MidiTrackOutputRouting()
{
    addAndMakeVisible(outputCount);
    outputCount.setRange(1, 8, 1);
    outputCount.setValue(2);

    addAndMakeVisible(mode);
    mode.addItemList({ "Duplicated", "Split", "Round Robin" }, 1);
    mode.setSelectedId(1);

    for (int i = 0; i < 8; ++i)
    {
        auto* ch = new juce::ComboBox();
        for (int c = 1; c <= 16; ++c)
            ch->addItem("Ch " + juce::String(c), c);
        ch->setSelectedId(1);
        outputChannels.add(ch);
        addAndMakeVisible(ch);

        auto* range = new juce::TextEditor();
        range->setText(juce::String("C1–C3"), juce::dontSendNotification);  // ✅ sécurisé
        splitRanges.add(range);
        addAndMakeVisible(range);
    }
}

void MidiTrackOutputRouting::resized()
{
    auto area = getLocalBounds().reduced(5);
    outputCount.setBounds(area.removeFromLeft(100));
    mode.setBounds(area.removeFromLeft(140));

    for (int i = 0; i < outputChannels.size(); ++i)
    {
        outputChannels[i]->setBounds(area.removeFromLeft(60));
        splitRanges[i]->setBounds(area.removeFromLeft(80));
    }
}
