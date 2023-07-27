//Brute Force O(N)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        for(int i = 0; i < n; i++){
            mini = min(mini,nums[i]);
        }
        return mini;
    }
};

//Better (using binary search) O(logN)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n - 1;
        int ans = INT_MAX;

        while(s<=e){
            int mid = (s + e)/2;

            if(nums[s]<=nums[mid]){
                ans = min(ans, nums[s]);
                s = mid + 1;
            }
            else{
                ans = min(ans,nums[mid]);
                e = mid - 1;
            }
        }
        return ans;
    }
};
