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

void dfs(vector<vector<int>> &m, int r, int c, int &gs) {
    int neighbors[4][2] = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };
    m[r][c] = 2;
    gs++;
    for (int i = 0; i < 4; i++) {
        int r1 = r + neighbors[i][0];
        int c1 = c + neighbors[i][1];
        if (r1 >= 0 && r1 < m.size() && c1 >=0 && c1 < m[0].size() && 1 == m[r1][c1])
            dfs(m, r1, c1, gs);
    }
    
}

vector<int> countGroups(vector<vector<int>> m, vector<int> t) {
    // <group_size, count>
    unordered_map<int, int> gs_map;
    int row = m.size();
    int col = m[0].size();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (1 == m[i][j]) {
                int gs = 0;
                dfs(m, i, j, gs);
                gs_map[gs]++;
            }
        }
    }
    
    vector<int> res(t.size(), 0);
    for (int i = 0; i < t.size(); i++) {
        res[i] = gs_map[t[i]];
    }
    
    return res;
}

int main(void) {
    vector<vector<int>> m = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
        {1, 1, 1, 1, 0, 0, 0, 0, 0, 0,},
        {1, 1, 1, 0, 0, 0, 0, 1, 1, 1,},
        {1, 1, 0, 0, 1, 0, 0, 1, 1, 1,},
        {1, 0, 1, 0, 0, 1, 1, 0, 0, 0,},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
    };
    vector<int> t = {1, 10, 20, 2, 6};
    vector<int> res = countGroups(m, t);
    
    cout << "hello" << endl;
    return 0;
}