/*void solve(vector<int> A, vector<vector<int>> &ans, vector<int> temp) {
    if(A.size() == 0) {
        ans.push_back(temp);
    }
    else {
        int val = A[0];
        A.erase(A.begin());
        temp.push_back(val);
        solve(A, ans, temp);
        temp.pop_back();
        solve(A, ans, temp);
        A.insert(A.begin(),val);
    } 
   /* ans.push_back(temp);
    for(int i = index; i < A.size(); i++) {
        temp.push_back(A[i]);
        solve(A, ans, temp, i+1);
        temp.pop_back();
    }
    return; 
} 

vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<vector<int>> ans;
    vector<int> temp;
    int i = 0;
    solv e(A, ans, temp);
    */
    
vector<vector<int>> v;
void subsetsHelper(vector<int>A, vector<int> aux)
{
    if(A.size() == 0) v.push_back(aux);
    else {
        int a = A[0];
        A.erase(A.begin());
        aux.push_back(a);
        subsetsHelper(A,aux);
        aux.pop_back();
        subsetsHelper(A,aux);
        A.insert(A.begin(),a);
    }
}

vector<vector<int>> Solution::subsets(vector<int> &A) {
    vector<int> c;
    sort (A.begin(),A.end());
    v.clear();
    subsetsHelper(A,c);
    sort (v.begin(),v.end());
    return v;
}
