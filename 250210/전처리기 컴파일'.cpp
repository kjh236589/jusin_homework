#include<iostream>

using namespace std;

int main() {
	// ���Ǻ� ������ : ������ �ϱ� ���� ������ ���Ͽ� �ڵ� ������ ������ ���� ���� ����

	// #if, #ifdef, $ifndef

//#if		(����)		//if���� �����ϰ� ������ ���� ��� �ش� �ڵ常 ������
//#elif	(����)			//else if���� �����ϰ� ������ ���� ��� �ش� �ڵ常 ������
//#else					// ��� ��찡 �����̾��ٸ� �ش� �ڵ常 ������
//#endif				// ���Ǻ� �������� �����ϰڴٴ� �ǹ�
#if NUMBER > 5
	cout << "5���� ũ��" << endl;
#elif NUMBER < 5
	cout << "5���� �۴�" << endl;
#else
	cout << "5��" << endl;
#endif;

}