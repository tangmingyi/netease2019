//
// Created by zb198 on 2019/9/2.
//
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
void initBound(std::vector<int >& bound){
    int sum = 0;
    for(auto Iter=bound.begin();Iter!=bound.end();Iter++){
        int temp;
        std::cin>>temp;
        sum += temp;
        *Iter = sum;
    }
}
void initResult(std::vector<std::tuple<int,int,int>>& results ){
    for(int i=0;i<results.size();i++){
        int quire;
        std::cin>>quire;
        std::get<0>(results[i])=i;
        std::get<1>(results[i])=quire;
        std::get<2>(results[i])=-1;
    }
}
bool cmp1(std::tuple<int,int,int>a,std::tuple<int,int,int>b){
    return std::get<1>(a) < std::get<1>(b);
}
bool cmp0(std::tuple<int,int,int>a,std::tuple<int,int,int>b){
    return std::get<0>(a) < std::get<0>(b);
}
void getResult(std::vector<int >& bounds,int& begin,std::tuple<int,int,int>& result){
    int index = begin+((bounds.size()-begin)>>1);
    int quire = std::get<1>(result);
    while (true){
        if(bounds[index]>= quire){
            if(bounds[index-1]<quire){
                std::get<2>(result)=index+1;
                break;
            } else{
                index = begin + ((index-begin)>>1);
            }
        } else{
            if(bounds[index+1]>=quire){
                std::get<2>(result)=index+1+1;
                break;
            } else{
                index = index + ((bounds.size()-index)>>1);
            }
        }
    }
    begin = index-1;
}
void printResult(const std::vector<std::tuple<int,int,int >>& results){
    for(auto Iter=results.begin();Iter!=results.end();Iter++){
        std::cout<<std::get<2>(*Iter)<< std::endl;
    }
}
int main(){
    int n,m;
    std::cin>>n;
    std::vector<int> bound(n);
    initBound(bound);
    std::cin>>m;
    std::vector<std::tuple<int,int,int >> results(m);//tuple 分别是 index，qi,result
    initResult(results);
    std::sort(results.begin(),results.end(),cmp1);
    int begin = 0;
    for (auto Iter=results.begin();Iter!=results.end();Iter++){
        getResult(bound,begin,*Iter);
    }
    std::sort(results.begin(),results.end(),cmp0);
    printResult(results);
    return 0;
}
