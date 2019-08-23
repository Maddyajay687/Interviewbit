void solve(int n, int K, vector<vector<int>> &ans, vector<int> &temp, int index) {
    if(temp.size() == K) {
        ans.push_back(temp);
    }
    for(int i = index; i <= n; i++) {
        temp.push_back(i);
        solve(n, K, ans, temp, i+1);
        temp.pop_back();
    }
}

vector<vector<int> > Solution::combine(int A, int B) {
    
    vector<vector<int>> ans;
    vector<int> temp;
    solve(A, B, ans, temp, 1);
    sort(ans.begin(), ans.end());
    
    return ans;
}
