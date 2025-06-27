#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<int,int>m;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        m[a]=1;
        m[b]=-1;
    }
    int people=0;
    int maximum=0;
    for(auto [key,value] : m){
        people+= value;
        maximum =max(maximum,people);
    }
    cout << maximum;
    return 0;
}