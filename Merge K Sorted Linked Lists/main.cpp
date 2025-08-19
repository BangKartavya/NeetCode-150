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
    private:
        ListNode* merge(ListNode* a, ListNode* b) {
            if(!a) return b;
            if(!b) return a;

            ListNode* temp1 = a;
            ListNode* temp2 = b;

            ListNode* newList = new ListNode(-1);
            ListNode* temp3 = newList;

            while(temp1 && temp2) {
                if(temp1->val <= temp2->val) {
                    temp3->next = temp1;
                    temp1 = temp1->next;
                } else {
                    temp3->next = temp2;
                    temp2 = temp2->next;
                }

                temp3 = temp3->next;
            }

            while(temp1) {
                temp3->next = temp1;
                temp1 = temp1->next;
                temp3 = temp3->next;
            }
            while(temp2) {
                temp3->next = temp2;
                temp2 = temp2->next;
                temp3 = temp3->next;
            }

            return newList->next;
        }

    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            if(lists.size() == 0) return nullptr;
            ListNode* first = lists[0];
            int n = lists.size();

            for(int i = 1; i < n; i++) {
                first = merge(first, lists[i]);
            }

            return first;
        }
};
