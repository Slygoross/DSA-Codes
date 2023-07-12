//Brute Force
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int n = prices.size();

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(prices[i]<prices[j]){
                    maxPro = max(prices[j]-prices[i],maxPro);
                }
            }
        }

        return maxPro;
    }
};

//Optimal O(N)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for(int i = 0; i < prices.size(); i++){
            minPrice = min(minPrice,prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }
};