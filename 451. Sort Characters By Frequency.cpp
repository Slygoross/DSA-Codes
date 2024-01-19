class Solution {
public:
    string frequencySort(string s) {
        if(s.length() == 0){
            return "";
        }

        int n = s.length();
        unordered_map<char, int> m;
        string ans = "";

        for(int i = 0; i < n; i++){
            m[s[i]]++;
        }

        vector<vector<char>> bucket(n+1);
        for(auto it = m.begin(); it != m.end(); it++){
            bucket[it->second].push_back(it->first);
        }

        for(int j = n; j >= 0; j--){
            if(ans.length() >= s.length()){
                break;
            }
            if(!bucket[j].empty()){
                for(char ch : bucket[j]){
                    ans += string(j, ch);
                }
            }
        }
        return ans;
    }
};