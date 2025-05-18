#pragma once
#include <vector>
#include "GoCS.h"

#include "Mathematics.h"
using namespace std;
namespace Sorting {
    inline int binary_search_recursive_gameobject_array(const std::vector<RenderCommand>& arr, float zPosition, int low = 0, int high = -1,int recNum = 0){
        recNum ++;
        
        if (high == -1) {
            high = static_cast<int>(arr.size()) - 1;
        }
        if (low >= high ){
            return -1;
        }
        int mid = (low + high) / 2;
        float val = arr[mid].transform->Position.z;
        std::cout << "Recursion #" << recNum << ": low=" << low << " high=" << high << " mid=" << mid << " val=" << val << std::endl;
        if (val = zPosition) {
            std::cout << "Equals\n";
            return mid;
        }
        else if (val < zPosition) {
            std::cout << "Less\n";
            return binary_search_recursive_gameobject_array(arr, zPosition, mid + 1, high, recNum);
        }
        else {
            std::cout << "Greater\n";
            return binary_search_recursive_gameobject_array(arr, zPosition, low, mid - 1, recNum);
        } 

    }
}