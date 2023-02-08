#include <iostream>
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
[백준 1753 c++ VV] 최단경로
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
    //2.거리배열 초기화 : INF
    //3.최단 경로: 다익스트라
    //1) 힙 생성, 푸쉬,
    //2) 계속 반복: 방문하지 않은 최소비용 노드 방문
    //3) 기존의 경로비용보다 현재 방문한 노드를 거치는 비용이 더 적으면 업데이트, 힙에 푸쉬
*/
int n, m,startN,a,b,c;
int dist[20005];
int INF = 210000000-1;
vector<pair<int, int>> al[20005]; // 인접 리스트

void init() {
    for (int i = 1; i <= n; i++) dist[i] = INF;
}

void daik() {
    priority_queue<pair<int, int>> pq; // (비용, 노드)
    dist[startN] = 0;
    pq.push({ 0,startN });

    while (!pq.empty()) {
        int no = pq.top().second;
        int co = -pq.top().first; // 음수로 넣었기 때문에 양수로 변환
        pq.pop();

        // 인접 리스트 탐색
        int size = al[no].size();
        for (int i = 0; i < size; i++) {
            int nn = al[no][i].first;
            int nco = al[no][i].second;

            if (dist[nn] > dist[no] + nco) {//2)현재 방문한 노드를 거쳐갈 수 있는 경로 중, 현재 경로의 비용 < 기존 경로 비용 하다면 갱신
                dist[nn] = dist[no] + nco;
                pq.push({ -(dist[no]+nco), nn });
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    cin >> n >> m>> startN;
    //2.거리배열 초기화 : INF
    init();
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        al[a].push_back({ b,c });
    }
    //3.최단 경로: 다익스트라
    //1) 힙 생성, 푸쉬,
    //2) 계속 반복: 방문하지 않은 최소비용 노드 방문
    //3) 기존의 경로비용보다 현재 방문한 노드를 거치는 비용이 더 적으면 업데이트, 힙에 푸쉬
    daik();
    //4.출력
    for (int i = 1; i <= n; i++) {
        if (i == startN) cout << 0 << '\n';
        else if (dist[i] == INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }
    return 0;
}
