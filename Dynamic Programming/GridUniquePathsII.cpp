
int Solution::solve(vector<vector<int> > &A) {
    int row = A.size();
    int col = A[0].size();
    int mod = 1000000007;
    vector<vector<int>> dp(row, vector<int> (col, 0));
    for(int i = 0; i < row;  i++) {
        if(A[i][0] == 1) {
            break;
        }
        dp[i][0] = 1;
    }
    for(int j = 0; j < col; j++) {
        if(A[0][j] == 1) {
            break;
        }
        dp[0][j] = 1;
    }
    for(int i = 1; i < row; i++) {
        for(int j = 1; j < col; j++) {
            if(A[i][j] == 1) {
                dp[i][j] = 0;
            }else {
                dp[i][j] = (dp[i-1][j]%mod + dp[i][j-1]%mod)%mod;
            }
        }
    }
    return dp[row-1][col-1];
}
