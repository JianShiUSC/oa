string removeVowel(string str) {
    string res;
    unordered_set<char> ss = {'a','e','i','o','u','A','E','I','O','U'};
    for(int i = 0; i < str.size(); i++) {
        if(ss.find(str[i]) == ss.end()) {
            res += str[i];
        }
    }
    return res;
}

int main() {
    string str = "abcde";
    cout << removeVowel(str) << endl;
}
