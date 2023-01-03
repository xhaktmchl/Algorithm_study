#include <iostream>
#include <algorithm>
using namespace std;
/*
[백준 2167 c++ O] 2차원 배열의 합
문제:
접근1: 완탐 -> 시간 초과
접근2: 행 마다 누적합 저장해놓으면 -> 배열의 구간 합 계산 가능
시간복잡도: 
풀이:
    //1.입력
    //배열
    //범위
    //2.행 누적합 구하기
    //3.각 구간의 배열 합 구하기
    //4.출력: 구간 합
*/
int n, m, k, xs, ys, xe, ye;
int a[310][310];
int pSum[310][310];

int calSum() {

    //i,j까지 구간합
    int sum = 0;
    //x,y까지 구간합
    for (int i = ys; i <= ye; i++) {
        sum += pSum[i][xe] - pSum[i][xs - 1];
    }
    //두개의 차 + (i,j)원소 합
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    //1.입력
    //배열
    //범위
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            //2.행 누적합 구하기
            pSum[i][j] = pSum[i][j - 1] + a[i][j];
        }
    }

    //3.각 구간의 배열 합 구하기
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> ys >> xs >> ye >> xe;
        //4.출력: 구간 합
        cout << calSum() << '\n';
    }
}
