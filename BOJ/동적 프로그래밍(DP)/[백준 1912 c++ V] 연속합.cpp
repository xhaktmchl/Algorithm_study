#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// [백준 1912 c++ V] 연속합
// 문제: 최대 연속된 부분수열의 합의 최댓값 구하기
// 접근1: 최대 부분수열의 합의 최댓값 알고리즘 적용
// 원소를 계속해서 더해간다
// 더한 값이 최댓값이면 최댓값 갱신
// 더함값이 음수면 0으로 초기화 하고 더해간다.
// 음수만 있는 경우는 음수 중 최댓값을 찾아서 예외처리 해준다
// 풀이: 
// 수열 입력
// 최대 부분수열의 합 구하고
// 만약 음수만 있는 경우가 아니면 최댓값 출력
// 음수만 있는 경우는 음수중 최댓값 출력
#define MAX 100001
int n;
vector<int> ar;
vector<int> dp(MAX,1); // LIS는 수열의 길이의 최솟값인 1로 초기화
int maxsum =0,maxN=-1001;
// 최대 부분수열 합 
int maxResult() {
	int sum=0;
	for(int i = 0; i < n; i++) {
		sum += ar[i];
		if (maxsum < sum) { maxsum = sum; }
		if (sum < 0) { sum = 0; }
	}

	return maxsum;
}
// 음수중 최대값 찾기
int maxMinus() {
	for (int i = 0; i < n; i++) {
		maxN = max(maxN, ar[i]);
	}
	return maxN;
}
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

	// 부분수열의 최대합 구하기
	int result = maxResult();
	if (result != 0) { cout << result; }
	else { // 음수만 있는 경우 예외처리
		cout << maxMinus();
	}
	
	return 0;
}
