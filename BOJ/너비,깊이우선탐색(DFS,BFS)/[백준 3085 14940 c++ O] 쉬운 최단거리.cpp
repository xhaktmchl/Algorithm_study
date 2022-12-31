#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
/*
[백준 3085 14940 c++ O] 쉬운 최단거리
문제:
접근: 
시간 복잡도: nlogm+n*n
풀이: 
    //1.입력: 이차원 그래프
    //2.bfs: (시작 행, 시작 열) 목표 지점에서 시작
    //1)큐 생성, 푸쉬, 방문처리, 거리 저장
    //2)큐 빌때까지 반복
    //큐 프론트
    //큐 팝
    //(2)인접 4방위 탐색
    //범위검사
    //방문안했으면
    //큐 푸쉬, 방문처리, 거리저장
    //3.출력: 거리배열
    //그래프 0이면 0
    //방문했으면 거리
    //안했으면 -1
*/
int n, m;
int g[1010][1010];
int sR, sC;
bool visit[1010][1010];
int dist[1010][1010];
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };

void bfs(int r, int c) {
    queue<pair<int,int>> q;
    q.push({ r,c }); visit[r][c] = 1; 
    dist[r][c] = 0;

    while (!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int rr = r + dy[i];
            int cc = c + dx[i];

            if (rr<0 || rr>n || cc<0 || cc>m) continue;
            if (!visit[rr][cc] && g[rr][cc]!=0) {
                q.push({ rr,cc }); visit[rr][cc] = 1;
                dist[rr][cc] = dist[r][c] + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    //1.입력: 이차원 그래프
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 2) {
                sR = i;
                sC = j;
            }
        }
    }
    //2.bfs: (시작 행, 시작 열) 목표 지점에서 시작 
    //1)큐 생성, 푸쉬, 방문처리, 거리 저장
    //2)큐 빌때까지 반복
    //큐 프론트
    //큐 팝
    //(2)인접 4방위 탐색
    //범위검사
    //방문안했으면 
    //큐 푸쉬, 방문처리, 거리저장
    bfs(sR, sC);
    //3.출력: 거리배열
    //그래프 0이면 0
    //방문했으면 거리
    //안했으면 -1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 0) cout << "0 ";
            else if (visit[i][j]) cout << dist[i][j] << " ";
            else cout << "-1 ";
        }cout << '\n';
    }
}
