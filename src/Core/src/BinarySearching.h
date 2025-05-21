#pragma once
#include <vector>
#include "GoCS.h"

#include "Mathematics.h"
using namespace std;
namespace Sorting {
    inline int binary_search_recursive_gameobject_array(const std::vector<RenderCommand>& arr, glm::vec3 pos,glm::vec3 cPos, int low = 0, int high = -1,int recNum = 0){
        
        recNum ++;
        
        if (high == -1) {
            high = static_cast<int>(arr.size()) - 1;
        }
        if (low >= high ){
            return -1;
        }
        int mid = (low + high) / 2;
        
        // Compare squared distances
        float objDistSqr = glm::distance2(cPos, pos);
        float midDistSqr = glm::distance2(cPos, arr[mid].transform->Position);
        
        // Recursion log (optional)
        std::cout << "Rec#" << recNum << " low=" << low << " high=" << high << " mid=" << mid << " objDist=" << objDistSqr << " midDist=" << midDistSqr << "\n";

        if (objDistSqr == midDistSqr){
            return mid;
        } else if (objDistSqr > midDistSqr) {
            // Object is further — search later part
            //Core::App::Application::GetInstance().GetLogger()->DebugLog("GREATER");
            std::cout << "Greater" << std::endl;
            return binary_search_recursive_gameobject_array(arr, pos, cPos, mid + 1, high, recNum);
        } else if (objDistSqr < midDistSqr){
            std::cout << "LESS" << std::endl;
            //Core::App::Application::GetInstance().GetLogger()->DebugLog("LESS");
            // Object is closer — search earlier part
            return binary_search_recursive_gameobject_array(arr, pos, cPos, low, mid - 1, recNum);
        } else{
            return 0;
        }

    }
}