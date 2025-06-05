#include "MidiTrackComponent.h"

MidiTrackComponent::MidiTrackComponent()
{
    addAndMakeVisible(inputConfig);
    addAndMakeVisible(processingConfig);
    addAndMakeVisible(arpSettings);
    addAndMakeVisible(arpAdvanced);
    addAndMakeVisible(outputRouting);

    processingConfig.arpEnabled.onClick = [this]() { updateVisibility(); };
    outputRouting.mode.onChange = [this]() { updateVisibility(); };
    updateVisibility();
}

void MidiTrackComponent::updateVisibility()
{
    const bool arpOn = processingConfig.arpEnabled.getToggleState();
    arpSettings.setVisible(arpOn);
    arpAdvanced.setVisible(arpOn);

    const bool split = outputRouting.mode.getSelectedId() == 2;
    for (int i = 0; i < outputRouting.splitRanges.size(); ++i)
        outputRouting.splitRanges[i]->setVisible(split);

    resized();
}

void MidiTrackComponent::resized()
{
    auto area = getLocalBounds().reduced(5);
    auto lineHeight = 50;

    inputConfig.setBounds(area.removeFromTop(lineHeight));
    processingConfig.setBounds(area.removeFromTop(lineHeight));

    if (processingConfig.arpEnabled.getToggleState())
    {
        arpSettings.setBounds(area.removeFromTop(lineHeight));
        arpAdvanced.setBounds(area.removeFromTop(lineHeight));
    }

    outputRouting.setBounds(area.removeFromTop(lineHeight));
}
