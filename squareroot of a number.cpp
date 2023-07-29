// using sqrt function
// using binary search:
int floorSqrt(int n)
{
    // Write your code here.
    int s = 1;
    int e = n;
    while(s<=e){
        long long mid = (s+e)/2;
        long long val = mid * mid;
        if(val <= (long long)(n)){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    return e;
}
