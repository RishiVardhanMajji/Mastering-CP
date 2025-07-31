#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,x;
    cin >> n >> x;
    vector<int>price(n,0);
    vector<int>npages(n,0);
    for(int i=0;i<n;i++){
        cin >> price[i];
    }
    for(int i=0;i<n;i++){
        cin >> npages[i];
    }


    vector<int> A(x+1,0);
    for(int i=0;i<n;i++){
        for(int j=x;j>=price[i];j--){
            
            A[j] = max(A[j], A[j - price[i]] + npages[i]);
        }
    }
    cout << A[x] << "\n";
}