#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long sum=arr[0];
    long long maximum=sum;
    for(int i=1;i<n;i++){
        sum=max(arr[i],sum+arr[i]); 
        maximum=max(maximum,sum);
    }
    cout << maximum;
    return 0;

}