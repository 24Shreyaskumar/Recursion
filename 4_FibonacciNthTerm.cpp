//multiple function calls

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll Solution(int n) {
    if (n <= 1) return n;

    return Solution(n-1) + Solution(n-2);
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin>>n;

    cout<<Solution(n)<<"\n";

    return 0;
}