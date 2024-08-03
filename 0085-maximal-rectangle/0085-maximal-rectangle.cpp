class Solution {
public:
    void fun(vector<int>his,int &maxi){
        int n = his.size();
        for(int i=0;i<n;i++){
            int breadth = 1;
            for(int j=i-1;j>=0;j--){
                if(his[j] >= his[i]){
                    breadth++;
                }
                else{
                    break;
                }
            }
            for(int j=i+1;j<n;j++){
                if(his[j]>=his[i]){
                    breadth++;
                }
                else{
                    break;
                }
            }
            maxi = max(maxi,his[i]*breadth);
        }
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n  = matrix.size();
        int m = matrix[0].size();
        vector<int>his(m,0);
        int maxi = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    his[j]++;
                }
                else{
                    his[j] = 0;
                }
            }
            fun(his,maxi);
        }
        return maxi;
    }
};