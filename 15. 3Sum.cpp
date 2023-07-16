//Brute Force (TLE)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        vector<int> temp = {nums[i],nums[j],nums[k]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> ans{st.begin(),st.end()};
        return ans;
    }
};

//Better (TLE)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;

        for(int i = 0; i < n; i++){
            set<int> hashset;
            for(int j = i + 1; j < n; j++){
                int third = -(nums[i] + nums[j]);
                if(hashset.find(third) != hashset.end()){
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[j]);
            }
        }
        vector<vector<int>> ans{st.begin(),st.end()};
        return ans;
    }
};

//Optimal
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res; 
        sort(nums.begin(), nums.end()); 
        
        
        for (int i = 0; i < (int)(nums.size())-2; i++) {
            
            if (i == 0 || (i > 0 && nums[i] != nums[i-1])) {
                
                int lo = i+1, hi = (int)(nums.size())-1, sum = 0 - nums[i];
                
                while (lo < hi) {
                    if (nums[lo] + nums[hi] == sum) {
                        
                        vector<int> temp; 
                        temp.push_back(nums[i]); 
                        temp.push_back(nums[lo]); 
                        temp.push_back(nums[hi]); 
                        res.push_back(temp);
                        
                        while (lo < hi && nums[lo] == nums[lo+1]) lo++;
                        while (lo < hi && nums[hi] == nums[hi-1]) hi--;
                        
                        lo++; hi--;
                    } 
                    else if (nums[lo] + nums[hi] < sum) lo++;
                    else hi--;
               }
            }
        }
        return res;
    }
};
