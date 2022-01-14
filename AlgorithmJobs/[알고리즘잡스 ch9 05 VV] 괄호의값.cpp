#include <iostream>
#include <string>
#include <stack>
using namespace std;
/*
[알고리즘잡스 ch9 05 VV] 괄호의값
풀이: 배열 스택: 
시간복잡도: O(30)
*/
#define MAX 100
string s;
int myStack[MAX];
int top=-1;

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

  cin>>s;
  int len = s.size();
  for(int i=0;i<len;i++){
    // 1.열린 괄호면 푸쉬
    if(s[i]=='(') { myStack[++top]=-1;}
    else if(s[i]=='[') { myStack[++top]=-2;}
    // 2.닫힌 괄호면 
   // 1) ')' 
    else if(s[i] == ')'){
      // 스택에 숫자 없으면 2 푸쉬
      if(myStack[top]==-1){
        myStack[top--]=0;
        myStack[++top]=2;
      }
        // 있으면 *2
      else if(top-1>=0 && myStack[top-1]==-1 && myStack[top]>=1){
        int num = myStack[top];
        top-=2;
        myStack[++top]=num*2;
      }
      else{ // 예외처리: 잘못된 괄호
        cout<<0<<'\n';
        return 0;
      }
    }
      // 2) ']'
    else if(s[i] == ']'){
      
      // 스택에 숫자 없고 '['이면 3 푸쉬
      if(myStack[top]==-2){
        myStack[top--]=0;
        myStack[++top]=3;
      }
        // 있으면 *3
      else if(top-1>=0 && myStack[top-1]==-2 && myStack[top]>=1){
        int num = myStack[top];
        top-=2;
        myStack[++top]=num*3;
      }
       else{// 예외처리: 잘못된 괄호
        cout<<0<<'\n';
        return 0;
      }
    }
    // 위의 두개가 숫자이면 더해준다
    if(top-1>=0 && myStack[top] >=1 && myStack[top-1]>=1){
      int num = myStack[top]+myStack[top-1];
      top-=2;
      myStack[++top]=num;
    }
  }
  // 정상출력
  if(top==0 && myStack[top]>=1){
    cout<<myStack[top]<<'\n';
  }// 불가 출력
  else{
    cout<<0<<'\n';
  }
  return 0;
}
