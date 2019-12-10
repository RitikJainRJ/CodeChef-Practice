#include <bits/stdc++.h>
using namespace std;

int bearSpecies(int);

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
    int **matrix = new int*[n];
    for(int i = 0; i < n; i++)
        matrix[i] = new int[n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> matrix[i][j];
     for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
     }

}
