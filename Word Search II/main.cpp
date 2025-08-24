class TrieNode {
public:
    char value;
    bool isEnd;
    TrieNode* children[26];

    TrieNode(char val) {
        value = val;
        isEnd = false;

        for(int i =0 ;i<26;i++) children[i] = nullptr;
    }
};

class Trie {
private:
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode(-1);
    }

    void add(const string& word) {
        TrieNode* currNode = root;

        for(const char& ch: word) {
            if(!currNode->children[ch-'a']) currNode->children[ch-'a'] = new TrieNode(ch);
            currNode = currNode->children[ch-'a'];
        }

        currNode->isEnd = true;
    }

    bool search(const string& word) {
        TrieNode* currNode = root;

        for(const char& ch: word) {
            if(!currNode->children[ch-'a']) return false;
            currNode = currNode->children[ch-'a'];
        }

        return currNode->isEnd;
    }

};

class Solution {
private:
    vector<vector<char>> board;
    vector<vector<bool>> vis;
    unordered_set<string> result;
    int n;
    int m;

    int dirX[4] = {0,-1,0,1};
    int dirY[4] = {1,0,-1,0};


    void dfs(int i, int j, string word,TrieNode* curr) {
        if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || !curr->children[board[i][j]-'a']) return;

        vis[i][j] = true;

        curr = curr->children[board[i][j]-'a'];
        word.push_back(board[i][j]);

        if(curr->isEnd) result.insert(word);

        dfs(i+1,j,word,curr);
        dfs(i,j+1,word,curr);
        dfs(i-1,j,word,curr);
        dfs(i,j-1,word,curr);

        vis[i][j] = false;
        word.pop_back();
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* tr = new Trie();

        for(string& word: words) {
            tr->add(word);
        } 

        this->board = board;
        n = board.size();
        m = board[0].size();

        vis.resize(n,vector<bool>(m,false));

        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                dfs(i,j,"",tr->root);
            }
        }

        return vector<string>(begin(result),end(result));
    }
};
