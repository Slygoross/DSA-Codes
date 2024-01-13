//Brute Force: (TLE)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
          int n = nums.size();

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[i] == nums[j]) {
                return true;
            }
        }
    }

    return false;
    }
};

//Better
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    vector<int> sortedNums = nums;
    sort(sortedNums.begin(), sortedNums.end());

    for (int i = 1; i < sortedNums.size(); ++i) {
        if (sortedNums[i - 1] == sortedNums[i]) {
            return true;
        }
    }
    return false;
    }
};

//Optimal
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) {
                return true;
            }
            s.insert(nums[i]);
        }
        
        return false;
    }
};