/*
Chef has two piles of stones with him, one has n1 stones and the other has n2 stones.
Fired up by boredom, he invented a game with the two piles.
Before the start of the game Chef chooses an integer m.
In the j-th move:
    He chooses a number xj such that 1 ≤ xj ≤ m, and removes xj stones from both the piles (this is only possible when both the piles have ≥ xj stones).
    The number chosen must be unique over all the moves in the game. That is, for all k < j, xj ≠ xk.

The game stops when Chef is unable to make any more moves.
Chef wants to make the moves in such a way that the sum of the number of stones remaining in the two
piles is minimized. Please help Chef find this.
*/
#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

void minSum(ll, ll, ll);
void _minSum(ll, ll, ll&, vector<ll>);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, n1, n2, m;

    cin >> t;
    while(t--){
        cin >> n1 >> n2 >> m;
        minSum(n1, n2, m);
        cout << endl;
    }
    return 0;
}

void minSum(ll n1, ll n2, ll m){
    vector<ll> vec;
    ll res = INT_MAX;

    for(ll i = 1; i <= m; i++)
        vec.push_back(i);
    _minSum(n1, n2, res, vec);
    cout << res;
}

void _minSum(ll n1, ll n2, ll &res, vector<ll> vec){
    if(vec.empty()){
        ll t = n1 + n2;
        if(res > t)
            res = t;
    }
    else{
        for(ll i = 0; i < vec.size(); i++){
            if(n1 - vec[i] >= 0 && n2 - vec[i] >= 0){
                vector<ll> temp = vec;
                temp.erase(temp.begin() + i);
                _minSum(n1 - vec[i], n2 - vec[i], res, temp);
            }
            else{
                ll t = n1 + n2;
                if(res > t)
                    res = t;
            }
        }
    }
}
