#include <cstdio>
#include <algorithm>

using namespace std;
/*
[알고리즘잡스 ch12 02 V] 단지 번호 붙이기(강사님 풀이)
풀이: dfs
//1.2차원 그래프 입력
//2.반복 완탐으로 각 위치에서 집 있고 방문 안했으면 dfs
//3.단지 수, 각 단지의 집 수 오름차순출력
시간복잡도: O(V+E)= 
개선된 점: // 배열을 1,1 부터 채웠으므로 패딩을 시켜 dfs 중 좌표의 범위체크 안해도 됨
*/

const int MAX = 30;

int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, 1, -1, 0};
int n;
int Map[MAX][MAX];
vector <int> result;

int getGroup(int y, int x) {
    int cnt = 0;

    Map[y][x] = 0;
    cnt++;

    for(int k=0;k<4;k++) {
        int yy = y + dy[k];
        int xx = x + dx[k];

        if(Map[yy][xx]) { // 배열을 1,1 부터 채웠으므로 패딩을 시켜 좌표의 범위체크 안해도 됨
            cnt += getGroup(yy, xx);
        }
    }

    return cnt;
}

int main() {
    scanf("%d",&n);

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            scanf("%1d",&Map[i][j]);
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(Map[i][j]) {
                result.push_back(getGroup(i, j));
            }
        }
    }

    sort(result.begin(), result.end());

    printf("%d\n",result.size());

    for(int i=0;i<result.size();i++) printf("%d\n",result[i]);

    return 0;
}
