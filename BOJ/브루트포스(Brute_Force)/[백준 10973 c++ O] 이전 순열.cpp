#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 10973 c++ O] 이전 순열
// 문제: 입력받은 수열의 이전 수열을 출력, 없으면 -1
// 접근: 이전 수열 -> prev_permutation(a,a+n) 사용
// 시간복잡도: 이전 순열 하나를 찾는데 O(n), 따라서 O(n)
// 풀이: 
// 수열 입력
// prev_permutation 을 이용해 이전수열 탐색
int n;
vector<int> a;

int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		a.push_back(num);
	}
	// 이전수열 탐색
	if (prev_permutation(a.begin(), a.end())) {
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
	}
	else cout<<-1<<'\n';
	return 0;
}
