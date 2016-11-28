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


vector<int> getSum(vector<int> A, int k) {
    vector<int> res;
    if(A.empty()) return res;
    int sum = 0;
    int size = A.size();

    for(int i = 0; i < size; i++) {
        if(i < k - 1) {
            sum += A[i];
        } else {
            sum += A[i];
            res.push_back(sum);
            sum -= A[i-k+1];
        }
    }
    return res;
}

int main() {
    vector<int> A = {1,2,3,4,5};
    getSum(A, 2);
}
