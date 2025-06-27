#include <iostream>
#include <set>
using namespace std;

int main(){
    int n,m,k;
    cin >> n >> m >>k;
    multiset<int>available;
    multiset<int>desired;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        desired.insert(x);   
    }
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        available.insert(x);
    }
    int count=0;
    for(auto iter=desired.begin();iter!= desired.end();iter++){
        auto it = available.lower_bound(*iter - k);
        if(it != available.end() && *it <= *iter + k){
            count++;
            available.erase(it);
        }
    }

    cout << count << endl;
    return 0;
}