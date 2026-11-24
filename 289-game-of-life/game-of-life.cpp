
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> ans = board;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                int count = 0;

                if(j+1 <= m-1 && board[i][j+1] == 1)
                    count++;

                if(j+1 <= m-1 && i+1 <= n-1 && board[i+1][j+1] == 1)
                    count++;

                if(i+1 <= n-1 && board[i+1][j] == 1)
                    count++;

                if(i+1 <= n-1 && j-1 >= 0 && board[i+1][j-1] == 1)
                    count++;

                if(j-1 >= 0 && board[i][j-1] == 1)
                    count++;

                if(j-1 >= 0 && i-1 >= 0 && board[i-1][j-1] == 1)
                    count++;

                if(i-1 >= 0 && board[i-1][j] == 1)
                    count++;

                if(j+1 <= m-1 && i-1 >= 0 && board[i-1][j+1] == 1)
                    count++;

                if(count < 2) {
                    ans[i][j] = 0;
                }
                else if(count == 3) {
                    ans[i][j] = 1;
                }
                else if(count > 3) {
                    ans[i][j] = 0;
                }
            }
        }

        board = ans;
    }
};
