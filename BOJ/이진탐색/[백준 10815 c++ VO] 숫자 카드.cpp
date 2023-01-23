#include <iostream>
#include <algorithm>
//#include <map> // 중복 x 
//#include <string> // getline
//#include <cstring> // memset, strok, strstr
#include <vector>
//#include <queue>
//#include <set> // 트리, 중복 x
//#include <unordered_set>
using namespace std;
/*
[백준 10815 c++ VO] 숫자 카드
접근1: 
시간복잡도: 
풀이: 
    //1.입력
    //2.정렬
    //3.이진탐색
    //4.출력: 있으면 1, 없으면 0
*/
int n,num,m,val;
vector<int> v;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }
    //2.정렬
    //3.이진탐색
    //4.출력: 있으면 1, 없으면 0
    sort(v.begin(), v.end());
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> val;
        if (binary_search(v.begin(), v.end(), val)) cout << 1 << " ";
        else cout << 0 << " ";
    }
    return 0;
}
