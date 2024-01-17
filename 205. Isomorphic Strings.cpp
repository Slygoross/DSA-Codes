//hashmap approach:
class Solution {
public:
    bool isIsomorphic(string s, string t) {
         if (s.length() != t.length()) {
        return false;
    }

    unordered_map<char, char> sToTMapping;
    unordered_map<char, char> tToSMapping;

    for (int i = 0; i < s.length(); ++i) {
        char sChar = s[i];
        char tChar = t[i];

        // Check if sToTMapping already contains sChar
        if (sToTMapping.find(sChar) != sToTMapping.end()) {
            // If yes, make sure the mapping is consistent
            if (sToTMapping[sChar] != tChar) {
                return false;
            }
        } else {
            // If sChar is not in the mapping, check if tChar is already mapped
            if (tToSMapping.find(tChar) != tToSMapping.end()) {
                return false;
            }

            // Add the mapping for both sChar to tChar and tChar to sChar
            sToTMapping[sChar] = tChar;
            tToSMapping[tChar] = sChar;
        }
    }

    return true;
    }
};
//
