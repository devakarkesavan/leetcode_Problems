class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int m = goal.length();
        if(n!=m){
            return false;
        }
        string str = s+s;
        if(str.find(goal) != string::npos){
            return true;
        }
        return false;
    }
};