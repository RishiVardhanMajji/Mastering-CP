
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<double>input(n,0);
    long long sum=0;
    for(int i=0;i<n;i++){
        cin >> input[i];
        sum+= floor(input[i]);
    }
    for(int i=0;i<-1*(sum);i++){
        if(floor(input[i])==input[i]){
            sum-=1;
            continue;
        }else{
            input[i]=ceil(input[i]);
        }
    }
    for(int i=(-1)*(sum);i<n;i++){
        input[i]=floor(input[i]);
    }

    for(int i=0;i<n;i++){
        if(input[i]==0)input[i]=0;
        cout << input[i] << "\n";
    }

}