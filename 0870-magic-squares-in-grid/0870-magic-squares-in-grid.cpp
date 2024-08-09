class Solution {
public:
    bool isposs(vector<vector<int>>&arr,int i,int j){
        int n = arr.size();
        int m = arr[0].size();
        if(i+2 <n && j+2<m){
            int col1 = arr[i][j] + arr[i+1][j] + arr[i+2][j];
            int col2 = arr[i][j+1] + arr[i+1][j+1]+arr[i+2][j+1];
            int col3 = arr[i][j+2] + arr[i+1][j+2]+arr[i+2][j+2];
            int row1 = arr[i][j] + arr[i][j+1]+arr[i][j+2];
            int row2 = arr[i+1][j] + arr[i+1][j+1]+arr[i+1][j+2];
            int row3 = arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            int diag1 = arr[i][j] + arr[i+1][j+1] + arr[i+2][j+2];
            int diag2 = arr[i+2][j] + arr[i+1][j+1] + arr[i][j+2];
            if(col1==col2 && col1==col3 && col1==row1 && col1==row2 && col1==row3 && col1==diag1 && col1==diag2){
                set<int>st({1,2,3,4,5,6,7,8,9});
                for(int l=0;l<3;l++){
                    for(int k=0;k<3;k++){
                        st.erase(arr[i+l][j+k]);
                    }
                }
                return st.empty();
            }
        }
        return false;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int cnt = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(isposs(grid,i,j)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};