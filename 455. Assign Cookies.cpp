//Two Pointer Approach:
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int count = 0;
        int l1 = 0;
        int l2 = 0;

        while(l1 < g.size() && l2 < s.size()){
            if(g[l1] <= s[l2]){
                count++;
                l1++;
            }
            l2++;
        }
        return count;
    }
};