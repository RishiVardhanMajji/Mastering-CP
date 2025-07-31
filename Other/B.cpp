#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    int x = str.size();

    vector<vector<int>>operation;

    while(true){

        vector<int> vec1;
        vector<int> vec2;

        for (int i = 0; i < x; i++) {
            if (str[i] == '(') vec1.push_back(i);
        }
        for (int j = x - 1; j >= 0; j--) {
            if (str[j] == ')') vec2.push_back(j);
        }
        
        reverse(vec2.begin(), vec2.end());

        int y = min(vec1.size(), vec2.size());
        vector<int>remov;
        for(int i=0;i<y;i++){
            if(vec1[i]<vec2[i]){
                remov.push_back(vec1[i]);
                remov.push_back(vec2[i]);
            }
        }
        if(remov.empty())break;


        sort(remov.begin(),remov.end());
        operation.push_back(remov);

        for(auto x:remov){
            str[x]=' ';
        }

    }
    cout << operation.size() << "\n";

    for(auto a:operation){
        cout << a.size() << "\n";
        for(int b:a){
            cout << b+1 << " ";
        }
        cout << "\n";
    }



}
