#include "PluginProcessor.h"
#include "PluginEditor.h"

GainAudioProcessorEditor::GainAudioProcessorEditor(GainAudioProcessor& p) : AudioProcessorEditor(&p), audioProcessor(p)
{
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    setSize(200, 400);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    addAndMakeVisible(SlBar);
    SlBar.setSliderStyle(juce::Slider::SliderStyle::LinearBarVertical);

    SlBar.setRange(-30.0, 30.0, 0.1);
    SlBar.setColour(juce::Slider::trackColourId, juce::Colours::pink.darker(0.2));
    SlBar.setAlpha(1.0);

    SlBar.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 160, SlBar.getTextBoxHeight());
    SlBar.setTextValueSuffix(" Db");

    SlBar.addListener(this);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    setResizable(true, true);
    setResizeLimits(150, 75, 2000, 2000);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    addAndMakeVisible(ByPass);
    ByPass.setClickingTogglesState(true);
    ByPass.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::pink.darker(0.2));

    ByPass.onClick = [&]() {
        const auto message = ByPass.getToggleState() ? "Bypass is on" : "Bypass is off";

        printf(message);
        ByPass.setButtonText(message);

        const auto colour = ByPass.getToggleState() ? 0 : 1;
        switch (colour) {
        case 1:
            ByPass.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::pink.darker(0.2));

        case 2:
            ByPass.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::black.brighter(0.1));
        }
    };

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

GainAudioProcessorEditor::~GainAudioProcessorEditor()
{
}


void GainAudioProcessorEditor::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colours::black.brighter(0.1));

    g.setColour(juce::Colours::pink.darker(0.2));
    g.setFont(getWidth() / 16);
    g.drawFittedText("Gain Control", getLocalBounds(), juce::Justification::topRight, 1);
    g.drawVerticalLine(getWidth() / 3, 0, getHeight());
    g.drawVerticalLine(0, 0, getHeight());
}

void GainAudioProcessorEditor::resized()
{
    SlBar.setBounds(0, 0, getWidth() / 3, getHeight());
    ByPass.setBounds(getWidth() / 3, 0, getWidth() / 3, getHeight());
}

void GainAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    if (slider == &SlBar)
    {
        audioProcessor.Change = pow(10, SlBar.getValue() / 20);
    }
}