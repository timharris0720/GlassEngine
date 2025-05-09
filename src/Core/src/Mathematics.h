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
}