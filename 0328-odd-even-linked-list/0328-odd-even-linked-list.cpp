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
    ListNode* oddEvenList(ListNode* head) {
        // using Optimal , T.C - O(n) , S.C - O(1)
        if(head==NULL || head->next==NULL || head->next->next==NULL){
            return head;
        }
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* evenHead=head->next;
        while(even!=NULL && even->next!=NULL){
            odd->next = even->next;
            odd=odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};