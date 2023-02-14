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
[백준 1238 c++ O] 파티 
문제:
접근: 다익 n번 반복
시간복잡도: O(n*mlogm)
풀이: 한 노드에서 모든 정점까지의 최단거리, 가중치 양수 -> 다익스트라, 간선 구조체

풀이2: 풀이 1과 같지만, 간선을 pair로 표현+ pq정렬을 -로 함
    //1.입력
    //간선 인접리스트
    //2.최단거리: 다익스트라-모든 노드에서 최단거리 구해서 x까지 오는거+x에서 가는거 비교
    //1) 거리배열 무한으로 초기화
    //2) 힙 생성, 푸쉬, 거리 시작 설정
    //3) 계속 반복: 최소비용 인접 노드 방문
    //4) 기존의 경로비용보다 현재 방문한 노드를 거치는 비용이 더 적으면 업데이트, 힙에 푸쉬
   */
typedef long long ll;
int n, m, x,a,b;
ll c;
vector<pair<int, ll>> al[1005];
ll INF = 1000001;
ll dist[1005][1005];
int node, nn;
ll cost, ncost;
ll maxDist = -1;

void init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
        }
    }
}

void daik(int start){
    priority_queue<pair<ll, int>> pq;

    pq.push({ 0, start });
    dist[start][start] = 0;

    while (!pq.empty()) {
        node = pq.top().second;
        cost = -pq.top().first;
        pq.pop();

        if (dist[start][node] < cost) continue; // 시간 단축;

        int size = al[node].size();
        for (int i = 0; i < size; i++) {
            nn = al[node][i].first;
            ncost = al[node][i].second;

            if (dist[start][node] + ncost < dist[start][nn]) {
                dist[start][nn] = dist[start][node] + ncost;
                pq.push({ -dist[start][nn], nn });
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    //간선 인접리스트
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        al[a].push_back({ b,c });
    }
    //2.최단거리: 다익스트라-모든 노드에서 최단거리 구해서 x까지 오는거+x에서 가는거 비교
    //1) 거리배열 무한으로 초기화
    //2) 힙 생성, 푸쉬, 거리 시작 설정
    //3) 계속 반복: 최소비용 인접 노드 방문
    //4) 기존의 경로비용보다 현재 방문한 노드를 거치는 비용이 더 적으면 업데이트, 힙에 푸쉬
    init();
    for (int i = 1; i <= n; i++) {
        daik(i);
    }
    for (int i = 1; i <= n; i++) {
        if (dist[i][x] != INF && dist[x][i] != INF) {
            maxDist = max(maxDist, dist[i][x] + dist[x][i]);
        }
        
    }
    cout << maxDist << '\n';
    return 0;
}
