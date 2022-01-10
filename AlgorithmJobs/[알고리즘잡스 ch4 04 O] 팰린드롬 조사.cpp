#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch4 04 O] 팰린드롬 조사
풀이: 문자열 완탐으로 같은 쌍의 갯수와 문자열 길이 비교
시간복잡도: O(n)=1000
*/
string s;
int c=0;
int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  cin>>s;
  // 문자열 반복 완탐
  for(int i=0;i<s.size();i++){
    if(s[i] == s[s.size()-i-1]){// 쌍이 같으면 카운트
      c++;
    }
  }
  if(c == s.size()){
    cout<<"YES"<<'\n';
  }
  else { cout<<"NO"<<'\n';}
  return 0;
}
