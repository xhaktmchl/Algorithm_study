#include <iostream>
#include <algorithm>
//#include <map> // 중복 x 
//#include <string> // getline
#include <cstring> // memset
//#include <vector>
//#include <queue>
//#include <set> // 트리, 중복 x
//#include <unordered_set>
using namespace std;
/*
[백준 3584 c++ V] 가장 가까운 공통 조상
접근: 공통 조상 -> LCA
시간복잡도: 
풀이:
    //1.테케
    //부모 배열 초기화
    //2.입력: 간선
    //트리 union
    //3.입력: 두 노드
    //1) LCA
    //한 노드의 루트 노드까지 탐색 및 방문처리
    //다른 노드의 루트노드까지 탐색 및 방문했으면 LCA출력
*/
int T,n,a,b,n1,n2;
int parent[10010];
bool visit[10010];

void node1Visit() {
    while (n1 != parent[n1]) {
        n1 = parent[n1];
        visit[n1] = 1;
    }
}

void LCA(int node) {
    while (1) {
        if (visit[node]) {
            cout << node << '\n';
            break;
        }
        node = parent[node];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //1.테케
    //부모 배열 초기화
    //2.입력: 간선
    //트리 union
    //3.입력: 두 노드
    //1) LCA
    //한 노드의 루트 노드까지 탐색 및 방문처리
    //다른 노드의 루트노드까지 탐색 및 방문했으면 LCA출력
    cin >> T;
    while (T--) {
        memset(visit, 0, sizeof(visit));
        cin >> n;

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < n-1; i++) {
            cin >> a >> b;
            parent[b] = a; // a가 b의 부모
        }
        
        cin >> n1 >> n2;
        visit[n1] = 1;
        node1Visit();

        LCA(n2);
    }
    return 0;
}
