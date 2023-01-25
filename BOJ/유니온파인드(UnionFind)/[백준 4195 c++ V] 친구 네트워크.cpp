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
[백준 4195 c++ V] 친구 네트워크
접근: bfs-> 친구 추가될 때 마다 bfs로 집합의 인원수 확인 -> 시간초과 예상
접근2: 유니온파인드 -> 친구 추가될 때 마다 유니온하고 cnt 배열에 인원수 갱신
시간복잡도: 
풀이1:
    //1.입력
    //부모 배열 초기화
    //2.유니온
    //3.출력: 집합의 노드 갯수
주의1: 친구 관계가 100000개니깐 노드의 갯수는 200000개가 최댓값이다. 당연히 100001노드가 최대인줄 알아서 계속 틀렸다 ㅜ.
주의2: 이미 같은 집합에 속해 있는 노드는 유니온하지 않는예외처리
*/
int T,n;
int par[200010];
string n1, n2;
int nCnt = 0;
int fCnt[200010];

int fin(int node) {
    if (par[node] == node) return node;
    else return par[node] = fin(par[node]); // 경로압축; 시간단축
}

void uni(int a, int b) {
    int rootA = fin(a);
    int rootB = fin(b);
    par[rootA] = rootB; // a트리가 b트리에 자식으로 합침
    fCnt[rootB] += fCnt[rootA]; // 루트가 b인 트리에 갯수 합치기
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    cin >> T;
    
    while (T--) {
        //초기화
        //부모 배열 초기화
        fill_n(fCnt, 200001, 1); nCnt = 0;
        map<string, int> m;
        for (int i = 0; i <= 200000; i++) {
            par[i] = i;
        }
        //2.유니온
        //3.출력: 집합의 노드 갯수
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> n1 >> n2;

            //맵에 없으면 추가
            if (m.find(n1) == m.end()) {
                m.insert({ n1,nCnt++ });
            }
            if (m.find(n2) == m.end()) {
                m.insert({ n2,nCnt++ });
            }
            //맵에서 조회하고
            //유니온
            //친구 수 합하기
            auto it1 = m.find(n1);
            auto it2 = m.find(n2);
            if(fin(it1->second) != fin(it2->second)) uni(it1->second, it2->second); //이미 같은 집합에 속해 있는 노드는 유니온하지 않는예외처리
            
            cout << fCnt[fin(it2->second)] << '\n';
        }
    }
    return 0;
}
