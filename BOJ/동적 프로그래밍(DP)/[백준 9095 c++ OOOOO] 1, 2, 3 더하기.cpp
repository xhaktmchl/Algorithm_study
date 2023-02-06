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
[백준 9095 c++ OOOOO] 1, 2, 3 더하기
문제: 정수를 1,2,3의 합으로 나타내는 방법의 수를 출력
접근1: 1,2,3 경우를 나눔 -> dp -> 탑다운 방식: 정수 i 가되는 경우
1. i-1 에서 1 더한 것
2. i-2에서  2 더한 것
3. i-3 에서 3 더한것 3가지
점화식 : dp[i] = dp[i-1]+dp[i-2]+dp[i-3]
바텀업 dp 구현
시간복잡도: O(n)
접근2: 완전탐색-> 재귀 -> 1,2,3, 각각 더할때 모두 탐색
시가복잡도: O(3^n) , dp 가 더 빠른 듯
풀이1:
// dp로 풀이
풀이2:
// 완전탐색 재귀
// n입력,재귀호출
// 현재 합에서 1,2,3더할때 각각 재귀, 합이 n이되면 종료
*/
int T,n;
int dp[15];

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    cin >> T;
    //2.dp 바텀업
    //dp[i]: 합한 수가 i가 되는 경우의 수-> 1더한경우, 2더한 경우, 3더한 경우
    //dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3])
    dp[1] = 1; dp[2] = 2; dp[3] = 4;
    for (int i = 4; i <= 10; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    //3.출력
    for (int t = 0; t < T; t++) {
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}
