
#include "Quadrature.hpp"

using namespace bF;

void Quadrature::step() {


    // Implement a simple sine oscillator
    deltaTime = 1.0f / engineGetSampleRate();

    pitch = params[PITCH_PARAM].value;
    if (inputs[PITCH_INPUT].active)
        pitch += inputs[PITCH_INPUT].value;

    if (inputs[CV2_POLARIZER_INPUT].active)
        pitch += inputs[CV2_POLARIZER_INPUT].value * params[CV2_POLARIZER_PARAM].value;
    else
        pitch += params[CV2_POLARIZER_PARAM].value;

    // Compute the frequency from the pitch parameter and input

    pitch  = clampf(pitch, -5.0f, 5.0f);

    // The default pitch is C4
    freq = 261.626f * powf(2.0f, pitch);


// Cheat with the lights for now; blink on LOW, steady dim on MEDIUM, and bright on HIGH
// Scale factors need a lot of work!
    range = (RANGE_VALUE)int(params[RANGE_PARAM].value);

    switch (range) {
     case LOW:
         freq /= 160.0f;
         break;

     case MEDIUM:
         freq /= 16.0f;
         break;

     case HIGH:
         freq *= 7.0f;
         break;

    };

    // Accumulate the phase
    phase += freq * deltaTime;

    if (phase >= 1.0f) phase = 0.0f;

    // Compute the sine outputs
    sine = sinf(2 * M_PI * phase);
    cosine = cosf(2 * M_PI * phase);
    notsine = -sine;
    notcosine = -cosine;

// Voltage range -5 - 5v?
    outputs[SINE_OUTPUT].value = 5.0f * sine;
    outputs[COSINE_OUTPUT].value = 5.0f * cosine;
    outputs[NOT_SINE_OUTPUT].value = 5.0f * notsine;
    outputs[NOT_COSINE_OUTPUT].value = 5.0f * notcosine;

    lights[POS_LIGHT].value = (sine > 0.0f) ? 1.0f : 0.0f;
    lights[NEG_LIGHT].value = 1.0f - lights[POS_LIGHT].value;

}
