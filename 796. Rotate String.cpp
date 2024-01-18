//optimal approach:
class Solution {
public:
    void reverse(string& s, int start, int end){
        while(start < end){
            swap(s[start],s[end]);
            start++;
            end--;
        }
    }

    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()){
            return false;
        }

        for(int i = 0; i < s.length(); i++){
            reverse(s,0,s.length()-1);
            reverse(s,1,s.length()-1);
            if(s ==  goal){
                return true;
            }
        }
        return false;
    }
};