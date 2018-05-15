//
//  test-convert-bst-greater-tree.cpp
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
#include "list-node.hpp"

using namespace std;


class Solution {
public:
    
    void traverse(TreeNode *root, int &greater_num) {
        if (root)
            return;
        
        traverse(root->right, greater_num);
        root->val += greater_num;
        greater_num = root->val;
        traverse(root->left, greater_num);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int greater_num = 0;
        traverse(root, greater_num);
        
        return root;
    }
};


int main(void) {

    return 0;
}