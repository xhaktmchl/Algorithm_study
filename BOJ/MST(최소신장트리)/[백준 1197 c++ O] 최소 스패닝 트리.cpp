#include <iostream>
#include <algorithm> // fill_n, min,max, swap
//#include <map> // 중복 x 
//#include <string> // getline
//#include <cstring> // memset, strok, strstr
#include <vector>
//#include <queue> // priority_queue<자료형, 구현체, 비교 연산자> (중복허용)
//#include <set> // 트리, 중복 x , multiset
//#include <unordered_set>
//#include <cmath>
using namespace std;
/*
[백준 1197 c++ O] 최소 스패닝 트리
문제:
접근:
시간복잡도:
풀이: MST(최소 신장 트리) -> 크루스칼 -> 유니온 파인드로 탐색
    //1. 입력
    //2.MST-크루스칼-> 유니온파인드
    //1) 정렬: 간선의 가중치로 오름차순
    //2) 부모배열 초기화
    //3)크루스칼-간선 연결
    //파인드: 이미 같은 집합아닌 것만
    //유니온: 합집합, 가중치더하기 
풀이2: 풀이1과 같은데 간선배열을 벡터로 구현 vector<pair<int, pair<int,int>>>
*/
struct ed {
    int n1, n2;
    int dist;
    
    bool operator<(ed& ref) { // 비교 연산자 정의
        return this->dist < ref.dist;
    }
}Ed[100005];
int n, m,n1,n2,dist;
int par[10005];
long long sum = 0;

void init() {
    for (int i = 1; i <= n; i++) par[i] = i;
}

int fin(int node) {
    if (par[node] == node) return node;
    else return par[node] = fin(par[node]); // 경로 압축: 시간 단축
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
    //1. 입력
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> Ed[i].n1 >> Ed[i].n2 >> Ed[i].dist;
    }
    //2.MST-크루스칼-> 유니온파인드
    //1) 정렬: 간선의 가중치로 오름차순
    sort(Ed, Ed + m);
    //2) 부모배열 초기화
    init();
    //3)크루스칼-간선 연결
    //파인드: 이미 같은 집합아닌 것만
    //유니온: 합집합, 가중치더하기
    for (int i = 0; i < m; i++) {
        n1 = Ed[i].n1; n2 = Ed[i].n2; dist = Ed[i].dist;
        if (fin(n1) != fin(n2)) {
            uni(n1, n2);
            sum += dist;
        }
    }
    cout << sum << '\n';
    return 0;
}
