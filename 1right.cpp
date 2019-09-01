//
// Created by tmy on 19-9-1.
//
#include <iostream>
#include <vector>
#include <algorithm>
int main(){
    int n,m;
    std::cin>>n;
    std::cin>>m;
    std::vector<int > rows(n,0);
    for (int i=0;i<m;i++){
        int row;
        std::cin>>row;
        rows[row-1] += 1;
    }
    std::sort(rows.begin(),rows.end());
    std::cout<<rows[0];
    return 0;
}

