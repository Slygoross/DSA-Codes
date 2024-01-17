//Bruteforce:
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
        return "";
    }

    // Iterate through characters of the first string
    for (int i = 0; i < strs[0].size(); i++) {
        char currentChar = strs[0][i];

        // Check if the current character is common to all strings
        for (int j = 1; j < strs.size(); j++) {
            if (i >= strs[j].size() || strs[j][i] != currentChar) {
                // If not common, return the prefix found so far
                return strs[0].substr(0, i);
            }
        }
    }

    // If all characters match, return the entire first string as the common prefix
    return strs[0];
    }
};

//Optimal Approach:
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());

        string first = strs.front();
        string last = strs.back();

        int commonLength = 0;

        while(commonLength < first.length() && first[commonLength] == last[commonLength]){
            commonLength++;
        }

        return first.substr(0,commonLength);
    }
};