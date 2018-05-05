#include <iostream>
#include "kmp.h"

using namespace std;

int main(){
    string str1, str2;
    cout<<"Str1:\n";
    cin>>str1;
    cout<<"Str2:\n";
    cin>>str2;
    if(str1.size()!=str2.size()){
        cout<<"-1";
        return 0;
    }
    vector<int> pi=prefix(str2);
    vector<int> index=kmp(str1+str1,str2,pi);
    if(index.size()){
        cout<<index[0];
    }
    else
        cout<<"-1";
    return 0;
}