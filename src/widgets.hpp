
#include "rack.hpp"

using namespace rack;

extern Plugin *plugin;

namespace bF {
struct inPort : SVGPort {
    inPort() {
        background->svg = SVG::load(assetPlugin(plugin, "res/in_port.svg"));
        background->wrap();
        box.size = Vec(24, 24);
    }
};

struct outPort : SVGPort {
    outPort() {
        background->svg = SVG::load(assetPlugin(plugin, "res/out_port.svg"));
        background->wrap();
        box.size = Vec(24, 24);
    }
};

struct OscWidget : ModuleWidget {
    OscWidget();
};

struct QuadWidget : ModuleWidget {
    QuadWidget();
};

struct MultWidget : ModuleWidget {
    MultWidget();
};

struct SumWidget : ModuleWidget {
    SumWidget();
};

struct beeWidget : ModuleWidget {
    beeWidget();
};

struct Blank2Widget : ModuleWidget {
    Blank2Widget();
};

struct Blank3Widget : ModuleWidget {
    Blank3Widget();
};

struct Blank5Widget : ModuleWidget {
    Blank5Widget();
};

struct bFScrew : SVGScrew {
        bFScrew() {
                sw->setSVG(SVG::load(assetPlugin(plugin, "res/bFScrew.svg")));
                box.size = sw->box.size;
        }
};

// Horizontal CKSS switch
struct bFCKSSH : SVGSwitch, ToggleSwitch {
	bFCKSSH() {
		addFrame(SVG::load(assetPlugin(plugin,"res/bFCKSSHThree_0.svg")));
		addFrame(SVG::load(assetPlugin(plugin,"res/bFCKSSHThree_1.svg")));
		addFrame(SVG::load(assetPlugin(plugin,"res/bFCKSSHThree_2.svg")));
	}
};


} // bF namespace
