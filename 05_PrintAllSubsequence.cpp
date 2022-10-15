//time complexity = O(2^n)
//space complexity = O(n)

#include <bits/stdc++.h>
#define vi vector<int>
#define F(i, n, m) for (int i = n; i < m; i++)
using namespace std;

void Solution(vi ans, vi v, int it, int n) {
    if (it >= n) {
        for (auto i : ans) cout<<i<<" ";
        cout<<"\n";
        return;
    }

    ans.push_back(v[it]);
    Solution(ans, v, it+1, n);
    ans.pop_back();
    Solution(ans, v, it+1, n);

    return;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin>>n;
    vi v;

    F(i, 0, n) {
        int x; cin>>x;
        v.push_back(x);
    }

    vi ans;
    Solution(ans, v, 0, n);
    
    return 0;
}