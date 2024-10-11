class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        // vector<int>rightmax(n);
        // vector<int>leftmax(n);
        // leftmax[0] = height[0];
        // for(int i=1;i<n;i++){
        //     leftmax[i] = max(leftmax[i-1],height[i]);
        // }
        // rightmax[n-1] = height[n-1];
        // for(int i=n-2;i>=0;i--){
        //     rightmax[i] = max(rightmax[i+1],height[i]);
        // }
        // int sum = 0;
        // for(int i=0;i<n;i++){
        //     sum+= min(leftmax[i],rightmax[i]) - height[i];
        // }
        // return sum;
        int left = 0,right = n-1;
        int leftmax=0, rightmax =0, total = 0;
        while(left < right){
            if(arr[left]<=arr[right]){
            if(leftmax > arr[left]){
                total += leftmax-arr[left];
            }
            else{
                leftmax = arr[left];
            }
            left++;
            }
            else{
                if(rightmax > arr[right]){
                    total+=rightmax - arr[right];
                }
                else{
                    rightmax = arr[right];
                }
                right--;
            }
        }
        return total;
    }
};