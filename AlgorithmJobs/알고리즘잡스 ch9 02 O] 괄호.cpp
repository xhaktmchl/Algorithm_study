#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
/*
[알고리즘잡스 ch9 02 O] 괄호
풀이: 올바른 괄호가 되려면 (,) 짝 갯수가 같아야 함,stack 라이브러리 이용
시간복잡도: O(50) 
*/
string s;
stack<char> st;

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  // 괄호입력
  cin>>s;
  // VPS 검증
  int len =s.size();
  for(int i=0;i<len;i++){
    // '(' 인 경우
    if(s[i]=='('){
      st.push('(');
    }
    // ')' 인 경우
    if(s[i]==')'){
      if(st.size() == 0){// 언더 플로두 예외처리
        cout<<"NO"<<'\n';
        return 0;
      }
      st.pop();
    }
  }
  // 스택에 남아있으면 VPs
  if(st.size()!=0){  cout<<"NO"<<'\n';}
  else{ cout<<"YES"<<'\n';}
  return 0;
}
