#include <iostream>
#include <map>
using namespace std;

int main(){
    int n;
    cin >>n;
    map<int,int> m;
    int no_round=1;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        m[x]=i;
    }

    for(int i=1;i<n;i++){
        if(m[i] > m[i+1])no_round+=1;
    }
    cout << no_round;
    return 0;
}