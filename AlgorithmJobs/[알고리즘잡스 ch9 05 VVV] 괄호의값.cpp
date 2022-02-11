#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[알고리즘잡스 ch9 05 VVV] 괄호의값
풀이: 배열 스택: 
  //1.괄호열 입력
  //2.괄호가 다 끝날 때 까지 반복
  //3.열린괄호는 스택 푸쉬
  //4.')'인데
  // 스택의 탑이 ( 인 경우 팝, 숫자 2 푸푸쉬
  // 스택의 탑이 숫자인 경우 스택 팝, 숫자*2 푸쉬
  // 숫자넣으려는데 탑이 숫자이면 합해서 푸쉬
  //5.']'인데
  // 스택의 탑이 [ 인 경우 팝, 숫자 3 푸푸쉬
  // 스택의 탑이 숫자인 경우 스택 팝, 숫자*3 푸쉬
  // 숫자넣으려는데 탑이 숫자이면 합해서 푸쉬
  // 출력: 스택에 숫자 하나 남으면 합 출력
  // 아니면 0출력
시간복잡도: O(30)
*/
#define MAX 50
string str;
int st[MAX];
int top=-1;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  
  //1.괄호열 입력
  cin>>str;
  //2.괄호가 다 끝날 때 까지 반복
  int len=str.size();
  for(int i=0;i<len;i++){
    if(str[i]=='('){//3.열린괄호는 스택 푸쉬
      st[++top]=-1;
    }
    else if(str[i]=='['){//3.열린괄호는 스택 푸쉬
      st[++top]=-2;
    }
    //4.')'인데
    else if(str[i]==')'){
      if(st[top]==-1){// 스택의 탑이 ( 인 경우 팝, 숫자 2 푸푸쉬
        st[top--]=0;
        st[++top]=2;
      }
      else if(top-1>=0 && st[top-1]==-1 && st[top]>=1){// 스택의 탑이 숫자인 경우 스택 팝, 숫자*2 푸쉬
        int num=st[top];
        top-=2;
        st[++top]=num*2;
      }
      else{ // 맞지않는 괄효
        cout<<0<<'\n';
        return 0;
      }
    }
    //5.']'인데
    else if(str[i]==']'){
      if(st[top]==-2){// 스택의 탑이 [ 인 경우 팝, 숫자 3 푸푸쉬
        st[top--]=0;
        st[++top]=3;
      }
      else if(top-1>=0 && st[top-1]==-2 && st[top]>=1){ // 스택의 탑이 숫자인 경우 스택 팝, 숫자*3 푸쉬
        int num=st[top];
        top-=2;
        st[++top]=num*3;
      }
      else{ // 맞지않는 괄효
        cout<<0<<'\n';
        return 0;
      }
    }
    // 위의 두개가 숫자이면 더해준다
    if(top-1>=0 && st[top] >=1 && st[top-1]>=1){
      int num = st[top]+st[top-1];
      top-=2;
      st[++top]=num;
    }
  }
  // 출력: 스택에 숫자 하나 남으면 합 출력
  // 아니면 0출력
  if(top==0 && st[top]>=1){
    cout<<st[top]<<'\n';
  }
  else{ cout<<0<<'\n';}
  return 0;
}
