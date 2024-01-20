//Optimal:
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int> ans;

        int low = 0;
        int high = n-1;

        while(low<high){
            int s = numbers[low] + numbers[high];
            if( s == target){
                ans.push_back(low+1);
                ans.push_back(high+1);
                return ans;
            }
            else if(s > target){
                high--;
            }
            else{
                low++;
            }

        }
        return ans;
    }
};