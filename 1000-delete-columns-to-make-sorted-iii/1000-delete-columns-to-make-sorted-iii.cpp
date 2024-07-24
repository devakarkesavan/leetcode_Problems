class Solution {
public:
    	int rows,cols;
    vector<vector<int>>dp;
    
    int solve(vector<string>&v,int currentIndex,int prevIndex){
        
        if(currentIndex==cols){
            return 0;
        }
        
        if(dp[currentIndex][prevIndex]!=-1)return dp[currentIndex][prevIndex];
        
        int ans=INT_MAX;
        if(prevIndex==cols){
            ans=min(solve(v,currentIndex+1,currentIndex),1+solve(v,currentIndex+1,prevIndex));
        }
        else{
            int canKeep=1;     
            for(int i=0;i<rows;i++){
                if(v[i][currentIndex]<v[i][prevIndex]){
                    canKeep=0;
                    break;
                }
            }
            if(canKeep)ans=min(ans,solve(v,currentIndex+1,currentIndex));
			
            ans=min(ans,1+solve(v,currentIndex+1,prevIndex));
        }
        
        return dp[currentIndex][prevIndex]=ans;
    }
    
    int minDeletionSize(vector<string>& strs) {
        rows=strs.size();
        cols=strs[0].size();
        dp.resize(cols+1,vector<int>(cols+1,-1));
        return solve(strs,0,cols);
    }
};