#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[알고리즘잡스 ch7 03 O] 과제물 망치기
풀이: 문자열 완탐
시간복잡도: O(n/2)=1000/5=500
주의: 
*/
string s;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  getline(cin,s);
  reverse(s.begin(),s.end()); // 양 끝부터 스왑해서 최소 시간복잡도
  cout<<s<<'\n';
  return 0;
}
