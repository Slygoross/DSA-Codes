//Bruteforce(TLE)
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }

        double ans = 1;
        
        if (n > 0) {
            for (int i = 0; i < n; i++) {
                ans *= x;
            }
        } else {
            for (int i = 0; i > n; i--) {
                ans /= x;
            }
        }
        
        return ans;
    }
};

//Optimal (Binary Exponentiation)
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
  long long nn = n;
  if (nn < 0) nn = -1 * nn;
  while (nn) {
    if (nn % 2) {
      ans = ans * x;
      nn = nn - 1;
    } else {
      x = x * x;
      nn = nn / 2;
    }
  }
  if (n < 0) ans = (double)(1.0) / (double)(ans);
  return ans;
    }
};

// Recursive:
class Solution {
public:
    double myPow(double x, int n) {
        //Base Case: if n = 0, return 1;
        if(n == 0){
            return 1;
        }
        //Recursive Case:
        double half = myPow(x,n/2);
        if(n%2 == 0){ // odd
            return half * half;
        }
        else if(n%2 == 1){ //even
            return half * half * x;
        }
        else{ // negative
            return (half * half)/x;
        }
    }
};