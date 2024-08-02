class Solution {
public:
    int maximumProduct(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int k  = arr[n-1]*arr[n-2]*arr[n-3];
        int p = arr[0]*arr[1]*arr[n-1];
        return max(k,p);
    }
};