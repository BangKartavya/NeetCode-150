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

class WordDictionary {
    private:
        TrieNode* root;

        bool dfs(int i, string word, TrieNode* currNode) {
            if(i == word.size()) {
                return currNode->isEnd;
            }

            if(word[i] == '.') {
                for(int j = 0; j < 26; j++) {
                    if(currNode->children[j]) {
                        if(dfs(i + 1, word, currNode->children[j])) return true;
                    }
                }
                return false;
            }

            if(!currNode->children[word[i] - 'a']) return false;

            return dfs(i + 1, word, currNode->children[word[i] - 'a']);
        }

    public:
        WordDictionary() {
            root = new TrieNode(-1);
        }

        void addWord(string word) {
            TrieNode* currNode = root;

            for(char& ch : word) {
                if(!currNode->children[ch - 'a']) currNode->children[ch - 'a'] = new TrieNode(ch);
                currNode = currNode->children[ch - 'a'];
            }

            currNode->isEnd = true;
        }

        bool search(string word) {
            return dfs(0, word, root);
        }
};
