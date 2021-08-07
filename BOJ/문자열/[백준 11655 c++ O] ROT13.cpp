#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
using namespace std;
// [백준 11655 c++ O] ROT13 
// 문제: 
// 접근: getline 으로 공백포함 string으로 입력하고 순환하는 인덱스 더해줌
// 시간복잡도: O(100) ,
// 풀이: 
int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	string s; 
	getline(cin, s);

	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') { // 소문자
			s[i] = 'a'+ (s[i]-'a' + 13) % 26;
		}
		if (s[i] >= 'A' && s[i] <= 'Z') { // 대문자
			s[i] = 'A' + (s[i]-'A' + 13) % 26;
		}
	}
	cout << s << '\n';
	return 0;
}


