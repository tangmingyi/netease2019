//
// Created by zb198 on 2019/9/3.
//
#include <iostream>
#include <math.h>


void initPoint(std::pair<int, int> &point, std::pair<int, int> &conter) {
    std::cin >> point.first;
    std::cin >> point.second;
    std::cin >> conter.first;
    std::cin >> conter.second;
}


std::pair<int, int> helpFunction(const std::pair<int, int> point, const std::pair<int, int> conter) {
    int x, y;
    if (point.first < conter.first) {
        x = -1;
    } else {
        x = 1;
    }
    if (point.second < conter.second) {
        y = -1;
    } else {
        y = 1;
    }
    if (x == 1 && y == 1) {
        x = -1;
    } else if (x == -1 && y == 1) {
        y = -1;
    } else if (x == -1 && y == -1) {
        x = 1;
    } else {
        y = 1;
    }
    return std::make_pair(x, y);
}

void getNextPoint(std::pair<int, int> &point, const std::pair<int, int> conter) {
    int xchange = std::abs(conter.first - point.first);
    int ychange = std::abs(conter.second - point.second);
    std::pair<int, int> temp = helpFunction(point, conter);
    point.first = conter.first + temp.first * ychange;
    point.second = conter.second + temp.second * xchange;
}

void getNextPoint(int num, std::pair<int, int> &point, const std::pair<int, int> conter) {
    for (int i = 0; i < num; i++) {
        getNextPoint(point, conter);
    }
}

void getNextPoint(std::pair<int, int> &point, const std::pair<int, int> conter, int &step, int num = 1) {
    int a = 0;
    getNextPoint(num, point, conter);
    step += num;
}

bool equal(std::pair<int, int> a, std::pair<int, int> b) {
    return (a.first == b.first) && (a.second == b.second);
}

bool isRight(std::pair<int, int> a, std::pair<int, int> b, std::pair<int, int> c, std::pair<int, int> d) {
    if(equal(a,b)){  //a,b同点的情况比较难发现
        return false;
    }
    int num = 1;
    std::pair<int, int> c1({a.first, a.second});
    std::pair<int, int> d1({b.first, b.second});
    getNextPoint(num, c1, b);
    if (!equal(c1, c)) {
        num = 3;
        c1.first = a.first;
        c1.second = a.second;
        getNextPoint(num, c1, b);
    }
    if (!equal(c1, c)) {
        return false;
    }
    getNextPoint(num, d1, c);
    return equal(d1, d);
}

void test() {
    std::pair<int, int> a(1, 1), b(-1, 1), c(-1, -1), d(1, -1), conter1(0, 0), conter2(0, 0), conter3(0, 0), conter4(0,0);
    if (isRight(a, b, c, d)) {
        std::printf("is right");
    } else {
        std::printf("is false");
    }
}

int getResult(std::pair<int, int> a, std::pair<int, int> b, std::pair<int, int> c, std::pair<int, int> d,std::pair<int, int> conter1,
              std::pair<int, int> conter2, std::pair<int, int> conter3, std::pair<int, int> conter4) {
    int result = -1;
    int astep = 0;
    for (int i = 0; i < 4; i++) {
        if (i != 0) {
            getNextPoint(a, conter1, astep);
        }
        int bstep = 0;
        std::pair<int, int> btemp(b.first,b.second);
        for (int j = 0; j < 4; j++) {
            if (j != 0) {
                getNextPoint(btemp, conter2, bstep);
            }
            int cstep = 0;
            std::pair<int, int> ctemp(c.first,c.second);
            for (int s = 0; s < 4; s++) {
                if (s != 0) {
                    getNextPoint(ctemp, conter3, cstep);
                }
                int dstep = 0;
                std::pair<int, int> dtemp(d.first,d.second);
                for (int m = 0; m < 4; m++) {
                    if (m != 0) {
                        getNextPoint(dtemp, conter4, dstep);
                    }
                    if (isRight(a, btemp, ctemp, dtemp)) {
                        int step = astep + bstep + cstep + dstep;
                        if (result == -1 || result > step) {
                            result = step;
                        }
                        break;
                    }
                }
            }
        }
    }
    return result;
}

int main() {
//    test();
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::pair<int, int> a, b, c, d, conter1, conter2, conter3, conter4;
        initPoint(a, conter1);
        initPoint(b, conter2);
        initPoint(c, conter3);
        initPoint(d, conter4);
        int result = getResult(a,b,c,d,conter1,conter2,conter3,conter4);
        std::cout << result << std::endl;
    }
    return 0;
}
