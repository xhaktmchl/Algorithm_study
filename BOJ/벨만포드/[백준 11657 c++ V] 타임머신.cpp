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
[백준 11657 c++ V] 타임머신
문제:
접근:
시간복잡도: O(VE)
풀이: 한점에서 모든 노드까지 최단 거리, 음수간선 존재 -> 벨만 포드
    //1.입력
    //거리배열 초기화
    //2.최단거리: 벨만포드
    //1)처음 노드 저장
    //2)n-1번 반복: 모든 간선 m개에 대해 현재 간선을 거쳐서 다음노드로 비용 < 기존 다음 노드의 경로비용 이면 갱신
    //3)만약 n번째에도 변화가 존재한다면 음수간선 존재
    //3.출력
주의: dist배열 longlong 아니면 출력초과
*/
struct ed {
    int start, end;
    int cost;
    // 벨만포드는 정렬이 필요 없어서 비교연산자 정의 없음
};
int n, m,a,b,c,startN=1;
vector<ed> eds;
int INF = 2100000000-1;
long long dist[505];
int node, nn, ncost;


void init() {
    for (int i = 1; i <= n; i++)  dist[i] = INF;
}

bool bellman() {
    init();
    dist[startN] = 0;
    
    for (int i = 0; i < n; i++) {
        
        for (int j = 0; j < m; j++) {
            node = eds[j].start; nn = eds[j].end; ncost = eds[j].cost;
            if (dist[node] != INF && dist[nn] > dist[node] + ncost) {
                dist[nn] = dist[node] + ncost;
                if (i == n - 1) { // n번째에도 갱신된다면 음수사이클 존재
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
    //1.입력
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        eds.push_back({ a,b,c });
    }
    
    //2.최단거리: 벨만포드
    //거리배열 초기화
    //1)처음 노드 저장
    //2)n-1번 반복: 모든 간선 m개에 대해 현재 간선을 거쳐서 다음노드로 비용 < 기존 다음 노드의 경로비용 이면 갱신
    //3)만약 n번째에도 변화가 존재한다면 음수간선 존재
    bool minu = bellman();
    //3.출력
    if (minu) cout << -1 << '\n';
    else {
        for (int i = 1; i <= n; i++) {
            if (i == startN) continue;
            else if (dist[i] == INF) cout << -1 << '\n';
            else cout << dist[i] << '\n';
        }
    }
    return 0;
}
