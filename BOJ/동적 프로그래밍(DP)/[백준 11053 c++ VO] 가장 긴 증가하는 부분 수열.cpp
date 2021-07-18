#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// [백준 11053 c++ VO] 가장 긴 증가하는 부분 수열
// 문제: LIS 가장 긴 증가하는 부분수열(오름차순의 부분수열)의 길이를 구하는 문제
// 접근1: 브루트포스로 큰 수 나올 때마다 카운트해서 최대값 찾으려 생각-> 시간초과 예상으로 안함
// 점근2: dp를 이용해 각 자리마다 나오는 증가하는 부분수열의 최대값 저장 
// 풀이: 
// 1일때는 모두가 1이므로 각 초기 dp[i]는 1
// 처음 인덱스부터 현재검사하는 인덱스 까지 현재검사하는 원소값보다 작으면 dp값 비교해서 최대값으로 최신화
// 계속 최신화 하며 현재 검사하는 인덳까지 가면 dp 값이 곧 부분수열의 길이랑 같음

#define MAX 1001
int n, max_len;
vector<int> ar;
vector<int> dp(MAX,1); // LIS는 수열의 길이의 최솟값인 1로 초기화
int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축
	// 수열 입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		ar.push_back(num);
	}
	// dp로 해당 인덱스 까지의 LIS길이를 저장시킴
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) { // 증가하는 부분수열 비교
			if (ar[j] < ar[i]) { // i번째 수가 더 크면
				dp[i] = max(dp[i], dp[j] + 1);
				
			}
		}
		// 최대 부분수열 길이 저장
		max_len = max(max_len, dp[i]);
	}

	cout << max_len;
	return 0;
}
