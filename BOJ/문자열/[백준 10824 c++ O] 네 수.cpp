#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
using namespace std;
// [백준 10824 c++ O] 네 수
// 문제: 
// 접근: 숫자 이어붙히기 -> 문자열 문제 -> 문자열 수로 변환후 계산
// 질문: 
// 시간복잡도: O(1) ,
// 풀이: 
// 수가 커서 longlong 사용
int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	string a,b,c,d; 
	cin >> a >> b >> c >> d;
	string s1 = a + b;
	string s2 = c + d;
	cout << stoll(s1) + stoll(s2) << '\n';
	return 0;
}


