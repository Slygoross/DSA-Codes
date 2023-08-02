//Brute Force: (TLE)
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n =nums.size();
    int maxi = *max_element(nums.begin(), nums.end());

    for (int d = 1; d <= maxi; d++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ceil((double)(nums[i]) / (double)(d)); // ceil function returns the smallest integer that is greater than or equal to the value passed as the argument (i.e.: rounds up the nearest integer)
        }
        if (sum <= threshold)
            return d;
    }
    return -1;
    }
};

// Optimal
class Solution {
public:
    int sumbyD(vector<int> nums, int div){
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ceil((double)(nums[i]) / (double)(div)); // ceil function returns the smallest integer that is greater than or equal to the value passed as the argument (i.e.: rounds up the nearest integer)
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n =nums.size();
        if(n > threshold){
            return -1;
        }
        int low = 1; int high = *max_element(nums.begin(), nums.end());
        while(low<=high){
            int mid = (low+high)/2;
            if(sumbyD(nums,mid) <= threshold){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};