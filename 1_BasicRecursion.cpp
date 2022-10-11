#include <bits/stdc++.h>
using namespace std;

//print hi 5 times
void Recursion1(int count) {
    //base condition
    if (count == 5) return;

    cout<<"Hi\n";
    count++;
    Recursion1(count);
    return;
}

//print linearly form 0 to n
void Recursion2(int k, int n) {
    //base condition
    if (k == n) return;

    cout<<k<<"\n";
    k++;
    Recursion2(k, n);
    return;
}

//print linearly from n to 1
void Recursion3(int k, int n) {
    //base condition
    if (k == n) return;

    cout<<k<<"\n";
    k--;
    Recursion3(k, n);
    return;
}

//Now print 1 to n using backtracking
void Backtracking1(int n) {
    //Base Condition
    if (n < 1) return;

    Backtracking1(n-1);
    cout<<n<<"\n";

    return;
} 


//print n to 1 using backtracking
void Backtracking2(int k, int n) {
    //Base Condition
    if (k > n) return;

    Backtracking2(k+1, n);
    cout<<k<<"\n";

    return;
}


int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    Recursion1(0);
    Recursion2(0, 5);
    Recursion3(5, 0);
    Backtracking1(5);
    Backtracking2(1, 5);
}