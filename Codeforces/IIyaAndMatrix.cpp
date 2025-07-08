#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >>n;
    vector<long long>matrix(n);
    for(int i=0;i<n;i++){
        cin >> matrix[i];
    }
    sort(matrix.rbegin(),matrix.rend());
    long long beauty=0;
    int k=(log(n)/log(4));
    int i=0;
    int a=0;
    while(n-i){
        beauty += matrix[i]*(k+1-a);
        if(i%4==0)a+=1;
        ++i;
    }
    cout << beauty << "\n";


}