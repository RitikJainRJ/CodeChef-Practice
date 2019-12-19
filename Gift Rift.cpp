/*
Our Chef is very happy that his son was selected for training in one of the finest culinary schools of the
world. So he and his wife decide to buy a gift for the kid as a token of appreciation. Unfortunately,
the Chef hasn't been doing good business lately, and is in no mood on splurging money. On the other hand,
the boy's mother wants to buy something big and expensive. To settle the matter like reasonable parents,
they play a game.

They spend the whole day thinking of various gifts and write them down in a huge matrix. Each cell of
the matrix contains the gift's cost. Then they decide that the mother will choose a row number r while
the father will choose a column number c, the item from the corresponding cell will be gifted to the
kid in a couple of days.

The boy observes all of this secretly. He is smart enough to understand that his parents will ultimately
choose a gift whose cost is smallest in its row, but largest in its column. If no such gift exists, then
our little chef has no option but to keep guessing. As the matrix is huge, he turns to you for help.

He knows that sometimes the gift is not determined uniquely even if a gift exists whose cost is smallest
in its row, but largest in its column. However, since the boy is so smart, he realizes that the gift's
cost is determined uniquely. Your task is to tell him the gift's cost which is smallest in its row,
but largest in its column, or to tell him no such gift exists.
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, min, max;

    cin >> n >> m;
    ll arr[n][m];
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < m; j++)
            cin >> arr[i][j];
    for(ll i = 0; i < n; i++){
        vector<ll> temp;
        min = INT_MAX;
        for(ll j = 0; j < m; j++){
            if(arr[i][j] < min)
                min = arr[i][j];
        }
        for(ll j = 0; j < m; j++){
            if(arr[i][j] == min)
                temp.push_back(j);
        }
        for(ll k = 0; k < temp.size(); k++){
            ll t = temp[k];
            max = 0;
            for(ll j = 0; j < n; j++){
                if(max < arr[j][t]){
                    max = arr[j][t];
                }
            }
            if(min == max){
                cout << min << endl;
                return 0;
            }
        }
    }
    cout << "GUESS" << endl;
    return 0;
}
