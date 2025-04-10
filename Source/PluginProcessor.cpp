#include "PluginProcessor.h"
#include "PluginEditor.h"

RIVE4JUCEAudioProcessor::RIVE4JUCEAudioProcessor()
    : AudioProcessor(BusesProperties().withInput("Input", juce::AudioChannelSet::stereo())
                                     .withOutput("Output", juce::AudioChannelSet::stereo())) {}

RIVE4JUCEAudioProcessor::~RIVE4JUCEAudioProcessor() {}

void RIVE4JUCEAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock) {}
void RIVE4JUCEAudioProcessor::releaseResources() {}

void RIVE4JUCEAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages) {
    buffer.clear();
}

juce::AudioProcessorEditor* RIVE4JUCEAudioProcessor::createEditor() {
    return new RIVE4JUCEAudioProcessorEditor(*this);
}


// This creates new instances of the plugin..
AudioProcessor *JUCE_CALLTYPE createPluginFilter() {
    return new RIVE4JUCEAudioProcessor();
}



