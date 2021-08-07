#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
using namespace std;
// [백준 1920 c++ V] 수 찾기
// 문제: 숫자 있는지 출력
// 접근1: 벡터에서 find 로 숫자 찾기 -> 맞음 근데 이진탐색보다 느림
// 접근2: binary_search 함수로 원소 찾기 -> 일반 find보다 빠름
// 시간복잡도: O(n+mlog2(n)) = O(n) ,
// 풀이: 
int n, m;
vector<int> a;
int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		a.push_back(num);
	}
	sort(a.begin(), a.end()); // 이진탐색을 위한 정렬

	cin >> m;
	for (int i = 0; i < m; i++) {
		int num; cin >> num;
		if (binary_search(a.begin(), a.end(), num)) { // 이진탐색으로 탐색
			cout << 1 << '\n';
		}
		/*if (find(a.begin(), a.end(), num) != a.end()) { // 선형탐색
			cout << 1 << '\n';
		}*/
		else cout << 0 << '\n';
	}
	
	
	
	return 0;
}


