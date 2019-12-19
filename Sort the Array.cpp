/*
Being a programmer, you like arrays a lot. For your birthday, your friends have given you an array a
consisting of n distinct integers.

Unfortunately, the size of a is too small. You want a bigger array! Your friends agree to give you a
bigger array, but only if you are able to answer the following question correctly: is it possible to
sort the array a (in increasing order) by reversing exactly one segment of a? See definitions of segment
and reversing in the notes.
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x = 0, y = 0, flag = 0;

    cin >> n;
    ll arr[n];
    for(ll i = 0; i < n; i++)
        cin >> arr[i];
    for(ll i = 0; i < n - 1; i++){
        if(arr[i] > arr[i + 1]){
            for(ll j = i + 1; j < n; j++){
                if(arr[j - 1] >= arr[j]){
                    x = i;
                    y = j;
                    flag = 1;
                }
                else{
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 1)
            break;
    }
    reverse(arr + x, arr + y + 1);
    if(is_sorted(arr, arr + n)){
        cout << "yes" << endl;
        cout << x + 1 << " " << y + 1 << endl;
    }
    else
        cout << "no" << endl;
    return 0;
}
