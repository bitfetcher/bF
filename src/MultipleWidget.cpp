
#include "Multiple.hpp"

using namespace bF;


MultWidget::MultWidget() {
    Multiple *module = new Multiple();

    setModule(module);
    box.size = Vec(MODULE_WIDTH, RACK_GRID_HEIGHT);

    {
        SVGPanel *panel = new SVGPanel();
        panel->box.size = box.size;
        panel->setBackground(SVG::load(assetPlugin(plugin, "res/Multiple.svg")));
        addChild(panel);
    }

    addChild(createScrew<bFScrew>(Vec(RACK_GRID_WIDTH, 0)));

    addChild(createScrew<bFScrew>(Vec(RACK_GRID_WIDTH,
                                          RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

    addInput(createInput<inPort>(Vec(RACK_GRID_WIDTH / 3 - 2,
                                         RACK_GRID_HEIGHT - 14.5f*PORT_SPACING), module,
                                     Multiple::SOURCE_INPUT));

    addOutput(createOutput<outPort>(Vec(RACK_GRID_WIDTH / 3 - 2,
                                           RACK_GRID_HEIGHT - int(12.5f*PORT_SPACING)), module,
                                       Multiple::PORT1_OUTPUT));
    addOutput(createOutput<outPort>(Vec(RACK_GRID_WIDTH / 3 - 2,
                                           RACK_GRID_HEIGHT - int(11*PORT_SPACING)), module,
                                       Multiple::PORT2_OUTPUT));
    addOutput(createOutput<outPort>(Vec(RACK_GRID_WIDTH / 3 - 2,
                                           RACK_GRID_HEIGHT - int(9.5f*PORT_SPACING)), module,
                                       Multiple::PORT3_OUTPUT));
    addOutput(createOutput<outPort>(Vec(RACK_GRID_WIDTH / 3 - 2,
                                           RACK_GRID_HEIGHT - int(8*PORT_SPACING)), module,
                                       Multiple::PORT4_OUTPUT));
    addOutput(createOutput<outPort>(Vec(RACK_GRID_WIDTH / 3 - 2,
                                           RACK_GRID_HEIGHT - int(6.5f*PORT_SPACING)), module,
                                       Multiple::PORT5_OUTPUT));
    addOutput(createOutput<outPort>(Vec(RACK_GRID_WIDTH / 3 - 2,
                                           RACK_GRID_HEIGHT - int(5*PORT_SPACING)), module,
                                       Multiple::PORT6_OUTPUT));
    addOutput(createOutput<outPort>(Vec(RACK_GRID_WIDTH / 3 - 2,
                                           RACK_GRID_HEIGHT - int(3.5f*PORT_SPACING)), module,
                                       Multiple::PORT7_OUTPUT));
    addOutput(createOutput<outPort>(Vec(RACK_GRID_WIDTH / 3 - 2,
                                           RACK_GRID_HEIGHT - 2*PORT_SPACING), module,
                                       Multiple::PORT8_OUTPUT));

}
