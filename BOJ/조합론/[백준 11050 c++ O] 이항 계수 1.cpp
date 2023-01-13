#include <iostream>
#include <algorithm>
//#include <map> // 중복 x 
//#include <string> // getline
//#include <vector>

using namespace std;
/*
[백준 11050 c++ O] 이항 계수 1
접근: 
시간복잡도: O(n)
풀이:
    //1.dp: 팩토리얼
    //2.이항계수 구하기
*/
int dp[10 + 5];
int n, k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //1.dp: 팩토리얼
    dp[0]= dp[1] = 1;
    for (int i = 2; i <= 10; i++) {
        dp[i] = dp[i - 1] * i;
    }

    //2.이항계수 구하기
    cin >> n >> k;
    int comb = dp[n] / (dp[n - k] * dp[k]);
    cout << comb << '\n';
    return 0;
}
