//Brute O(N)
class Solution {
public:
    int findPeakElement(vector<int>& nums){
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if((i==0 || nums[i]>nums[i-1]) && (i==n-1 || nums[i]>nums[i+1])){
                return i;
            }
        }
        return -1;
    }
};

//Optimal
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return 0;
        }
        if(nums[0]>nums[1]){
            return 0;
        }
        if(nums[n-1]>nums[n-2]){
            return n-1;
        }
        int s = 1; int e = n-2;
        while(s<=e){
            int mid = (s+e)/2;
            //Checking if mid is the peak:
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
                return mid;
            }
            //if we are left of peak:
            if(nums[mid]>nums[mid-1]){
                s = mid + 1;
            }
            //if we are right of peak:
            else{
                e = mid - 1;
            }

        }
        return -1;
    }
};