class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = 0;
        double chef = customers[0][0];
        for(auto it:customers){
            int st = it[0];
            int tak  = it[1];
            if(chef<st){
                chef = st;
            }
            chef+=tak;
            ans+=(chef-st);
        }
        return ans/(double)customers.size();
    }
};