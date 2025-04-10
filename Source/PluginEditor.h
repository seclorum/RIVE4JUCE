#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "RiveRenderer.h"

class RIVE4JUCEAudioProcessorEditor : public juce::AudioProcessorEditor {
public:
    explicit RIVE4JUCEAudioProcessorEditor(RIVE4JUCEAudioProcessor&);
    ~RIVE4JUCEAudioProcessorEditor() override;

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    RIVE4JUCEAudioProcessor& audioProcessor;
    RiveRenderer riveRenderer;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RIVE4JUCEAudioProcessorEditor)
};
