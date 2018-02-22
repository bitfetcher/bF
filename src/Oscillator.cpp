
#include "Oscillator.hpp"


void Oscillator::step() {
    // Implement a simple sine oscillator
    float deltaTime = 1.0f / engineGetSampleRate();

    // Compute the frequency from the pitch parameter and input
    float pitch = params[PITCH_PARAM].value;

    pitch += inputs[PITCH_INPUT].value;
    pitch  = clampf(pitch, -4.0f, 4.0f);

    // The default pitch is C4
    float freq = 261.626f * powf(2.0f, pitch);

    // Accumulate the phase
    phase += freq * deltaTime;

    if (phase >= 1.0f) phase -= 1.0f;

    // Compute the sine output
    float sine = sinf(2 * M_PI * phase);
    outputs[SINE_OUTPUT].value = 5.0f* sine;

    // Blink light at 1Hz
    blinkPhase += deltaTime;

    if (blinkPhase >= 1.0f) blinkPhase -= 1.0f;
    lights[BLINK_LIGHT].value = (blinkPhase < 0.5f) ? 1.0f : 0.0f;
}
