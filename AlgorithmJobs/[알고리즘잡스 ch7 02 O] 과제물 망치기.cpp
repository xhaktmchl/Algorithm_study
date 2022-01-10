#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[알고리즘잡스 ch7 02 O] 과제물 망치기
풀이: 완탐, 탐색하다 공백만 제외하고 새로운 문자열에 저장
시간복잡도: O(n)=100000
주의: 
*/
string s;
string s2;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  getline(cin,s);// 공백포함 문자열 입력
  for(int i=0;i<s.size();i++){
    if(s[i] != ' '){
      s2+= s[i];
    }
  }
  cout<<s2<<'\n';
  return 0;
}
