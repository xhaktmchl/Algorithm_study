#include <iostream>
#include <algorithm>
//#include <map> // 중복 x 
//#include <string> // getline
//#include <cstring> // memset
//#include <vector>
//#include <queue>
//#include <set> // 트리, 중복 x
//#include <unordered_set>
using namespace std;
/*
[백준 11053 c++ VOOO] 가장 긴 증가하는 부분 수열
접근: DP
dp[i]: i번재 숫자까지의 최장 증가 수열의 길이
dp[i] = max(dp[0] ... dp[i-1])+1
p[i]: i번째 숫자까지의 최장증가수열 바로 전 인덱스
시간복잡도: n*n
풀이:
    //1.입력
    //초기화
    //2.dp[i]: i번재 숫자까지의 최장 증가 수열의 길이
    //dp[i] = max(dp[0] ... dp[i - 1]) + 1
    //p[i]: i번째 숫자까지의 최장증가수열 바로 전 인덱스
    //3.출력: LIS 길이
*/
int n;
int a[1000000 + 10];
int p[1000000 + 10];
int dp[1000000 + 10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //1.입력
    //초기화
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = -1;
    }
    //2.dp[i]: i번재 숫자까지의 최장 증가 수열의 길이
    //dp[i] = max(dp[0] ... dp[i - 1]) + 1
    //p[i]: i번째 숫자까지의 최장증가수열 바로 전 인덱스
    for (int i = 1; i <= n; i++) {

        for (int j = 1; j < i; j++) {
            if (a[i] > a[j] && dp[j] > dp[i]) {
                dp[i] = dp[j];
                p[i] = j;
            }
        }
        dp[i] += 1; // 현재 구간 길이
    }
    //3.출력: LIS 길이
    cout << *max_element(dp, dp + n + 1) << '\n';
    return 0;
}
