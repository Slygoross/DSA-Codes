//Brute Force O(N + N/2)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos;
        vector<int> neg;

        for(int i = 0; i < n; i++){
            if(nums[i]>0){
                pos.push_back(nums[i]);
            }
            else{
                neg.push_back(nums[i]);
            }
        }

        for(int i = 0; i < n/2; i++){
            nums[2*i] = pos[i];
            nums[2*i+1] = neg[i];
        }

        return nums;
    }
};

//Optimal O(N)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int posIdx = 0;
        int negIdx = 1;
        vector<int> ans(n,0);
        for(int i = 0; i < n; i++){
            if(nums[i]>0){
                ans[posIdx] = nums[i];
                posIdx+=2;
            }

            if(nums[i]<0){
                ans[negIdx] = nums[i];
                negIdx+=2;
            }
        }
        return ans;
    }
};