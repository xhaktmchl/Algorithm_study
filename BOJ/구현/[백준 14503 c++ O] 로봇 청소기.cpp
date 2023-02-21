#include <iostream>
#include <algorithm> // fill_n, min,max, swap
//#include <map> // 중복 x 
//#include <string> // getline
//#include <cstring> // memset, strok, strstr
//#include <vector>
//#include <queue> // priority_queue<자료형, 구현체, 비교 연산자> (중복허용), 
//#include <set> // 트리, 중복 x , multiset
//#include <unordered_set>
//#include <cmath>
using namespace std; // lower_bound, upper_bound
/*
[백준 14503 c++ O] 로봇 청소기
문제:
접근: 
시간복잡도: O()
풀이:     
    //1.입력
    //2.dfs: 시뮬 그래프 탐색:
    //1)현재 칸이 청소되지 않은 경우 현재 칸을 청소한다.
    //2) 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
    //반시계 방향으로 90도 회전한다.
    //바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
    //1번으로 돌아간다.
    //3) 현재 칸의 주변 $4$칸 중 청소되지 않은 빈 칸이 없는 경우,
    //바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
    //바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
    //3.출력
주의: dfs로 4방향 탐색할 때 청소기는 한번 방향을 정하면 다른 방향으로 가지 않는 조건을 빼먹어서 틀림.
*/
int n, m,sr,sc,sdir;
int gr[55][55];
int visit[55][55];
int dy[4] = { -1,0,1,0 }; // 상좌하우: 반시계 방향
int dx[4] = { 0,1,0,-1 };
int maxCnt = 0;

void simul(int r, int c, int dir, int cnt) {
    bool Bin = 1;
    int rr = 0, cc = 0;

    //1)현재 칸이 청소되지 않은 경우 현재 칸을 청소한다.
    if (!visit[r][c]) {
        visit[r][c] = 1; cnt += 1;
    }
    maxCnt = max(maxCnt, cnt);

    //2) 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
    //반시계 방향으로 90도 회전한다.
    //바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
    //1번으로 돌아간다.
    for (int i = dir+3; i >= dir; i--) {
        rr = r + dy[i%4];
        cc = c + dx[i%4];

        if (rr < 1 || rr > n || cc < 1 || cc > m) continue; // ㅇㅖ외:범위검사
        if (gr[rr][cc] == 1) continue; // 예외: 벽이면 이동 못함
        if (!visit[rr][cc]) {
            Bin = 0;
            simul(rr, cc, i, cnt);
            break; // 예외: 찾으면 그 방향만으로 가야된다
        }
    }

    //3) 현재 칸의 주변 $4$칸 중 청소되지 않은 빈 칸이 없는 경우,
    //바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
    //바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
    if (Bin) {
        rr = r + dy[(dir + 2)%4]; // 후진
        cc = c + dx[(dir + 2)%4];
        if (rr < 1 || rr > n || cc < 1 || cc > m) return;
        if (gr[rr][cc] == 1) return;
        simul(rr, cc, dir, cnt); // dir 방향은 그대로
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    cin >> n >> m>>sr>>sc>>sdir;
    sr += 1; sc += 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> gr[i][j];
        }
    }
    //2.시뮬 그래프 탐색:
    //1)현재 칸이 청소되지 않은 경우
    //2) 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
    //반시계 방향으로 90도 회전한다.
    //바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
    //1번으로 돌아간다.
    //3) 현재 칸의 주변 $4$칸 중 청소되지 않은 빈 칸이 없는 경우,
    //바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
    //바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
    simul(sr, sc, sdir, 0);
    //3.출력
    cout << maxCnt << '\n';
    return 0;
}
