#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
using namespace std;
// [백준 11652 c++ V] 카드  
// 문제: 
// 접근: 해쉬로 해당 수의 갯수 벡터에 저장 해놓고 제일 큰 값 인덱스 출력 -> 메모리 초과
// 접근2: 벡터에 입력 후 정렬하고 나오는 수 완탐 
// 시간복잡도: O(n)
// 풀이: 
int n,maxN=0;
vector<long long> v;

int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	for (int i = 0; i < n; i++) {
		long long num;
		cin >> num;
		v.push_back(num);
	}
	// 정렬 후 제일 많은 정수 구하기
	sort(v.begin(), v.end());
	int c = 1; long long ans = v[0];
	for (int i = 1; i < v.size(); i++) {
		if (v[i] != v[i - 1]) { c = 1; continue; }
		c++; 
		if (c > maxN) { maxN = max(maxN, c); ans = v[i]; } // 최빈수 최신화
	}
	cout << ans << '\n';
	return 0;
}
