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
[백준 1916 c++ V] 최소비용 구하기
문제:
접근: 
주의: 시간 단축을 위한 방법이 2가지 있다. -> 첫 시작 노드 가중치 정렬, 다익중간에 탐색안하기
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
typedef long long ll;
int n, m;
int a, b;
ll c;
vector <pair<ll, int>> al[1005]; // 인접 리스트
int startN, endN;
ll dist[1005];
int node,nn;
ll cost, ncost;
ll INF = 100000000000;

void init() {
    for (int i = 1; i <= n; i++) dist[i] = INF;
}

void daik(int start) {
    init();

    priority_queue<pair<ll, int>> pq;
    pq.push({ 0, start });
    dist[start] = 0;

    while (!pq.empty()) {
        node = pq.top().second;
        cost = -pq.top().first;
        pq.pop();

        if (dist[node] < cost) continue; //주의: 시간 단축

        int size = al[node].size();
        for (int i = 0; i < size; i++) {
            nn = al[node][i].second;
            ncost = al[node][i].first;

            if (dist[node] + ncost < dist[nn]) {
                dist[nn] = dist[node] + ncost;
                pq.push({ -dist[nn], nn });
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    //방향간선 인접리스트
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        al[a].push_back({ c,b });
    }
    for (int i = 1; i <= n; i++) sort(al[i].begin(), al[i].end()); // 주의: 시간 단축 방법2: 비용 오름차순 정렬 
    
    //2.최단거리: 한점에서 다른점 -> 다익스트라
    //1)거리배열 무한대로 초기화
    //2)힙 생성, 푸쉬, 거리 저장
    //3) 계속 반복: 최소비용 인접 노드 방문
    //4) 기존의 경로비용보다 현재 방문한 노드를 거치는 비용이 더 적으면 업데이트, 힙에 푸쉬
    cin >> startN >> endN;
    daik(startN);
    cout << dist[endN] << '\n';
    return 0;
}
