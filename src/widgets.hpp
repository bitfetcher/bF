
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
struct beeWidget : ModuleWidget {
    beeWidget();
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


} // namespace
