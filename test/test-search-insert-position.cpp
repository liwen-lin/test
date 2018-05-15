//
//  test-subsets.cpp
//  test
//
//  Created by Liwen Lin on 5/9/18.
//  Copyright © 2018 Liwen Lin. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <string>
#include <queue>
#include "list-node.hpp"

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s, e, m;
        s = 0;
        e = nums.size()-1;
        
        while (s <= e) {
            m = (s+e)/2;
            if (nums[m] < target)
                s = m+1;
            else if (nums[m] > target)
                e = m-1;
            else
                return m;
        }
        
        return s;
    }
};

int main(void) {
    
    vector<int> nums = {1, 3};
    int t = 2;
    cout << Solution().searchInsert(nums, t);
    
    return 0;
}