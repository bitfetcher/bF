#include "bF.hpp"


#define MODULE_WIDTH 4 * RACK_GRID_WIDTH

struct Oscillator : Module {
    enum ParamIds {
        PITCH_PARAM,
        NUM_PARAMS
    };
    enum InputIds {
        PITCH_INPUT,
        NUM_INPUTS
    };
    enum OutputIds {
        SINE_OUTPUT,
        NUM_OUTPUTS
    };
    enum LightIds {
        BLINK_LIGHT,
        NUM_LIGHTS
    };

    float phase	     = 0.0f;
    float blinkPhase = 0.0f;

    Oscillator() : Module(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS) {}

    void step() override;

    // For more advanced Module features, read Rack's engine.hpp header file
    // - toJson, fromJson: serialization of internal data
    // - onSampleRateChange: event triggered by a change of sample rate
    // - onReset, onRandomize, onCreate, onDelete: implements special behavior
    // when user clicks these from the context menu
};
