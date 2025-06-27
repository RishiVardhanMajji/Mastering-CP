#include <iostream>
#include <set>

using namespace std;

int main(){
    int n;
    cin >> n;
    multiset<int>s;
    for(int i=0;i<n;i++){
        int x;
        cin >>x;
        s.insert(x);
    }

    for(auto x:s){
        cout << x << " ";
    }
}