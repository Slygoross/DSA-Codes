// Brute Force: O(N^3)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(); 
    int cnt = 0;

    for (int i = 0 ; i < n; i++) { 
        for (int j = i; j < n; j++) { 
            int sum = 0;
            for (int K = i; K <= j; K++)
                sum += nums[K];
            if (sum == k)
                cnt++;
        }
    }
    return cnt;
    }
};

// Better O(N^2)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;

        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                if(sum==k){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

//Optimal O(N) or O(N*logN)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int,int> mpp;
    int preSum = 0, cnt = 0;

    mpp[0] = 1;
    for (int i = 0; i < n; i++) {
        preSum += nums[i];
        int remove = preSum - k;
        cnt += mpp[remove];
        mpp[preSum] += 1;
    }
    return cnt;
    }
};