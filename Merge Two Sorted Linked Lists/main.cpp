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
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode* temp1 = list1;
            ListNode* temp2 = list2;

            ListNode* merged = new ListNode(-1);
            ListNode* mergedTemp = merged;

            while(temp1 && temp2) {
                if(temp1->val <= temp2->val) {
                    mergedTemp->next = temp1;
                    temp1 = temp1->next;
                } else {
                    mergedTemp->next = temp2;
                    temp2 = temp2->next;
                }

                mergedTemp = mergedTemp->next;
            }

            while(temp1) {
                mergedTemp->next = temp1;
                temp1 = temp1->next;
                mergedTemp = mergedTemp->next;
            }

            while(temp2) {
                mergedTemp->next = temp2;
                temp2 = temp2->next;
                mergedTemp = mergedTemp->next;
            }

            return merged->next;
        }
};
