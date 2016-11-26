vector<int> getSum(vector<int> A, int k) {
    vector<int> res;
    int size = A.size();
    for(int i = 0; i + k - 1 < size; i++) {
        int sum = 0;
        for(int j = 0; j < k; j++) {
            sum += A[i+j];
        }
        res.insert(res.begin() + i, sum);
    }
    return res;
}

int main() {
    vector<int> A = {1,2,3,4,5};
    getSum(A, 2);
}
