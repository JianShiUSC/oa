class GCD {
private:
    int gcdF(int num1, int num2) {
        if(num1 == 0) return num2;
        if(num2 == 0) return num1;

        if(num1%2 == 0 && num2%2 == 0) {
            return 2*gcdF(num1>>1, num2>>1);
        } else if(num1%2 == 0) {
            return gcdF(num1>>1, num2);
        } else if(num2%2 == 0) {
            return gcdF(num1, num2>>1);
        } else {
            return gcdF(abs(num1 - num2), min(num1, num2));
        }
    }
public:
    int result(vector<int> arr) {
        if(arr.empty()) return 0;
        int gcd = arr[0];
        for(int i = 1; i < arr.size(); i++) {
            gcd = gcdF(gcd, arr[i]);
        }
        return gcd;
    }
};

int main() {
    vector<int> arr = {13,26,39};
    GCD sol;
    cout << sol.result(arr) << endl;
}
