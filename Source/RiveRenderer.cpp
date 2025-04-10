#include "RiveRenderer.h"

RiveRenderer::RiveRenderer() {}

RiveRenderer::~RiveRenderer() {}

void RiveRenderer::loadRiveFile(const juce::String& filePath) {
#if 0 // !J! TODO: This
    juce::File file(filePath);
    if (file.existsAsFile()) {
        auto fileData = file.loadFileAsData();
        riveFile = rive::File::import(fileData.getData(), fileData.getSize(), nullptr);
        if (riveFile) {
            artboard = riveFile->artboardDefault();
        }
    }
#endif

}

void RiveRenderer::paint(juce::Graphics& g) {
    if (artboard) {
#if 0 // !J! TODO: This
        // Basic Rive rendering setup
        g.addTransform(juce::AffineTransform::scale(getWidth() / artboard->width(),
                                                  getHeight() / artboard->height()));
        renderer = std::make_unique<rive::JuceRenderer>(&g);
        renderer->save();
        artboard->draw(renderer.get());
        renderer->restore();
#endif
    }
}

void RiveRenderer::resized() {}
