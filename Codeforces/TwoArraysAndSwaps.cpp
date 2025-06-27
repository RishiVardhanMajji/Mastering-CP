#include <iostream>
#include <set>

using namespace std;

int main(){
    int t;
    cin >> t;

    for(int i=0;i<t;i++){
        int n,k;
        cin >> n >> k;
        multiset<int>A;
        multiset<int>B;
        for(int i=0;i<n;i++){
            int x;
            cin >>x;
            A.insert(x);
        }
        for(int i=0;i<n;i++){
            int y;
            cin >> y;
            B.insert(y);
        }
        auto itA=A.begin();
        auto itB=B.end();
        --itB;
        int sum=0;
        for(int i=0;i<n;i++){
            if(i<k){
                if(*itB>*itA)sum+=*itB;
                else {
                    sum+=*itA;
                }
            }else sum+= *itA;
            ++itA;
            --itB;
        }
        cout << sum << "\n";
    }
}