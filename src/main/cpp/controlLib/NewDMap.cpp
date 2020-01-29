#include "controlLib/NewDMap.h"

void NewDMap::SetParam_dmap(double D, double Vm, double a, double V0){
    //Call once to set D1, D2, D3, t1, t2, t3, V2
    Dmin = (V0*V0)/(2*a);    //(test value)

    if (V0 > Vm){
        a1 = -a;
    }
    else{
        a1 = a;
    }

    a3 = -a;

    //assume TRAP, then test
    T1 = (Vm-V0)/a1;
    D1 = 0.5*a1*(T1*T1)+V0*T1;
    T3 = Vm/a;
    D3 = T3*Vm/2;

    if (D1+D3<D) {       //TRAP velocity
        D2 = D - (D1 + D3);
        t2 = T1 + D2 / Vm;
        t1 = T1;
        t3 = t2 + T3;
        V2 = Vm;
    }
    else if (Dmin<D) {         //SAW velocity profile
        T1 = (-2*V0 + std::sqrt(2*(V0*V0) + 4*a*D)) / (2*a);
        D1 = 0.5*a*(T1*T1) + V0*T1;
        V2 = a*T1 + V0;
        T3 = T1 + V0 / a;
        D3 = V2*T3 / 2;
        D2 = 0;
        T2 = 0;
        t1 = T1;
        t2 = T1;
        t3 = t2 + T3;
    }
    else{                         //DECEL velocity profile
        T1 = 0, T2 = 0, t1 = 0, t2 = 0;
        T3 = V0/a;
        D3 = T3*V0/2;  //This could be > D!!
    }

    NewDMap::D = D;
    NewDMap::Vm = Vm;
    NewDMap::a = a;
    NewDMap::V0 = V0;

    //D is total distance to travel
    //D=D1+D2+D3 (accel + const_vel + decel)
    //D1=distance traveled while accelerating
        //D2=distance traveled at constant velocity
    //(will be zero for a SAW velocity profile)
    //D3=distance traveled while declerating
        //T1,T2,T3 = amount of time spent on D1,D2,D3
    //t0= reference time at start of maneuver
    //t1=cumulative time at end of acceleration
    //t2=cumulative time at end of constant velocity
    //(will be same as t1 for a SAW velocity profile)
    //t3=cumulative time at end of deceleration
    //Vm = max allowable velocity     //constant param
    //V0= initial velocity
    //V2= velocity at time t2
    //a = acceleration / deceleration //constant param
}

double NewDMap::Func_dmap (double t) {
    //returns the desired distance at time t
    double dmap;

    if (t<T1){      //accelerating
        dmap = a * (t * t) / 2 + V0 * t;
    }
    else if (t<T2) {    //constant velocity
        dmap = D1 + V2 * (t - T1);
    }
    else if (t<T3) {    //decelerating
        dmap = D1 + D2 + V2 * (t - T2) - (a / 2) * ((t - T2) * (t - T2));
    }
    else {    //hold at destination
        dmap = D;
    }

    return dmap;

}

