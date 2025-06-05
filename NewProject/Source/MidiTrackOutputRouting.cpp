#include "MidiTrackOutputRouting.h"

MidiTrackOutputRouting::MidiTrackOutputRouting()
{
    addAndMakeVisible(outputCount);
    outputCount.setRange(1, 8, 1);
    outputCount.setValue(2);
    outputCount.onValueChange = [this]() { updatePairVisibility(); };

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

    // Ensure widgets visibility matches the initial outputCount
    updatePairVisibility();
}

void MidiTrackOutputRouting::resized()
{
    auto area = getLocalBounds().reduced(5);
    outputCount.setBounds(area.removeFromLeft(100));
    mode.setBounds(area.removeFromLeft(140));

    const int count = static_cast<int>(outputCount.getValue());
    for (int i = 0; i < count; ++i)
    {
        outputChannels[i]->setBounds(area.removeFromLeft(60));
        splitRanges[i]->setBounds(area.removeFromLeft(80));
    }
}

void MidiTrackOutputRouting::updatePairVisibility()
{
    const int count = static_cast<int>(outputCount.getValue());

    for (int i = 0; i < outputChannels.size(); ++i)
    {
        const bool visible = i < count;
        outputChannels[i]->setVisible(visible);
        splitRanges[i]->setVisible(visible);
    }

    // Adjust component size to only occupy the space needed for visible pairs
    const int width = 240 + count * 140; // 100 + 140 + count*(60+80)
    setSize(width, getHeight());
    resized();
}
