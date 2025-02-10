#include<iostream>

using namespace std;

int main() {
	// 조건부 컴파일 : 컴파일 하기 전에 조건을 비교하여 코드 라인을 컴파일 할지 말지 지정

	// #if, #ifdef, $ifndef

//#if		(조건)		//if문과 동일하게 조건이 참인 경우 해당 코드만 컴파일
//#elif	(조건)			//else if문과 동일하게 조건이 참인 경우 해당 코드만 컴파일
//#else					// 모든 경우가 거짓이었다면 해당 코드만 컴파일
//#endif				// 조건부 컴파일을 종료하겠다는 의미
#if NUMBER > 5
	cout << "5보다 크다" << endl;
#elif NUMBER < 5
	cout << "5보다 작다" << endl;
#else
	cout << "5다" << endl;
#endif;

}