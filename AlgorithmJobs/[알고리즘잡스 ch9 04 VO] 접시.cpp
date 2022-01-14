#include <iostream>
#include <string>
#include <stack>
using namespace std;
/*
[알고리즘잡스 ch9 04 VO] 접시
풀이: 알파벳 안맞으면 푸쉬, 맞으면 팝 
시간복잡도: O()= 
*/
#define MAX 1000
string s;
char curAlpha='a';
stack<char> st;
int result[MAX];
int idx=0,c=0;
bool flag;

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

  cin>>s;
  int len = s.size();
  // 끝날 때까지 반복
  while(1){
    if(st.size()==0){ st.push(0);}// 예외처리: 스택이 빌 경우
    // 같으면 팝
    if(s[c] == st.top()){
      c++;
      st.pop();
      result[idx++]=2;
      if(c == len){  // 예외처리: 완료한 경우
        flag = true;
        break;
      }
    }
    // 다르면 푸쉬
    else if(s[c] != st.top()){
      // 예외처리: 불가능한 경우
      if(curAlpha == 'a'+len){
        flag == false;
        break;
      }
      st.push(curAlpha++);
      result[idx++]=1;
    }
  }
  // 결과 출력
  if(flag == true){
    for(int i=0;i<idx;i++){
      if(result[i]==1){ cout<<"push"<<'\n';}
      else { cout<<"pop"<<'\n';}
    }
  }
  else{ cout<<"impossible"<<'\n';}
  return 0;
}
