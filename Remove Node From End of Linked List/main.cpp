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
            if(!head) return nullptr;

            if(!head->next) return (n == 0) ? head : nullptr;

            ListNode* temp = head;
            int cnt = 0;

            while(temp) {
                temp = temp->next;
                cnt++;
            }

            if(n == cnt) return head->next;

            temp = new ListNode(-1);
            temp->next = head;
            for(int i = 0; i < cnt - n; i++) {
                cout << "i : " << i << endl;
                cout << "temp : " << temp->val << endl;
                temp = temp->next;
            }

            temp->next = temp->next->next;

            return head;
        }
};
