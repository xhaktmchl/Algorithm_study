#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
using namespace std;
// [백준 1357 c++ O] 뒤집힌 덧셈
// 문제: 
// 접근: 
// 시간복잡도: 
// 풀이1:  
string a, b;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int sum = stoi(a) + stoi(b); // 수 더하기 
	string ret = to_string(sum); 
	reverse(ret.begin(), ret.end()); // 더한 수 역순
	int ans = stoi(ret);
	cout << ans << '\n';
    return 0;
}
