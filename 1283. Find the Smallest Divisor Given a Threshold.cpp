//Brute Force:
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