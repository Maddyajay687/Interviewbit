void solve(vector<int> &A, vector<vector<int>> &ans, vector<int> &temp, int sum, int index) {
    if(sum == 0) {
        ans.push_back(temp);
        return;
    }
    while(index < A.size() && (sum-A[index]) >= 0) {
        temp.push_back(A[index]);
        solve(A,ans,temp,sum-A[index],index);
        index++;
        temp.pop_back();
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    vector<vector<int>> ans;
    vector<int> temp;
    
    solve(A,ans,temp, B, 0);
    
    sort(ans.begin(), ans.end());
    
    return ans;
}
