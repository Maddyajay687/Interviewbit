bool comparator(vector<int> a, vector<int> b) {
    
}

void solve(vector<int>&A, set<vector<int>> &ans, vector<int> &temp, int i) {
    if(A.empty()) {
        ans.insert(temp);
    } else {
        int val = A[0];
        A.erase(A.begin());
        temp.push_back(val);
        solve(A, ans, temp, i);
        temp.pop_back();
        solve(A, ans, temp, i);
        A.insert(A.begin(), val);
    }
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    set<vector<int>> ans;
    vector<int> temp;
    vector<vector<int>> res;    
    solve(A, ans, temp, 0);
    
    for(auto i : ans) {
        sort(i.begin(), i.end());
        res.push_back(i);
    }
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    return res;
}
