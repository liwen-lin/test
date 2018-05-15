//
//  test_solution.cpp
//  test
//
//  Created by Liwen Lin on 7/13/17.
//  Copyright © 2017 Liwen Lin. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <memory>

using namespace std;

#define STRINGIZE(x) #x

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution1 {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head)
            return NULL;
        
        ListNode *p1, *p2;
        p1 = p2 = head;
        p2 = p2->next;
        while (p1 != p2 && p1 != NULL && p2 != NULL) {
            p1 = p1->next;
            p2 = p2->next;
            if (p2)
                p2 = p2->next;
        }
        
        if (p1 == NULL || p2 == NULL)
            return NULL;
        else {
            p2 = head;
            p1 = p1->next;
            while (p1 != p2) {
                p1 = p1->next;
                p2 = p2->next;
            }
            return p1;
        }
    }
};

class Solution2 {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;
        
        vector<int> wc_s1(26, 0);
        vector<int> int_s2(s2.length());
        
        for (int i = 0; i < s2.length(); i++)
            int_s2[i] = s2.at(i)-'a';
        
        for (int i = 0; i < s1.length(); i++)
            wc_s1[s1.at(i)-'a']++;
        
        for (int i = 0; i <= (s2.length()-s1.length()); i++) {
            if (wc_s1[int_s2[i]] == 0)
                continue;
            
            int j, i1;
            vector<int> wc_s1_tmp = wc_s1;
            for (j = 0, i1 = i; j < s1.length() && i1 < s2.length(); j++, i1++) {
                if (wc_s1_tmp[int_s2[i1]] == 0)
                    break;
                else {
                    wc_s1_tmp[int_s2[i1]]--;
                }
            }
            
            if (j == s1.length())
                return true;
        }
        
        return false;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)
            return head;
        
        int n = 0;
        ListNode *node = head;
        
        // Node count
        while (node) {
            n++;
            node = node->next;
        }
        
        // List array
        ListNode **A = new ListNode*[n];
        node = head;
        for (int i = 0; i < n; i++) {
            A[i] = node;
            node = node->next;
        }
        
        // Move flag
        vector<bool> flag(n, false);
        int pre, next;
        ListNode *cur_next, *pre_next;
        for (int i = 0; i < k && i < n; i++) {
            if (flag[i])
                continue;
            
            pre = i;
            next = (pre+k)%n;
            pre_next = A[pre];
            do {
                cur_next = A[next];
                A[next] = pre_next;
                pre_next = cur_next;
                flag[pre] = true;
                pre = next;
                next = (pre+k)%n;
            } while (flag[pre] == false);
        }
        
        for (int i = 0; i < n-1; i++) {
            A[i]->next = A[i+1];
        }
        A[n-1]->next = NULL;
        
        return A[0];
    }
};

int fun4(int x, int y) {
    if (0 == x)
        return 0;
    
    if (1 == x)
        return y;
    
    return fun4(x-1, y) + fun4(x-2, y);
    
}

void fun5(int *a) {
    shared_ptr<int> sp_a(a);
    int t = 5;
    t = t++;
    return;
}

enum TEST_ENUM{
    a = -1,
    b,
};

int main(int argc, const char * argv[])
{
    TEST_ENUM te = b;
    
    vector<int> aab(10);
    cout << &(aab[0]) << ", " << &(aab[1]) << ", " << &(aab[5]) << endl;
    aab.insert(aab.end(), 5, 100);
    cout << &(aab[0]) << ", " << &(aab[1]) << ", " << &(aab[5]) << endl;
    
    int a = 3;
    int b = 4;
    int c;
    if (a < b)
        goto LOC1;
    else
        goto DONE;
LOC1:
    c = a-b;
DONE:
    c = b-a;
        
    int res = fun4(7, 2);
    
    
    int A1[5][10];
    int (*A)[5];
    //*A[1] = 5;
    
    int *aa = new int(5);
    fun5(aa);
    *aa = 10;
    
    
    Solution s;
    
    /*
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    n1->next = n2;
    n2->next = n1;
     
    s.detectCycle(n1);
    

    string s1, s2;
    //s1 = "adc"; s2 = "dcda";
    s1 = "ab"; s2 = "ab";
    s.checkInclusion(s1, s2);
    */
    
    int k = 1;
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    n1->next = n2;
    ListNode *newn = s.rotateRight(n1, k);
    while (newn) {
        cout << newn->val << endl;
        newn = newn->next;
    }
    
    return 1;
}


