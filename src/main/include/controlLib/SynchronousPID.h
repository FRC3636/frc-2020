#pragma once

#include <iostream>
#include <cmath>
#include <math.h>
#include <string>

class SynchronousPID {
private:
    double m_P; // factor for "proportional" control
    double m_I; // factor for "integral" control
    double m_D; // factor for "derivative" control
    double m_maximumOutput; // |maximum output|
    double m_minimumOutput; // |minimum output|
    double m_maximumInput = 100000; // maximum input - limit setpoint to
        // this
    double m_minimumInput = -100000; // minimum input - limit setpoint to
        // this
    bool m_continuous = false; // do the endpoints wrap around? eg.
        // Absolute encoder
    double m_prevError = 0.0; // the prior sensor input (used to compute
        // velocity)
    double m_totalError = 0.0; // the sum of the errors for use in the
        // integral calc
    double m_setpoint;
    double m_error = 0.0;
    double m_result = 0.0;

    double m_last_input = NAN;

    double m_deadband; // If the absolute error is less than
        // deadband
        // then treat error for the proportional
        // term as 0

        //might need to set: m_minimumOutput (should be fine as is), m_maximumOutput (should be fine as is)
        //need to set once: m_deadband, m_minimumInput, m_maximumInput, m_P, m_I, m_D
        //need to set often: m_setpoint
        //need to set every time calculate is called: input (from encoder)

public:
    /**
     * Allocate a PID object with the given constants for P, I, D
     *
     * @param Kp
     *            the proportional coefficient
     * @param Ki
     *            the integral coefficient
     * @param Kd
     *            the derivative coefficient
     */
     SynchronousPID(double Kp, double Ki, double Kd, double starting_setpoint, double deadband, double minimum_output, double maximum_output);

    /**
     * Read the input, calculate the output accordingly, and write to the
     * output. This should be called at a constant rate by the user (ex. in a
     * timed thread)
     *
     * @param input
     *            the input
     */
     double calculate(double input);

     double get_deadband();

    /**
     * Set the PID controller gain parameters. Set the proportional, integral,
     * and differential coefficients.
     *
     * @param p
     *            Proportional coefficient
     * @param i
     *            Integral coefficient
     * @param d
     *            Differential coefficient
     */
    void setPID(double p, double i, double d);

    /**
     * Get the Proportional coefficient
     *
     * @return proportional coefficient
     */
    double getP();

    /**
     * Get the Integral coefficient
     *
     * @return integral coefficient
     */
    double getI();

    /**
     * Get the Differential coefficient
     *
     * @return differential coefficient
     */
    double getD();

    /**
     * Return the current PID result This is always centered on zero and
     * constrained the the max and min outs
     *
     * @return the latest calculated output
     */
    double get();

    /**
     * Set the PID controller to consider the input to be continuous, Rather
     * then using the max and min in as constraints, it considers them to be the
     * same point and automatically calculates the shortest route to the
     * setpoint.
     *
     * @param continuous
     *            Set to true turns on continuous, false turns off continuous
     */
    void setContinuous(bool continuous);

    void setDeadband(double deadband);

    /**
     * Set the PID controller to consider the input to be continuous, Rather
     * then using the max and min in as constraints, it considers them to be the
     * same point and automatically calculates the shortest route to the
     * setpoint.
     */
    void setContinuous();

    /**
     * Sets the maximum and minimum values expected from the input.
     *
     * @param minimumInput
     *            the minimum value expected from the input
     * @param maximumInput
     *            the maximum value expected from the output
     */
    void setInputRange(double minimumInput, double maximumInput);

    /**
     * Sets the minimum and maximum values to write.
     *
     * @param minimumOutput
     *            the minimum value to write to the output
     * @param maximumOutput
     *            the maximum value to write to the output
     */
    void setOutputRange(double minimumOutput, double maximumOutput);

    /**
     * Set the setpoint for the PID controller
     *
     * @param setpoint
     *            the desired setpoint
     */
    void setSetPoint(double setpoint);

    /**
     * Returns the current setpoint of the PID controller
     *
     * @return the current setpoint
     */
    double getSetpoint();

    /**
     * Returns the current difference of the input from the setpoint
     *
     * @return the current error
     */
    double getError();

    /**
     * Return true if the error is within the tolerance
     *
     * @return true if the error is less than the tolerance
     */
    bool onTarget(double tolerance);

    /**
     * Reset all internal terms.
     */
    void reset();

    void resetIntegrator();
};

