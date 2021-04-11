#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio> // c 문법 헤더파일
#include<string> // c++ 문자열 클래스
#include<vector> // 동적배열 라이브러리
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>  // sort와 unique 사용
#include<cmath> // 제곱이나 루트함수 사용
#include<cstring> // memset 함수
#include <set>
#include <map> // map구조체
#include <numeric> //accumulate(v.begin(), v.end(), 0);

// [백준 9251 c++ *] LCS
// 문제: LCS(가장 긴 공통 부분수열)의 길이를 구하는 문제 
// 점근:  잘 이해 안감
// 풀이: 
// 같은 문자일 때는 이전 까지의 dp +1
// 다른 문자일 때는 왼쪽,위 중 큰값 dp 저장
// 점화식 : 같은 문자 dp[i][j] = dp[i - 1][j - 1]+1
// 다른 문자 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

using namespace std; // cin,cout 편하게 사용 라이브러리 
#define MAX 1001

int dp[MAX][MAX];

int main()
{
	// IO 속도 향상
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축
	string str1, str2;
	cin >> str1 >> str2;
	
	// dp
	for (int i = 1; i <= str2.size(); i++) {
		for (int j = 1; j <= str1.size(); j++) {
			if (str2[i-1] == str1[j-1]) // 같은 문자면 그 전까지의 공통dp +1
			{
				dp[i][j] = dp[i - 1][j - 1]+1; // 왼쪽위 대각선 +1
			}
			else {// 다른 문자면 다른 문자일 경우 각 dp 값중 큰값 저장
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // 왼쪽이랑, 위중 큰 값
			}
		}
	}

	cout << dp[str2.size()][str1.size()];
	
	return 0;
}

