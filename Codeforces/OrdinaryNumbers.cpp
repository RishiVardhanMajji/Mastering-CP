/*
#include <iostream>
#include <vector>

using namespace std;


bool myfunc(long long a,vector<long long>&memry){
    if(((memry.at(a/10))-(memry.at((a/10)-1)) ==1) && (a%100)%11==0)return true;
    else return false;
}
int main(){
    int t;
    cin >> t;
    long long arr[t];
    vector<long long>memry={0,1,2,3,4,5,6,7,8,9};

    for(int i=0;i<t;i++){
        cin >> arr[i];
    }

    for(int i=0;i<t;i++){
        if(memry.size()>arr[i]){
            cout<<memry.at(arr[i])<<"\n";
        }else{
            for(long long a=memry.size();a<=arr[i];a++){
                if(myfunc(a,memry))memry.push_back((memry.at(a-1))+1);
                else memry.push_back(memry.at(a-1));
            }
            cout<<memry.at(arr[i])<< "\n";
        }
    }
}

*/

#include <iostream>
using namespace std;

int countOrdinary(long long n) {
    int count = 0;
    for (int digit = 1; digit <= 9; digit++) {
        long long num = digit;
        while (num <= n) {
            count++;
            num = num * 10 + digit;
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        cout << countOrdinary(n) << '\n';
    }
    return 0;
}