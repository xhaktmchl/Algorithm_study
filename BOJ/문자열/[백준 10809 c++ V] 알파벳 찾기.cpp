#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
using namespace std;
// [백준 10809 c++ V] 알파벳 찾기
// 문제: a ~z 까지 문자 있으면 포함되는 인덱스 출력
// 접근: string으로 입력하고 str.find() 함수 이용해서 위치 출력
// 시간복잡도: 
// 풀이: 
//개념: 
//// s.find(i) 는 찾는 문자의 인덱스 반환, 문자가 없으면 string::npos 으로 가장 큰 수 unsigned로 반환
// unsigned 를 int 형으로 바꾸면 -1 이다.
string s;
int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> s;
	for (char i = 'a'; i <= 'z'; i++) {
		cout << (int)s.find(i) << " ";  
	}
	return 0;
}


