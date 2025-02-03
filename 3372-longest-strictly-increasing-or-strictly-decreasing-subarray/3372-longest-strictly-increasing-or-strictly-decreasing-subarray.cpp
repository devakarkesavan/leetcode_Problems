class Solution {
public:
    int longestMonotonicSubarray(vector<int>& arr) {
        int count = 1;
        int maxi1 = 1;
        int n = arr.size();
        int prev= arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]>prev){
                count++;
            }
            else{
                count=1;
            }
            prev = arr[i];
            maxi1 = max(count,maxi1);
        }
        int prev1 = arr[0];
        int count1 = 1;
        int maxi2 = 1;
        for(int i=1;i<n;i++){
            if(arr[i]<prev1){
                count1++;
            }
            else{
                count1 = 1;
            }
            prev1 = arr[i];
            maxi2 = max(count1,maxi2);
        }
        return max(maxi1,maxi2);
        
    }
};