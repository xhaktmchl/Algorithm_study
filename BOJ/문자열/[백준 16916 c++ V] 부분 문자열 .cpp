#include <iostream>
#include <algorithm>
//#include <map> // 중복 x 
#include <string> // getline
#include <cstring> // memset, strok, strstr
//#include <vector>
//#include <queue>
//#include <set> // 트리, 중복 x
//#include <unordered_set>
using namespace std;
/*
[백준 16916 c++ V] 부분 문자열 
접근1: 
시간복잡도: n
풀이: 
    //1.입력
    //2.s문자열 탐색: 해당 문자부터 p문자열포함했는지
    //3.출력
*/
string s, p;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    
    //1.입력
    cin >> s >> p;
    //2.s문자열 탐색: 해당 문자부터 p문자열포함했는지
    if (strstr((char*)s.c_str(), (char*)p.c_str()) == NULL) {
        cout << 0 << '\n';
    }
    else cout << 1 << '\n';
    //3.출력
    return 0;
}
