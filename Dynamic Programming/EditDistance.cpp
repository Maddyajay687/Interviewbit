int solve(string A, int len1, string B, int len2) {
   //Recursive Approach
   /* if(len1 == 0) {
        return len2;
    } 
    if(len2 == 0) {
        return len1;
    }
    if(A[len1-1] == B[len2-1]) {
        return solve(A,len1-1,B, len2-1);
    }
    else {
        return 1 + min(solve(A, len1-1, B, len2), 
                min(solve(A, len1, B, len2-1), solve(A, len1-1, B, len2-1)));
    }*/
    vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
    
    for(int i = 0; i <= len1; i++) {
        dp[i][0] = i;
    }
    for(int j = 0; j <= len2; j++) {
        dp[0][j] = j;
    }
    for(int i = 1; i <= len1; i++) {
        for(int j = 1; j <= len2; j++) {
            if(A[i-1] == B[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else{
                dp[i][j] = 1 + min(dp[i-1][j], 
                    min(dp[i][j-1], dp[i-1][j-1]));
            }
        }
    }
 /*   for(auto i : dp) {
        for(auto data : i) {
            cout<<data<<" ";
        }
        cout<<endl;
    } */
    
    return dp[len1][len2];
}

int Solution::minDistance(string A, string B) {
    int len1 = A.length();
    int len2 = B.length();
    
    return solve(A, len1, B, len2);
}
