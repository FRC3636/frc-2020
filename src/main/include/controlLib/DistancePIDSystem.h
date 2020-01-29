#pragma once

#include <iostream>
#include <cmath>

class DistancePIDSystem {
public:
    DistancePIDSystem(double D, double Vm, double a);
    ~DistancePIDSystem();
    void setDistance(double setPoint);
    double getDistance(double time);
private:
    void setDmapParams();
    double D1, D2, D3, T1, T2, T3, VT2;
    double D;
    const double Vm;
    const double a;

};
