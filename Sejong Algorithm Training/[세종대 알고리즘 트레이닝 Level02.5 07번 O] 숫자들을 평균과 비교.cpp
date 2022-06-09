#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level02.5 07번 O] 숫자들을 평균과 비교
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a, b, c, d;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> a >> b >> c >> d;
	int avg = (a + b + c + d) / 4;
	if (a > avg) { cout << a << ">" << avg << '\n'; }
	else if(a<avg){ cout << a << "<" << avg << '\n'; }
	else if(a== avg){ cout << a << "==" << avg << '\n'; }

	if (b > avg) { cout << b << ">" << avg << '\n'; }
	else if (b < avg) { cout << b << "<" << avg << '\n'; }
	else if (b == avg) { cout << b << "==" << avg << '\n'; }

	if (c > avg) { cout << c << ">" << avg << '\n'; }
	else if (c < avg) { cout << c << "<" << avg << '\n'; }
	else if (c == avg) { cout << c << "==" << avg << '\n'; }

	if (d > avg) { cout << d << ">" << avg << '\n'; }
	else if (d < avg) { cout << d << "<" << avg << '\n'; }
	else if (d == avg) { cout << d << "==" << avg << '\n'; }
    return 0;
}
