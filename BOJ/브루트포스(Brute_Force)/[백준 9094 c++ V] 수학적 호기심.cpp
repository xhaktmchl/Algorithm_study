#include <iostream>
#include <algorithm>
using namespace std;
/*
[백준 9094 c++ V] 수학적 호기심
문제:
접근1: 
풀이: 
*/
int cnt, n, m, t, a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> t;  //테스트 케이스 입력
    while (t)
    {
        t--;
        cnt = 0;
        cin >> n >> m;
        for (a = 1; a < n; a++)  //1부터 n까지 하나하나 다 해본다.
        {
            for (b = a + 1; b < n; b++)
            {
                if (!((a * a + b * b + m) % (a * b)))  //나눠서 나머지가 없으면 정수이므로 카운트해준다.
                    cnt++;
            }
        }
        cout << cnt << endl;
    }
}
