#include <iostream>
#include <string>
using namespace std;
/*
[알고리즘잡스 ch7 05 O] 문자열 압축
풀이: 완탐
시간복잡도: O(n)=1000
*/
string s,s2;
int c=0;
int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  cin>>s;
  //1.문자열 완탐: 연속된 문자갯수 카운트
  for(int i=0;i<s.size();i++){
    c++;
    if(s[i] != s[i+1]){
      if(c!=1) s2+=to_string(c);//2.연속된 카운트 새로운 문자열에 추가
      s2+=s[i];//3.원래 문자 추가
      c=0;
    }
  }
  // 출력
  cout<<s2<<'\n';
  return 0;
} 
