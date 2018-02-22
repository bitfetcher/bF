
#include "Oscillator.hpp"

using namespace bF;

OscWidget::OscWidget() {
    Oscillator *module = new Oscillator();

    setModule(module);
    box.size = Vec(MODULE_WIDTH, RACK_GRID_HEIGHT);

    {
        SVGPanel *panel = new SVGPanel();
        panel->box.size = box.size;
        panel->setBackground(SVG::load(assetPlugin(plugin, "res/Oscillator.svg")));
        addChild(panel);
    }


    addChild(createScrew<bFScrew>(Vec(0, 0)));
    addChild(createScrew<bFScrew>(Vec(box.size.x -  RACK_GRID_WIDTH, 0)));
    addChild(createScrew<bFScrew>(Vec(0, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
    addChild(createScrew<bFScrew>(Vec(box.size.x - RACK_GRID_WIDTH,
                                      RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

    //addChild(createLight<MediumLight<RedLight> >(Vec(26, 35), module,
    //                                             Oscillator::BLINK_LIGHT));

    addParam(createParam<Davies1900hWhiteKnob>(Vec(13, 55), module,
                                             Oscillator::PITCH_PARAM, -3.0f, 3.0f,
                                             0.0f));

    addInput(createInput<inPort>(Vec(17, 175), module,
                                     Oscillator::PITCH_INPUT));

    addOutput(createOutput<outPort>(Vec(17, 280), module,
                                       Oscillator::SINE_OUTPUT));

}
