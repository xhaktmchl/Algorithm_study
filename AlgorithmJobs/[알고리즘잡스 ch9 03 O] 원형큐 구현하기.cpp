#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
/*
[알고리즘잡스 ch9 03 O] 원형큐 구현하기
풀이: queue 라이브러리로 원형 큐 구현
시간복잡도: O(m)= 1000 
*/
int n,m,num;
queue<int> q;

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  cin>>n>>m;
  // m번 큐 연산
  for(int i=0;i<m;i++){
    int op;
    cin>>op;
    // push
    if(op == 1){
      cin>>num;
      // 오버플로우
      if(q.size() == n){ cout<<"Overflow"<<'\n'; continue;}
      q.push(num);
    }
    // pop
    else if(op == 2){
      // 언더프로우
      if(q.size() == 0){ cout<<"Underflow"<<'\n'; continue;}
      q.pop();
    }
    // front
    else if(op == 3){
      // NULL
      if(q.size() == 0){ cout<<"NULL"<<'\n'; continue;}
      cout<<q.front()<<'\n';
    }
  }
  return 0;
}
