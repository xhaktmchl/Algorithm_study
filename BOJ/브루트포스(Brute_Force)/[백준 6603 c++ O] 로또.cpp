#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 6603 c++ O] 로또
// 접근: 로또 수 조합 구하기-> 완탐(재귀,순열) -> 중복없는 조합(방문배열) -> 완전탐색 재귀이용
// 재귀인자(현재 뽑은 수 객수, 중복방지 오름차순을 위한 start인자, 현재까지 뽑은 조합)
// 시간복잡도: O(k^6*t) : 재귀13^6*테스트케이스t , 약 몇십만-> 1초 이내
// 접근2: 수열 -> 구현방법 잘 모르겠음
// 풀이:
// 수열 입력받기
// 완전탐색 재귀로 가능한조합 구해서 출력
// 재귀- 순서대로 start인자부터 탐색 - 조합 완성되면 출력
#define MAX 14
int k;
int visit[MAX];
int s[MAX];

void re(int idx, int start, vector<int> a) {// 재귀인자(현재 뽑은 수 객수, 중복방지 오름차순을 위한 start인자, 현재까지 뽑은 조합)
	// 종료조건, 조합 완성시
	if (idx == 6) {
		for (int i = 0; i < 6; i++) {
			cout << a[i] << " ";
		}cout << '\n';
		return;
	}
	//재귀
	// start부터 k까지 탐색
	for (int i = start; i < k; i++) {
		if (visit[i]) { continue; } 
		visit[i] = 1; a.push_back(s[i]);
		re(idx + 1, i+1, a);
		visit[i] = 0; a.pop_back();
	}
}
int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	while (1) {
		cin >> k;
		if (k == 0) { break; }
		memset(visit, 0, sizeof(visit));
		memset(s, 0, sizeof(s));
		for (int i = 0; i < k; i++) {
			cin >> s[i];
		}

		vector<int> a;
		re(0, 0, a);
		cout << '\n';
	}
	return 0;
}
