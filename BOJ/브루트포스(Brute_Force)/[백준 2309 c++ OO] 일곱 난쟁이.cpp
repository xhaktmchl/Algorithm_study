#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring> // memset 헤더
#include <queue>

using namespace std;
// [백준 2309 c++ OO] 일곱 난쟁이
// 접근: 난쟁이 키의 합 = 100 인 경우는 9명중 두명의 키를 뺀 값
// 접근: 완전탐색 
// 풀이: 벡터에 저장후 정렬하고 완전탐색으로 100 이되는 경우가 있으면 출력후 중단

#define MAX 10
int a[MAX];
vector<int> v;
int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> a[i];
		sum += a[i];
	}
	
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - a[i] - a[j] == 100) {
				for (int q = 0; q < 9; q++) {
					if (q != i && q != j) v.push_back(a[q]);
				}
				sort(v.begin(), v.end());
				for (int q = 0; q < v.size(); q++) {
					cout << v[q] << '\n';
				}
				return 0;
			}
		}
	}
	
	return 0;
}
