#include <iostream>
#include <algorithm> // fill_n, min,max, swap
//#include <map> // 중복 x 
//#include <string> // getline
//#include <cstring> // memset, strok, strstr
#include <vector>
//#include <queue> // priority_queue<자료형, 구현체, 비교 연산자> (중복허용), 
#include <set> // 트리, 중복 x , multiset
//#include <unordered_set>
//#include <cmath>
using namespace std; // lower_bound, upper_bound
/*
[백준 10816 c++ VO] 숫자 카드 2
문제: 숫자 있는지 출력
접근1: 완전탐색 -> 50만*50만 이어서 시간초과
접근2: 벡터 정렬 후 lower_bound ,upper_bound 함수의 차가 그 원소의 갯수
시간복잡도:
풀이:
    //1.입력
    //2.정렬
    //3.이진탐색
개념:
//: lower_bound(a.begin(), a.end(), num); 찾는 값 이상 숫자의 시작 주소
//  upper_bound(a.begin(), a.end(), num); 찾는 값 초과 숫자의 시작 주소
*/
int n,num,m;
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
    sort(v.begin(), v.end());
    //3.이진탐색
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> num;
        cout << upper_bound(v.begin(), v.end(), num) - lower_bound(v.begin(), v.end(), num) << " ";
    }
    return 0;
}
