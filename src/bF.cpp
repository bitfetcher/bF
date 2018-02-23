#include "bF.hpp"


// The plugin-wide instance of the Plugin class
Plugin *plugin;

using namespace bF;

void init(rack::Plugin *p) {
    plugin = p;

#ifdef SLUG
    plugin->slug = TOSTRING(SLUG);
#else
    plugin->slug = "bitFetcher";
#endif

#ifdef VERSION
    plugin->version = TOSTRING(VERSION);
#endif

    plugin->website = "https://github.com/bitfetcher/bF";
    plugin->manual = "https://github.com/bitfetcher/bF/blob/master/README.md";

    // For each module, specify the ModuleWidget subclass, manufacturer slug (for saving in patches), manufacturer human-readable name, module slug, and module name
    p->addModel(createModel<OscWidget>(plugin->slug, "Oscillator", "Sine Oscillator", OSCILLATOR_TAG));

	p->addModel(createModel<MultWidget>(plugin->slug, "Multiple", "8-out Multiple", MULTIPLE_TAG, UTILITY_TAG));

	p->addModel(createModel<SumWidget>(plugin->slug, "Sum", "8-in Sum", MULTIPLE_TAG, UTILITY_TAG));

    p->addModel(createModel<QuadWidget>(plugin->slug, "Quadrature", "Quadrature LFO", OSCILLATOR_TAG, LFO_TAG, QUAD_TAG));

	p->addModel(createModel<Blank2Widget>(plugin->slug, "Blank2", "Blank 2", BLANK_TAG));

	p->addModel(createModel<Blank3Widget>(plugin->slug, "Blank3", "Blank 3", BLANK_TAG));

	p->addModel(createModel<Blank5Widget>(plugin->slug, "Blank5", "Blank 5", BLANK_TAG));

    // Any other plugin initialization may go here.
    // As an alternative, consider lazy-loading assets and lookup tables when your module is created to reduce startup times of Rack.
}
