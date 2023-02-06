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
[백준 16398 c++ O] 행성 연결
문제:
접근1: 모든 그래프 연결 최소비용 -> MST
시간복잡도: O(nlogn)
풀이1: MST-크루스칼 -> 간선 구조체 배열 정의
    //1.입력
    //2.MST-크루스칼(유니온파인드)
    //부모배열 초기화
    //1)정렬: 간선배열 오름차순
    //2) 유니온 파인드
    //파인드: 같은 집합이 아니면
    //유니온: 합집합, 비용 합
    //3.출력
주의: 간선배열의 크기 부모의 수 n*n보다 커야함, 이유는 모름
풀이2: 간선 벡터베열 이용 vector<int, pair<int,int>>
*/
int n, cnt = 0;
int par[1005];
long long sum = 0;
long long num;

struct ed {
    int n1, n2;
    long long dist;

    bool operator<(ed& ref) {
        return this->dist < ref.dist;
    }
}Ed[1000005]; // 주의: 간선배열의 크기 부모의 수 n*n보다 커야함, 이유는 모름

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
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> num;
            if (j > i) {
                Ed[cnt].n1 = i; Ed[cnt].n2 = j;
                Ed[cnt++].dist = num;
            }
        }
    }
    //2.MST-크루스칼(유니온파인드)
    //부모배열 초기화
    init();
    //1)정렬: 간선배열 오름차순
    sort(Ed, Ed + cnt);
    //2) 유니온 파인드
    //파인드: 같은 집합이 아니면
    //유니온: 합집합, 비용 합
    for (int i = 0; i < cnt; i++) {
        int n1 = Ed[i].n1, n2 = Ed[i].n2;
        long long dist = Ed[i].dist;
        if (fin(n1) != fin(n2)) {
            uni(n1, n2);
            sum += dist;
        }
    }
    //3.출력
    cout << sum << '\n';
    return 0;
}
