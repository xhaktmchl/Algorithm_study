#include <iostream>
#include <string>
using namespace std;
/*
[알고리즘잡스 ch7 08 V] 큰 자릿수 덧셈
풀이: 
시간복잡도: O(str.size)=100
*/
string s1,s2,result;
int nextSum=0; // 덧셈중 10보다 커서 다음 자릿수 덧셈
int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  cin>>s1>>s2;
  if(s1.size()<s2.size()) swap(s1,s2); // s1을 더 큰 숫자로 스왑
  int s1_size = s1.size();
  int s2_size = s2.size();
  int minSize = s2_size; // 둘 중 작은 사이즈
  // 작은 문자열 까지 두 문자열 덧셈
  for(int i=0;i<minSize;i++){
    int sum= (s1[s1_size-i-1]-'0')+(s2[s2_size-i-1]-'0')+nextSum;
    //cout<<sum<<'\n';
    // 자리의 숫자 합이 10보다 작으면
    if(sum <10){
      result = to_string(sum)+result;
      nextSum=0;
    }
    // 10보다 클 때
    else{
      // 결과값에 일의 자릿수 추가
      result = to_string(sum%10)+result;
      // 다음 자릿수 1 증가
      nextSum=1;
    }
  }
  // 더할 문자열 남아있으면 결과값에 추가
  for(int i=s1_size-s2_size-1;i>=0;i--){
    int sum= (s1[i]-'0')+nextSum;
     // 자리의 숫자 합이 10보다 작으면
    if(sum <10){
      result = to_string(sum)+result;
      nextSum=0;
    }
    // 10보다 클 때
    else{
      // 결과값에 일의 자릿수 추가
      result = to_string(sum%10)+result;
      // 다음 자릿수 1 증가
      nextSum=1;
    }
  }
  // 가장 큰 자릿수의 마지막 합이 10 이상이면 1 자릿수 하나 늘어남
  if(nextSum == 1){
    result = '1'+result;
  }
  cout<<result<<'\n';
  return 0;
}
