/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    public:
        Node* copyRandomList(Node* head) {
            unordered_map<Node*, Node*> mp;

            Node* temp = head;

            while(temp) {
                mp[temp] = new Node(temp->val);
                temp = temp->next;
            }

            Node* newList = new Node(-1);
            Node* newTemp = newList;
            temp = head;

            while(temp) {
                newTemp->next = mp[temp];
                newTemp->next->random = mp[temp->random];

                newTemp = newTemp->next;
                temp = temp->next;
            }

            return newList->next;
        }
};
