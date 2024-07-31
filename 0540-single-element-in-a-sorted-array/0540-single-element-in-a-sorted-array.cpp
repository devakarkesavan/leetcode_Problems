class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int xorr = 0;
        for(auto it:arr){
            xorr^=it;
        }
        return xorr;
    }
};