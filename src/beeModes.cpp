
#include "beeSting_mk2.hpp"
#include <math.h>


float x_value, y_value, z_value;



void beeSting::lights_out() {

    for (int light = 0; light < NUM_LIGHTS; light++) {
        lights[light].value = 0.1f;
    }

}


void beeSting::mode_1A() {
/*
    Precision Adder
 */

    if (inputs[X_INPUT].active)
        x_value = inputs[X_INPUT].value;
    else
        x_value = 0.0f;

    if (inputs[Y_INPUT].active)
        y_value = inputs[Y_INPUT].value;
    else
        y_value = 0.0f;
    if (inputs[Z_INPUT].active)
        z_value = float(int(inputs[Z_INPUT].value + params[Z_PARAM].value));
    else
        // Scale to octave??
        z_value = float(int(params[Z_PARAM].value));

    outputs[A_OUTPUT].value = clampf(x_value + y_value + z_value, -10.0f, 10.0f);
    outputs[B_OUTPUT].value = clampf(x_value - y_value - z_value, -10.0f, 10.0f);


}

void beeSting::mode_1B() {
/*
 *  Four Quadrant Multiplier
 */
    if (!(inputs[X_INPUT].active ||  inputs[Y_INPUT].active))
        // No inputs connected
        return;

    if (inputs[X_INPUT].active)
        x_value = inputs[X_INPUT].value;
    else
        x_value = 0.0f;

    if (inputs[Y_INPUT].active)
        y_value = inputs[Y_INPUT].value;
    else
        y_value = 0.0f;
    if (inputs[Z_INPUT].active) {

// zero-crossing still an issue
        if (inputs[Z_INPUT].value < 0.0f)
            z_value = 1.0f/ abs(roundf(inputs[Z_INPUT].value));
        else
            z_value = abs(roundf(inputs[Z_INPUT].value));
    }
    else {
        if (params[Z_PARAM].value < 0.0f)
            z_value = 1.0f/ abs(roundf(params[Z_PARAM].value));
        else
            z_value = abs(roundf(params[Z_PARAM].value));
    }
    outputs[A_OUTPUT].value = clampf(x_value * y_value * z_value, -10.0f, 10.0f);
    outputs[B_OUTPUT].value = -clampf(x_value * y_value * z_value, -10.0f, 10.0f);

}

void beeSting::mode_1C() {
/*
 * Full-wave Rectifier
 */
    if (!(inputs[X_INPUT].active ||  inputs[Y_INPUT].active))
        // No inputs connected
        return;

    if (inputs[Z_INPUT].active)
        z_value = inputs[Z_INPUT].value;
    else
        z_value = params[Z_PARAM].value;

// zero-crossing still an issue
    if (z_value < 0.0f) {
        outputs[A_OUTPUT].value = clampf(abs(inputs[X_INPUT].value), 0.0f, 10.0f);
        outputs[B_OUTPUT].value = clampf(abs(inputs[Y_INPUT].value), 0.0f, 10.0f);
    }
    else
    {
        outputs[A_OUTPUT].value = clampf(abs(inputs[X_INPUT].value + inputs[Y_INPUT].value), 0.0f, 10.0f);
        outputs[B_OUTPUT].value = clampf(abs(inputs[X_INPUT].value - inputs[Y_INPUT].value), 0.0f, 10.0f);
    }

}

void beeSting::mode_1D() {
/*
 * Minimum/maximum
 */
    if (!(inputs[X_INPUT].active ||  inputs[Y_INPUT].active))
        // No inputs connected
        return;

    if (inputs[Z_INPUT].active)
        z_value = inputs[Z_INPUT].value;
    else
        z_value = params[Z_PARAM].value;

// zero-crossing still an issue
    if (z_value > 2.5f) {
        outputs[A_OUTPUT].value = clampf(fmin(inputs[X_INPUT].value, inputs[Y_INPUT].value), -10.0f, 10.0f);
        outputs[B_OUTPUT].value = clampf(fmax(inputs[X_INPUT].value,inputs[Y_INPUT].value), -10.0f, 10.0f);
    }
//    else
//    {
//		outputs[A_OUTPUT].value = clampf(abs(inputs[X_INPUT].value), -10.0f 10.0f;
//        outputs[B_OUTPUT].value = clampf(abs(inputs[Y_INPUT].value), -10.0f 10.0f;
//    }

}

void beeSting::mode_2A() {
/*
 * Linear/Exponential Converter
 */
    if (!(inputs[X_INPUT].active ||  inputs[Y_INPUT].active))
        // No inputs connected
        return;

    if (inputs[Z_INPUT].active)
        z_value = inputs[Z_INPUT].value;
    else
        z_value = params[Z_PARAM].value;
    // Convert -10 - 10 to Hz/V value between >0 and 2kHz
    z_value = clampf(params[Z_PARAM].value, 0.0001f, 10.0f);
    z_value *= 200.0f;
// This is wrong; do outputs need to be clamped?
//    if (z_value > 2.5)
//    {
    outputs[A_OUTPUT].value = powf(2.0f, inputs[X_INPUT].value) * z_value;
    outputs[B_OUTPUT].value = log2f(inputs[Y_INPUT].value / z_value);
//    }

}

void beeSting::mode_2B() {
/*
 * Quantizer
 */
}

void beeSting::mode_2C() {
/*
 * Comparator
 */
    float last_x = 100000.0f;
    if (!(inputs[X_INPUT].active ||  inputs[Y_INPUT].active))
        // No inputs connected
        return;

    if (inputs[Z_INPUT].active)
        z_value = clampf(inputs[Z_INPUT].value, 0.0f, 10.0f);
    else
        z_value = clampf((params[Z_PARAM].value + 10.0f) / 2.0f, 0.0f, 10.0f);

    if (inputs[X_INPUT].value > inputs[Y_INPUT].value)
    {
        outputs[A_OUTPUT].value = 5.0f;
        outputs[B_OUTPUT].value = 0.0f;
// Figure out hysteresis later...
        // // Rising?
        // if (last_x < inputs[X_INPUT].value)
        // {
        //     // Passed the hysteresis value?
        //     if (last_x < z_value)
        //     {
        //         outputs[A_OUTPUT].value = 0.0f
        //     }
        // }

    }
    else
    {
        outputs[A_OUTPUT].value = 0.0f;
        outputs[B_OUTPUT].value = 5.0f;
    }

    last_x = inputs[X_INPUT].value;
}

void beeSting::mode_2D() {
/*
 * Dual Waveshaper
 */
}

void beeSting::mode_3A() {
/*
 * Sample and Hold
 */
    if (!(inputs[X_INPUT].active ||  inputs[Y_INPUT].active))
        // No inputs connected
        return;

    if (inputs[Z_INPUT].active)
        z_value = inputs[Z_INPUT].value;
    else
        z_value = params[Z_PARAM].value;

    if (inputs[Y_INPUT].value > 1.0f)
    {
        outputs[A_OUTPUT].value = inputs[X_INPUT].value;
    }
//    outputs[B_OUTPUT].value = getRand() * 8.0f
}

void beeSting::mode_3B() {
/*
 * Slew Rate Limiter
 */
}

void beeSting::mode_3C() {
/*
 * Pitch and Envelope Tracker
 */
}

void beeSting::mode_3D() {
/*
 * Clockable Delay/Echo
 */
}

void beeSting::mode_4A() {
/*
 * LFO
 */

}

void beeSting::mode_4B() {
/*
 * Clockable LFO
 */
}

void beeSting::mode_4C() {
/*
 * VCO with linear FM
 */
}

void beeSting::mode_4D() {
/*
 * VCO with waveshaping
 */
}
