#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
/*
[알고리즘잡스 ch9 05 V] 괄호의값
풀이: 배열 스택: 
시간복잡도: O(30)
*/
#define MAX 35
string s;
int st[MAX];
int top = -1;

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  cin>>s;
  for(int i=0;i<s.size();i++){
    // 여는 괄호 스택 푸쉬
    if(s[i] == '('){ st[++top]=-1;}
    else if(s[i] == '['){ st[++top]=-2;}
    // 닫는 괄호 
    else if(s[i]==')' || s[i]==']'){
      // 스택 탑이 여는 괄호: 팝하고 2, 3 푸쉬
      if(top>=0 && st[top]==-1 && s[i]==')'){ st[top--]=0; st[++top]=2;}
      else if(top>=0 && st[top]==-2 && s[i]==']'){ st[top--]=0; st[++top]=3;}
      // 스택 탑이 숫자: *2 또는 *3 해서 푸쉬
      else if(top-1>=0 && st[top-1]==-1 && s[i]==')'){ 
        int num = st[top]*2;
        st[top]=st[top-1]=0;
        top-=2;
        st[++top]=num;
      } 
      else if(top-1>=0 && st[top-1]==-2 && s[i]==']'){ 
        int num = st[top]*3;
        st[top]=st[top-1]=0;
        top-=2;
        st[++top]=num;
      } 
      else{
        cout<<0<<'\n';
        return 0;
      }
      // 숫자 푸쉬하는데 탑이 숫자면 더해서 푸쉬 
      if(top-1>=0 && st[top]>=1 && st[top-1]>=1){
        int num = st[top]+st[top-1];
        top-=2;
        st[++top]=num;
      }
    }
  }
  // 올바른 괄호이면 결과값 출력
  if(top==0 && st[top]>=1){
    cout<<st[top]<<'\n';
  }
  else { cout<<0<<'\n';}// 아니면 0 출력
  return 0;
}
