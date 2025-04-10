#include "PluginEditor.h"

RIVE4JUCEAudioProcessorEditor::RIVE4JUCEAudioProcessorEditor(RIVE4JUCEAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p), riveRenderer() {
    setSize(400, 300);
    riveRenderer.loadRiveFile(juce::File::getCurrentWorkingDirectory()
        .getChildFile("Assets")
        .getChildFile("PulseCircle.riv")
        .getFullPathName());
}

RIVE4JUCEAudioProcessorEditor::~RIVE4JUCEAudioProcessorEditor() {}

void RIVE4JUCEAudioProcessorEditor::paint(juce::Graphics& g) {
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
    riveRenderer.draw(g);
}

void RIVE4JUCEAudioProcessorEditor::resized() {
    riveRenderer.setBounds(getLocalBounds());
}
