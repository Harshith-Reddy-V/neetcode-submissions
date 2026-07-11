class Solution {
public:
    // Helper function to check if a specific substring is a pure palindrome
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        
        while (l < r) {
            if (s[l] != s[r]) {
                // We found a mismatch. We must try both options:
                // 1. Skip the left character: check substring from l+1 to r
                // 2. Skip the right character: check substring from l to r-1
                return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
            }
            l++;
            r--;
        }
        return true;
    }
};