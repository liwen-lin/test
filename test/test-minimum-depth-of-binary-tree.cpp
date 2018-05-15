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
    void dfs(TreeNode *n, int &min_d, int cur_d) {
        if (!n)
            return;
        
        cur_d++;
        if (!(n->left) && !(n->right)) {
            min_d = min_d < cur_d ? min_d : cur_d;
            return;
        }
        if (cur_d >= min_d)
            return;
        
        if (n->left)
            dfs(n->left, min_d, cur_d);
        if (n->right)
        dfs(n->right, min_d, cur_d);
    }
    
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        
        int min_d = 1000000000;
        dfs(root, min_d, 0);
        return min_d;
    }
};

int main(void) {
    //vector<int> nums = {1,2};
    vector<int> nums;
    TreeNode *root = tree_create_from_vector(nums);
    cout << Solution().minDepth(root) << endl;
    
    return 0;
}