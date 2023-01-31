#include <iostream>
#include <algorithm> // fill_n, min,max, swap
#include <map> // 중복 x 
//#include <string> // getline
//#include <cstring> // memset, strok, strstr
//#include <vector>
#include <queue> // priority_queue<자료형, 구현체, 비교 연산자>
#include <set> // 트리, 중복 x , multiset
//#include <unordered_set>
//#include <cmath>
using namespace std;
/*
[백준 22252 c++ V] 정보 상인 호석
문제: 
접근: 
시간복잡도: 
풀이1: 해시맵으로 (이름, 인덱스) 저장 , 멀티셋으로 중복허용 내림차순 정렬
*/
int n,k,op,num,idx=0;
multiset<int, greater<int>> ms[100000 + 10];
map<string, int> m;
string  na;
long long sum = 0;

priority_queue<int> q;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    //2.명령 입력
    //1) 1명령일 때 
    //2) 2 명령일 때 
    cin >> n;
    for (int t= 0; t < n; t++) {
        cin >> op >> na>>k;
        if (op == 1) {
            
            if (m.find(na) == m.end()) m[na] = idx++;
            auto it = m.find(na);
            int curIdx = it->second;
            
            for (int i = 0; i < k; i++) {
                cin >> num;
                ms[curIdx].insert(num);
            }
        }
        else if (op == 2) {
            auto it = m.find(na);
            if (it != m.end()) {
                int curIdx  = it->second;

                for (int i = 0; i < k;i++) {
                    auto tpit = ms[curIdx].begin();
                    if (tpit == ms[curIdx].end()) break;
                    sum += *tpit;
                    ms[curIdx].erase(tpit);
                }
            }
        }
    }
    cout << sum << '\n';
    return 0;
}
