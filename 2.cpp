/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * head = NULL;
        ListNode * rear = head;
        int c = 0;
        bool flag = false;
        while(l1||l2||c){
            int cur = c;
            c = 0;
            if(l1){
                cur += l1->val;
                l1 = l1->next;
            }
            if(l2){
                cur += l2->val;
                l2 = l2->next;
            }
            c = cur/10;
            ListNode * tmp = new ListNode(cur%10);
            if(!flag){
                flag = true;
                head = rear = tmp;
            }else{
                rear -> next = tmp;
                rear = tmp;
            }
        }
        return head;
    }
};
