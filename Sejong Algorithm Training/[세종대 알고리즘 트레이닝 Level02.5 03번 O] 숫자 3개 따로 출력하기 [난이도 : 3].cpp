#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level02.5 03번 O] 숫자 3개 따로 출력하기 [난이도 : 3]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a, b,c;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> a >> b>>c;
	cout << "첫번째 숫자는 " << a << " 입니다." << '\n';
	cout << "두번째 숫자는 " << b << " 입니다." << '\n';
	cout << "세번째 숫자는 " << c << " 입니다." << '\n';
    return 0;
}
