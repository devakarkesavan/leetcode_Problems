/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        vector<int>ans;
        int sum = 0;
        ListNode* temp = head;
        while(temp){
            if(temp->val==0 && sum!=0){
                ans.push_back(sum);
                sum = 0;
            }
            else{
                sum+=temp->val;
            }
            temp = temp->next;
        }
        if(sum){
            ans.push_back(sum);
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* ans1 = dummy;
        for(int i=0;i<ans.size();i++){
            ListNode* tmp = new ListNode(ans[i]);
            dummy->next = tmp;
            dummy = tmp;
        }
        return ans1->next;
        
    }
};