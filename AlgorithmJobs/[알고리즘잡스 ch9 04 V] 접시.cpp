#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
/*
[알고리즘잡스 ch9 04 V] 접시
풀이: 알파벳 안맞으면 푸쉬, 맞으면 팝 
시간복잡도: O()= 
*/
#define MAX 1000
stack<char> st;
string s;
string op[MAX];
bool flag;

char curAlpha='a';
int idx=0,c=0;

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  cin>>s;
  int len = s.size();
  //st.push(curAlpha++);
  while(1){
    // 스택에 비어있으면 
    if(st.size()==0){
      st.push(0);
    }
    // 뽑을 수 없으면 푸쉬
    if(st.top() != s[idx]){
      // 예외처리: 더이상 못 뽑는 경우
      if(curAlpha > 'a'+len-1){ 
        flag=false;
        break;
      }
      st.push(curAlpha++);
      op[c++]="push";
    }
    // 같으면 팝
    else if(st.top() == s[idx]){
      st.pop();
      op[c++]="pop";
      idx++;
      // 예외처리: 다 뽑은 경우
      if(idx>= len){
        flag=true;
        break;
      }
    }
  }
  // 출력
  if(flag == true){
    for(int i=0;i<c;i++){
      cout<<op[i]<<'\n';
    }
  }
  else{ cout<<"impossible"<<'\n';}
  return 0;
}
