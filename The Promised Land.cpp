/*
Years after the Ishval Civil War, the Ishvalan refugees have now found a safe place for themselves which
is a rectangular piece of land, surrounded by fences. The land can be thought of as a 2d grid which extends
N units vertically and M units horizontally. It is divided into N horizontal rows, which are
numbered from 1 to N, as you move from top to bottom and into M vertical columns numbered from 1 to M, from
left to right. There are X rivers flowing in a horizontal direction, each flowing in a different row and
covering the entire row. Similarly, there are Y rivers flowing in a vertical direction, each flowing in a
different column and covering the entire column.
The people want to build houses of dimensions S×S on the remaining land. What is the maximum number of houses
of the given dimensions that could be built on the remaining land, such that no part of any house is in a
river and no two houses overlap?
*/
#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

ll findMaxHouse(ll, ll);
ll _fms(ll**, ll, ll, ll);
bool isSafe(ll**, ll, ll, ll , ll, ll);

int main(void){
    ll t;

    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        cout << findMaxHouse(n, m) << endl;
    }
    return 0;
}

ll findMaxHouse(ll n, ll m){
    ll **arr = new ll*[n];
    ll x, y, s;

    for(ll i = 0; i < n; i++)
        arr[i] = new ll[m];
    cin >> x >> y >> s;
    ll X[x], Y[y];
    for(ll i = 0; i < x; i++){
        ll temp;
        cin >> temp;
        X[i] = temp - 1;
    }
    for(ll i = 0; i < y; i++){
        ll temp;
        cin >> temp;
        Y[i] = temp - 1;
    }

    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < m; j++)
            arr[i][j] = 0;
    for(ll i = 0; i < x; i++)
        for(ll j = 0; j < m; j++)
            arr[X[i]][j] = 1;
    for(ll i = 0; i < y; i++)
        for(ll j = 0; j < n; j++)
            arr[j][Y[i]] = 1;

    return _fms(arr, n, m, s);
}

ll _fms(ll **arr, ll n, ll m , ll s){
    ll res = 0;

    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < m; j++)
            if(isSafe(arr, i, j, n, m, s))
                res++;
    return res;
}

bool isSafe(ll **arr, ll x, ll y, ll n, ll m, ll s){
    if(arr[x][y] == 1 || arr[x][y] == -1)
        return false;
    for(ll i = x; i < x + s && i < n; i++)
        for(ll j = y; j < y + s && j < m; j++)
            if(arr[i][j] == 1 || arr[i][j] == -1)
                return false;
    for(ll i = x; i < x + s && i < n; i++)
        for(ll j = y; j < y + s && j < m; j++)
                arr[i][j] = -1;
    return true;
}
