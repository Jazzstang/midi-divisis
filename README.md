# MIDI Divisis

This repository contains a JUCE-based MIDI processing project.

## IDEPreferLogStreaming warning on macOS

When invoking `xcodebuild` on macOS you may see:

```
warning: IDEPreferLogStreaming is not set, falling back to file loggers
```

The build will still succeed, so this message can be ignored. If you would like to silence it and see logs streamed as they are produced, set the environment variable:

```sh
export IDEPreferLogStreaming=YES
```

before running the build.
