#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class ParmeterisedRecursion {
    public:
        ll sumPR(ll k, ll add) {
            if (k < 1) return add;

            return sumPR(k - 1, add + k);
        }

        ll factPR(ll k, ll prod) {
            if (k < 1) return prod;

            return factPR(k - 1, prod * k);
        }
};

class FunctionalRecursion {
    public:
        ll sumFR (ll n) {
            if (n == 0) return 0;

            return n + sumFR(n-1);
        }

        ll factFR (ll n) {
            if (n == 0) return 1;

            return n * factFR(n-1);
        }
};

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    ParmeterisedRecursion pr;
    FunctionalRecursion fr;

    cout<<pr.sumPR(5, 0)<<" "<<pr.factPR(5, 1)<<"\n";

    cout<<fr.sumFR(5)<<" "<<fr.factFR(5)<<"\n";

    return 0;
}