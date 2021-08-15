#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 16198 c++ O] 에너지 모으기
// 문제: 
// 접근: 무게 합의 최댓값-> 완탐,그리디,dp -> n<10, 어디 에서 숫자 고르는지 랜덤 -> 완탐 재귀
// 시간복잡도: O((n-2)!) =  8! 
// 풀이: 
// 재귀 모든경우
// 1.가능한 경우 : 끝까지 고른 경우
// 2.불가능 : 없음
// 3. 재귀: 처음과 마지막 수를 제외하고 고르고 삭제된 벡터 넘겨주기,
#define MAX 11
int n;
int maxN = 0;

void re(int cnt,int sum, vector<int> a) {
	maxN = max(maxN, sum);
	// 종료,정답 찾은 경우
	if (cnt == n - 2) { 
		return; }
	//불가능, 없음

	// 다음 선택 재귀
	for (int i = 1; i < a.size()-1; i++){
		vector<int> tp = a; // 선태한 원소 삭제된 대체 배열
		tp.erase(tp.begin() + i);
		re(cnt + 1, sum + a[i - 1] * a[i + 1], tp);
	}
	
}

int main(){
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	vector<int> a(MAX);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	// 완탐 재귀
	re(0,0, a);
	cout << maxN << '\n';
	return 0;
}



