#pragma once

#include <frc/I2C.h>
#include <frc/util/Color.h>

namespace constant {
    //I2CPort
    static constexpr auto I2C_PORT = frc::I2C::Port::kOnboard;

    //PWM
    static constexpr int LEFT_MOTOR_PORT = 0;
    static constexpr int RIGHT_MOTOR_PORT = 1;
    static constexpr int ELEVATOR_MOTOR_PORT = 2;

    //DIO
    static constexpr int LEFT_ENCODER_PORT_1 = 0;
    static constexpr int LEFT_ENCODER_PORT_2 = 1;
    static constexpr int RIGHT_ENCODER_PORT_1 = 2;
    static constexpr int RIGHT_ENCODER_PORT_2 = 3;

    //input
    static constexpr int LEFT_JOYSTICK_PORT = 0;
    static constexpr int RIGHT_JOYSTICK_PORT = 1;
    static constexpr int CONTROLLER_PORT = 2;

    //colors
    static constexpr frc::Color BLUE = frc::Color(0.143, 0.427, 0.429);
    static constexpr frc::Color GREEN = frc::Color(0.197, 0.561, 0.240);
    static constexpr frc::Color RED = frc::Color(0.561, 0.232, 0.114);
    static constexpr frc::Color YELLOW = frc::Color(0.361, 0.524, 0.113);
}