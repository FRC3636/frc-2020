#include "subsystems/NetworkTableHandler.h"

NetworkTableHandler::NetworkTableHandler() {}

// This method will be called once per scheduler run
double NetworkTableHandler::getAngle() {
    return m_Angle.GetDouble(0);
}

double NetworkTableHandler::getDistance() {
    return m_Distance.GetDouble(0);
}
