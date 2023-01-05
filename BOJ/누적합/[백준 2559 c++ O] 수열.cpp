#include <iostream>
#include <algorithm>
using namespace std;
/*
[백준 2559 c++ O] 수열
문제:
접근1: 완탐 -> 시간 초과
접근2: 누적합
시간복잡도: O(n)
풀이:
    //1.입력
    //2.누적합
    //3.연속 k일 구간합 구하기
    //구간합
    //최댓값 갱신
    //4.출력
*/
int n, k,num;
int a[100010];
int psum[100010];
int maxN = -1987987987;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    //1.입력
    //2.누적합
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }

    //3.연속 k일 구간합 구하기
    //구간합
    //최댓값 갱신
    //4.출력
    for (int i = 1 ; i <= n-(k-1); i++) {
        maxN = max(maxN, psum[i + k - 1] - psum[i - 1]);
    }
    cout << maxN << '\n';
}  
