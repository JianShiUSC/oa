/*
给一个int[][]的matirx，对于一条从左上到右下的path pi，pi中的最小值是mi，求所有mi中的最大值。只能往下或右.

[8, 4, 7]
[6, 5, 9]
有3条path：
8-4-7-9 min: 4
8-4-5-9 min: 4
8-6-5-9 min: 5
return: 5
*/
// dp
??????
int helper(vector<vector<int>> matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    vector<int> res(col, 0);

    for(int i = 1; i < col; i++) {
        res[i] = min(res[i-1], matrix[0][i]);
    }

    for(int i = 1; i < row; i++) {
        res[0] = min(matrix[i][0], res[0]);
        for(int j = 1; j < col; j++) {
            res[j] = (res[j] < matrix[i][j] && res[j-1] < matrix[i][j]) ? max(res[j-1], res[j]) : matrix[i][j];
        }
    }
    return res.back();
}

// dfs
class maximumMinimumPath {
private:
    int minV, maxV, row, col;
public:
    void dfsHelper(vector<vector<int>>& matrix, int minValue, int i, int j) {
        if(i >= row || j >= col) return;
        if(i == row - 1 && j == col - 1) {
            minValue = min(minValue, matrix[i][j]);
            maxV = max(maxV, minValue);
            return;
        }
        minValue = min(minValue, matrix[i][j]);
        dfsHelper(matrix, minValue, i, j+1);
        dfsHelper(matrix, minValue, i+1, j);
    }
    int maxMinPath(vector<vector<int>> matrix) {
        row = matrix.size();
        col = matrix[0].size();
        minV = INT_MAX;
        maxV = INT_MIN;
        dfsHelper(matrix, minV, 0, 0);
        return maxV;
    }
};
