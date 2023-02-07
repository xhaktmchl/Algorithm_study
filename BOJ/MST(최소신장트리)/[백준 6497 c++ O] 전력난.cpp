#include <iostream>
#include <algorithm> // fill_n, min,max, swap
//#include <map> // 중복 x 
//#include <string> // getline
//#include <cstring> // memset, strok, strstr
//#include <vector>
//#include <queue> // priority_queue<자료형, 구현체, 비교 연산자> (중복허용)
//#include <set> // 트리, 중복 x , multiset
//#include <unordered_set>
#include <cmath>
using namespace std;
/*
[백준 6497 c++ O] 전력난 
문제: 
접근1: 모든 그래프 연결 최소비용 -> MST
시간복잡도: O(nlogn)
풀이1: MST-크루스칼 -> 간선 구조체 배열 정의
    //1.입력
    //2.간선 배열 저장
    //3.MST-크루스칼(유니온 파인드)
    //1)부모배열 초기화
    //2)정렬: 간선 비용 오름차순
    //3)유니온 파인드
    //파인드: 같은 집합 아니면
    //유니온: 합집합, 비용 합
    //4.출력
풀이2: 풀이1과 같은데 MST-크루스칼 -> 간선 배열을 벡터로 정의, vector<pair<int, pair<int,int>>>
*/
struct ed {
    int n1, n2;
    int dist;

    bool operator<(ed& ref) {
        return this->dist < ref.dist;
    }
}Ed[200005];
int n, m;
int par[200005];


void init() {
    for (int i = 1; i <= m; i++) par[i] = i;
}

int fin(int node) {
    if (par[node] == node) return node;
    else return par[node] = fin(par[node]); // 경로압축: 시간단축
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
    while (1) {
        int sum = 0, totalDist = 0;
        //1.입력
        cin >> m >> n;
        if (m == 0 && n == 0) break;
        //2.간선 배열 저장
        for (int i = 0; i < n; i++) {
            cin >> Ed[i].n1 >> Ed[i].n2 >> Ed[i].dist;
            totalDist += Ed[i].dist;
        }
        //3.MST-크루스칼(유니온 파인드)
        //1)부모배열 초기화
        init();
        //2)정렬: 간선 비용 오름차순
        sort(Ed, Ed + n);
        //3)유니온 파인드
        //파인드: 같은 집합 아니면
        //유니온: 합집합, 비용 합
        for (int i = 0; i < n; i++) {
            int n1 = Ed[i].n1, n2 = Ed[i].n2, dist = Ed[i].dist;
            if (fin(n1) != fin(n2)) {
                uni(n1, n2);
                sum += dist;
            }
            //4.출력
        }
        cout << totalDist - sum << '\n';
    }
    return 0;
}
