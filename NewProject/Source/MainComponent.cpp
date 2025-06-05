#include "MainComponent.h"

MainComponent::MainComponent()
{
    addAndMakeVisible(addTrackButton);
    addAndMakeVisible(trackViewport);

    trackViewport.setViewedComponent(&trackContainer, false);

    addTrackButton.onClick = [this]() { addNewTrack(); };
    addNewTrack();
    setSize(1000, 600);
}

void MainComponent::addNewTrack()
{
    auto* track = new MidiTrackComponent();
    trackContainer.addAndMakeVisible(track);
    tracks.add(track);
    resized();
}

void MainComponent::resized()
{
    auto area = getLocalBounds().reduced(10);
    addTrackButton.setBounds(area.removeFromBottom(30));
    trackViewport.setBounds(area);

    int y = 0;
    for (auto* track : tracks)
    {
        track->setBounds(0, y, getWidth() - 40, 260);
        y += 270;
    }
    trackContainer.setSize(getWidth() - 40, y);
}
