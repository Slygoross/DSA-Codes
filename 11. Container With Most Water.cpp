//O(N2) (TLE)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0;
        int area = 0;
        for(int i = 0; i < height.size(); i++){
            for(int j = i + 1; j < height.size(); j++){
                int minheight = min(height[i],height[j]);
                area = (j-i) * minheight;
                maxarea = max(area, maxarea);
            }
        }
        return maxarea;
    }
};

// Two-Pointer Approach:
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;

        int area = 0;
        int maxArea = 0;

        while(i < j){
            area = min(height[i],height[j]) * (j-i);
            maxArea = max(area, maxArea);

            if(height[i] <= height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxArea;
    }
};