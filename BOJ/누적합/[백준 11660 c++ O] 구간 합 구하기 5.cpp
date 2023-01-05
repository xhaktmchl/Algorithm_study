#include <iostream>
#include <algorithm>
using namespace std;
/*
[백준 11660 c++ O] 구간 합 구하기 5
문제:
접근1: 완탐 -> 시간 초과
접근2: 누적합
시간복잡도: O(n)
풀이:
    //1.입력
    //2.행열 까지 누적합 저장
    //i,j까지 누적 합 = (i-1,j)까지 누적 +(i,j-1)까지 누적 - 겹치는구간(i-1,j-1) +마지막 i,j 원소 값
    //3.m개 배열 구간 합 구하기
    //구간 전체 - 좌 세로 구간 - 상 가로 구간 + 좌상 겹치는 구간
*/
int n, m, r1, r2, c1, c2;
int a[1030][1030];
int pSum[1030][1030];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    //1.입력
    //2.행열 까지 누적합 저장
    //i,j까지 누적 합 = (i-1,j)까지 누적 +(i,j-1)까지 누적 - 겹치는구간(i-1,j-1) +마지막 i,j 원소 값
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            pSum[i][j] = pSum[i - 1][j] + pSum[i][j - 1] - pSum[i - 1][j - 1] + a[i][j];
        }
    }

    //3.m개 배열 구간 합 구하기
    //구간 전체 - 좌 세로 구간 - 상 가로 구간 + 좌상 겹치는 구간
    for (int i = 0; i < m; i++) {
        cin >> r1 >> c1 >> r2 >> c2;
        cout << pSum[r2][c2] - pSum[r2][c1 - 1] - pSum[r1 - 1][c2] + pSum[r1 - 1][c1 - 1]<<'\n';
    }
}
