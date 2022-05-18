#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level19 05번 O] 맥도날드 주문받기
문제:
접근: 구현
풀이:
시간복잡도: O()=
*/
typedef struct MC {
	string bur1, bur2;
}MC;

MC bob, tom;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력: bob, tom2개씩
	cin >> bob.bur1 >> bob.bur2 >> tom.bur1 >> tom.bur2;
	//2.출력:각 햄버거 길이 
	cout << "bob.burger1=" << bob.bur1.size() << '\n';
	cout << "bob.burger2=" << bob.bur2.size() << '\n';
	cout << "tom.burger1=" << tom.bur1.size() << '\n';
	cout << "tom.burger2=" << tom.bur2.size() << '\n';
	return 0;
}
