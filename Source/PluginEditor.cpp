#include "PluginProcessor.h"
#include "PluginEditor.h"

GainAudioProcessorEditor::GainAudioProcessorEditor (GainAudioProcessor& p) : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (200, 200);
    
    addAndMakeVisible(SlBar);
    SlBar.setSliderStyle(juce::Slider::SliderStyle::LinearBarVertical);
    SlBar.setRange(-60.0, 60.0);

    SlBar.addListener(this);
}

GainAudioProcessorEditor::~GainAudioProcessorEditor()
{
}


void GainAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::transparentWhite);

    //g.setColour (juce::Colours::pink);
    //g.setFont (15.0f);
    //g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void GainAudioProcessorEditor::resized()
{
    SlBar.setBounds(getLocalBounds());
}

void GainAudioProcessorEditor::sliderValueChanged(juce::Slider* slider) 
{
    if (slider == &SlBar) 
    {
        audioProcessor.Change = pow(10, SlBar.getValue()/20);
    }
}