// Pointers Solution (TLE)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0); // Initialize ans with zeros
        for (int i = 0; i < temperatures.size(); i++) {
            int count = 0;
            int j = i + 1;
            while (j < temperatures.size() && temperatures[j] <= temperatures[i]) {
                count++; // Increment count if the temperature at j is not warmer
                j++;
            }
            if (j < temperatures.size()) // If there's a warmer day ahead
                ans[i] = count + 1; // Count includes the next day
        }
        return ans;
    }
};