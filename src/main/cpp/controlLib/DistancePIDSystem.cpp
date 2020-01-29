#include "controlLib/DistancePIDSystem.h"

DistancePIDSystem::DistancePIDSystem(double initD, double initVm, double inita) : D(initD), Vm(initVm), a(inita) {
    setDmapParams();
}

DistancePIDSystem::~DistancePIDSystem() = default;

void DistancePIDSystem::setDistance(double setPoint) {
    D = setPoint;
    setDmapParams();
}

void DistancePIDSystem::setDmapParams() {
    D1 = (Vm * Vm) / (2 * a);
    if (2 * D1 >= D) {
        D1 = D / 2;
        D2 = 0;
        T1 = std::sqrt((2 * D1) / a);
        T2 = T1;
        T3 = T2 + T1;
        VT2 = a * T1;
    } else {
        D2 = D - 2 * D1;
        T1 = std::sqrt((2 * D1) / a);
        T2 = D2 / Vm + T1;
        T3 = T2 + T1;
        VT2 = Vm;
    }

}

double DistancePIDSystem::getDistance(double time) {
    std::cout << "D: " << D << " D1: " << D1 << " D2: " << D2 << " VT2: " << VT2 << std::endl;
    std::cout << "T1: " << T1 << " T2: " << T2 << " T3: " << T3 << std::endl;
    if (time < T1) {
        return a * (time * time) / 2;
    } else if (time < T2) {
        return D1 + VT2 * (time - T1);
    } else if (time < T3) {
        return D1 + D2 + VT2 * (time - T2) - (a / 2) * ((time - T2) * (time - T2));
    } else {
        return D;
    }
}