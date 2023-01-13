#include <iostream>
#include <algorithm>
//#include <map> // 중복 x 
//#include <string> // getline
//#include <vector>
using namespace std;
/*
[백준 1010 c++ O] 다리 놓기
접근: 
시간복잡도: 
풀이:
    //1.dp: 파스칼의 삼각형
    //2.comb구하기
*/
int T,n,m;
long long dp[35][35];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //dp: 콤비네이션, 파스칼
    dp[0][0] = dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i <= 30; i++) {
        for (int j = 0; j <= i; j++) {      
            if (j == 0 || j == i) { // 가장자리
                dp[i][j] = 1;
            }
            else { // 그 외
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }
    //1.테케
    cin >> T;
    //2.mCn 구하기
    while (T--) {
        cin >> n >> m;
        cout << dp[m][n] << '\n';
    }
    return 0;
}
