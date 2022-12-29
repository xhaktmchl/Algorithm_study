#include <iostream>
#include <algorithm>
#include <cstring> // memset
using namespace std;
// [백준 10971 c++ VO] 외판원 순회 2
// 문제:
// 접근1:
// 시간복잡도: O(n*nlogn)
// 풀이: 
    //1.입력
    //2.완탐: 배역 각 원소에서 시작
    //방문처리
    //1) 현재 위치에서 dfs:  최소 비용 구하기
    //인접 그래프 탐색
    //예외: 같은 노드로 이동 불가
    //예외: 못가는 경우
    //(1)방문했는데 시작 점이고 n번째 노드이면
    //비용 더하고 최소 비용 갱신
    //(2)방문 안했으면
    //방문처리
    //dfs
    //방문 초기화
    //3.출력: 
int n;
int w[25][25];
bool visit[25];
int minPay = 1987987987;

void dfs(int cnt, int sn, int paySum, int curN) {

    //인접 그래프 탐색
    for (int i = 0; i < n; i++){
        //예외: 같은 노드로 이동 불가
        //예외: 못가는 경우
        if (i == curN) continue;
        if (w[curN][i] == 0) continue;
        //(1)방문했는데 시작 점이고 n번째 노드이면
        //비용 더하고 최소 비용 갱신
        if (i==sn && visit[i] == 1 && cnt+1 == n) {
            minPay = min(minPay, paySum+ w[curN][i]);
            return;
        }
        //(2)방문 안했으면
        //방문처리
        //dfs
        //방문 초기화
        if (visit[i] == 0) {
            visit[i] = 1;
            dfs(cnt + 1, sn, paySum + w[curN][i], i);
            visit[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    //1.입력
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }
    //2.완탐: 배역 각 원소에서 시작
    for (int i = 0; i < n; i++) {
        
        memset(visit, 0, sizeof(visit));
        visit[i] = 1;
        dfs(0, i, 0, i);
        visit[i] = 0;
    }
    //방문처리
    //1) 현재 위치에서 dfs: (row, col, ) , 최소 비용 구하기
    //인접 그래프 탐색
    //(1)방문했는데 시작 점이고 n번째 노드이면
    //비용 더하고 최소 비용 갱신
    //(2)방문 안했으면
    //방문처리
    //dfs
    //방문 초기화
    //3.출력: 
    cout << minPay << '\n';
}
