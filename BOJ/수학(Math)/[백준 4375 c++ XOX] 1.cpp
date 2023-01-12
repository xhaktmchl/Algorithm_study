#include <iostream>
#include <algorithm>
//#include <map> // 중복 x 
#include <string> // getline
using namespace std;
/*
[백준 4375 c++ XOX] 1
문제:  1로만 이루어진 n의 배수를 찾는 문제
접근: 완전탐색 -> 수의 범위가 넘어감 1111111111111 -> 틀림
접근2: 11 = (1*10+1) , 111 = (11*10+1) 인 것 이용해 규칙 세우기
접근3: 문자열을 이용해 1 씩 추가해 서 11111 관련 숫자만 탐색
시간복잡도: O()
풀이:
*/
long long n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (cin >> n) {
        long long num = 0;
        for (int i = 1;; i++) {
            num = (num * 10 % n + 1);

            if (num%n == 0) {
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}
