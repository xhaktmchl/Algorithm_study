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
[백준 11404 c++ VO] 플로이드
문제:
접근:
시간복잡도:
풀이: 모든 정점의 최소비용 -> 플로이드와샬
    //1.입력
    //중복된 경로는 최소비용으로 입력
    //2.최단경로: 플로이드와샬
    //1)비용 경로 초기화
    //2)플로이드와샬: k를 거쳐가는 i->j 경로의 최소비용 3중 포문
    //3.출력

주의: 비용의 최댓값이 노드갯수*하나당 최대비용이다.
*/
int n, m,a,b,d;
int dist[105][105];
int INF = 10000005;

void init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
        }
    }
}

void flo() {

    for (int k = 1; k <= n; k++) {

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    //중복된 경로는 최소비용으로 입력
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> d;
        if (dist[a][b] > d) {
            dist[a][b] = d;
        }
    }
    //2.최단경로: 플로이드와샬
    //1)비용 경로 초기화
    //2)플로이드와샬: k를 거쳐가는 i->j 경로의 최소비용 3중 포문
    flo();
    //3.출력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF || i==j) cout << 0 << " ";
            else cout << dist[i][j] << " ";
        }cout << '\n';
    }
    return 0;
}
