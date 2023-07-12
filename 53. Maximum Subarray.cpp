//Brute Force O(N^3)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += nums[k];
            }
            maxi = max(maxi, sum);
        }
    }

    return maxi;
    }
};

//Better (Using Prefix Sum) O(N^2)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            maxi = max(maxi, sum);
        }
    }

    return maxi;
    }
};

//Optimal (Kadane's Algorithm) O(N)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cs = 0;
	int largest = INT_MIN;
	bool flag = false;
	for(int i = 0; i < nums.size(); i++)
	{
	    if(nums[i]>0)
	    {
	        flag = true;
	        break;
	    }
	    if(nums[i]>largest)
	    {
	        largest = nums[i];
	    }
	}
	if(flag==false)
	{
	    return largest;
	}
	largest = 0;

	for(int i = 0; i < nums.size(); i++)
	{
		cs = cs + nums[i];
		if(cs < 0)
		{
			cs = 0;
		}
		largest = max(largest, cs);
	}
	return largest;
    }
};

