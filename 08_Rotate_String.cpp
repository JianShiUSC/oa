/*
Given two words, find if second word is the round rotation of first word.
For example: abc, cab
return 1
since cab is round rotation of abc

Example2: ab, aa
return -1
since ab is not round rotation for aa
*/
bool isRotation(string s1, string s2) {
    int size = s1.size();
    if(s2.size() == size && !s1.empty()) {
        for(int i = 0; i < size; i++) {
            if(s1[i] != s2[size-i-1]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

int main() {
    string s1 = "abc";
    string s2 = "cbs";
    cout << isRotation(s1, s2) << endl;
}
