#include <iostream>
#include <algorithm> // fill_n, min,max, swap
//#include <map> // 중복 x 
//#include <string> // getline
#include <cstring> // memset, strok, strstr
#include <vector>
#include <queue> // priority_queue<자료형, 구현체, 비교 연산자> (중복허용), 
//#include <set> // 트리, 중복 x , multiset
//#include <unordered_set>
//#include <cmath>
using namespace std; // lower_bound, upper_bound
/*
[백준 16236 c++ V] 아기 상어
문제:
접근: bfs로 상,좌,우,하 하면서 찾은 첫번째 먹이로 이동 -> 이러면 틀림 -> 모든 가능한 먹이를 확인해야 함
접근2: bfs+ 완탐
시간복잡도: O()
풀이:
    //1.입력
    //2.완탐 bfs 반복:상어가 먹을 수 있는 모든 물고기 탐색
    //(자신보다 작은 물고기) 로부터 거리,큰 물고기는 못지나감, 도달할 수 있는지
    //도달할 수 있으면
    //1).먹을 수 없다면 중단.
    //2) 물고기 먹을 수 있을때,
    //정렬: 1.거리, 2.행위에, 3.왼쪽열 오름차순
    //1순위 먹이로 상어 이동
    //먹이 먹기:  아기상어의 크기=2, 크기만큼 먹을 때 +1 , 몸집 커짐 검사
    //먹이 지도에서 초기화
    //3.출력: 먹을 먹이가 없을때 까지 걸린 시간
*/
int n, curr, curc, curSize = 2, eatSize = 0, nearFishr, nearFishc;
int a[25][25];
vector<pair<int, int>> fish;
int dist[25][25];
int dy[] = { -1,0,0,1 }; // 상,좌,우,하
int dx[] = { 0,-1,1,0 };
bool visit[25][25];
int time = 0;
vector<pair<int, pair<int, int>>> canEatFish;

void bfs(int r, int c) {
    //초기화
    memset(visit, 0, sizeof(visit));
    memset(dist, 0, sizeof(dist));
    canEatFish.clear();
    nearFishr = 0; nearFishc = 0;

    //bfs
    queue<pair<int, int>> q;
    q.push({ r,c }); visit[r][c] = 1;
    dist[r][c] = 0;

    while (!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();

        //상,좌,우,하 탐색
        for (int i = 0; i < 4; i++) {
            int rr = r + dy[i];
            int cc = c + dx[i];

            //범위검사,
            if (rr<1 || rr>n || cc<1 || cc>n) continue;
            if (!visit[rr][cc]) {
                if (a[rr][cc] != 9 && a[rr][cc] != 0 && a[rr][cc] < curSize) { // (1)상어보다 작은 물고기인 경우
                    dist[rr][cc] = dist[r][c] + 1;
                    visit[rr][cc] = 1;

                    //가능한 경우 모두 넣기
                    canEatFish.push_back({ dist[rr][cc], {rr,cc} });
                    continue;
                }
                if (a[rr][cc] == 0 || a[rr][cc] == curSize || a[rr][cc] == 9) { //(2)그냥 이동할 때
                    q.push({ rr,cc }); visit[rr][cc] = 1;
                    dist[rr][cc] = dist[r][c] + 1;
                }
            }
        }
    }
}

bool mySort(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    //1) 거리 짧은거부터
    if (a.first != b.first) {
        return a.first < b.first;
    }
    //2) 행 위에부터
    if (a.second.first != b.second.first) return a.second.first < b.second.first;
    //3) 열 왼쪽부터
    if (a.second.second != b.second.second) return a.second.second < b.second.second;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);

    //1.입력
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 9) { // 상어의 현재 위치 저장
                curr = i; curc = j;
            }
        }
    }
    //2.완탐 bfs 반복:상어가 먹을 수 있는 모든 물고기 탐색
    //(자신보다 작은 물고기) 로부터 거리,큰 물고기는 못지나감, 도달할 수 있는지
    //도달할 수 있으면
    //1).먹을 수 없다면 중단.
    //2) 물고기 먹을 수 있을때, 
    //정렬: 1.거리, 2.행위에, 3.왼쪽열 오름차순
    //1순위 먹이로 상어 이동
    //먹이 먹기:  아기상어의 크기=2, 크기만큼 먹을 때 +1 , 몸집 커짐 검사
    //먹이 지도에서 초기화   
    //3.출력: 먹을 먹이가 없을때 까지 걸린 시간
    while (1) {
        bfs(curr, curc);
        int canEatSize = canEatFish.size();

        if (canEatSize==0) {
            break;
        }
        else {
            sort(canEatFish.begin(), canEatFish.end(), mySort);
            
            int rr = canEatFish[0].second.first;
            int cc = canEatFish[0].second.second;

            a[curr][curc] = 0;//기존 상어위치 초기화
            // 이동
            curr = rr;
            curc = cc;

            eatSize += 1; // 먹고
            if (eatSize == curSize) { // 몸집 커질 때
                curSize += 1;
                eatSize = 0;
            }

            a[rr][cc] = 0;// 물고기 지도에서 없앰.
            //먹은 먹이의 위치 저장
            nearFishr = rr;
            nearFishc = cc;

            time = time + canEatFish[0].first; // 먹이까지 가는데 시간 추가
        }
    }
    cout << time << '\n';
    return 0;
}
