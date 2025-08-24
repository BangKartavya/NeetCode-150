class Solution {
    private:
        int dirX[4] = {0, -1, 0, 1};
        int dirY[4] = {1, 0, -1, 0};

        vector<vector<char>> board;
        vector<vector<bool>> vis;
        int n;
        int m;
        string word;

        bool dfs(int x, int y, string curr) {
            if(curr.size() > word.size()) return false;

            if(curr == word) return true;

            for(int i = 0; i < 4; i++) {
                int newX = x + dirX[i];
                int newY = y + dirY[i];

                if(newX < 0 || newX >= n || newY < 0 || newY >= m) continue;

                if(!vis[newX][newY]) {
                    vis[newX][newY] = true;
                    curr.push_back(board[newX][newY]);
                    if(dfs(newX, newY, curr)) return true;
                    curr.pop_back();
                    vis[newX][newY] = false;
                }
            }

            return false;
        }

    public:
        bool exist(vector<vector<char>>& board, string word) {
            if(board.size() * board[0].size() < word.size()) return false;
            this->board = board;
            this->word = word;
            n = board.size();
            m = board[0].size();
            vis.resize(n, vector<bool>(m, false));
            string s;

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    for(int x = 0; x < n; x++) {
                        for(int y = 0; y < m; y++)
                            vis[x][y] = false;
                    }
                    s.push_back(board[i][j]);

                    if(dfs(i, j, s)) return true;
                    s.pop_back();
                }
            }

            return false;
        }
};
