
#include "Sum.hpp"

using namespace bF;


SumWidget::SumWidget() {
    Sum *module = new Sum();

    setModule(module);
    box.size = Vec(MODULE_WIDTH, RACK_GRID_HEIGHT);

    {
        SVGPanel *panel = new SVGPanel();
        panel->box.size = box.size;
        panel->setBackground(SVG::load(assetPlugin(plugin, "res/Sum.svg")));
        addChild(panel);
    }

    addChild(createScrew<bFScrew>(Vec(RACK_GRID_WIDTH, 0)));

    addChild(createScrew<bFScrew>(Vec(RACK_GRID_WIDTH,
                                      RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

    addInput(createInput<inPort>(Vec(RACK_GRID_WIDTH / 3 - 2,
                                       RACK_GRID_HEIGHT - int(14.5f*PORT_SPACING)),
                                   module, Sum::PORT1_INPUT));
    addInput(createInput<inPort>(Vec(RACK_GRID_WIDTH / 3 - 2,
                                       RACK_GRID_HEIGHT - int(13*PORT_SPACING)),
                                   module, Sum::PORT2_INPUT));
    addInput(createInput<inPort>(Vec(RACK_GRID_WIDTH / 3 - 2,
                                       RACK_GRID_HEIGHT - int(11.5f*PORT_SPACING)),
                                   module, Sum::PORT3_INPUT));
    addInput(createInput<inPort>(Vec(RACK_GRID_WIDTH / 3 - 2,
                                       RACK_GRID_HEIGHT - int(10*PORT_SPACING)),
                                   module, Sum::PORT4_INPUT));
    addInput(createInput<inPort>(Vec(RACK_GRID_WIDTH / 3 - 2,
                                       RACK_GRID_HEIGHT - int(8.5f*PORT_SPACING)),
                                   module, Sum::PORT5_INPUT));
    addInput(createInput<inPort>(Vec(RACK_GRID_WIDTH / 3 - 2,
                                       RACK_GRID_HEIGHT - int(7*PORT_SPACING)),
                                   module, Sum::PORT6_INPUT));
    addInput(createInput<inPort>(Vec(RACK_GRID_WIDTH / 3 - 2,
                                       RACK_GRID_HEIGHT - int(5.5f*PORT_SPACING)),
                                   module, Sum::PORT7_INPUT));
    addInput(createInput<inPort>(Vec(RACK_GRID_WIDTH / 3 - 2,
                                       RACK_GRID_HEIGHT - int(4*PORT_SPACING)),
                                   module, Sum::PORT8_INPUT));

    addOutput(createOutput<outPort>(Vec(RACK_GRID_WIDTH / 3 - 2,
                                      RACK_GRID_HEIGHT - 2*PORT_SPACING),
                                  module, Sum::SUM_OUTPUT));
}
