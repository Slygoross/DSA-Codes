class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        validP(n,0,0,"",result);
        return result;
    }
private:
    void validP(int n, int open, int close, string curr, vector<string> &result){

        // Base Case:
        if(open == n && close == n){
            result.push_back(curr);
            return;
        }

        // Recursive Case:
        if(open < n){
            validP(n, open + 1, close, curr + "(", result);
        }

        if(close < open){
            validP(n, open, close + 1, curr + ")", result);
        }
    }
};