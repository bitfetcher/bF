#include "Blanks.hpp"

using namespace bF;

Blank2Widget::Blank2Widget()
{
    Blank2 *module = new Blank2();
    setModule(module);
    box.size = Vec(2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

    {
        SVGPanel *panel = new SVGPanel();
        panel->setBackground(SVG::load(assetPlugin(plugin, "res/Blank2.svg")));
        panel->box.size = box.size;
        addChild(panel);
    }

    addChild(createScrew<bFScrew>(Vec(0, 0)));
    addChild(createScrew<bFScrew>(Vec(0, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
}


Blank3Widget::Blank3Widget()
{
    Blank3 *module = new Blank3();
    setModule(module);
    box.size = Vec(3 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

    {
        SVGPanel *panel = new SVGPanel();
        panel->setBackground(SVG::load(assetPlugin(plugin, "res/Blank3.svg")));
        panel->box.size = box.size;
        addChild(panel);
    }

    addChild(createScrew<bFScrew>(Vec(0, 0)));
    addChild(createScrew<bFScrew>(Vec(box.size.x - RACK_GRID_WIDTH, 0)));
    addChild(createScrew<bFScrew>(Vec(0, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
    addChild(createScrew<bFScrew>(Vec(box.size.x - RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
}


Blank5Widget::Blank5Widget()
{
    Blank5 *module = new Blank5();
    setModule(module);
    box.size = Vec(5 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

    {
        SVGPanel *panel = new SVGPanel();
        panel->setBackground(SVG::load(assetPlugin(plugin, "res/Blank5.svg")));
        panel->box.size = box.size;
        addChild(panel);
    }

    addChild(createScrew<bFScrew>(Vec(0, 0)));
    addChild(createScrew<bFScrew>(Vec(box.size.x - RACK_GRID_WIDTH, 0)));
    addChild(createScrew<bFScrew>(Vec(0, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
    addChild(createScrew<bFScrew>(Vec(box.size.x - RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
}
