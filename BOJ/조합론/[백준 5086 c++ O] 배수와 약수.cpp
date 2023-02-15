#include <iostream>
#include <algorithm> // fill_n, min,max, swap
//#include <map> // 중복 x 
//#include <string> // getline
//#include <cstring> // memset, strok, strstr
#include <vector>
#include <queue> // priority_queue<자료형, 구현체, 비교 연산자> (중복허용), 
//#include <set> // 트리, 중복 x , multiset
//#include <unordered_set>
//#include <cmath>
using namespace std; // lower_bound, upper_bound
/*
[백준 5086 c++ O] 배수와 약수 
문제:
접근: 
시간복잡도: O()
풀이: 
*/
int x, y;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);

    while (1) {
        cin >> x >> y;
        if (x == 0 && y == 0) break;

        if (y % x == 0) cout << "factor" << endl;
        else if (x % y == 0) cout << "multiple" << endl;
        else cout << "neither" << endl;
    }
    return 0;
}
