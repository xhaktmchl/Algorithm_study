#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level01 13번 O] Trace 연습하기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

    int a;
    a = 8;
    cout << a << "\n";
    a = a + 1;
    a++;
    a = 3;
    a = a + 1;
    a++;

    //endl 와 "\n" 로 엔터를 출력할 수 있습니다.
    cout << "a값은 : " << a << endl;

    a = a + 1;
    a++;
    cout << "마지막 a값은 : " << a << endl;
    return 0;
}
