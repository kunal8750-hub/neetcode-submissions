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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*  temp = head;
        int count = 0;

        while(temp){
            count++;
            temp = temp->next;
        }
        int k = count-n;
    
        if(k==0){
            ListNode* nextnode = head->next;
            delete head;
            return nextnode;
        }
        temp = head;
        for(int i=0; i<k-1; i++){
            temp = temp->next;
        }
        ListNode* deletenode = temp->next;
        temp->next = deletenode->next;
        delete deletenode;

        return head;
    }
};
