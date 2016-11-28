/*
Given two hexadecimal numbers find if they can be consecutive in gray code
    For example: 10001000, 10001001
    return 1, since they are successive in gray code

    Example2: 10001000, 10011001
    return -1, since they are not successive in gray code.
*/
typedef bitset<8> byte;

class GrayCode {
public:
    // if can be placed consecutively return 1 else 0
    int grayCheck(byte term1, byte term2) {
        byte rst = (byte)(term1 ^ term2);   // XOR operation by bit, for gray code there is only one diff between two terms
        for(int i = 0; i <= 7; i++) {
            byte tmp = (byte)(1 << i);
            if(tmp == rst) return 1;
        }
        return 0;
    }
};

int main() {
    byte term1 = (byte)0x88, term2 = (byte)0x89;
    GrayCode gc;
    int out = gc.grayCheck(term1, term2);
    cout << out << endl;
}
