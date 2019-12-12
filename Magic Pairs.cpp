#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

int main(void){
    ll t, n;

    cin >> t;
    while(t--){
        cin >> n;
        ll arr[n];
        for(ll i = 0; i < n; i++)
            cin >> arr[i];
        n--;
        ll s = n * (n + 1) / 2;
        cout << s << endl;
    }
    return 0;
}
