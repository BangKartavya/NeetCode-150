#include <cstring>

class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            int n = 9;

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    board[i][j] = (board[i][j] == '#') ? 0 : (board[i][j] - '0');
                }
            }

            // check row

            for(int i = 0; i < n; i++) {
                int freq[10];
                memset(freq, 0, sizeof(freq));
                for(int j = 0; j < n; j++) {
                    freq[board[i][j]]++;
                }

                for(int k = 0; k < 10; k++)
                    if(freq[k] > 1) return false;
            }

            // check col

            for(int j = 0; j < n; j++) {
                int freq[10];
                memset(freq, 0, sizeof(freq));
                for(int i = 0; i < n; i++) {
                    freq[board[i][j]]++;
                }

                for(int k = 0; k < 10; k++)
                    if(freq[k] > 1) return false;
            }

            // check the 3x3

            for(int l = 0; l < n; l += 3) {
                for(int k = 0; k < n; k += 3) {
                    int freq[10];
                    memset(freq, 0, sizeof(freq));

                    for(int i = k; i < k + 3; i++) {
                        for(int j = l; j < l + 3; j++) {
                            freq[board[i][j]]++;
                        }
                    }

                    for(int z = 0; z < 10; z++)
                        if(freq[z] > 1) return false;
                }
            }

            return true;
        }
};
