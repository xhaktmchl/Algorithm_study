#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 3028 c++ O] 창영마을
// 문제: 3가지 스왑 명령을 입력받아 공의 마지막 위치 출력
// 접근: 문자열로 명령 입력-> swap 명령으로 2개의 원소 스왑
// 시간복잡도: O(50) 
// 풀이: 
// swap(원소, 원소2) , 2ㅜ개의 원소 교환
// string.find(찾고자 하는 원소) : 찾은 원소의 첫 인덱스 반환
#define MAX 501
string a;
string ball="100";

int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == 'A') {swap(ball[0], ball[1]);}
		if (a[i] == 'B') { swap(ball[1], ball[2]); }
		if (a[i] == 'C') { swap(ball[0], ball[2]); }
	}
	cout << ball.find('1')+1 << '\n';
	return 0;
}



