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
[백준 11657 c++ VO] 타임머신
문제:
접근:
시간복잡도: O(VE) = 3000만
풀이: 한점에서 모든 노드까지 최단 거리, 음수간선 존재 -> 벨만 포드
    //1.입력: 간선 벡터
    //2.최단 경로: 음수 -> 벨만포드
    //1)거리배열 무한대로 초기화
    //2) 시작 노드 설정
    //3)n-1번 반복: 노드개수-1번 만큼 모든 간선 탐색
    //시작노드부터 시작 조건(방문한 노드만 탐색
    //만약 현재까지 경로비용+다음노드비용 < 기존 다음 노드 경로비용이면 갱신
    //4)n번째에도 갱신되면 음의 사이클 존재
    //3.출력
주의: dist배열 longlong 아니면 출력초과
*/
struct ed {
    int start, end;
    int cost;
};
int n, m,a,b,c;
vector<ed> eds;
int INF = 2100000000 - 1;
long long dist[505]; // INF가 두번 더하면 int범위 초과
int startN;

bool bellman() {
    for (int i= 1; i <= n; i++) dist[i] = INF;
    startN = 1;
    dist[startN] = 0;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {
            if (dist[eds[j].start] != INF && dist[eds[j].start] + eds[j].cost < dist[eds[j].end]) { // 시작노드부터 탐색시작하기 위해 방문 조건 추가
                dist[eds[j].end] = dist[eds[j].start] + eds[j].cost;
                if (i == n - 1) { // n번째 에도 갱신된다면 음의 사이클 존재
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력: 간선 벡터
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        eds.push_back({ a,b,c });
    }
    //2.최단 경로: 음수 -> 벨만포드
    //1)거리배열 무한대로 초기화
    //2) 시작 노드 설정
    //3)n-1번 반복: 노드개수-1번 만큼 모든 간선 탐색
    //시작노드부터 시작 조건(방문한 노드만 탐색
    //만약 현재까지 경로비용+다음노드비용 < 기존 다음 노드 경로비용이면 갱신
    //4)n번째에도 갱신되면 음의 사이클 존재
    bool isMinusCycle = bellman();
    //3.출력
    if (isMinusCycle) cout << -1 << '\n';
    else {
        for (int i = 1; i <= n; i++) {
            if (i == startN) continue;
            else if (dist[i] == INF) cout << -1 << '\n';
            else cout << dist[i] << '\n';
        }
    }
    return 0;
}
