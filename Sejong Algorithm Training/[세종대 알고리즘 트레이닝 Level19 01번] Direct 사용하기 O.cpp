#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level19 01번] Direct 사용하기 O
문제:
접근: direct기법 방향 탐색,
풀이:
시간복잡도: O()=
*/
int arr[3][3] = {
    {3, 5, 4},
    {1, 1, 2},
    {1, 3, 9}
};

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int row, col, sum = 0;


int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

    //1.입력,: 좌표
    cin >> row >> col;
    //2.좌표에서 상우하좌 탐색
    // 범위검사
    // 상우하좌 합 구하기
    for (int i = 0; i < 4; i++) {
        int rr = row + dy[i];
        int cc = col + dx[i];

        if (rr < 0 || rr >= 3 || cc < 0 || cc >= 3) { continue; }
        sum += arr[rr][cc];
    }
    //3.출력: 합
    cout << sum;
	return 0;
}
