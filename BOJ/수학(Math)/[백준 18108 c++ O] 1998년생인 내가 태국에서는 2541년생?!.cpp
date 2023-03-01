#include <iostream>
#include <algorithm> // fill_n, min,max, swap
//#include <map> // 중복 x 
#include <string> // getline
//#include <cstring> // memset, strok, strstr
//#include <vector>
//#include <queue> // priority_queue<자료형, 구현체, 비교 연산자> (중복허용), 
//#include <set> // 트리, 중복 x , multiset
//#include <unordered_set>
#include <cmath>
using namespace std; // lower_bound, upper_bound
/*
[백준 18108 c++ O] 1998년생인 내가 태국에서는 2541년생?!
문제:
접근:
시간복잡도: O()
풀이: 
*/
int year;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    
    cin >> year;
    cout << year - 543 << '\n';
    return 0;
}
