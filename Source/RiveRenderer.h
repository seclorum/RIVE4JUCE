#pragma once

#include <JuceHeader.h>
#include <rive/factory.hpp>
#include <rive/file.hpp>

class RiveRenderer : public juce::Component {
public:
    RiveRenderer();
    ~RiveRenderer() override;

    void loadRiveFile(const juce::String& filePath);
    void paint(juce::Graphics&) override;
    void resized() override;

private:
    std::unique_ptr<rive::File> riveFile;
    std::unique_ptr<rive::Artboard> artboard;
    std::unique_ptr<rive::Renderer> renderer;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RiveRenderer)
};
