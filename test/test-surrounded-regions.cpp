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

using namespace std;

class Solution {
public:
    
    void dfs(vector<vector<char>> &board, int r, int c) {
        board[r][c] = 'P';
        int neighbors[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int r1, c1;
        for (int i = 0; i < 4; i++) {
            r1 = r+neighbors[i][0];
            c1 = c+neighbors[i][1];
            if (r1 >= 0 && r1 < board.size() &&
                c1 >= 0 && c1 < board[0].size() &&
                'O' == board[r1][c1]) {
                dfs(board, r1, c1);
            }
        }
    }
    
    
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if (!row)
            return;
        
        int col = board[0].size();
        // Row border
        for (int i = 0; i < row; i++) {
            if ('O' == board[i][0]) {
                dfs(board, i, 0);
            }
            
            if ('O' == board[i][col-1]) {
                dfs(board, i, col-1);
            }
        }
        
        // Col border
        for (int i = 0; i < col; i++) {
            if ('O' == board[0][i]) {
                dfs(board, 0, i);
            }
            
            if ('O' == board[row-1][i]) {
                dfs(board, row-1, i);
            }
        }
        
        // Change non-border element to 'O'
        for (int i = 1; i < row-1; i++) {
            for (int j = 1; j < col-1; j++)
                if ('O' == board[i][j])
                    board[i][j] = 'X';
        }
        // Change border element to 'X'
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++)
                if ('P' == board[i][j])
                    board[i][j] = 'P';
        }
        
        
    }
};

int main(void) {
    vector<vector<char>> data = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    Solution().solve(data);
    
    
    
    return 0;
}