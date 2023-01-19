#include <iostream>
#include <algorithm>
//#include <map> // 중복 x 
//#include <string> // getline
//#include <cstring> // memset, strok
//#include <vector>
//#include <queue>
//#include <set> // 트리, 중복 x
//#include <unordered_set>
using namespace std;
/*
[백준 1932 c++ VOO] 정수 삼각형
접근1: 최댓값(완전탐색,그리디,dp) -> 탑다운 dp로 생각
// dp[n][i] : n번째 층의 i번째 숫자까지의 최대 합
//-> 1.n번째 층의 1번째 수는 자신의 오른쪽 위 숫자에서만 올 수 있음= dp[i][j] = dp[i-1][1] + ar[i][1];
//-> 2.n번째 층의 2~n-1번째 수는 양 대각석 위의 수에서 올 수 있음= dp[i][j] = max(dp[i - 1][j-1],dp[i-1][j]) + ar[i][j];
//-> 3.n번째 층의 n번째 수는 자신의 왼쪽 위 숫자에서만 올 수 있음= dp[i][j] = dp[i - 1][j-1] + ar[i][j];
시간복잡도: n*n
풀이: 바텀업 dp 구현
    //1.입력
    //2.dp[i][j] : i행j열까지 합의 최댓값
    //1)맨 왼쪽 숫자인 경우
    //2)맨 오른쪽 숫자인 경우
    //3)그 외 중간 숫자인 경우
    //3.출력: 마지막 행의 dp 최댓값
*/
int n;
int a[505][505];
int dp[505][505];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(0);

    //1.입력
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            cin >> a[i][j];
        }
    }
    //2.dp[i][j] : i행j열까지 합의 최댓값
    //1)맨 왼쪽 숫자인 경우
    //2)맨 오른쪽 숫자인 경우
    //3)그 외 중간 숫자인 경우
    for (int i = 1; i <= n; i++) {

        for (int j = 0; j < i; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][0] + a[i][j];
            }
            else if (j == i - 1) {
                dp[i][j] = dp[i - 1][j - 1] + a[i][j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
            }
        }
    }
    
    //3.출력: 마지막 행의 dp 최댓값
    int maxDp = -1;
    for (int i = 0; i < n; i++) {
        maxDp = max(maxDp, dp[n][i]);
    }
    cout << maxDp << '\n';
    return 0;
}
