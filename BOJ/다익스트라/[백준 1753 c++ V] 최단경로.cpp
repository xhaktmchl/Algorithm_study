include <iostream>
#include <algorithm> // fill_n, min,max, swap
//#include <map> // 중복 x 
//#include <string> // getline
//#include <cstring> // memset, strok, strstr
#include <vector>
#include <queue> // priority_queue<자료형, 구현체, 비교 연산자> (중복허용)
//#include <set> // 트리, 중복 x , multiset
//#include <unordered_set>
//#include <cmath>
using namespace std;
/*
[백준 1753 c++ V] 최단경로
문제:
접근:
시간복잡도: O()
풀이: 한 노드에서 모든 정점까지의 최단거리, 가중치 양수 -> 다익스트라
    //1.입력
    //2.초기화: 거리배열 INF로
    //3.최단거리: 다익스트라
    //1)방문하지 않은 노드 중 최단거리 먼저 방문
    //2)현재 방문한 노드를 거쳐갈 수 있는 경로 중, 현재 경로의 비용 < 기존 경로 비용 하다면 갱신
    //4.출력
*/
struct n_t {
    int node;
    int cost;
   
    inline bool operator<(const n_t& ref) const{
        return this->cost > ref.cost;
    }// 오름차순 정렬 작은게 앞
};

int INF = 2100000000-1;
int n, m, startN;
int dist[20005]; //거리배열
vector<n_t> v[20005]; // 인접 리스트

void init() {
    for (int i = 1; i <= n; i++) dist[i] = INF;
}

void daik() {
    priority_queue<n_t> pq;
    dist[startN] = 0;
    pq.push({ startN, 0 });

    while (!pq.empty()) {
        n_t cur = pq.top();
        pq.pop();

        // 현재노드의 인접 노드 탐색
        int size = v[cur.node].size();
        for (int i = 0; i < size; i++) {
            int nn = v[cur.node][i].node;
            int ncost = v[cur.node][i].cost;

            if (dist[cur.node] + ncost < dist[nn]) {     //2)현재 방문한 노드를 거쳐갈 수 있는 경로 중, 현재 경로의 비용 < 기존 경로 비용 하다면 갱신
                dist[nn] = dist[cur.node] + ncost;
                pq.push({ nn, dist[cur.node] + ncost });
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    cin >> n >> m>>startN;
    init();
    for (int i = 0; i < m; i++) {
        int n1, n2,cost;
        cin >> n1 >> n2 >> cost;
        v[n1].push_back({ n2,cost }); // 인접 리스트
    }
    //2.초기화: 거리배열 INF로
    //3.최단거리: 다익스트라
    //1)방문하지 않은 노드 중 최단거리 먼저 방문
    //2)현재 방문한 노드를 거쳐갈 수 있는 경로 중, 현재 경로의 비용 < 기존 경로 비용 하다면 갱신
    daik();
    //4.출력
    for (int i = 1; i <= n; i++) {
        if (i == startN) cout << 0 << '\n';
        else if (dist[i] == INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';

    }
    return 0;
}
