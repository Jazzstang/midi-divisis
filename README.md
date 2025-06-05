# MIDI Divisis

This repository contains a JUCE-based MIDI utility project.

## Building

The project is maintained using JUCE. Open `NewProject/NewProject.jucer` with the Projucer application and generate an Xcode project. Once generated, open the `.xcodeproj` or `.xcworkspace` file in Xcode to build and run.

## "Failed to initialize logging system" message

When launching the app in Xcode you might encounter a console message similar to:

```
Failed to initialize logging system...
```

Xcode sometimes fails to attach its logging subsystem when log streaming is disabled. This does not prevent the app from running, but it hides runtime logs.

### Enabling log streaming in Xcode

1. In Xcode, open the **Scheme** selector next to the Stop button and choose **Edit Scheme…**.
2. Select the **Run** action in the sidebar.
3. Expand the **Arguments** pane.
4. In the **Environment Variables** section, add `IDEPreferLogStreaming` with the value `YES` and ensure it is checked.
5. Close the dialog and run the app again.

Enabling this environment variable allows Xcode to stream logs properly and avoids the warning.
