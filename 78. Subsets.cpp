class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        vector<vector<int>> result;
        generateSubset(nums,0,current,result);
        return result;
    }
private:
    void generateSubset(vector<int> &nums, int index, vector<int> &current, vector<vector<int>> &result){
        result.push_back(current);
        for(int i = index; i < nums.size(); i++){
            current.push_back(nums[i]);
            generateSubset(nums,i+1,current,result);
            current.pop_back();
        }
    }
};