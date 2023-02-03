#include <iostream>
#include <algorithm> // fill_n, min,max, swap
//#include <map> // 중복 x 
//#include <string> // getline
//#include <cstring> // memset, strok, strstr
//#include <vector>
//#include <queue> // priority_queue<자료형, 구현체, 비교 연산자> (중복허용)
//#include <set> // 트리, 중복 x , multiset
//#include <unordered_set>
//#include <cmath>
using namespace std;
/*
[백준 1922 c++ XV] 네트워크 연결
문제:
접근:
시간복잡도:
풀이: MST(최소 신장 트리) -> 크루스칼 -> 유니온 파인드로 탐색
    //1.입력
    //부모배열 초기화
    //2.MST-크루스칼
    //1) 간선의 비용 오름차순으로 정렬
    //2) 최소비용 간선부터 노드와 연결
    //파인드: 이미 같은 집합이면 넘어감
    //유니온: 아니라면 합집합, 최소비용
*/
struct ed {
    int n1, n2;
    int dist;

    bool operator<(ed &ref) { // 비교 연산자 정의
        return this->dist < ref.dist;
    }
}Ed[100010];

int n, m,a,b,c;
int par[1000 + 10];
int sum = 0;

void init() {
    for (int i = 1; i <= n; i++) par[i] = i;
}

int fin(int node) {
    if (par[node] == node) return node;
    else return par[node] = fin(par[node]); // 경로압축: 시간 단축
}

void uni(int a, int b) {
    int rootA = fin(a);
    int rootB = fin(b);

    if (rootA < rootB) par[rootB] = rootA;
    else par[rootA] = rootB;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    //부모배열 초기화
    cin >> n >> m;
    init();
    //2.MST-크루스칼
    for (int i = 0; i < m; i++) {
        cin >> Ed[i].n1 >> Ed[i].n2 >> Ed[i].dist;
    }
    sort(Ed, Ed + m);//1) 간선의 비용 오름차순으로 정렬
    //2) 최소비용 간선부터 노드와 연결
    //파인드: 이미 같은 집합이면 넘어감
    //유니온: 아니라면 합집합, 최소비용
    for (int i = 0; i < m; i++) {
        int n1 = Ed[i].n1; int n2 = Ed[i].n2;
        if (fin(n1) != fin(n2)) {
            uni(n1, n2);
            sum += Ed[i].dist;
        }
    }
    cout << sum << '\n';
    return 0;
}
