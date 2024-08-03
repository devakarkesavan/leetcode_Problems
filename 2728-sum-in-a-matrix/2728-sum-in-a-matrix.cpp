class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        int k = m;
        int sum = 0;
        while(k--){
            int maxi = 0;
        for(int i=0;i<n;i++){
            pair<int,int>it = {0,0};
            for(int j=0;j<m;j++){
                if(nums[i][j] >it.first){
                    it.first = nums[i][j];
                    it.second = j;
                }
            }
            maxi = max(maxi,it.first);
            nums[i][it.second] = -1;  
        }
        sum+=maxi;
        }
        return sum;
    }
};