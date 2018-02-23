#include "bF.hpp"

#define MODULE_WIDTH 5 * RACK_GRID_WIDTH

struct Quadrature : Module {
    enum ParamIds {
        PITCH_PARAM,
        CV2_POLARIZER_PARAM,
        RANGE_PARAM,
        NUM_PARAMS
    };
    enum InputIds {
        PITCH_INPUT,
        CV2_POLARIZER_INPUT,
        NUM_INPUTS
    };
    enum OutputIds {
        SINE_OUTPUT,
        COSINE_OUTPUT,
        NOT_SINE_OUTPUT,
        NOT_COSINE_OUTPUT,
        NUM_OUTPUTS
    };
    enum LightIds {
        POS_LIGHT,
        NEG_LIGHT,
        NUM_LIGHTS
    };

    float phase = 0.0;
    float blinkPhase = 0.0;
	float sine = 0.0f;
    float cosine = 1.0f;
    float notsine = -sine;
    float notcosine = -cosine;
	float deltaTime;
	float pitch, freq;

    enum RANGE_VALUE {
        LOW,
        MEDIUM,
        HIGH
    };

    RANGE_VALUE range = LOW;

    Quadrature() : Module(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS) {
    }
    void step() override;

    // For more advanced Module features, read Rack's engine.hpp header file
    // - toJson, fromJson: serialization of internal data
    // - onSampleRateChange: event triggered by a change of sample rate
    // - onReset, onRandomize, onCreate, onDelete: implements special behavior when user clicks these from the context menu
};
