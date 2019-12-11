/*
 For any positive integer N, Z(N) is the number of zeros at the end of the decimal form of number N!.
 They noticed that this function never decreases. If we have two numbers N1<N2, then Z(N1) <= Z(N2).
 It is because we can never "lose" any trailing zero by multiplying by any positive number.
 We can only get new and new zeros. The function Z is very interesting, so we need a computer program that
 can determine its value efficiently.
*/
#include<bits/stdc++.h>
using namespace std;

int trailZero(int);

int main(void){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << trailZero(n) << endl;
    }
    return 0;
}

int trailZero(int n){
    int res = 0;

    while(n){
        n = n / 5;
        res += n;
    }
    return res;
}
