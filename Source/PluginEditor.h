#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class GainAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    GainAudioProcessorEditor (GainAudioProcessor&);
    ~GainAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    juce::Slider SlBar;

    GainAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GainAudioProcessorEditor)
};
