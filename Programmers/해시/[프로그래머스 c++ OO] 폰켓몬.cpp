#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

// [프로그래머스 c++ OO] 폰켓몬
// 문제: 포켓몬을 n개 중 n/2개 뽑았을 때 서로 다른 종류의 최대값 구하기
// 접근:  구현-> n개중 서로다른 개수 구하고 최대값을 n/2가 넘어가는지 아닌지 검사 
// 풀이: 
// 벡터 정렬 후 중복원소 제거
// 서로다른 종류의 개수 구하고 ㅇn/2 보다 큰지 아닌지 검사
// 종류의 최댓값 출력
// 개념:
// v.erase(시작주고, 끝주소)
// unique(시작 주소, v.end()) : 연속으로 반복되는 원소를 제외한 값 뒤로 보내고 반복되는 원소의 시작주소 반환
// 벡터의 중복값 제거 : 정렬 후 -> erase(unique(v.begin(),v.end()),v.end());
// 풀이 2: 해시맵 이용
    //1.포켓몬 배열 해시에 저장
    //2.만약 해시 사이즈가 >= 2/N 인 경우는 2/N을 출력
    //3.아닌 경우 는 해시 사이즈 출력

map<int, int> m;
int solution(vector<int> nums)
{
    int answer = 0;
    //1.포켓몬 배열 해시에 저장
    int size = nums.size();
    for(int i=0;i<size;i++){
        m.insert({nums[i],1});
    }
    //2.만약 해시 사이즈가 >= 2/N 인 경우는 2/N을 출력
    int mSize = m.size();
    if(mSize >= size/2) answer = size/2;
    else answer = mSize;
    //3.아닌 경우 는 해시 사이즈 출력
    return answer;
}
