//
// Created by zb198 on 2019/9/2.
//
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
void initBound(std::vector<std::pair<int,int >>& bound){
    for(int i=1;i<bound.size();i++){
        std::cin>>bound[i].first;
        bound[i].second = i;
        bound[i].first += bound[i-1].first;
    }
}

bool comp(std::pair<int,int >a,std::pair<int,int >b){
    return a.first < b.first;
}
int getResult(std::vector<std::pair<int,int > >& bounds,int quire){
    return (*std::lower_bound(bounds.begin(),bounds.end(),std::make_pair(quire,0),comp)).second;
}

int main(){
    int n,m;
    std::cin>>n;
    std::vector<std::pair<int,int >> bound(n+1,{0,0});
    initBound(bound);
    std::cin>>m;
    for(int i=0;i<m;i++){
        int quite;
        std::cin>>quite;
        std::cout<<getResult(bound,quite)<<std::endl;
    }
    return 0;
}
