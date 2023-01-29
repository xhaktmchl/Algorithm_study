#include <iostream>
#include <algorithm> // fill_n, min,max, swap
#include <map> // 중복 x 
#include <string> // getline
//#include <cstring> // memset, strok, strstr
//#include <vector>
//#include <queue>
//#include <set> // 트리, 중복 x
//#include <unordered_set>
//#include <cmath>
using namespace std;
/*
[백준 4358 c++ VV] 생태학
문제: 
접근: 나무이름에 따른 갯수저장 -> map stl이용
시간복잡도:
풀이1: 
    //1.입력
    //2.해시에 저장 (이름, 개수)
    //전체 나무 갯수 카운트
    //3.완탐:해시 탐색, 출력
개념: map 자료구조 insert 2가지 방법
1) map.insert({키, 값});
2) map[키]=값;

개념: map 자료구조 find 2가지 방법
1) map.find(키) == iterator와 같다
2) map[키] == 값과 같다

개념: 소수점 고정 
cout << fixed;
cout.precision(4);
*/
string tree;
map<string, float> m;
float totalCnt = 0;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    while (getline(cin, tree)) {
        if (m.find(tree) != m.end()) {
            m[tree] += 1;
        }
        else m[tree] = 1;
        totalCnt += 1;
    }
    //2.해시에 저장 (이름, 개수)
    //전체 나무 갯수 카운트
    //3.완탐:해시 탐색, 출력
    cout << fixed;
    cout.precision(4);
    for (auto it = m.begin(); it != m.end(); it++) {
        float per = (it->second * 100) / totalCnt;

        cout << it->first << " " << per << '\n';
    }
    return 0;
}  
