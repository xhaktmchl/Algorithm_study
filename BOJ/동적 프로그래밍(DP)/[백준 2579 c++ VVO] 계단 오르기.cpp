#include <iostream>
#include <algorithm> // fill_n, min,max, swap
//#include <map> // 중복 x 
//#include <string> // getline
//#include <cstring> // memset, strok, strstr
//#include <vector>
//#include <queue> // priority_queue<자료형, 구현체, 비교 연산자> (중복허용)
//#include <set> // 트리, 중복 x , multiset
//#include <unordered_set>
//#include <cmath>
using namespace std;
/*
[백준 2579 c++ VVO] 계단 오르기
문제: 정수를 1,2,3의 합으로 나타내는 방법의 수를 출력
접근1: 재귀 dp로 모든 경우의 수 -> 시간초과 날 것 같에서 않함1. i-1 에서 1 더한 것
접근2: dp 초기값 구하고 규칙있는 부분 점화식 구해서 그때그때의 최댓값 저장하며 n까지의 최댓값 저장
시간복잡도: O(n)
풀이1:
    //1.입력
    //2.dp[i]: i번째 계단까지 점수의 합의 최댓값 
    //1)첫번째 전 계단에서 오는 경우(연속1 두번 예외처리하기위해 dp[i - 3] 에서 오는 경우로 생각
    //2)두 번째 계단에서 오는 경우
    //dp[i] = max(dp[i - 3] + a[i - 1] + a[i], dp[i - 2] + a[i])
    //3.출력
*/
int n;
int a[305];
int dp[305];

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    //2.dp[i]: i번째 계단까지 점수의 합의 최댓값 
    //1)첫번째 전 계단에서 오는 경우(연속1 두번 예외처리하기위해 dp[i - 3] 에서 오는 경우로 생각
    //2)두 번째 계단에서 오는 경우
    //dp[i] = max(dp[i - 3] + a[i - 1] + a[i], dp[i - 2] + a[i])
    dp[0] = 0; dp[1] = a[1]; dp[2] = max(a[1] + a[2], a[2]);
    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i - 3] + a[i - 1] + a[i], dp[i - 2] + a[i]);
    }
    //3.출력
    cout << dp[n] << '\n';
    return 0;
}
