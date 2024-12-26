class Solution {
private:
    int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<int>prev(k+1,0),cur(k+1,0);
	prev[0] = cur[0] = 1;
        if (arr[0] <= k && arr[0] == 0) {
          prev[arr[0]] = 2;
        } else if (arr[0] <= k) {
          prev[arr[0]] = 1;
        }
        for(int ind=1;ind<n;ind++){
		for(int tar=0;tar<=k;tar++){
			int nottake = (prev[tar]);
			int take = 0;
			if(arr[ind]<=tar){
				take = (prev[tar-arr[ind]]);
			}
			cur[tar] = (take + nottake);
		}prev = cur;
	}
	return prev[k];
}
private:
    int countPartitions(int n, int d, vector<int> &arr) {
    int totsum = 0;
    for(int i=0;i<arr.size();i++){
        totsum+=arr[i];
    }
   
    if(totsum-d < 0 || (totsum-d)%2){
        return 0;
    }
    
    return findWays(arr, (totsum-d)/2);

}
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        return countPartitions(n,target,nums);
    }
};