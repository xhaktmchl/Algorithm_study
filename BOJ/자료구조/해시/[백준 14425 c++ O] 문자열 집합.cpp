#include <iostream>
#include <algorithm> // fill_n, min,max, swap
#include <map> // 중복 x 
//#include <string> // getline
//#include <cstring> // memset, strok, strstr
//#include <vector>
//#include <queue> // priority_queue<자료형, 구현체, 비교 연산자>
//#include <set> // 트리, 중복 x
//#include <unordered_set>
//#include <cmath>
using namespace std;
/*
[백준 14425 c++ O] 문자열 집합
문제: 
접근: 
시간복잡도: O(n)
풀이1: 
    //1.입력
    //2.해시맵에 저장
    //3.출력: 갯수
*/
int n, m,cnt=0;
string na;
map<string, int> ma;

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> na;
        ma.insert({ na,1 });
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    input();
    //2.해시맵에 저장
    //3.출력: 갯수
    for (int i = 0; i < m; i++) {
        cin >> na;
        if (ma.find(na) != ma.end()) cnt += 1;
    }
    cout << cnt << '\n';
    return 0;
}  
