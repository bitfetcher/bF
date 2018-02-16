// Bring in system includes
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//#include <algorithm>

// Bring in Rack header
#include "rack.hpp"

// Bring in my own includes
//#include "dsp/digital.hpp"
//#include "widgets.hpp"

using namespace rack;
//using namespace bF;

extern Plugin *plugin;

////////////////////
// module widgets
////////////////////

struct OscWidget : ModuleWidget {
	OscWidget();
};
