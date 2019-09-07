//
// Created by zb198 on 2019/9/6.
//
#include <iostream>
#include <vector>
#include <algorithm>

void initVector(std::vector<std::pair<int, int >>& towers) {
    for (int i = 0; i < towers.size(); i++) {
        std::cin >> towers[i].first;
        towers[i].second = i;
    }

}

void update(std::vector<std::pair<int, int >>::iterator* lower, std::vector<std::pair<int, int >>::iterator start,
            std::vector<std::pair<int, int >>::iterator* end) {
    (**lower).first+=1;
    if (*lower == *end) {
        if ((**end).first==(*((*end)+1)).first){
            (*end)++;
        }
        *lower=start;
    } else{
        (*lower)++;
    }
}
void update(std::vector<std::pair<int, int >>::iterator* highter, std::vector<std::pair<int, int >>::iterator* start,
            std::vector<std::pair<int, int >>::iterator end) {
    (**highter).first-=1;
    if (*highter == *start) {
        if ((**start).first==(*((*start)-1)).first){
            (*start)--;
        }
        *highter=end;
    } else{
        (*highter)--;
    }
}

std::pair<int, int> getResult(std::vector<std::pair<int, int >>& towers, std::vector<std::pair<int, int >>& moves, int n,int k) {
    auto lowerBegin = towers.begin();
    auto lowerEnd = towers.begin();
    while ((*lowerEnd).first==(*(lowerEnd+1)).first){lowerEnd++;}//init lower bound
    auto hightBegin = towers.begin()+(n-1);
    while ((*hightBegin).first==(*(hightBegin-1)).first){hightBegin--;}//init hight bound
    auto hightEnd = towers.begin()+(n-1);
    auto lower = towers.begin();
    auto hight = towers.begin()+(n-1);
    int i=0;
    for(i;i<k;i++){
        if((*lower).first==(*hight).first){
            break;
        }
        moves.emplace_back((*hight).second,(*lower).second);
        update(&lower,lowerBegin,&lowerEnd);
        update(&hight,&hightBegin,hightEnd);
    }
    return std::make_pair(((*hight).first-(*lower).first),i);

}

void printResult(std::vector<std::pair<int, int >> &moves, std::pair<int, int> result) {
    std::cout << result.first <<" "<< result.second<<std::endl;
    for (auto Iter = moves.begin(); Iter != moves.end(); Iter++) {
        std::cout << (*Iter).first+1<<" " << (*Iter).second+1<<std::endl;
    }
}

bool comp(std::pair<int, int> a, std::pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    int n, k;
    std::scanf("%d%d", &n, &k);
    std::vector<std::pair<int, int >> towers(n, std::make_pair(0, 0));// pair.first=塔高,pair.second=index
    std::vector<std::pair<int, int >> moves;//pair.first=hight towers index,pair.second=lower towers index
    initVector(towers);
    std::sort(towers.begin(), towers.end(), comp);//sort后vector.size()丢失，不知道为啥?
    std::pair<int, int> result = getResult(towers, moves,n,k);//pair.first=s,pair.second=m
    printResult(moves, result);
    return 0;
}
