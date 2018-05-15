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

using namespace std;

struct DispenerStatus {
    int liters;
    int nat; // next available time
    int pre_nat; // previous
};

int find_next_available_dispenser(int a, DispenerStatus ds[3]) {
    int min_nat = 2000000000;
    int min_id = -1;
    for (int i = 0; i < 3; i++) {
        if (ds[i].liters >= a && ds[i].nat < min_nat) {
            min_id = i;
            min_nat = ds[i].nat;
        }
    }
    
    return min_id;
}

int solution(vector<int> &A, int X, int Y, int Z) {
    // write your code in C++14 (g++ 6.2.0)
    DispenerStatus ds[3] = {{X, 0, 0}, {Y, 0, 0}, {Z, 0, 0}};
    for (int i = 0; i < A.size(); i++) {
        int di = find_next_available_dispenser(A[i], ds);
        if (-1 == di)
            return -1;
        
        ds[di].liters -= A[i];
        ds[di].pre_nat = ds[di].nat;
        ds[di].nat += A[i];
        cout << i << ": A[i]:" << A[i] << ", d:" << di << ", l:" << ds[di].liters << ", pre_nat:" << ds[di].pre_nat << ", nat:" << ds[di].nat << endl;
    }
    
    // Find max of pre_nat
    int max_pre_nat = ds[0].pre_nat;
    for (int i = 1; i < 3; i++) {
        if (ds[i].pre_nat > max_pre_nat)
            max_pre_nat = ds[i].pre_nat;
    }
    
    return max_pre_nat;
}

int main(void) {
    vector<int> A = {2, 8, 4, 3, 2};
    vector<int> d = {17, 111, 31};
    //vector<int> d = {7, 11, 3};
    cout << solution(A, d[0], d[1], d[2]) << endl;
    
    return 0;
}