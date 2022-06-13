#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
/*
[세종대 알고리즘 트레이닝 Level12.5 07번 V] 가장 긴 문장을 찾아내기
문제:
접근: 
풀이: 
시간복잡도: O()=
질문: int maxL=-1; 로 하면 str.size() 값이랑 비교가 안됌 왜???
*/
string str[10];
int maxL=0;
string maxS;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for(int i=0;i<3;i++){
	    cin>>str[i];
	    
	    if(str[i].size() > maxL){
	        maxL = str[i].size();
	        maxS = str[i];
	    }
	}
	
	cout<<maxS;
	return 0;
}
