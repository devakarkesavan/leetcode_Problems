class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int maxi = INT_MIN;
        int p  = 1;
        for(int i=0;i<arr.size();i++){
            p = p*arr[i];
            maxi = max(maxi,p);
            if(p==0){
                p = 1;
            }
        }
        p = 1;
        for(int i=arr.size()-1;i>=0;i--){
            p = p*arr[i];
            maxi = max(maxi,p);
            if(p==0){
                p = 1;
            }
        }
        return maxi;
    }
};