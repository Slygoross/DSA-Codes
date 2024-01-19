class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);    
        vector<int> leftProducts(n,1);
        vector<int> rightProducts(n,1);

        int leftProduct = 1;
        for(int i = 0; i < n; i++){
            leftProducts[i] = leftProduct;
            leftProduct *= nums[i];
        }

        int rightProduct = 1;
        for(int i = n - 1; i >= 0; i--){
            rightProducts[i] = rightProduct;
            rightProduct *= nums[i];
        }

        for(int i = 0; i < n; i++){
            ans[i] = leftProducts[i]*rightProducts[i];
        }

        return ans;
    }
};