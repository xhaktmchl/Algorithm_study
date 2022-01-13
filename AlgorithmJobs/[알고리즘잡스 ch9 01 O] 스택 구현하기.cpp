#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
/*
[알고리즘잡스 ch9 01 O] 스택 구현하기
풀이: stack 라이브러리 이용
시간복잡도: O(m) = 1000
*/
int n,m,num;
stack<int> st;

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  cin>>n>>m;
  // m번 스택 연산
  for(int i=0;i<m;i++){
    int op;
    cin>>op;
    // push
    if(op == 1){
      cin>>num;
      if(st.size()+1 >n){ cout<<"Overflow"<<'\n'; continue;}// 스택 오버플로우 예외처리
      st.push(num);
    }
    // pop
    else if(op == 2){
      // 예외처리: 언더 플로우
      if(st.size() == 0){ cout<<"Underflow"<<'\n'; continue;}
      st.pop();
    }
    // top
    else if(op == 3){
      // 예외처리: NULL
      if(st.size() == 0){ cout<<"NULL"<<'\n'; continue;}
      cout<<st.top()<<'\n';
    }
  }
  return 0;
}
