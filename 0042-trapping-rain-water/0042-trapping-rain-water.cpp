class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int left = 0,right = n-1,leftmax = arr[0],rightmax = arr[n-1],tot = 0;
        while(left<right){
            if(arr[left]<=arr[right]){
                if(arr[left]<=leftmax){
                    tot+=leftmax-arr[left];
                }
                else{
                    leftmax = arr[left];
                }
                left++;
            }
            else{
                if(arr[right]<=rightmax){
                    tot+=rightmax-arr[right];
                }
                else{
                    rightmax = arr[right];
                }
                right--;
            }
        }
        return tot;
    }
};