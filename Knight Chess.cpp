/*
Abhineet the Chess master of NIT Kurukshetra got bored of 8x8 chess board and invented the new
variation of Chess, the one on an infinite chess board. There is only a white king and N black knights.
The white king has to avoid checkmate as long as it can.

A situation is given. Determine if white king is in checkmate or not. The white king is in checkmate
if and only if it is in check and it is not able to move to any of its neighboring positions which is
not in check.
*/
#include<bits/stdc++.h>
#define ll long long
#define MAX 1000000000
#define MIN -1000000000
using namespace std;

string isCheckmate(ll);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << isCheckmate(n) << endl;
    }
    return 0;
}

string isCheckmate(ll n){
    ll x_move[] = {-1, 0, 1, 0};
    ll y_move[] = {0, 1, 0, -1};
    ll kx_move[] = {-2, -1, -2, -1, 2, 1, 2, 1};
    ll ky_move[] = {1, 2, -1, -2, 1, 2, -1, -2};
    ll x, y;
    set<pair<ll, ll>> us1, us2;
    set<pair<ll, ll>>::iterator it, temp;

    for(ll i = 0; i < n; i++){
        cin >> x >> y;
        for(ll j = 0; j < 8; j++){
            ll _x = x + kx_move[j];
            ll _y = y + ky_move[j];
            if(MIN <= _x && _x <= MAX && MIN <= _y && _y <= MAX)
                us1.insert({_x, _y});
        }
    }
    cin >> x >> y;
    for(ll i = 0; i < 4; i++){
        ll _x = x + x_move[i];
        ll _y = y + y_move[i];
        if(MIN <= _x && _x <= MAX && MIN <= _y && _y <= MAX)
            us2.insert({_x, _y});
    }
    for(it = us1.begin(); it != us1.end(); it++){
        temp = us2.find({it->first, it->second});
        if(temp != us2.end()){
            us2.erase(temp);
        }
    }
    if(us2.empty())
        return "YES";
    else
        return "NO";
}
