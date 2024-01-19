// NlogN Approach (Mine)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int longestLength = 1;
        int runningLength = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] != nums[i-1]){
                if(nums[i] == nums[i-1] + 1){
                    runningLength++;
                }
                else{
                    longestLength = max(longestLength,runningLength);
                    runningLength = 1;
                }
            }
            
        }
        return max(longestLength,runningLength);
    }
};