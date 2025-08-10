#include<bits/stdc++.h>
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1;
        int n = nums.size();
        for(int j=n-2;j>=0;j--){
            if(nums[j]<nums[j+1]){
                ind = j;
                break;
            }
        }
        if(ind==-1){
            reverse(nums.begin(),nums.end());
            
        }
        else{
        for(int j=n-1;j>=0;j--){
            if(nums[ind]<nums[j]){
                swap(nums[ind],nums[j]);
                break;
            }
        }
        reverse(nums.begin()+ind+1,nums.end());
        }
    }
};