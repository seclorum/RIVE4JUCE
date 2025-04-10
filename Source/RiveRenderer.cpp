#include "RiveRenderer.h"

RiveRenderer::RiveRenderer() {}

RiveRenderer::~RiveRenderer() {}

void RiveRenderer::loadRiveFile(const juce::String& filePath) {
    juce::File file(filePath);
    if (file.existsAsFile()) {
        auto fileData = file.loadFileAsData();
        riveFile = rive::File::import(fileData.getData(), fileData.getSize(), nullptr);
        if (riveFile) {
            artboard = riveFile->artboardDefault();
        }
    }
}

void RiveRenderer::paint(juce::Graphics& g) {
    if (artboard) {
        // Basic Rive rendering setup
        g.addTransform(juce::AffineTransform::scale(getWidth() / artboard->width(),
                                                  getHeight() / artboard->height()));
        renderer = std::make_unique<rive::JuceRenderer>(&g);
        renderer->save();
        artboard->draw(renderer.get());
        renderer->restore();
    }
}

void RiveRenderer::resized() {}
