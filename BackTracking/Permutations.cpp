void solve(vector<int> &A,vector<vector<int>> &ans, vector<int> &v) {
    if(A.size() == 0) {
        ans.push_back(v);
        return;
    } for(int i = 0; i < A.size(); i++) {
        int c = A[i];
        v.push_back(c);
        A.erase(A.begin()+i);
        solve(A, ans, v);
        A.insert(A.begin()+i, c);
        v.pop_back();
    }
}

vector<vector<int>> Solution::permute(vector<int> &A) {
    vector<vector<int>> ans;
    vector<int> v;
    solve(A, ans,v);
    return ans;
}
