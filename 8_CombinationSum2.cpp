//time complexity = O(2^n)
//space complexity = O(n^2)
//assuming the array to presorted

#include <bits/stdc++.h>
#define vi vector<long long int>
#define F(i, n, m) for (int i = n; i < m; i++) 
#define ll long long int 
using namespace std;

set<vi> sol;

void display(set<vi> sol) {
    for (auto row : sol) {
        for (auto i : row) cout<<i<<" ";
        cout<<"\n";
    }

    return;
}

void Solution(vi v, int n, vi ans, int it, ll k) {
    if (k == 0) {
        sol.insert(ans);
        return;
    }

    if (k < v[it]) return;

    ans.push_back(v[it]);
    Solution(v, n, ans, it+1, k - v[it]);
    ans.pop_back();
    Solution(v, n, ans, it+1, k);

    return;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin>>n;
    vi v, ans;
    F(i, 0, n) {
        int x; cin>>x;
        v.push_back(x);
    }

    ll k; cin>>k;

    Solution(v, n, ans, 0, k);
    display(sol);

    return 0;
}