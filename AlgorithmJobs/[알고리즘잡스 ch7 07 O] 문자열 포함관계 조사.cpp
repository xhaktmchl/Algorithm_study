#include <iostream>

using namespace std;
/*
[알고리즘잡스 ch7 07 O] 문자열 포함관계 조사
풀이: str.find()이용
시간복잡도: O(log(n))=log(100)
*/
string s1,s2;

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  cin>>s1>>s2;
  // 문자열 포함 탐색
  if((int)s1.find(s2) != -1){cout<<"YES"<<'\n';}
  else{cout<<"NO"<<'\n';}
  return 0;
} 
