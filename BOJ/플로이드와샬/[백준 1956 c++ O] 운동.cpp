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
[백준 1956 c++ O] 운동
문제:
접근:
시간복잡도: O(n^3)
풀이: 모든 정점의 최소비용 -> 플로이드와샬
    //1.초기화: 비용배열 최댓값으로
    //2.입력
    //3.최단거리: 모든 노드에서 노드까지 최단거리 -> 플로이드 와샬
    //1) 3중 포문: k를 거쳐가는 i->j까지 비용,
    //4.출력: 시작점과 도착점이 같은 사이클 중 최단거리, 없으면 -1
*/
int n, m,n1,n2,dist;
int INF = 2100000000;
int d[405][405];
int minDist = INF;

void init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = INF;
        }
    }
}

void flo() {
    
    for (int k = 1; k <= n; k++) {

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][k] != INF && d[k][j] != INF) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.초기화: 비용배열 최댓값으로
    cin >> n >> m;
    init();
    //2.입력
    for (int i = 0; i < m; i++) {
        cin >> n1 >> n2 >> dist;
        d[n1][n2] = dist;
    }
    //3.최단거리: 모든 노드에서 노드까지 최단거리 -> 플로이드 와샬
    //1) 3중 포문: k를 거쳐가는 i->j까지 비용, 
    flo();
    //4.출력: 시작점과 도착점이 같은 사이클 중 최단거리, 없으면 -1
    for (int i = 1; i <= n; i++) {
        if (d[i][i] == INF) continue;
        minDist = min(minDist, d[i][i]);
    }
    if (minDist == INF) cout << -1 << '\n';
    else cout << minDist << '\n';
    return 0;
}
