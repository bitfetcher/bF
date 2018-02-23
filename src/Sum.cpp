
#include "Sum.hpp"

using namespace bF;


void Sum::step() {
    if (!outputs[SUM_OUTPUT].active)
        return;
    float sum_in = 0.0f;
    for (int i = 0; i < NUM_INPUTS; i++) {
        if (inputs[i].active)
            sum_in += inputs[i].value;
    }
    outputs[SUM_OUTPUT].value = sum_in;
}
