#include <iostream>
#include <algorithm> // fill_n, min,max, swap
//#include <map> // 중복 x 
//#include <string> // getline
//#include <cstring> // memset, strok, strstr
//#include <vector>
//#include <queue> // priority_queue<자료형, 구현체, 비교 연산자> (중복허용), 
//#include <set> // 트리, 중복 x , multiset
//#include <unordered_set>
//#include <cmath>
using namespace std; // lower_bound, upper_bound
/*
[백준 1934 c++ O] 최소공배수
문제:
접근: 
시간복잡도: O()
풀이: 
*/
int T;
int A, B;

int divide(int x, int y)
{
    if (x % y == 0)
        return y;
    else return divide(y, x % y);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> A >> B;
        if (A >= B) cout << A * B / divide(A, B) << "\n";
        else cout << A * B / divide(B, A) << "\n";
    }
    return 0;
}
