bool solve(vector<int> &A, int B) {
    
    if(B == 0 || B == 1) {
        return true;
    }
    if(A[0] == 0) {
        return false;
    }
    int temp = A[0];
    for(int i = 1; i < B-1; i++) {
        if(i > temp) {
            return false;
        }
        temp = max(temp, i + A[i]);
    }
    return (temp >= B-1);
}

int Solution::canJump(vector<int> &A) {
    int n = A.size();
    
    return solve(A, n);
}
