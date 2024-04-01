class Solution {
public:

    void genCombSum(int index, int target, vector<int> &current, vector<vector<int>> &result, vector<int> &candidates){
        if(index == candidates.size()){
            if(target == 0){
                result.push_back(current);
            }
            return;
        }

        //picking element:
        if(candidates[index] <= target){
            current.push_back(candidates[index]);
            genCombSum(index, target - candidates[index], current, result, candidates);
            current.pop_back();   
        }

        // Not Picking Element:
        genCombSum(index + 1, target, current, result, candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        genCombSum(0,target,current,result,candidates);
        return result;
    }
};