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
        // Using extra space , T.C - O(n) , S.C - O(n)
        int n=0;
        ListNode* temp=head;
        while(temp!=NULL){
            n++;
            temp = temp->next;
        }
        if(n<=2)return head;
        vector<int> arr;
        temp = head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        temp=head;
        for(int i=0;i<n;i++){
            if(i%2==0){
                temp->val = arr[i];
                temp = temp->next;
            }
        }
        for(int i=0;i<n;i++){
            if(i&1){
                temp->val = arr[i];
                temp = temp->next;
            }
        }
        return head;
    }
};