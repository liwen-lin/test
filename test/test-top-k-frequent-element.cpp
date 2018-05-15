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
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Get frequency for each nums
        unordered_map<int, int> hash;
        for (auto &e : nums) {
            auto found = hash.find(e);
            if (found != hash.end())
                found->second++;
            else
                hash[e] = 1;
        }
        
        // Heap
        priority_queue<int> heap;
        for (auto &e : hash) {
            if (heap.size() < k) {
                heap.push(-e.second);
                continue;
            }
            
            if (heap.top() > -e.second) {
                heap.pop();
                heap.push(-e.second);
            }
        }
        
        // Get results
        vector<int> res;
        for (auto &e : hash) {
            if (e.second >= -heap.top())
                res.push_back(e.first);
        }
        
        return res;
    }
};

int main(void) {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> res = Solution().topKFrequent(nums, k);
    for (auto &e : res)
        cout << e << ", ";
    cout << endl;
    
    return 0;
}