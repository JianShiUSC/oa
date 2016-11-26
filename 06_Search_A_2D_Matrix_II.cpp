// leetcode 240
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int row = matrix.size(), col = matrix[0].size();
        int curRow = 0, curCol = col - 1;
        while(curRow < row && curCol >= 0) {
            if(matrix[curRow][curCol] == target) return true;
            else if(matrix[curRow][curCol] > target) curCol--;
            else curRow++;
        }
        return false;
    }
};
