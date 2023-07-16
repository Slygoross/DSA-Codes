//Brute Force:
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        
        for(int i = 0; i < n; i++){
            if (ans.size() == 0 || ans[0] != nums[i]){
                int cnt = 0;
                for(int j = 0; j < n; j++){
                    if(nums[i]==nums[j]){
                        cnt++;
                    }
                }
                if(cnt>(n/3)){
                    ans.push_back(nums[i]);
                }
            }
            if(ans.size()==2){
                break;
            }
        }
        return ans;
    }
};

// Better 
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        map<int,int> mpp;
        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
        }

        for(auto it : mpp){
            if(it.second>(n/3)){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};

// Optimal
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       int n = nums.size();

    int cnt1 = 0, cnt2 = 0; // counts
    int el1 = INT_MIN; // element 1
    int el2 = INT_MIN; // element 2


    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && el2 != nums[i]) {
            cnt1 = 1;
            el1 = nums[i];
        }
        else if (cnt2 == 0 && el1 != nums[i]) {
            cnt2 = 1;
            el2 = nums[i];
        }
        else if (nums[i] == el1) cnt1++;
        else if (nums[i] == el2) cnt2++;
        else {
            cnt1--, cnt2--;
        }
    }

    vector<int> ls; 
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == el1) cnt1++;
        if (nums[i] == el2) cnt2++;
    }

    int mini = int(n / 3) + 1;
    if (cnt1 >= mini) ls.push_back(el1);
    if (cnt2 >= mini) ls.push_back(el2);

    return ls;
    }
};