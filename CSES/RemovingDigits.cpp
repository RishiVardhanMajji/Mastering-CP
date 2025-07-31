#include <bits/stdc++.h>

using namespace std;

int maxdigit(int n){
    int req=0;
    while(n){
        req=max(req,n%10);
        n=n/10;
    }
    return req;
}

int main(){
    int n;
    cin >> n;
    int ans=0;
    while(n){
        n-=maxdigit(n);
        ans++;
    }
    cout << ans << "\n";
}