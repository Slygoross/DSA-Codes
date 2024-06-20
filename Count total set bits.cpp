//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Your logic here
        
        if(n == 0){
            return 0;
        }
        int x = highPower(n);
        int btillx = (1 << x - 1)*x;
        int msbtofinal = n - (1 << x) + 1;
        int rem = n - (1 << x);
        int ans = btillx + msbtofinal + countSetBits(rem);
        return ans;
    }
    
    int highPower(int n){
        int x = 0;
        while((1 << x) <= n){
            x++;
        }
        return x-1;
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends