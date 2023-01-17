#include <iostream>
#include <algorithm>
//#include <map> // 중복 x 
//#include <string> // getline
#include <vector>
#include <queue>
//#include <set> // 트리, 중복 x
//#include <unordered_set>
using namespace std;
/*
[백준 1922 c++ X] 네트워크 연결
접근: 
시간복잡도: 
풀이: MST(최소 신장 트리) -> 유니온 파인드로 탐색
*/
struct e_t {
    int a, b, c;
    // 정렬 시 cmp 정의
    const inline bool operator<(const e_t &ref) const {
        return this->c < ref.c;
    }
}Edge[100000];

int n, m;
int a, b, co;
int parent[1001];
int answer = 0;

int fin(int node) {
    if (parent[node] == node) return node;
    return parent[node] = fin(parent[node]); // 경로 압축, 시간 단축
}

void uni(int a, int b) {
    int rootA = fin(a), rootB = fin(b);
    parent[rootA] = rootB;
}

void mst() {
    for (int i = 0; i < m; i++) {
        if (fin(Edge[i].a) == fin(Edge[i].b)) continue; // 같은 그룹이면
        else uni(Edge[i].a, Edge[i].b); // 아니면 합집합
        answer += Edge[i].c;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //1.입력
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> Edge[i].a >> Edge[i].b >> Edge[i].c;
    }
    // 서로소집합 U배열 초기화
    for (int i = 1; i <= n; i++) parent[i] = i;
    // 간선표 오름차순 정렬 - 최소 비용부터 탐색하기 위해?
    sort(Edge, Edge + m);

    mst();
    
    cout << answer << '\n';
    return 0;
}
