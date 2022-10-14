//time complexity = O(2^n)
//space complexity = O(n^2)

#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
#define ll long long int
#define F(i, n, m) for (int i = n; i < m; i++)
using namespace std;

void display(vi v) {
    ll sum = 0;
    for (auto i : v) sum += i;
    cout<<sum<<" ";
    return;
}

void Solution(vi &v, vi &ans, int n, int it) {
    if (it == n) {
        display(ans);
        return;
    }

    ans.push_back(v[it]);
    Solution(v, ans, n, it+1);
    ans.pop_back();
    Solution(v, ans, n, it+1);

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

    Solution(v, ans, n, 0);

    return 0;
}