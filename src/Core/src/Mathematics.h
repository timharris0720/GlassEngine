#pragma once
namespace Maths{
    template <typename T>
    inline T Clamp(T valueToClamp, T ClampMax, T ClampMin){
        if(valueToClamp > ClampMax){
            valueToClamp = ClampMax;
        }
        if(valueToClamp < ClampMin){
            valueToClamp = ClampMin;
        }
        return valueToClamp;
    }
    inline int floor_div(int a, int b) {
        int q = a / b;
        int r = a % b;
        // If remainder exists and signs differ, subtract 1 to floor
        if ((r != 0) && ((a < 0) != (b < 0))) {
            q -= 1;
        }
        return q;
    }
}