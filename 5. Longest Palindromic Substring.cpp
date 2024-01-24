//Brute Force:
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) {
            return s;
        }

        int maxLength = 1;  // Length of the longest palindromic substring
        int start = 0;      // Starting index of the longest palindromic substring

        // Check all possible substrings
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // Check if the substring [i, j] is a palindrome
                if (isPalindrome(s, i, j) && j - i + 1 > maxLength) {
                    start = i;
                    maxLength = j - i + 1;
                }
            }
        }

        return s.substr(start, maxLength);
    }

private:
    // Helper function to check if a substring is a palindrome
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            ++start;
            --end;
        }
        return true;
    }
};

//Dynamic Programming approach:
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) {
            return s;
        }

        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

        // All substrings of length 1 are palindromes
        for (int i = 0; i < n; ++i) {
            isPalindrome[i][i] = true;
        }

        int start = 0; // Start index of the longest palindromic substring
        int maxLength = 1; // Length of the longest palindromic substring

        // Check substrings of length 2
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                isPalindrome[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }

        // Check substrings of length 3 or more
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1; // Ending index of the substring

                // Check if the substring is a palindrome and the inner substring is also a palindrome
                if (isPalindrome[i + 1][j - 1] && s[i] == s[j]) {
                    isPalindrome[i][j] = true;
                    start = i;
                    maxLength = len;
                }
            }
        }

        return s.substr(start, maxLength);
    }
};