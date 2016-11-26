// leetcode 74
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int beginRow = 0;
        int endRow = row - 1;
        int currentRow = -1;

        while(beginRow <= endRow) {
            int midRow = beginRow + (endRow - beginRow) / 2;
            if(matrix[midRow][0] == target) {
                return true;
            } else if(matrix[midRow][0] > target) {
                endRow = midRow - 1;
            } else {
                if(matrix[midRow][col - 1] < target) {
                    beginRow = midRow + 1;
                } else if(matrix[midRow][col - 1] == target) {
                    return true;
                } else {
                    currentRow = midRow;
                    break;
                }
            }
        }

        if(currentRow == -1) return false;

        int beginCol = 0;
        int endCol = col - 1;
        while(beginCol <= endCol) {
            int midCol = beginCol + (endCol - beginCol) / 2;
            if(matrix[currentRow][midCol] == target) return true;
            else if(matrix[currentRow][midCol] < target) {
                beginCol = midCol + 1;
            } else {
                endCol = midCol - 1;
            }
        }
        return false;
    }
};
