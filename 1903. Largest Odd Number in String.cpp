//TLE
class Solution {
public:
    string largestOddNumber(string num) {
        if(num.back() % 2 == 1){
            return num;
        }
        int i = num.length() - 1;
        while(i >= 0){
            int n = num[i];
            if(n % 2 == 1){
                return num.substr(0,i+1);
                i--;
            }
        }
        return "";
    }
};

//Optimised
class Solution {
public:
    string largestOddNumber(string num) {
        int end = num.size() - 1;
        while (end >= 0 && !(num[end] & 1)) {
            end--;
        }
        return num.substr(0, end + 1);
    }
};