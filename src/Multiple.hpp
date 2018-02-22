#include "bF.hpp"

#define MODULE_WIDTH 3 * RACK_GRID_WIDTH
#define PORT_SPACING 25

struct Multiple : Module {
    enum ParamIds {
        NUM_PARAMS
    };
    enum InputIds {
        SOURCE_INPUT,
        NUM_INPUTS
    };
    enum OutputIds {
        PORT1_OUTPUT,
        PORT2_OUTPUT,
        PORT3_OUTPUT,
        PORT4_OUTPUT,
        PORT5_OUTPUT,
        PORT6_OUTPUT,
        PORT7_OUTPUT,
        PORT8_OUTPUT,
        NUM_OUTPUTS
    };


    Multiple() : Module(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS) {}

    void step() override;

    // For more advanced Module features, read Rack's engine.hpp header file
    // - toJson, fromJson: serialization of internal data
    // - onSampleRateChange: event triggered by a change of sample rate
    // - onReset, onRandomize, onCreate, onDelete: implements special behavior
    // when user clicks these from the context menu
};
