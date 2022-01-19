#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
[알고리즘잡스 ch12 00 O] vector STL
풀이:
시간복잡도: O()
*/

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  /*벡터 개념*/
  //1. 벡터 선언
  vector<int> v1(); // 빈 벡터 
  vector<int> v2(10); // 공간10인 벡터
  vector<int> v3(10,1); // 공간10인 벡터 3 초기화
  
  // v.push_back(1);
  v1.push_back(1);
  
  // v.pop_back();
  v1.pop_back();
  
  // v.size()
  // 사이즈 반환
  v2.size();
  
  // v.resize()
  // 벡터 공간 변경, 원래 있던 숫자는 그대로
  v2.resize(2)
  return 0;
}
