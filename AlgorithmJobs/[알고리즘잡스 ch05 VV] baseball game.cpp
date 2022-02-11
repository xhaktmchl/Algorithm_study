#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch05 VV] baseball game
풀이: 완탐 , 123부터 987까지 모든 숫자가 주어진 스트라이크 볼 맞는지 검사
  //1.n개의 질문 입력
  //2.완탐:123~987까지 각 숫자에  n개의 질문 검사
  //예외처리: 같은 숫자 포함일 때
  //3.현재 숫자가 n개의 숫자의 힌트와 같은지 검사
  //숫자 같은데 위치 같으면 스트라이크 카운트
  //숫자 같은데 위치 다르면 볼 카운트
  //스트라익, 볼 같으면 질문 통과 카카운트//
  //모든 질문을 통과하면 후보숫자 카운트
  //4.출력: 후보숫자의 갯수
시간복잡도: O(1000*n*3*3)=90만
*/

#define MAX 110
int n,result=0;
string q[MAX];
int strike[MAX],ball[MAX];

int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  

  //1.n개의 질문 입력
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>q[i]>>strike[i]>>ball[i];
  }
  //2.완탐:123~987까지 각 숫자에  n개의 질문 검사
  for(int i=123;i<=987;i++){
    
    string cur_num=to_string(i);
    //예외처리: 같은 숫자 포함일 때
    if(cur_num[0]=='0' || cur_num[1]=='0' ||cur_num[2]=='0' || cur_num[0]==cur_num[1]||cur_num[0]==cur_num[2] ||cur_num[1]==cur_num[2]){
      continue;
    }
    //3.현재 숫자가 n개의 숫자의 힌트와 같은지 검사
    int cnt=0;
    for(int k=0;k<n;k++){
      int strcnt=0, ballcnt=0;
      for(int j=0;j<3;j++){
        for(int p=0;p<3;p++){
          if(q[k][j]==cur_num[p] && j==p){ strcnt++;}//숫자 같은데 위치 같으면 스트라이크 카운트
          else if(q[k][j]==cur_num[p] && j!=p) { ballcnt++;}//숫자 같은데 위치 다르면 볼 카운트
        }
      }
      if(strike[k]==strcnt && ball[k]==ballcnt){    //스트라익, 볼 같으면 질문 통과 카카운트//
        cnt++;
      }
    }
    if(cnt==n){//모든 질문을 통과하면 후보숫자 카운트
      result++;
    }
  }
  //4.출력: 후보숫자의 갯수
  cout<<result<<'\n';
  return 0;
}
