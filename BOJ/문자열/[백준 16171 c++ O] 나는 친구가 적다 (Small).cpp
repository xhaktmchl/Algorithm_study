#include <iostream>
#include <algorithm>
//#include <map> // 중복 x 
#include <string> // getline
//#include <cstring> // memset, strok, strstr
//#include <vector>
//#include <queue>
//#include <set> // 트리, 중복 x
//#include <unordered_set>
using namespace std;
/*
[백준 16171 c++ O] 나는 친구가 적다 (Small)
접근1: 문자열 구현
시간복잡도: nlogn
풀이: 
    //1.입력
    //2.문자열에서 숫자 제거
    //3.문자 포함되었는지 탐색
    //4.출력
*/
string a, b, c;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    
    //1.입력
    cin >> a >> b;
    //2.문자열에서 숫자 제거
    int size = a.size();
    for (int i = 0; i < size; i++) {
        if (a[i] >= '0' && a[i] <= '9') continue;
        c.push_back(a[i]);
    }
    //3.문자 포함되었는지 탐색
    //4.출력
    if (c.find(b) == string::npos) cout << 0 << '\n';
    else cout << 1 << '\n';
    return 0;
}
