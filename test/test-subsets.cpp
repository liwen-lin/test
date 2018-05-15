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

using namespace std;

class Solution {
public:
    
    void backtrack(vector<int> &nums, vector<int> cur, vector<vector<int>> &res, int start) {
        res.push_back(cur);
        
        for (int i = start; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            backtrack(nums, cur, res, i+1);
            cur.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums, {}, res, 0);
        
        return res;
    }
};

int main(void) {
    vector<int> nums = {1, 2, 3};
    
    vector<vector<int>> res = Solution().subsets(nums);
    for (auto &e: res) {
        for (auto &e1 : e)
            cout << e1 << ", ";
        cout << endl;
    }
    
    
    return 0;
}