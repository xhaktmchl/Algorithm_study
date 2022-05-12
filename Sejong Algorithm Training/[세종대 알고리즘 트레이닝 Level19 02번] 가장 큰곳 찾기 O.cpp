#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level19 02번] 가장 큰곳 찾기 O
문제:
접근: 완탐, direct기법 방향 탐색,
풀이:
시간복잡도: O()=
*/
int Map[5][5] = {
    {3, 3, 5, 3, 1},
    {2, 2, 4, 2, 6},
    {4, 9, 2, 3, 4},
    {1, 1, 1, 1, 1},
    {3, 3, 5, 9, 2}
};

int rr, cc, maxSum=0,maxR,maxC;
int dx[4] = { 1,1,-1,-1 };
int dy[4] = { -1,1,1,-1 };

// (y, x)좌표로부터 대각선 방향의 합을 반환
//1)대각 4방향 합 검사
    //대각 4방향 좌표
    //범위 검사
    //합이 최대이면 갱신, 좌표값 저장
int sum(int y, int x) {
    int tpSum = 0;
    for (int i = 0; i < 4; i++) {
        rr = y + dy[i];
        cc = x + dx[i];
        if (rr < 0 || rr >= 5 || cc < 0 || cc >= 5) {
            continue;
        }
        tpSum += Map[rr][cc];
    }
    return tpSum;
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
    
    //1.완탐: map배열에서 각 좌표 탐색
    //1)대각 4방향 합 검사
    //대각 4방향 좌표
    //범위 검사
    //합이 최대이면 갱신, 좌표값 저장
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int tp = sum(i, j);
            if (maxSum < tp) {
                maxSum = tp;
                maxR = i;
                maxC = j;
            }
        }
    }
    //3.출력: 행,렬
    cout << maxR<<" " << maxC;
	return 0;
}
