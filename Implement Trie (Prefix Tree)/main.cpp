class TrieNode {
    public:
        char value;
        bool isEnd;
        TrieNode* children[26];

        TrieNode(char val) {
            value = val;
            isEnd = false;

            for(int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
};

class PrefixTree {
    private:
        TrieNode* root;

    public:
        PrefixTree() {
            root = new TrieNode(-1);
        }

        void insert(string word) {
            TrieNode* currNode = root;

            for(char& ch : word) {
                if(!currNode->children[ch - 'a']) {
                    currNode->children[ch - 'a'] = new TrieNode(ch);
                }

                currNode = currNode->children[ch - 'a'];
            }

            currNode->isEnd = true;
        }

        bool search(string word) {
            TrieNode* currNode = root;

            for(char& ch : word) {
                if(!currNode->children[ch - 'a']) return false;

                currNode = currNode->children[ch - 'a'];
            }

            return currNode->isEnd;
        }

        bool startsWith(string prefix) {
            TrieNode* currNode = root;

            for(char& ch : prefix) {
                if(!currNode->children[ch - 'a']) return false;

                currNode = currNode->children[ch - 'a'];
            }

            return true;
        }
};
