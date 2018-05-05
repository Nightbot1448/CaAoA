#include <iostream>
#include "kmp.h"

void print(const vector<int>& index){ //print result
    for(const auto& it: index){
        cout<<it;
        if(it!=index[index.size()-1])
            cout<<",";
    }
}

int main(){
    string text, temp;
    cout<<"Template:\n";
    cin>>temp;
    cout<<"Text:\n";
    cin>>text;
    if(temp.size()<15000 && text.size()<5000000){
        vector<int> pi=prefix(temp);
        vector<int> index=kmp(text,temp,pi);
        if(index.size()){
            print(index);
        }
        else
            cout<<"-1";
    }
    else
        cout<<"out of range\n";
    return 0;
}