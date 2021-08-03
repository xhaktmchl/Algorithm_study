#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 1759 c++ OO] 안전 영역 
// 문제: 
// 접근: 가능한 비밀번호 경우 추출 -> 완전탐색 해야하는데 비밀번호의 자릿수가 일정한 것이 아니므로 dfs/ 재귀 생각
// 오름차순=정렬+start인자,중복없음= 방문배열 없음
// 풀이: 
// 오름차순 출력위해 정렬
// 완전탐색 재귀: 새로운 문자배열 인덱스, start 인자, 모음 수 , 자음 수 인자활용
// 문자열 완성시 종료
// 문자열 start부터 탐색 (모음, 자음일 경우 다름)
#define MAX 16
int l, c;
char a[MAX]; // 문자열 입력 배열
char b[MAX]; // 생성되는 문자열 배열

void re(int idx, int start,int cnt1,int cnt2) {
	// 종료조건, 수열 완성시
	if (idx == l) {
		if (cnt1 >= 1 && cnt2 >= 2) { // 자음모음 조건 검사
			for (int i = 0; i < l; i++) {
				cout << b[i];
			}cout << '\n';
		}
		return;
	}	// 종료조건, 불가능 시
	if (idx > l) { return; }
	
	// start부터 탐색
	for (int i = start; i < c; i++) {
		b[idx] = a[i];
		// 모음일 때
		if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u') {
			re(idx + 1, i + 1,cnt1+1,cnt2);
		}// 자음일 때
		else{ re(idx + 1, i + 1, cnt1, cnt2+1); }
	}
}
int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		cin >> a[i];
	}
	sort(a, a + c);
	// 완전탐색 재귀
	re(0, 0,0,0);
	return 0;
}
