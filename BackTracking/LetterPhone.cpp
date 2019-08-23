vector<string> v;
vector<string> ans;

void solve(string A, string temp ,int i) {
    if(i == A.length()) {
        ans.push_back(temp);
        return;
    }
    int x = A[i]-'0';
    for(int j = 0; j < v[x].length(); j++) {
        temp.push_back(v[x][j]);
        solve(A,temp, i+1);
        temp.pop_back();
    }
    
}

vector<string> Solution::letterCombinations(string A) {
    ans.clear();
    v.clear();
    
    v.push_back("0");
    v.push_back("1");
    v.push_back("abc");
    v.push_back("def");
    v.push_back("ghi");
    v.push_back("jkl");
    v.push_back("mno");
    v.push_back("pqrs");
    v.push_back("tuv");
    v.push_back("wxyz");
    
    solve(A,"", 0);
    sort(ans.begin(), ans.end());
    
    return ans;
    
}
