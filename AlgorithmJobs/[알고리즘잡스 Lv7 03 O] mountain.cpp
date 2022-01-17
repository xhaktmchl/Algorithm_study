#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[알고리즘잡스 Lv7 03 O] mountain
풀이: 1.재귀 -> 시간초과 에러
시간복잡도: O()
풀이2: 1.dp로 저장-> re(n) = re(n-1)+n+re(n-1) 
시간복잡도: O(n)
*/
#define MAX 110
int n;
string result[MAX];

string re(int num){
  // 기저사례: 1이면 1 반환
  if(num==1){
    return "1";
  }
  string tp = re(n-1);
  
  // 재귀 re(n) = re(n-1)+n+re(n-1) 
  return tp+to_string(num)+tp;
}


int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  // 1.숫자 입력
  cin>>n;
  // 2.dp: re(n) = re(n-1)+n+re(n-1) 
  result[1] = "1";
  for(int i=2;i<=20;i++){
    result[i] = result[i-1]+to_string(i)+result[i-1];
  }
  cout<<result[n]<<'\n';
  return 0;
}
