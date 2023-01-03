#include <iostream>
#include <algorithm>
using namespace std;
/*
[백준 11659 c++ O] 구간 합 구하기 4
문제:
접근1: 완탐 -> 시간 초과
접근2: 누적합
시간복잡도: 
풀이:
    //1.입력
    //2.누적합 저장
    //3.m번 구간합 구하기
    //4.출력
*/
int n, m, n1, n2;;
int a[100010];
int pSum[100010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    //1.입력
    cin >> n >> m;
    //2.누적합 저장
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pSum[i] = pSum[i - 1] + a[i];
    }
    //3.m번 구간합 구하기
    //4.출력
    for (int i = 0; i < m; i++) {
        cin >> n1 >> n2;
        cout << pSum[n2] - pSum[n1 - 1]<<'\n';
    }
}
