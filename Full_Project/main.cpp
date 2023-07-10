/*
*    22120065 - Trần Đại Đồng
*      22CTT2
*/

#include"lib.h"
int main() {
	ShowCur(0);
	School* Sch = new School[100];
	int i_Sch = 0;
	Menu(Sch, i_Sch);
	system("cls");
	gotoXY(40, 10);
	cout << "Made by Tran Dai Dong, HCMUS-22CTT2" << endl;
	_getch();
}
