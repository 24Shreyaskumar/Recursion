//time complexity = O(n * 2^n)
//space complexity = O(k * 2^n)
//auxillary space complexity = O(n)

#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
#define F(i, n, m) for (int i = n; i < m; i++)
using namespace std;

void display(vvi sol) {
    cout<<"[";
    for (auto i : sol) {
        cout<<"[ ";
        for (auto j : i) cout<<j<<" ";
        cout<<"]";
    }
    cout<<"]\n";
    return;
}

void Solution(vi v, vi &ans, vvi &sol, int n, int it) {
    sol.push_back(ans);
    F(i, it, n) {
        if (i != it && v[i] == v[i-1]) continue;
        ans.push_back(v[i]);
        Solution(v, ans, sol, n, i+1);
        ans.pop_back();
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin>>n;
    vi v, ans;
    vvi sol;
    F(i, 0, n) {
        int x; cin>>x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    Solution(v, ans, sol, n, 0);
    display(sol);
    return 0;
}