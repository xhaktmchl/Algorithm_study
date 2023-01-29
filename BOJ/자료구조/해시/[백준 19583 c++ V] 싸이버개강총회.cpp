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
[백준 19583 c++ V] 싸이버개강총회
문제: 
접근: 사람 출석 여부 체크; -> 메모이제이션 or 해시맵
시간복잡도:
풀이1: 문제가 틀린듯 -> 문제에선 1시간 이전에 기록이 있어야 입장이라는데 그냥 시작시간 이전이어야 맞음
    //1.입력: 개총시작, 끝, 스트리밍 끝
    //2.만약 개총시작-1 ~ 개총시작 사이 시간이면 입장 여부 해시에 추가
    //3.만약 개총 끝 ~ 스트리밍 끝 사이고 입장여부 체크되어 있으면 출석 카운트
개념: map 자료구조 insert 2가지 방법
1) map.insert({키, 값});
2) map[키]=값;

개념: map 자료구조 find 2가지 방법
1) map.find(키) == iterator와 같다
2) map[키] == 값과 같다
*/
string S, E, Q;
string t,na;
int s1, s2, e1, e2, q1, q2,t1,t2;
map<string, int> m, res;
int cnt = 0;

void input() {
    cin >> S >> E >> Q;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력: 개총시작, 끝, 스트리밍 끝
    input();
    
    //2.만약 개총시작-1 ~ 개총시작 사이 시간이면 입장 여부 해시에 추가
    //3.만약 개총 끝 ~ 스트리밍 끝 사이고 입장여부 체크되어 있으면 출석 카운트
    while (cin >> t >> na) {
        if (t <= S) m.insert({ na,1 });
        else if (t >= E && t <= Q) {
            if (m.find(na) != m.end()) res.insert({ na,1 });
        }
    }
    cout << res.size() << '\n';
    return 0;
}  
