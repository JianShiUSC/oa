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


public class Solution {
	public String longestPalindrome(String s) {
		if(s == null || s.length() == 0) {
			return "";
		}
		int length = s.length();
		String res = String.valueOf(s.charAt(0));
		int max = 1;
		for(int i = 1; i < length; i++) {
			if(i-max >= 0 && isPalindrome(s.substring(i-max, i+1))) {
				res = s.substring(i-max, i+1);
				max = max + 1;
			} else if(i-max-1 >= 0 && isPalindrome(s.substring(i-max-1, i+1))) {
				res = s.substring(i-max-1, i+1);
				max = max+2;
			}
		}
		return res;
	}
	public boolean isPalindrome(String s) {
		int left = 0, right = s.length() - 1;
		char[] array = s.toCharArray();
		while(left < right) {
			if(array[left++] != array[right--]) {
				return false;
			}
		}
		return true;
	}

	public static void main(String[] args) {
		Solution sol = new Solution();
		String s = sol.longestPalindrome("babab");
		System.out.println(s);
	}
}
