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
[백준 20040 c++ O] 사이클 게임
접근: bfs -> 간선 추가할 때 마다 bfs 탐색으로 방문 노드 갯수 세기 -> 풀어보진 않음(시간초과 예상)
접근2: 유니온파인드 -> 간선추가할 때 마다 유니온 하고 -> 만약 두 노드의 부모가 같다면 사이클 완성
시간복잡도:
풀이1:
    //1.입력
    //부모배열 초기화
    //2.유니온
    //이미 두노드가 같은 집합이면 사이클 완성
    //같은 집합 아닐때만 유니온
    //3.출력: 사이클이면 만들어진 순서, 아니면 0
*/
int n, m,n1,n2;
int par[500000 + 10];
int cnt[500000 + 10];
int cycleIdx = 0;

int fin(int node) {
    if (par[node] == node) return node;
    else return par[node] = fin(par[node]); // 경로 압축: 시간단축
}

void uni(int a, int b) {
    int rootA = fin(a);
    int rootB = fin(b);
    par[rootA] = rootB;
    cnt[rootB] += cnt[rootA]; // 트리의 노드 갯수 합치기
}

void init() {
    for (int i = 0; i < n; i++) {
        par[i] = i;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    cin >> n >> m;
    //부모배열 초기화
    init();
    //2.유니온
    //이미 두노드가 같은 집합이면 사이클 완성
    //같은 집합 아닐때만 유니온
    //3.출력: 사이클이면 만들어진 순서, 아니면 0
    for (int i = 0; i < m; i++) {
        cin >> n1 >> n2;
        if (n1 > n2) swap(n1, n2);
        
        if (fin(n1) == fin(n2)) {
            cycleIdx = i+1;
            break;
        }
        if(fin(n1) != fin(n2)) uni(n1, n2);
    }
    cout << cycleIdx << '\n';
    return 0;
}  
