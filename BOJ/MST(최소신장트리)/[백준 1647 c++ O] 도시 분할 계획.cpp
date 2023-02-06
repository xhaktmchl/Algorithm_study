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
[백준 1647 c++ O] 도시 분할 계획
문제: 
접근1: 
시간복잡도: O(nlogn)
풀이1: 간선 구조체 배열 정의
    //1.입력
    //2.MST-크루스칼(유니온 파인드)
    //부모배열 초기화
    //1)정렬: 간선배열 오름차순
    //2)비용이 작은 간선부터 연결
    //파인드: 이미 같은 집합이 아니면
    //유니온: 합집합
    //3.출력: 최소 비용
풀이2: 간선 벡터베열 이용
*/
int n, m,a,b,c;
int par[100005];
int sum = 0, cnt=1;

struct ed {
    int n1, n2;
    int dist;
    
    bool operator<(ed& ref) { // 비교연산자 정의
        return this->dist < ref.dist;
    }
}Ed[1000005];

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
    //1.입력
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> Ed[i].n1 >> Ed[i].n2 >> Ed[i].dist;
    }
    //2.MST-크루스칼(유니온 파인드)
    //부모배열 초기화
    init();
    //1)정렬: 간선배열 오름차순
    sort(Ed, Ed + m);
    //2)비용이 작은 간선부터 연결
    //파인드: 이미 같은 집합이 아니면
    //유니온: 합집합
    for (int i = 0; i < m; i++) {
        int n1 = Ed[i].n1, n2 = Ed[i].n2, dist = Ed[i].dist;
        if (fin(n1) != fin(n2)) {
            uni(n1, n2);
            cnt += 1;
            if(cnt<n) sum += dist;
        }
    }
    //3.출력: 최소 비용
    cout << sum << '\n';
    return 0;
}
