bool isPalindrome(string s, int start, int end) {
    while(start < end) {
        if(s[start++] != s[end--]){
            return false;
        }
    }
    return true;
}


void solve(string s, vector<vector<string>> &ans, vector<string> &temp, int t) {
    if(t == s.length()) {
        ans.push_back(temp);
    } else {
        for(int i = t; i < s.length(); i++) {
            if(isPalindrome(s, t, i)) {
                string str = s.substr(t, i-t+1);
                temp.push_back(str);
                solve(s, ans, temp, i+1);
                temp.pop_back();
            }
        }
    }
}

vector<vector<string> > Solution::partition(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<string>> ans;
    vector<string> temp;
    solve(A, ans, temp, 0);
    
    
    return ans;
}
