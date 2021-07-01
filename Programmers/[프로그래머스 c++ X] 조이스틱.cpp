#include <string>
#include <vector>
#include <iostream>
using namespace std;
// [프로그래머스 c++ X] 조이스틱
// 문제: 
// 접근:  최솟값 -> 일단 최소 되는경우 생각-> 위아래 이동중 가까운 거리 + 오/왼 가까운 거리
// 풀이: 
//  'A' 로만 채워진 비교 문자열 생성
// while 반복으로 
// 현재 인덱스에서 위아래 거리 계산  // 주의: A부터 아래로 갈 경우 A->Z에서 거리1 추가됨
// 문자 바꿈
// 바뀐 후 정답 확인
// 오/왼 중 가까운 거리 구해서 인덱스 최신화
// 오른 인덱스: (i+dist)%name.size() 
// 왼 : (i+name.size() - dist)%name.size() : 왼쪽으로 빼면 음수가 나오기 때문에 전체 사이즈 name.size() 더한다음 뺀다.
// 주의: 위아래 계산중 A부터 아래로 갈 경우 A->Z에서 거리1 추가됨
int solution(string name) {
    int answer = 0;
    
    string tp(name.size(),'A');
    cout<<tp;
    int i=0; // 현재 인덱스

    while(1){
         
        // 위아래 최소횟수
       if( name[i]-'A' <= 'Z'+1-name[i]){answer+= (name[i]-'A');} // 위가 가까운 경우 
        // 주의: A부터 아래로 갈 경우 A->Z에서 거리1 추가됨
        else{ answer+= 'Z'+1-name[i];} // 
        tp[i] = name[i]; // 바꾼 값 최신화
        
        //바뀐 후 정답 확인
        if(name == tp){ break;}
        
        // 아니면 왼/오른쪽 거리 비교
        for(int dist=1;dist<name.size();dist++){
            // 오른쪽이 가까운 경우
            if(name[(i+dist)%name.size()] != tp[(i+dist)%name.size()]){ // 오른방향의 name과 tp문자가 다르면
                 answer += dist; // 이동횟수 추가
                //tp[(i+dist)%name.size()] = name[(i+dist)%name.size()];
                i= (i+dist)%name.size(); // 현재인덱스 최신화
                break;
            }// 왼쪽이 가까운 경우
            else if(name[(i+name.size() - dist)%name.size()] != tp[(i+name.size() - dist)%name.size()]){
                answer += dist; // 이동횟수 추가
               // tp[(i+name.size() - dist)%name.size()] = name[(i+name.size() - dist)%name.size()];
                i = (i+name.size() - dist)%name.size(); // 현재인덱스 최신화
                break;
            }
        }
        
    }

    return answer;
}
