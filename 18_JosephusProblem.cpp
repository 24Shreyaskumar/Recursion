#include<bits/stdc++.h>
using namespace std;

int josephusProblem(int n, int k) {
    if (n == 1) return 0;

    return (josephusProblem(n-1, k) + k) % n;
}

int Solution(int n, int k) {
    return josephusProblem(n, k) + 1;
}

int main() { 
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;

    while (t--) {
        int n, k; cin>>n>>k;
        cout<<Solution(n, k)<<"\n";
    }

    return 0;
}