#include <iostream>
#include <algorithm>
using namespace std;
/*
[백준 14929 c++ V] 귀찮아 (SIB)
문제:
접근1: 완탐 -> 시간 초과 
접근2: 누적 합
풀이: 
    //1.입력
    //2.완탐: 구간합 구하기
    //3.출력:
*/
int n;
int a[100010];
int sum[100010];
long long resSum = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    //1.입력
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    //2.완탐: 구간합 구하기
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i < n; i++) {
        resSum += a[i] * (sum[n] - sum[i]);
        //cout << resSum << '\n';
    }
    //3.출력:
    cout << resSum << '\n';
}
