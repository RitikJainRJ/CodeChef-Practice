#include<bits/stdc++.h>
using namespace std;

int findMaxHouse(int, int);
int _fms(int**, int, int, int);
bool isSafe(int**, int, int, int , int, int);

int main(void){
    int t;

    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        cout << findMaxHouse(n, m) << endl;
    }
    return 0;
}

int findMaxHouse(int n, int m){
    int **arr = new int*[n];
    int x, y, s;

    for(int i = 0; i < n; i++)
        arr[i] = new int[m];
    cin >> x >> y >> s;
    int X[x], Y[y];
    for(int i = 0; i < x; i++){
        int temp;
        cin >> temp;
        X[i] = temp - 1;
    }
    for(int i = 0; i < y; i++){
        int temp;
        cin >> temp;
        Y[i] = temp - 1;
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            arr[i][j] = 0;
    for(int i = 0; i < x; i++)
        for(int j = 0; j < m; j++)
            arr[X[i]][j] = 1;
    for(int i = 0; i < y; i++)
        for(int j = 0; j < n; j++)
            arr[j][Y[i]] = 1;

    return _fms(arr, n, m, s);
}

int _fms(int **arr, int n, int m , int s){
    int res = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(isSafe(arr, i, j, n, m, s))
                res++;
    return res;
}

bool isSafe(int **arr, int x, int y, int n, int m, int s){
    if(arr[x][y] == 1 || arr[x][y] == -1)
        return false;
    for(int i = x; i < x + s && i < n; i++)
        for(int j = y; j < y + s && j < m; j++)
            if(arr[i][j] == 1 || arr[i][j] == -1)
                return false;
    for(int i = x; i < x + s && i < n; i++)
        for(int j = y; j < y + s && j < m; j++)
                arr[i][j] = -1;
    return true;
}
