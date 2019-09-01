//
// Created by tmy on 19-9-1.
//
#include <iostream>
#include <vector>
void initValue(std::vector<int >& value){
    for(auto Iter=value.begin();Iter!=value.end();Iter++){
//        std::scanf("%d",Iter);
        std::cin>>(*Iter);
    }
}
void initIsRalse(std::vector<bool >& isRalse){
    for(auto Iter=isRalse.begin();Iter!=isRalse.end();Iter++){
        int temp;
//        std::scanf("%d",&temp);
        std::cin>>temp;
        *Iter = (temp==1);
    }
}
int core(std::vector<int >& value,std::vector<bool >& isRalse,int index,int k){
    int result=0;
    for(int i=0;i<k;i++){
        if(!isRalse[index+i]){
            result += value[index+i];
        }
    }
    return result;
}
int main(){
    int n,k;
    std::cin>>n;
    std::cin>>k;
    std::vector<int > value(n);
    std::vector<bool > isRalse(n);
    initValue(value);
    initIsRalse(isRalse);
    int sum = 0;
    int max = 0;
    for(int i=0;i<n;i++){
        if(isRalse[i]){sum += value[i];}
        if(i >= n-k+1){ continue;}
        int temp = core(value,isRalse,i,k);
        if(temp > max){
            max = temp;
        }
    }
    std::cout<<(sum+max);
    return 0;
}
