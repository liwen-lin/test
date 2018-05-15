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
    
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        
        vector<TreeNode*> level;
        level.push_back(root);
        while (!level.empty()) {
            // Check symmetry
            int s, e;
            s = 0; e = level.size()-1;
            while (s <= e) {
                if ((!level[s] && !level[e]) ||
                    (level[s] && level[e] && level[s]->val == level[e]->val)) {
                    s++; e--;
                } else {
                    return false;
                }
            }
            
            vector<TreeNode*> next_level;
            for (int i = 0; i < level.size(); i++) {
                if (level[i]) {
                    next_level.push_back(level[i]->left);
                    next_level.push_back(level[i]->right);
                }
            }
            
            level = next_level;
        }
        
        return true;
    }
};

int main(void) {
    TreeNode n[7];
    vector<int> nums = {1,2,2,3,4,4,3};
    for (int i = 0; i < nums.size(); i++)
        n[i].val = nums[i];
    n[0].left = n+1;
    n[0].right = n+2;
    n[1].left = n+3;
    n[1].right = n+4;
    n[2].left = n+5;
    n[2].right = n+6;
    Solution().isSymmetric(n);
    
    
    return 0;
}