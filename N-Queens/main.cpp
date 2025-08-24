class Solution {
private:
    vector<vector<string>> result;
    int n;

    bool isValid(int x,int y, vector<string>& board) {

        for(int i =0 ;i<x;i++) if(board[i][y] == 'Q') return false; // same column
        
        int i = x-1;
        int j = y+1;

        while(i >= 0 && j < n) {
            if(board[i--][j++] == 'Q') return false;
        }

        i = x-1;
        j = y-1;

        while(i >= 0 && j >=0) {
            if(board[i--][j--] == 'Q') return false;
        }
        
        bool up = (x > 0) ? board[x-1][y] == '.' : true;
        bool upLeft = (y > 0 && x > 0) ? board[x-1][y-1] == '.' : true; 
        bool upRight = (y+1 < n && x > 0) ? board[x-1][y+1] == '.' : true;

        return up && upLeft && upRight; 
    }

    void printBoard(const vector<string>& board) {
        cout << "board : ";

        for(const string& s: board) {
            cout << s << " ";
        }
        cout << endl;
    }

    void dfs(int queens, vector<string> board) {
        if(queens == n) {
            result.push_back(board);
            return;
        }

        for(int j = 0;j<n;j++) {
            if(board[queens][j] == '.' && isValid(queens,j,board)) {
                board[queens][j] = 'Q';
                dfs(queens+1,board);
                board[queens][j] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        string s;
        for(int i = 0;i<n;i++) s += ".";

        vector<string> board(n,s);
        this-> n = n;

        dfs(0,board);

        return result;

    }
};
