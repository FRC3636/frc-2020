#pragma once
#include <frc/I2C.h>

namespace constant {
    //I2CPort
    static constexpr auto I2C_PORT = frc::I2C::Port::kOnboard;

    //PWM
    static constexpr int LEFT_MOTOR_PORT = 0;
    static constexpr int RIGHT_MOTOR_PORT = 1;

    //DIO
    static constexpr int LEFT_ENCODER_PORT_1 = 0;
    static constexpr int LEFT_ENCODER_PORT_2 = 1;
    static constexpr int RIGHT_ENCODER_PORT_1 = 2;
    static constexpr int RIGHT_ENCODER_PORT_2 = 3;

    //input
    static constexpr int LEFT_JOYSTICK_PORT = 0;
    static constexpr int RIGHT_JOYSTICK_PORT = 1;
    static constexpr int CONTROLLER_PORT = 2;
}