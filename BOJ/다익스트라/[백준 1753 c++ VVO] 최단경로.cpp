#include <iostream>
#include <algorithm> // fill_n, min,max, swap
//#include <map> // 중복 x 
//#include <string> // getline
//#include <cstring> // memset, strok, strstr
#include <vector>
#include <queue> // priority_queue<자료형, 구현체, 비교 연산자> (중복허용), 
//#include <set> // 트리, 중복 x , multiset
//#include <unordered_set>
//#include <cmath>
using namespace std; // lower_bound, upper_bound
/*
[백준 1753 c++ VVO] 최단경로
문제:
접근:
시간복잡도: O()
풀이: 한 노드에서 모든 정점까지의 최단거리, 가중치 양수 -> 다익스트라, 간선 구조체
    //1.입력
    //2.초기화: 거리배열 INF로
    //3.최단거리: 다익스트라
    //1)방문하지 않은 노드 중 최단거리 먼저 방문
    //2)현재 방문한 노드를 거쳐갈 수 있는 경로 중, 현재 경로의 비용 < 기존 경로 비용 하다면 갱신
    //4.출력
풀이2: 풀이 1과 같지만, 간선을 pair로 표현+ pq정렬을 -로 함
    //1.입력
    //방향 간선 구조체 배열 입력
    //2.최단거리: 다익스트라
    //1) 거리배열 무한대 초기화
    //2) 힙 생성, 푸쉬
    //3) 계속 반복: 최소비용 인접 노드 방문
    //4) 기존의 경로비용보다 현재 방문한 노드를 거치는 비용이 더 적으면 업데이트, 힙에 푸쉬
*/
struct n_t {
    int next;
    long long cost;

    inline bool operator<(const n_t& ref) const{
        return this->cost > ref.cost;  // 오름차순 정렬 작은게 앞
    }
};
int n, m, startN,a,b,c;
int INF = 2100000000-1;
long long dist[20005];

vector<n_t> al[20005]; // 인접 리스트

void init() {
    for (int i = 1; i <= n; i++) dist[i] = INF;
}

void daik(int start) {
    init();

    priority_queue<n_t> pq;
    pq.push({ start, 0 });
    dist[start] = 0;

    while (!pq.empty()) {
        n_t cur = pq.top();
        pq.pop();
        // 현재노드의 인접 노드 탐색
        int size = al[cur.next].size();
        for (int i = 0; i < size; i++) {
            n_t nn = al[cur.next][i];

            //2)현재 방문한 노드를 거쳐갈 수 있는 경로 중, 현재 경로의 비용 < 기존 경로 비용 하다면 갱신
            if (dist[cur.next] + nn.cost < dist[nn.next]) {
                dist[nn.next] = dist[cur.next] + nn.cost;
                pq.push({ nn.next, dist[nn.next] });
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    //방향 간선 구조체 배열 입력
    cin >> n >> m >> startN;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        al[a].push_back({ b,c });
    }
    //2.최단거리: 다익스트라
    //1) 거리배열 무한대 초기화
    //2) 힙 생성, 푸쉬
    //3) 계속 반복: 최소비용 인접 노드 방문
    //4) 기존의 경로비용보다 현재 방문한 노드를 거치는 비용이 더 적으면 업데이트, 힙에 푸쉬
    daik(startN);

    for (int i = 1; i <= n; i++) {
        if (i == startN) cout << 0 << '\n';
        else if (dist[i] == INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }
    return 0;
}
