//
// Created by tmy on 19-9-1.
//
#include <iostream>
#include <map>
#include <vector>
void initVector(std::vector<int>& value){
    for(int i=0;i<value.size();i++){
        std::cin>>value[i];
    }
}
void initHash(std::map<int,int>& hash,std::vector<int>& value){
    int m = value.size();
    for(int i=0;i<m;i++){
        if(hash.count(value[i])){
            hash[value[i]] +=1;
        } else{
            hash[value[i]] = 1;
        }
    }
}
int getResult(std::map<int,int>& hash,int n){
    int i = 1;
    int result = 0;
    while (hash.size()==n){
        hash[i] -= 1;
        if(hash[i]==0){
            hash.erase(i);
        }
        if(i==n){
            i = 1;
            result++;
            continue;
        }
        i++;
    }
    return result;
}
int main(){
    int n,m;
    std::cin>>n;
    std::cin>>m;
    std::vector<int > value(m);
    initVector(value);
    std::map<int,int> hash;
    initHash(hash,value);
    std::cout<<getResult(hash,n);
    return 0;
}

