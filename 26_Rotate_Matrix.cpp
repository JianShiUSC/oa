class Rotate {
private:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> rvalue(row, vector<int>(col, 0));

        for(int i = 0; i < col; i++) {
            for(int j = 0; j < row; j++) {
                rvalue[i][j] = matrix[j][i];
            }
        }
        return rvalue;
    }

    void flip(vector<vector<int>>& matrix, int flag) {
        int row = matrix.size();
        int col = matrix[0].size();
        if(flag == 1) {     // clockwise
            for(int i = 0; i < row; i++) {
                for(int j = 0; j < col / 2; j++) {
                    swap(matrix[i][j], matrix[i][col-j-1]);
                }
            }
        } else {
            for(int i = 0; i < row/2; i++) {
                for(int j = 0; j < col; j++) {
                    swap(matrix[i][j], matrix[row-i-1][j]);
                }
            }
        }
    }
public:
    vector<vector<int>> Solution(vector<vector<int>> matrix, int flag) {
        if(matrix.empty()) return matrix;
        vector<vector<int>> rvalue = transpose(matrix);
        flip(rvalue, flag);
        return rvalue;
    }
};

int main() {
    vector<vector<int>> matrix = {{1,2,3,4},
                                  {5,6,7,8},
                                  {9,10,11,12},
                                  {13,14,15,16}};
    Rotate sol;
    sol.Solution(matrix, 1);
}
