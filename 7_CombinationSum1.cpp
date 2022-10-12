//time complexity = O(2^n)
//space complexity = O(n^2)
//assuming the array to presorted

#include <bits/stdc++.h>
#define vi vector<long long int>
#define F(i, n, m) for (int i = n; i < m; i++) 
#define ll long long int 
using namespace std;

void display(vector<vi> sol) {
    for (auto row : sol) {
        for (auto i : row) cout<<i<<" ";
        cout<<"\n";
    }

    return;
}

void push(vi ans) {
    vector<vi> sol;
    sol.push_back(ans);
    display(sol);
}

void Solution(vi v, int n, vi ans, int it, ll k, ll x) {
    if (x == 0) {
        push(ans);
        return;
    }

    if (x < v[it]) return;

    ans.push_back(v[it]);
    x -= v[it];
    Solution(v, n, ans, it, k, x);
    x += v[it];
    ans.pop_back();
    Solution(v, n, ans, it+1, k, x);

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

    Solution(v, n, ans, 0, k, k);

    return 0;
}