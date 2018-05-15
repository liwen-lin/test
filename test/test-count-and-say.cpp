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
    string countAndSay(int n) {
        string str = "1";
        for (int i = 1; i < n; i++) {
            string new_str;
            int k = 0;
            char pre = str.at(k++);
            int cnt = 1;
            while (k < str.length()) {
                if (pre == str.at(k))
                    cnt++;
                else {
                    new_str.push_back('0'+cnt);
                    new_str.push_back(pre);
                    pre = str.at(k);
                    cnt = 1;
                }
                
                k++;
            }
            
            if (cnt) {
                new_str.push_back('0'+cnt);
                new_str.push_back(pre);
            }
            
            str = new_str;
        }
        
        return str;
    }
};

int main(void) {
    string str = "hello world ";
    int n = str.length()-1-str.find_last_not_of(' ');
    
    
    cout << Solution().countAndSay(5) << endl;
    
    return 0;
}