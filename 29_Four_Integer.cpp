/*
Given four integers, make
F(S) = abs(S[0]-S[1]) + abs(S[1]-S[2]) + abs(S[2]-S[3]) to be largest.
*/
vector<int> solution(int A, int B, int C, int D) {
    vector<int> arr(4);
    arr[0] = A;
    arr[1] = B;
    arr[2] = C;
    arr[3] = D;

    sort(arr.begin(), arr.end());
    swap(arr[0], arr[1]);
    swap(arr[2], arr[3]);
    swap(arr[0], arr[3]);
    return arr;
}

int main() {
    solution(1, 2, 3, 4);
}
