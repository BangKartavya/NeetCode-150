#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
    public:
        int key;
        int value;

        Node* next;
        Node* prev;

        Node(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
};

class LRUCache {
    private:
        Node* head;
        Node* tail;
        int capacity;
        unordered_map<int, Node*> mp;

        void remove(Node* node) {
            Node* prev = node->prev;
            Node* next = node->next;

            prev->next = next;
            next->prev = prev;
        }

        void insert(Node* newNode) {
            Node* prev = tail->prev;
            tail->prev = newNode;
            newNode->next = tail;
            newNode->prev = prev;
            prev->next = newNode;
        }

    public:
        LRUCache(int capacity) {
            this->capacity = capacity;
            head = new Node(-1, -1);
            tail = new Node(-1, -1);

            head->next = tail;
            tail->prev = head;
        }

        int get(int key) {
            if(mp.find(key) == mp.end()) return -1;

            Node* node = mp[key];
            remove(node);
            insert(node);

            return node->value;
        }

        void put(int key, int value) {
            if(mp.find(key) != mp.end()) remove(mp[key]);

            Node* newNode = new Node(key, value);
            mp[key] = newNode;
            insert(newNode);

            if(mp.size() > capacity) {
                Node* first = head->next;
                remove(first);
                mp.erase(first->key);
                delete first;
            }
        }
};
