
#include "Quadrature.hpp"

using namespace bF;

QuadWidget::QuadWidget() {
    Quadrature *module = new Quadrature();

    setModule(module);
    box.size = Vec(MODULE_WIDTH, RACK_GRID_HEIGHT);

    {
        SVGPanel *panel = new SVGPanel();
        panel->box.size = box.size;
        panel->setBackground(SVG::load(assetPlugin(plugin,
                                                   "res/Quadrature.svg")));
        addChild(panel);
    }

    addChild(createScrew<bFScrew>(Vec(0, 0)));
    addChild(createScrew<bFScrew>(Vec(box.size.x - RACK_GRID_WIDTH, 0)));
    addChild(createScrew<bFScrew>(Vec(0, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
    addChild(createScrew<bFScrew>(Vec(box.size.x - RACK_GRID_WIDTH,
                                      RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

    addInput(createInput<inPort>(Vec(5, 45), module, Quadrature::PITCH_INPUT));

    addInput(createInput<inPort>(Vec(5, 105), module, Quadrature::CV2_POLARIZER_INPUT));

    addParam(createParam<Davies1900hWhiteKnob>(Vec(32, 40), module,
                                               Quadrature::PITCH_PARAM, -3.0f, 3.0f, 0.0f));
    addParam(createParam<Davies1900hWhiteKnob>(Vec(32, 100), module,
                                               Quadrature::CV2_POLARIZER_PARAM, -5.0f, 5.0f, 0.0f));

    addParam(createParam<bFCKSSH>(Vec(MODULE_WIDTH / 2 - 18, 160), module,
                                  Quadrature::RANGE_PARAM, 0.0f, 2.0f, 0.0f));

    addChild(createLight<MediumLight<RedLight> >(Vec(45, 190), module,
                                                 Quadrature::POS_LIGHT));
    addChild(createLight<MediumLight<RedLight> >(Vec(60, 190), module,
                                                 Quadrature::NEG_LIGHT));
    addOutput(createOutput<outPort>(Vec(13, 200), module,
                                    Quadrature::SINE_OUTPUT));
    addOutput(createOutput<outPort>(Vec(13, 235), module,
                                    Quadrature::COSINE_OUTPUT));
    addOutput(createOutput<outPort>(Vec(13, 270), module,
                                    Quadrature::NOT_SINE_OUTPUT));
    addOutput(createOutput<outPort>(Vec(13, 305), module,
                                    Quadrature::NOT_COSINE_OUTPUT));

}
