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

// Stack Solution
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        
        // pair: [index, temp]
        stack<pair<int, int>> stk;
        vector<int> result(n);
        
        for (int i = 0; i < n; i++) {
            int currDay = i;
            int currTemp = temperatures[i];
            
            while (!stk.empty() && stk.top().second < currTemp) {
                int prevDay = stk.top().first;
                int prevTemp = stk.top().second;
                stk.pop();
                
                result[prevDay] = currDay - prevDay;
            }
            
            stk.push({currDay, currTemp});
        }
        
        return result;
    }
};