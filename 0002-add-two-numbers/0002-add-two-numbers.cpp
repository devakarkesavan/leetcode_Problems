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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode= new ListNode(-1);
        ListNode* dummyHead = dummyNode;
        ListNode* list1 = l1;
        ListNode* list2 = l2;
        int carry = 0;
        while(list1 || list2){
            int sum = carry;
            if(list1){
                sum+=list1->val;
            }
            if(list2){
                sum+=list2->val;
            }
            ListNode* newNode = new ListNode(sum%10);
            carry = sum/10;
            dummyNode->next = newNode;
            dummyNode = newNode;

            if(list1){
                list1 = list1->next;
            }
            if(list2){
                list2 = list2->next;
            }
        }
        if(carry){
            dummyNode->next = new ListNode(carry);
            dummyNode = dummyNode->next;
        }
        return dummyHead->next;
    }
};