#pragma once
#include <vector>
#include "GoCS.h"

#include "Mathematics.h"
using namespace std;
namespace Sorting {
    inline int binary_search_recursive_gameobject_array(std::vector<RenderCommand> arr, float zPosition, int low = 0, int high = NULL){
        if(high == NULL){
            high = arr.size() - 1;
        }
        if (low > high ){
            return -1;
        }
        int mid = Maths::floor_div((low + high),  2);
        float val = arr[mid].transform->Position.z;
        if(val == zPosition){
            return mid;
        }
        else if(val < zPosition){
            return binary_search_recursive_gameobject_array(arr, zPosition, mid + 1, high);
        }
        else{
            return binary_search_recursive_gameobject_array(arr, zPosition, low, mid - 1);
        }   

    }
}