class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n = 0;
        for(auto it:logs){
            if(it=="../" && n!=0){
                n--;
            }
            else if(it=="./"){
                continue;
            }
            else if(it!="../"){
                n++;
            }
        }
        return n;
    }
};