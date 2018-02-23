#include "bF.hpp"

#define MODULE_WIDTH 2 * RACK_GRID_WIDTH
#define PORT_SPACING 25

struct Sum : Module {
    enum ParamIds {
        NUM_PARAMS
    };
    enum InputIds {
		PORT1_INPUT,
        PORT2_INPUT,
        PORT3_INPUT,
        PORT4_INPUT,
        PORT5_INPUT,
        PORT6_INPUT,
        PORT7_INPUT,
        PORT8_INPUT,
        NUM_INPUTS
    };
    enum OutputIds {
		SUM_OUTPUT,
        NUM_OUTPUTS
    };


    Sum() : Module(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS) {}

    void step() override;

    // For more advanced Module features, read Rack's engine.hpp header file
    // - toJson, fromJson: serialization of internal data
    // - onSampleRateChange: event triggered by a change of sample rate
    // - onReset, onRandomize, onCreate, onDelete: implements special behavior
    // when user clicks these from the context menu
};
