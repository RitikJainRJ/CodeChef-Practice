#include <bits/stdc++.h>
using namespace std;

int bearSpecies(int);
void _bearSpecies(char**, int**, int, int&);
bool findPosition(char**, int**, int&, int&, int);
bool isSafe(int, int, int, char**, int**, int);

int main(void){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << bearSpecies(n) << endl;
    }
    return 0;
}

int bearSpecies(int n){
    int res = 0;
    int flag = 0;
    char **arr = new char*[n];
    int **sol = new int*[n];

    for(int i = 0; i < n; i++){
        arr[i] = new char[n];
        sol[i] = new int[n];
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            sol[i][j] = 0;
        }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(arr[i][j] == '?')
                flag = 1;
    if(flag == 0)
        return 0;
    _bearSpecies(arr, sol, n, res);
    return res;
}

bool findPosition(char **arr, int **sol, int &row, int &col, int n){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(arr[i][j] == '?' && sol[i][j] == 0){
                row = i;
                col = j;
                return true;
            }
    return false;
}

void _bearSpecies(char **arr, int **sol, int n, int &res){
    int row, col;
    if(!findPosition(arr, sol, row, col, n)){
        res = (res + 1) % 1000000007;
        return;
    }
    for(int i = 1; i <= 3; i++){
        if(isSafe(i, row, col, arr, sol, n)){
            sol[row][col] = i;
            _bearSpecies(arr, sol, n, res);
            sol[row][col] = 0;
        }
    }
}

bool isSafe(int i, int row, int col, char **arr, int **sol, int n){
    int xMove[] = {-1, 0, 1, 0};
    int yMove[] = {0, 1, 0, -1};
    if(i == 1){
        for(int k = 0; k < 4; k++){
            int _x = row + xMove[k];
            int _y = col + yMove[k];
            if(0 <= _x && _x < n && 0 <= _y && _y < n){
                if(arr[_x][_y] != '.')
                    return false;
            }
        }
        return true;
    }
    else{
        if(i == 2){
            for(int k = 0; k < 4; k++){
                int _x = row + xMove[k];
                int _y = col + yMove[k];
                if(0 <= _x && _x < n && 0 <= _y && _y < n){
                    if(arr[_x][_y] == 'B' || arr[_x][_y] == '.' || arr[_x][_y] == '?'){
                        if(arr[_x][_y] == '?' && (sol[_x][_y] == 1 || sol[_x][_y] == 3))
                            return false;
                    }
                    else{
                        return false;
                    }
                }
            }
            return true;
        }
        if(i == 3){
            for(int k = 0; k < 4; k++){
                int _x = row + xMove[k];
                int _y = col + yMove[k];
                if(0 <= _x && _x < n && 0 <= _y && _y < n){
                    if(arr[_x][_y] == 'P' || arr[_x][_y] == '.' || arr[_x][_y] == '?'){
                        if(arr[_x][_y] == '?'  && (sol[_x][_y] == 1 || sol[_x][_y] == 2))
                            return false;
                    }
                    else{
                        return false;
                    }
                }
            }
            return true;
        }
    }
}
