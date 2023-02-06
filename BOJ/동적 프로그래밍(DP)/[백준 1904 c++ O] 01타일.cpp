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
[백준 1904 c++ O] 01타일
문제:
접근: 직접 갯수를 세보다 규칙을 찾음
시간복잡도:
풀이: 
    //1.입력
    //2.dp 바텀업
    //dp[i]: i개의 타일이 있을 때 이진수의 갯수
    //dp[i] = dp[i-1]+dp[i-2];
    //3.출력
*/
int n;
long long dp[1000005];

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    cin >> n;
    //2.dp 바텀업
    //dp[i]: i개의 타일이 있을 때 이진수의 갯수
    //dp[i] = dp[i-1]+dp[i-2];
    dp[1] = 1; dp[2] = 2; 
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2])%15746;
    }
    //3.출력
    cout << dp[n]%15746 << '\n';
    return 0;
}
