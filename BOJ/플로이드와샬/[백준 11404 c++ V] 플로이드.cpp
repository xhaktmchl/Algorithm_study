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
[백준 11404 c++ V] 플로이드
문제:
접근:
시간복잡도:
풀이: 모든 정점의 최소비용 -> 플로이드와샬
    //1.입력
    //2.최단경로: 플로이드와샬
    //1)비용 경로 초기화
    //2)플로이드와샬: k를 거쳐가는 i->j 경로의 최소비용
    //3.출력

주의: 비용의 최댓값이 노드갯수*하나당 최대비용이다.
*/
#define INF 10000001 // 주의: 100개의 도시가 있으니까 이론적으로 최대 10000000 까지 값이 존재할 수 있음
int n, m;
int n1, n2, dist;
int d[105][105];

void flo() {
    //1)비용 경로 초기화
    //2)플로이드와샬: k를 거쳐가는 i->j 경로의 최소비용
    for (int k = 1; k <= n; k++) {
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][k] != INF && d[k][j] != INF) {
                    if (d[i][k] + d[k][j] < d[i][j]) {
                        d[i][j] = d[i][k] + d[k][j];
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
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> n1 >> n2 >> dist;
        if (d[n1][n2] > dist) { // 중복된 입력은 최소 비용만 저장
            d[n1][n2] = dist;
        }
    }

    //2.최단경로: 플로이드와샬
    //1)비용 경로 초기화
    //2)플로이드와샬: k를 거쳐가는 i->j 경로의 최소비용
    flo();
    //3.출력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] == INF || i == j) cout << 0 << " ";
            else cout << d[i][j] << " ";
        }cout << '\n';
    }
    return 0;
}
