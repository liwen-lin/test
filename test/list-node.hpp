//
//  list-node.hpp
//  test
//
//  Created by Qian Fan on 06/05/2018.
//  Copyright © 2018 Qian Fan. All rights reserved.
//

#ifndef list_node_hpp
#define list_node_hpp

#include <stdio.h>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode() : val(0), left(NULL), right(NULL) {}
};


static ListNode *create_from_vector(vector<int> &nums) {
    ListNode head(0), *p = &head;
    for (int i = 0; i < nums.size(); i++) {
        p->next = new ListNode(nums[i]);
        p = p->next;
    }
    
    return head.next;
}

#define null 0xFFFFFFFF

static TreeNode *tree_create_from_vector(vector<int> &nums) {
    if (nums.empty())
        return NULL;
    
    vector<TreeNode*> tree_array(nums.size());
    
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == null)
            continue;
        
        tree_array[i] = new TreeNode(nums[i]);
    }

    int n_at_level = 1;
    int s = 0;
    while (s < nums.size()) {
        for (int i = s; ((i < s+n_at_level) && i < nums.size()); i++) {
            if ((2*i+1) < nums.size())
                tree_array[i]->left = tree_array[2*i+1];
            if ((2*i+2) < nums.size())
                tree_array[i]->right = tree_array[2*i+2];
        }
        
        s += n_at_level;
        n_at_level *= 2;
    }
    
    return tree_array[0];
}



#endif /* list_node_hpp */
