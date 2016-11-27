/*
Given an array, return the number of possible arithmetic sequence.
给一个数组，返回可能的等差数列个数。
*/
int getLAS(vector<int> A) {
    if(A.size() < 3) return 0;
    int res = 0;
    int diff = INT_MIN;
    int count = 0;
    int start = 0;

    for(int i = 1; i < A.size(); i++) {
        int curDiff = A[i] - A[i-1];
        if(diff == curDiff) {
            count += i - start - 1 > 0 ? i - start - 1 : 0;
        } else {
            start = i-1;
            diff = curDiff;
            res += count;
            count = 0;
        }
    }
    res += count;
    return res;
}

int main() {
    vector<int> A = {1,2,3,4,5};
    cout << getLAS(A) << endl;
}
