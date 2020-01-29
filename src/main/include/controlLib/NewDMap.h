#pragma once

#include <cmath>

class NewDMap {
public:
    void SetParam_dmap(double D, double Vm, double a, double V0);

    double Func_dmap(double t);

private:
    double Dmin;
    double a1;
    double a3;

    double T1;
    double D1;
    double T3;
    double D3;

    double D2;
    double t2;
    double t1;
    double t3;
    double V2;

    double T2;

    double D;
    double Vm;
    double a;
    double V0;

    double dmap;
};

