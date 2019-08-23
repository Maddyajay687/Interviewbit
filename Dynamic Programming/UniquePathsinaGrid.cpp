int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    vector<vector<int>> dp(A.size(), vector<int>(A[0].size(), 0));
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < A[0].size(); j++) {
            if(A[i][j] == 1) {
                A[i][j] = -1;
            }
        }
    }
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < A[0].size(); j++) {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    
    for(int i = 0; i < A.size(); i++) {
        if(A[i][0] == -1) {
            break;
        }
        dp[i][0] = 1;
    } 
    for(int j = 0; j < A[0].size(); j++) {
        if(A[0][j] == -1) {
            break;
        }
        dp[0][j] = 1;
    } 
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < A[0].size(); j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i = 1; i < A.size(); i++) {
        for(int j = 1; j < A[0].size(); j++) {
            if(A[i][j] == -1) {
                dp[i][j] = 0;
                continue;
            }
            
            if(A[i-1][j] == -1 && A[i][j-1] == -1) {
                dp[i][j] = 0;
            } else if(A[i-1][j] == -1 && A[i][j-1] != -1) {
                dp[i][j] = A[i][j-1];
            } else if(A[i-1][j] != -1 && A[i][j-1] == -1) {
                dp[i][j] = A[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    } 
    
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < A[0].size(); j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[A.size()-1][A[0].size()-1];
}
