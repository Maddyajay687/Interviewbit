void solve(int A, vector<string> &ans,string str, int open, int close) {
    if(open == 0 && close == 0) {
        ans.push_back(str);
    }
    cout<<open<<" "<<close<<" ";
    if(open > 0) {
        solve(A, ans, str+"(", open-1, close);
    } 
    if(open < close) {
        solve(A, ans, str+")", open, close-1);
    }
}
vector<string> Solution::generateParenthesis(int A) {
    vector<string> v;
    solve(A, v, "", A, A);
    
    return v;
}
