bool isSafe(vector<vector<int>> &board, int i, int j, int n) {
    for(int row  = 0; row < n; row++) {
        if(board[row][j] == 1) {
            return false;
        }
    }
    
    int x = i;
    int y = j;
    while(x >= 0 && y >= 0) {
        if(board[x--][y--] == 1) {
            return false;
        }
    }
    x = i; 
    y = j;
    while(x >= 0 && y < n) {
        if(board[x--][y++] == 1) {
            return false;
        }
    }
    
    return true;
}

bool solve(vector<vector<int>> &board,vector<vector<string>> &ans, int i, int n) {
    if(i == n) {
        vector<string> temp;
        for(int i = 0; i < n; i++) {
            string str = "";
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 1) {
                    str.push_back('Q');
                } else {
                    str.push_back('.');
                }
            }
            temp.push_back(str);
        }
        ans.push_back(temp);
        return false;
    }
    for(int j = 0; j < n; j++) {
        if(isSafe(board, i, j, n)){
            board[i][j] = 1;
            if(solve(board, ans, i+1, n)) {
                return true;
            }
            board[i][j] = 0;
        }
    }
    
    return false;
}

vector<vector<string> > Solution::solveNQueens(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<string>> ans;
    vector<vector<int>> board(A, vector<int>(A, 0));
    
    solve(board, ans, 0, A);
    
    return ans;
    
}
