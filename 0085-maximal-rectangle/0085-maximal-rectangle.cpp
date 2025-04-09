class Solution {
public:
    void fun(vector<int>his,int &maxi){
        int n = his.size();
        for(int i=0;i<n;i++){
            int b = 1;
            for(int j=i-1;j>=0;j--){
                if(his[i]<=his[j]){
                    b++;
                }
                else{
                    break;
                }
            }
            for(int j=i+1;j<n;j++){
                if(his[i]<=his[j]){
                    b++;
                }
                else{
                    break;
                }
            }
            maxi = max(maxi,b*his[i]);
        }
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxi = 0;
        vector<int>his(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    his[j]+=1;
                }
                else{
                    his[j]=0;
                }
            }
            fun(his,maxi);
        }
        return maxi;
    }
};