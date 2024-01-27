//Pulkit Approach:
class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int left[n],right[n];
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(maxi,arr[i]);
            left[i] = maxi;
        }
        maxi = INT_MIN;
        for(int i=n-1;i>=0;i--){
            maxi = max(maxi,arr[i]);
            right[i] = maxi;
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            ans += (min(left[i],right[i])-arr[i]);
        }
        return ans;
    }
};