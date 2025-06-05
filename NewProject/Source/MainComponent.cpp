#include "MainComponent.h"

MainComponent::MainComponent()
{
    addAndMakeVisible(addTrackButton);
    addAndMakeVisible(trackViewport);

    trackContainer = std::make_unique<juce::Component>();
    trackViewport.setViewedComponent(trackContainer.get(), false);

    addTrackButton.onClick = [this]() { addNewTrack(); };
    addNewTrack();
    setSize(1000, 600);
}

MainComponent::~MainComponent() = default;

void MainComponent::paint(juce::Graphics& g)
{
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
}

void MainComponent::addNewTrack()
{
    auto* track = new MidiTrackComponent();
    trackContainer->addAndMakeVisible(track);
    midiTracks.add(track);
    resized();
}

void MainComponent::resized()
{
    auto area = getLocalBounds().reduced(10);
    addTrackButton.setBounds(area.removeFromBottom(30));
    trackViewport.setBounds(area);

    int y = 0;
    for (auto* track : midiTracks)
    {
        track->setBounds(0, y, getWidth() - 40, 260);
        y += 270;
    }
    trackContainer->setSize(getWidth() - 40, y);
}
