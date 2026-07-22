#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    void createPath(int row, int col, string& seq, vector<string>& ans, vector<vector<int>>& maze,
                    vector<vector<int>>& visited) {
        int n = maze.size();
        visited[row][col] = 1;
        if (row == n - 1 && col == n - 1) {
            ans.push_back(seq);
            return;
        }
        int delrow[] = {1, 0, 0, -1};
        int delcol[] = {0, -1, 1, 0};
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (isValid(nrow, ncol, n) && maze[nrow][ncol] == 1 && !visited[nrow][ncol]) {
                switch (i) {
                    case 0:
                        seq.push_back('D');
                        break;
                    case 1:
                        seq.push_back('L');
                        break;
                    case 2:
                        seq.push_back('R');
                        break;
                    case 3:
                        seq.push_back('U');
                        break;
                    default:
                        break;
                }
                createPath(nrow, ncol, seq, ans, maze, visited);
                visited[nrow][ncol] = 0;
                seq.pop_back();
            }
        }
    }

    bool isValid(int row, int col, int n) {
        return (row >= 0 && col >= 0 && row < n && col < n);
    }

   public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;
        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
            return ans;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        string seq;
        createPath(0, 0, seq, ans, maze, visited);
        return ans;
    }
};