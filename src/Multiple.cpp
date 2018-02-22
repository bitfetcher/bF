
#include "Multiple.hpp"

using namespace bF;


void Multiple::step() {
    if (inputs[SOURCE_INPUT].active)
    {
        float in_value = inputs[SOURCE_INPUT].normalize(0.0f);
        outputs[PORT1_OUTPUT].value = in_value;
        outputs[PORT2_OUTPUT].value = in_value;
        outputs[PORT3_OUTPUT].value = in_value;
        outputs[PORT4_OUTPUT].value = in_value;
        outputs[PORT5_OUTPUT].value = in_value;
        outputs[PORT6_OUTPUT].value = in_value;
        outputs[PORT7_OUTPUT].value = in_value;
        outputs[PORT8_OUTPUT].value = in_value;
    }
}
