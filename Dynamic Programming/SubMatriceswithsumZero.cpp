void find(vector<int> &v, int *count) {
    unordered_map<int, int> mp;
    int sum = 0;
    //mp[0]++;
    for(auto i : v) {
        sum = sum + i;
        if(sum == 0) {
            *count = *count +1;
        }
        *count  = *count + mp[sum];
        mp[sum]++;
    }
}

int Solution::solve(vector<vector<int> > &A) {
    if(A.size() == 0) {
        return 0;
    }
    int row = A.size();
    int col = A[0].size();
    int count = 0;    
    for(int i = 0; i < row; i++) {
        vector<int> v(col, 0);
        for(int j = i; j < row; j++) {
            for(int k = 0; k < col; k++) {
                v[k]+=A[j][k];
            }
            find(v, &count);
        }
    }
    return count;
}
