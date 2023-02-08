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
[백준 1865 c++ V] 웜홀 
문제:
접근1: 1~n에서 각가 벨만포드 시작 -> 시간 초과
접근2: 벨만포드 조건 중 방문한 노드(처음에 시작노드)만 방문한다는 조건 빼서 모든 노드에서 시작하는 로직으로 바꿔야 함
시간복잡도: O(VE)
풀이: 한점에서 모든 노드까지 최단 거리, 음수간선 존재 -> 벨만 포드
    //1.입력
    //2.음의 사이클 존재 유무: 벨만포드
    //1)거리배열 무한대로 초기화
    //2)시작노드 저장-이 문제에선 생략
    //3)n-1번 반복: 노드개수-1만큼 모든 간선탐색
    //시작노드가 정해지지 않았기 때문에 방문한 노드만 탐색조건은 생략
    //만약 현재노드까지 비용+다음노드비용 < 기존 다음 노드비용이라면 갱신
    //4)n번째에도 갱신이 된다면 음의 사이클 존재
주의: dist배열 longlong 아니면 출력초과
*/
struct ed {
    int start, end;
    int cost;
};
int T,n,m,w,s,e,c;
vector<ed> eds; // 간선 벡터
long long dist[505]; // INF가 두번 더해지면 int의 범위를 넘기때문에longlong
int INF = 2100000000 - 1;

bool bellman() {
    for (int i = 1; i <= n; i++) dist[i] = INF;
    
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m*2+w; j++) { // 도로는 양방향이라 개수*2배
            if (dist[eds[j].start] + eds[j].cost < dist[eds[j].end]) { // 벨만포드 조건 중 방문한 노드(처음에 시작노드)만 방문한다는 조건 빼서 모든 노드에서 시작하는 로직으로 바꿔야 함
                dist[eds[j].end] = dist[eds[j].start] + eds[j].cost;
                if (i == n - 1) return true; // n번째에도 갱신되면 음의 사이클 존재
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    cin >> T;
    while (T--) {
        eds.clear();
        cin >> n >> m >> w;
        for (int i = 0; i < m; i++) {
            cin >> s >> e >> c;
            eds.push_back({ s,e,c });
            eds.push_back({ e,s,c }); // 도로는 양방향
        }
        for (int i = 0; i < w; i++) {
            cin >> s >> e >> c;
            eds.push_back({ s,e,-c }); // 웜홀은 단방향
        }
        //2.음의 사이클 존재 유무: 벨만포드
        //1)거리배열 무한대로 초기화
        //2)시작노드 저장-이 문제에선 생략
        //3)n-1번 반복: 노드개수-1만큼 모든 간선탐색
        //시작노드가 정해지지 않았기 때문에 방문한 노드만 탐색조건은 생략
        //만약 현재노드까지 비용+다음노드비용 < 기존 다음 노드비용이라면 갱신
        //4)n번째에도 갱신이 된다면 음의 사이클 존재
        bool isMinusCycle = bellman();
        if (isMinusCycle) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
