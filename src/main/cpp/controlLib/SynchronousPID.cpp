#include "controlLib/SynchronousPID.h"

SynchronousPID::SynchronousPID(double Kp, double Ki, double Kd, double starting_setpoint, double deadband, double minimum_output, double maximum_output) {
    m_P = Kp;
    m_I = Ki;
    m_D = Kd;
    m_setpoint = starting_setpoint;
    m_deadband = deadband;
    m_minimumOutput = minimum_output;
    m_maximumOutput = maximum_output;
}

double SynchronousPID::calculate(double input) {
    m_last_input = input;
    m_error = m_setpoint - input;
    //std::cout << "error: " << m_error << std::endl;
    if (m_continuous) {
        if (std::abs(m_error) > (m_maximumInput - m_minimumInput) / 2) {
            if (m_error > 0) {
                m_error = m_error - m_maximumInput + m_minimumInput;
            } else {
                m_error = m_error + m_maximumInput - m_minimumInput;
            }
        }
    }


    m_totalError += m_error;

    // Don't blow away m_error so as to not break derivative
    double proportionalError = std::abs(m_error) < m_deadband ? 0 : m_error;

    m_result = (m_P * proportionalError + m_I * m_totalError + m_D * (m_error - m_prevError));
    m_prevError = m_error;

    if (m_result > m_maximumOutput) {
        m_result = m_maximumOutput;
    } else if (m_result < m_minimumOutput) {
        m_result = m_minimumOutput;
    }
    return m_result;
}

double SynchronousPID::get_deadband(){
    return m_deadband;
}

void SynchronousPID::setPID(double p, double i, double d) {
    m_P = p;
    m_I = i;
    m_D = d;
}

double SynchronousPID::getP() {
    return m_P;
}

double SynchronousPID::getI() {
    return m_I;
}

double SynchronousPID::getD() {
    return m_D;
}

double SynchronousPID::get() {
    return m_result;
}

void SynchronousPID::setContinuous(bool continuous) {
    m_continuous = continuous;
}

void SynchronousPID::setDeadband(double deadband) {
    m_deadband = deadband;
}

void SynchronousPID::setContinuous() {
    this->setContinuous(true);
}

void SynchronousPID::setInputRange(double minimumInput, double maximumInput) {
    if (minimumInput > maximumInput) {
        std::cerr << "Lower bound is greater than upper bound" << std::endl;
    }
    m_minimumInput = minimumInput;
    m_maximumInput = maximumInput;
    setSetPoint(m_setpoint);
}

void SynchronousPID::setOutputRange(double minimumOutput, double maximumOutput) {
    if (minimumOutput > maximumOutput) {
        std::cerr << "Lower bound is greater than upper bound" << std::endl;
    }
    m_minimumOutput = minimumOutput;
    m_maximumOutput = maximumOutput;
}

void SynchronousPID::setSetPoint(double setpoint) {
    reset();
    if (m_maximumInput > m_minimumInput) {
        if (setpoint > m_maximumInput) {
            m_setpoint = m_maximumInput;
        } else if (setpoint < m_minimumInput) {
            m_setpoint = m_minimumInput;
        } else {
            m_setpoint = setpoint;
        }
    } else {
        m_setpoint = setpoint;
    }
}

double SynchronousPID::getSetpoint() {
    return m_setpoint;
}

double SynchronousPID::getError() {
    return m_error;
}

bool SynchronousPID::onTarget(double tolerance) {
    return m_last_input != NAN && std::abs(m_last_input - m_setpoint) < tolerance;
}

void SynchronousPID::reset() {
    m_last_input = NAN;
    m_prevError = 0;
    m_totalError = 0;
    m_result = 0;
    m_setpoint = 0;
}

void SynchronousPID::resetIntegrator() {
    m_totalError = 0;
}

