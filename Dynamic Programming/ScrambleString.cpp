
int Solution::isScramble(const string A, const string B) {
    if(A == B) {
        return true;
    }
    int len1 = A.length();
    int len2 =  B.length();
    if(len1 != len2) {
        return false;
    }
    vector<int> dp(26, 0);
    for(int i = 0; i < len1; i++) {
        dp[A[i]-'a']++;
        dp[B[i]-'a']--;
    }
    for(auto i : dp) {
        if(i != 0) {
            return false;
        }
    }
    for(int i = 1; i < len1; i++) {
        if(isScramble(A.substr(0,i), B.substr(0,i)) &&
            isScramble(A.substr(i), B.substr(i))) {
                return true;
        }
        if(isScramble(A.substr(0,i), B.substr(len1-i)) &&
            isScramble(A.substr(i), B.substr(0,len1-i))) {
                return true;    
        }
    }
    return false;
}
