#include <bits/stdc++.h>
using namespace std;

bool isLucky(int n, int k) {
    if (n < k) return true;
    if (n % k == 0) return false;
    isLucky(n - n/k, k+1);
}

string Solution(int n) {
    if (isLucky(n, 2)) return "Lucky";
    return "Unlucky";
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;

    while (t--) {
        int n; cin>>n;
        cout<<Solution(n)<<"\n";
    }

    return 0;
}