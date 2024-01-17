//Hashmap Approach:
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            freq[nums[i]]++;
        }

        vector<vector<int>> bucket(n+1);
        for(auto it = freq.begin(); it != freq.end(); it++){
            bucket[it->second].push_back(it->first);
        }

        for(int i = n; i >= 0; i--){
            if(ans.size() >= k){
                break;
            }
            if(!bucket[i].empty()){
                ans.insert(ans.end(), bucket[i].begin(), bucket[i].end());
            }
        }
        return ans;
    }
};

//