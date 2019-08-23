void solve(vector<int> &A, set<vector<int>> &ans, vector<int> &temp, int sum, int i) {
    if(sum == 0) {
        ans.insert(temp);
    }
    while(i < A.size() && (sum-A[i]) >= 0) {
        temp.push_back(A[i]);
        solve(A, ans, temp,sum-A[i], i+1);
        i++;
        temp.pop_back();
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    set<vector<int>> ans;
    vector<int> temp;
    sort(A.begin(), A.end());
    solve(A, ans, temp, B, 0);
    vector<vector<int>> res;
    
    for(auto i : ans) {
        res.push_back(i);
    }
    
    return res;
}
