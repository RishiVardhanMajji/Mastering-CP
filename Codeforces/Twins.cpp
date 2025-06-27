#include <iostream>
#include <set>
using namespace std;

int main(){
    int n;
    cin >> n;
    multiset<int>s;
    double sum=0;
    for(int i=0;i<n;i++){
        int x;
        cin >>x;
        sum+=x;
        s.insert(x);
    }

    auto it=s.end();
    --it;
    int mysum=0;
    int count=0;
    for(int i=1;i<=n;i++){
        mysum += *it;
        --it;
        count++;
        if(mysum > sum/2)break;
    }

    cout << count;

}