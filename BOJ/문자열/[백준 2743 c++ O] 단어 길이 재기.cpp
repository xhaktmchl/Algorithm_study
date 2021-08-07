#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
using namespace std;
// [백준 2743 c++ O] 단어 길이 재기
// 문제: 
// 접근: string으로 입력하고 문자갯수 배열에 저장
// 시간복잡도: O(n) ,
// 풀이: 
int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	string s; cin >> s;
	cout << s.size() << '\n';
	return 0;
}


