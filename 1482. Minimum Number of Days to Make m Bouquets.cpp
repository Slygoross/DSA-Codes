//Brute Force:
class Solution {
public:
    bool possible(vector<int> bloomDay, int day, int m, int k){
        int n = bloomDay.size();
        int cnt = 0;
        int noOfB = 0;

        for(int i = 0; i < n; i++){
            if(bloomDay[i] <= day){
                cnt++;
            }
            else{
                noOfB += (cnt/k);
                cnt = 0;
            }
        }
        noOfB += (cnt/k);
        return noOfB >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1ll * k * 1ll;
    int n = bloomDay.size(); //size of the array
    if (val > n) return -1; //impossible case.
    //find maximum and minimum:
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        mini = min(mini, bloomDay[i]);
        maxi = max(maxi, bloomDay[i]);
    }

    for (int i = mini; i <= maxi; i++) {
        if (possible(bloomDay, i, m, k))
            return i;
    }
    return -1;
    }
};

// Optimal 
class Solution {
public:
    bool possible(vector<int> bloomDay, int day, int m, int k){
        int n = bloomDay.size();
        int cnt = 0;
        int noOfB = 0;

        for(int i = 0; i < n; i++){
            if(bloomDay[i] <= day){
                cnt++;
            }
            else{
                noOfB += (cnt/k);
                cnt = 0;
            }
        }
        noOfB += (cnt/k);
        return noOfB >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1ll * k * 1ll;
    int n = bloomDay.size(); //size of the array
    if (val > n) return -1; //impossible case.
    //find maximum and minimum:
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        mini = min(mini, bloomDay[i]);
        maxi = max(maxi, bloomDay[i]);
    }

    for (int i = mini; i <= maxi; i++) {
        if (possible(bloomDay, i, m, k))
            return i;
    }
    return -1;
    }
};