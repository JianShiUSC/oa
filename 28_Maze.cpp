class Maze {
public:
    bool solution(vector<vector<int>> matrix) {
        vector<int> dx = {-1,0,0,1};
        vector<int> dy = {0,1,-1,0};
        if(matrix.empty()) return 0;
        if(matrix[0][0] == 9) return true;
        int row = matrix.size();
        int col = matrix[0].size();

        queue<pair<int, int>> qu;
        qu.push({0,0});
        matrix[0][0] = 0;   // mark it as visited

        while(!qu.empty()) {
            pair<int, int> cur = qu.front();
            qu.pop();
            for(int i = 0; i < 4; i++) {
                pair<int, int> next = {cur.first + dx[i], cur.second + dy[i]};
                if(next.first >= 0 && next.first < row && next.second >= 0 && next.second < col && matrix[next.first][next.second] != 0) {
                    if(matrix[next.first][next.second] == 9) {
                        return true;
                    } else {
                        qu.push(next);
                        matrix[next.first][next.second] = 0;
                    }
                }
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {{1,1,0,0},
                                  {0,1,1,0},
                                  {0,0,1,0},
                                  {0,0,0,9}};
    Maze sol;
    cout << sol.solution(matrix) << endl;
}
