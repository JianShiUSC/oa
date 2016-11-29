class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        int size = s.size();
        string res = string(1, s[0]);
        int maxLen = 1;

        for(int i = 1; i < size; i++) {
            if(i-maxLen >= 0 && isPalindrome(s.substr(i-maxLen, maxLen+1))) {
                res = s.substr(i-maxLen, maxLen+1);
                maxLen += 1;
            } else if(i-maxLen-1 >= 0 && isPalindrome(s.substr(i-maxLen-1, maxLen+2))) {
                res = s.substr(i-maxLen-1, maxLen+2);
                maxLen += 2;
            }
        }
        return res;
    }

    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while(left < right) {
            if(s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }
};
