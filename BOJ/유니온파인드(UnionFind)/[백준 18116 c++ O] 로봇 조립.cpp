#include <iostream>
#include <algorithm> // fill_n, min,max, swap
//#include <map> // 중복 x 
#include <string> // getline
//#include <cstring> // memset, strok, strstr
//#include <vector>
//#include <queue>
//#include <set> // 트리, 중복 x
//#include <unordered_set>
//#include <cmath>
using namespace std;
/*
[백준 18116 c++ O] 로봇 조립
접근: bfs: 간선 추가해줄 때 마다 bfs로 집합의 갯수 구하기 -> 시간초과 예상
접근2: 유니온파인드: 유니온해줄 때 마다 트리의 노드 갯수도 같이 저장.
시간복잡도:
풀이1:
    //1.입력
    //부모 배열 초기화
    //2.명령
    //1)I면 유니온
    //갯수도 저장
    //2)Q면 갯수 출력
*/
int n,n1,n2;
int par[1000000 + 5];
string op;
int cnt[1000000 + 5];

void init() {
    for (int i = 1; i <= 1000000; i++) {
        par[i] = i;
        cnt[i] = 1;
    }
}

int fin(int node) {
    if (par[node] == node) return node;
    else return par[node] = fin(par[node]); // 경로 압축: 시간 단축
}

void uni(int a, int b) {
    int rootA = fin(a);
    int rootB = fin(b);

    par[rootA] = rootB;
    cnt[rootB] += cnt[rootA]; // 갯수 합
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    cin >> n;
    //부모 배열 초기화, 갯수 배열 초기화
    init();
    
    //2.명령
    //1)I면 유니온
    //갯수도 저장
    //2)Q면 갯수 출력
    for (int t = 0; t < n; t++) {
        cin >> op;
        if (op == "I") {
            cin >> n1 >> n2;
            if (fin(n1) != fin(n2)) uni(n1, n2);
        }
        else if (op == "Q") {
            cin >> n1;
            cout << cnt[fin(n1)] << '\n';
        }
    }
    return 0;
}  
