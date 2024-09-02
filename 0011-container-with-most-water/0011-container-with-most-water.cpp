class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0,right = n-1;
        int maxi = 0;
        while(left<=right){
            int val = min(height[left],height[right]);
            int area = val * (right-left);
            maxi = max(area,maxi);
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxi;
    }
};