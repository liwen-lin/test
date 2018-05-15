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

using namespace std;

class Solution {
public:
    bool is_alphanumeric(char &c) {
        return (
                (c >= 'a' && c <= 'z') ||
                (c >= 'A' && c <= 'Z') ||
                (c >= '0' && c <= '9')
                );
    }
    
    void capitilize(char &c) {
        if (c >= 'a' && c <= 'z')
            c = c - 'a' + 'A';
    }
    
    bool isPalindrome(string s) {
        int b, e;
        b = 0;
        e = s.length()-1;
        while (b < e) {
            while (b < e && !is_alphanumeric(s.at(b))) b++;
            while (b < e && !is_alphanumeric(s.at(e))) e--;
            
            char c1, c2;
            c1 = s.at(b);
            c2 = s.at(e);
            capitilize(c1);
            capitilize(c2);
            if (c1 != c2)
                return false;
            
            b++;
            e--;
        }
        
        return true;
    }
};

int main(void) {
    string str = "A man, a plan, a canal: Panama";
    Solution().isPalindrome(str);
    
    return 0;
}