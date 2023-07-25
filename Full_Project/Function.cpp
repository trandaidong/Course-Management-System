#include"lib.h"
char s[100];
char ss[100];
bool FLAG1 = true;
bool FLAG2 = true;
bool FLAG3 = true;
// Lưu ngày hiện tại
Date TIME;
void TimeActually() {
	time_t now = time(NULL);
	tm* t = localtime(&now);
	asctime(t);
	TIME.day = t->tm_mday;
	TIME.month = 1 + t->tm_mon;
	TIME.year = 1900 + t->tm_year;
}
// Mảng lưu ngày max trong tháng
const int MaxDay[] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
// Hàm kiểm tra năm nhuận
bool leapYear(Date a) {
	return (a.year % 100 != 0 && a.year % 4 == 0) || a.year % 400 == 0;
}
// Hàm trả về ngày lớn nhất trong tháng
int maxDay(Date a) {
	switch (a.month) {
	case 1:case 3: case 5: case 7:case 8: case 10: case 12:
		return MaxDay[a.month];
		break;
	case 4: case 6: case 9: case 11:
		return MaxDay[a.month];
		break;
	case 2:
		if (leapYear(a))return 29;
		return 28;
	}
}
// Check ngày
bool checkDay(Date a) {
	if (a.year < 0)return false;
	if (a.month < 0 || a.month>12)return false;
	if (a.day<0 || a.day>maxDay(a))return false;
	return true;
}
// So sanh ngay
int compareDate(Date a, Date b) {
	if (a.year > b.year)return 1;
	if (a.year < b.year)return -1;

	if (a.month > b.month)return 1;
	if (a.month < b.month)return -1;

	if (a.day > b.day)return 1;
	if (a.day < b.day)return -1;

	return 0;
}
// Copy và cấp phất bộ nhớ cho con trỏ Destination từ kiểu char
void cpychar(char*& Destination, char Source[]) {
	int n = strlen(Source);
	Destination = new char[n];
	for (int i = 0; i < n; i++) {
		Destination[i] = Source[i];
	}
	Destination[n] = '\0';
}
// Copy và cấp phát bộ nhớ cho con trỏ Destination từ kiểu string
void cpyString(char*& Destination, string Source) {
	int n = Source.length();
	Destination = new char[n];
	for (int i = 0; i < n; i++) {
		Destination[i] = Source[i];
	}
	Destination[n] = '\0';
}
// Copy và cấp phát động bộ nhớ cho con trỏ Destination, kiểu char *
void cpycharPoint(char*& Destination, char* Source) {
	int n = strlen(Source);
	Destination = new char[n];
	for (int i = 0; i < n; i++) {
		Destination[i] = Source[i];
	}
	Destination[n] = '\0';
}
// Cấp phát liên khóa
void AllocationSchoolYear(int*& SchoolYear, int& lengthOfSchoolYear, int temp) {
	int* ans = new int[lengthOfSchoolYear];
	for (int i = 0; i < lengthOfSchoolYear; i++) {
		ans[i] = SchoolYear[i];
	}
	if (lengthOfSchoolYear != 0) {
		delete[]SchoolYear;
	}
	lengthOfSchoolYear++;
	SchoolYear = new int[lengthOfSchoolYear];
	for (int i = 0; i < lengthOfSchoolYear - 1; i++) {
		SchoolYear[i] = ans[i];
	}
	SchoolYear[lengthOfSchoolYear - 1] = temp;
	delete[]ans;
}
// Cấp phát bộ nhớ cho học kì
void AllocationSemester(Semester*& Ster, int& s_Ster, Semester temp)
{
	if (s_Ster > 3) {
		cout << "Can't create more semester!.";
	}
	else {
		Semester* ans = new Semester[s_Ster];
		for (int i = 0; i < s_Ster; i++) {
			ans[i] = Ster[i];
		}
		if (s_Ster != 0) {
			delete[]Ster;
		}
		s_Ster++;
		Ster = new Semester[s_Ster];
		for (int i = 0; i < s_Ster - 1; i++) {
			Ster[i] = ans[i];
		}
		Ster[s_Ster - 1] = temp;
		delete[]ans;
	}
}
// Cấp phát bộ nhớ cho khoa
void AllocationFaculty(Faculty*& Fac, int& s_Fac, Faculty temp) {
	Faculty* ans = new Faculty[s_Fac];
	for (int i = 0; i < s_Fac; i++) {
		ans[i] = Fac[i];
	}
	if (s_Fac != 0) {
		delete[]Fac;
		Fac = NULL;
	}
	s_Fac++;
	Fac = new Faculty[s_Fac];
	for (int i = 0; i < s_Fac - 1; i++) {
		Fac[i] = ans[i];
	}
	Fac[s_Fac - 1] = temp;
	delete[]ans;
	ans = NULL;
}
// Cấp phát bộ nhớ cho môn học
void AllocationCourse(Course*& Cour, int& s_Cour, Course temp) {
	Course* ans = new Course[s_Cour];
	for (int i = 0; i < s_Cour; i++) {
		ans[i] = Cour[i];
	}
	if (s_Cour != 0) {
		delete[]Cour;
	}
	s_Cour++;
	Cour = new Course[s_Cour];
	for (int i = 0; i < s_Cour - 1; i++) {
		Cour[i] = ans[i];
	}
	Cour[s_Cour - 1] = temp;
	delete[]ans;
}
// Cấp phát bộ nhớ cho lớp
void AllocationClass(DArray*& DAClass, int& s_class, DArray temp) {
	DArray* ans = new DArray[s_class];
	for (int i = 0; i < s_class; i++) {
		ans[i] = DAClass[i];
	}
	if (s_class != 0) {
		delete[]DAClass;
	}
	s_class++;
	DAClass = new DArray[s_class];
	for (int i = 0; i < s_class - 1; i++) {
		DAClass[i] = ans[i];
	}
	DAClass[s_class - 1] = temp;
	delete[]ans;
}
// Cấp phát bộ nhớ cho bảng điểm
void AllocationScoreBoard(ScoreBoard*& Score, int& lengthOfScoreBoard, ScoreBoard temp) {
	ScoreBoard* ans = new ScoreBoard[lengthOfScoreBoard];
	for (int i = 0; i < lengthOfScoreBoard; i++) {
		ans[i] = Score[i];
	}
	if (lengthOfScoreBoard != 0) {
		delete[]Score;
	}
	lengthOfScoreBoard++;
	Score = new ScoreBoard[lengthOfScoreBoard];
	for (int i = 0; i < lengthOfScoreBoard - 1; i++) {
		Score[i] = ans[i];
	}
	Score[lengthOfScoreBoard - 1] = temp;
	delete[]ans;
}
// Cấp phát bộ nhớ cho sinh viên
void AllocationStudent(Information*& infor, Account*& Acc, int& s_Student, Information temp1, Account temp2) {
	Information* ans = new Information[s_Student];
	Account* anss = new Account[s_Student];
	for (int i = 0; i < s_Student; i++) {
		ans[i] = infor[i];
		anss[i] = Acc[i];
	}
	if (s_Student != 0) {
		delete[]infor;
		delete[]Acc;
	}
	s_Student++;
	infor = new Information[s_Student];
	Acc = new Account[s_Student];
	for (int i = 0; i < s_Student - 1; i++) {
		infor[i] = ans[i];
		Acc[i] = anss[i];
	}
	temp1.No = s_Student;
	infor[s_Student - 1] = temp1;
	Acc[s_Student - 1] = temp2;
	delete[]ans;
	delete[]anss;
}
// Kiểm tra xem tài khoản có tồn tại không
bool CheckAccount(Account Acc1, Account* Acc2, int n, int& k) {
	for (int i = 0; i < n; i++) {
		if (((strcmp(Acc1.Username, Acc2[i].Username) == 0) && (strcmp(Acc1.Password, Acc2[i].Password) == 0))) {
			k = i;
			return true;
		}
	}
	return false;
}
// Kiểm tra xem lớp có tồn tại không
bool CheckClass(Faculty Fac, char* nameclass) {
	for (int i = 0; i < Fac.lengthOfClass; i++) {
		if (strcmp(Fac.Class[i].NameClass, nameclass) == 0) {
			return false;
		}
	}
	return true;
}
// Hàm đăng nhập trả về true nếu đăng nhập thành công
bool SignIn(Account& Acc1, DArray& DA, int& k, bool notification) {
	Account Acc2;
	int n, quantity;
	int lc = 0;
	system("cls");
	int x = 37, y = 10;
	gotoXY(x, y++);
	cout << "\t\tSIGN IN" << endl;
	do {
		BoxUsage(1, 0, 19, 5);
		gotoXY(60, 7); cout << "SIGN IN" << endl;
		n_Box13(38, 8, 50, 2, 1, 7, quantity, Acc2);
		if ((CheckAccount(Acc2, DA.Acc, DA.lengthStudent, n) == true)) {
			if (notification == false) {
				k = n;
				return true;
			}
			BoxUsage(1, 0, 19, 5);
			cpychar(Acc1.Username, s);
			cpychar(Acc1.Password, s);
			k = n;
			if (BoxNotification(42, 10, 30, 4, 1, 7, "Sign in successfully!", true)) {
				return true;
			}
			return true;
		}
		else if (CheckAccount(Acc2, DA.Acc, DA.lengthStudent, n) == false) {
			BoxUsage(1, 0, 19, 5);
			if (BoxNotification(42, 10, 30, 2, 1, 7, "Wrong account!", true)) {
				return false;
			}
		}
	} while (CheckAccount(Acc2, DA.Acc, DA.lengthStudent, n) == false);
}
// Hàm thay đổi tài khoản trả về true nếu thay đổi thành công
bool ChangePassword(DArray& DA) {
	Account Acc1;
	int n, quantity;
	int x = 37, y = 15;
	if (SignIn(Acc1, DA, n, false)) {
		n_Box14(38, 12, 50, 2, 1, 7, quantity, Acc1);
		BoxUsage(1, 0, 19, 5);
		if (strcmp(Acc1.Password, Acc1.Username) == 0) {
			// cập nhật mật khâu vừa nhập chính xác và thay thế mật khẩu cũ
			cpychar(DA.Acc[n].Password, Acc1.Password);
			gotoXY(x, y++);
			BoxNotification(40, 10, 50, 4, 1, 7, "Change password successfully!", true);
			return true;
		}
		else {
			system("cls");
			BoxNotification(40, 10, 30, 4, 1, 7, "Password is not valid!", true);
			return false;
		}
	}
	return false;
}
// Hàm tạo Email 
void CreateEmail(DArray& DA, int vitri) {
	char emailStudent[] = { "@student.hcmus.edu.vn" };
	char emailStaff[] = { "@hcmus.edu.vn" };
	char s1[100];
	if (DA.lengthStudent < 10) {
		int k = 0;
		s1[k++] = char(DA.Member[vitri].FirstName[0] + 32);
		int n1 = strlen(DA.Member[vitri].FirstName);
		int n2 = strlen(DA.Member[vitri].LastName);
		for (int i = 1; i < n1; i++) {
			if (DA.Member[vitri].FirstName[i] == ' ') {
				s1[k++] = char(DA.Member[vitri].FirstName[i + 1] + 32);
			}
		}
		s1[k++] = char(DA.Member[vitri].LastName[0] + 32);
		for (int i = 1; i < n2; i++) {
			s1[k++] = char(DA.Member[vitri].LastName[i]);
		}
		s1[k] = '\0';
		strcat_s(s1, emailStaff);
	}
	else {
		for (int i = 0; i < 8; i++) {
			s1[i] = DA.Member[vitri].StudentID[i];
		}
		for (int i = 0; i < strlen(emailStudent); i++) {
			s1[8 + i] = emailStudent[i];
		}
		s1[8 + strlen(emailStudent)] = '\0';
	}
	cpychar(DA.Member[vitri].Email, s1);
	cpychar(DA.Acc[vitri].Username, s1);
	char s2[100];
	char s3[100];
	_itoa_s(DA.Member[vitri].DateOfBirth.day, s2, 10);
	if (DA.Member[vitri].DateOfBirth.day < 10) {
		s3[0] = '0';
		s3[1] = s2[0];
	}
	else {
		s3[0] = s2[0];
		s3[1] = s2[1];
	}
	_itoa_s(DA.Member[vitri].DateOfBirth.month, s2, 10);
	if (DA.Member[vitri].DateOfBirth.month < 10) {
		s3[2] = '0';
		s3[3] = s2[0];
	}
	else {
		s3[2] = s2[0];
		s3[3] = s2[1];
	}
	s3[4] = '\0';
	_itoa_s(DA.Member[vitri].DateOfBirth.year, s2, 10);
	strcat_s(s3, s2);
	cpychar(DA.Acc[vitri].Password, s3);
}
// Hàm tạo mã số sinh viên 
void CreateID(char*& ID, int K, int F, int No) {
	long long MSSV = 1;
	ID = new char[9];
	MSSV = (MSSV * K * 1000 + F) * 1000 + No;
	_itoa(MSSV, ID, 10);
}
// Hàm đọc thông tin từ file
void ReadListFromFile(ifstream& filein, DArray& DA) {
	char c;
	DA.lengthStudent = 0;
	string s;
	int n = 0;
	while (filein.eof() != true) {
		getline(filein, s, '\n');
		n++;
	}
	// Đưa con trỏ chỉ vị về đầu danh sách
	filein.seekg(0, ios::beg);
	DA.Member = new Information[n - 1];
	DA.Acc = new Account[n - 1];
	getline(filein, s, '\n');
	while (filein.eof() != true) {
		filein >> DA.Member[DA.lengthStudent].No;
		filein.get(c);
		getline(filein, s, ',');
		cpyString(DA.Member[DA.lengthStudent].StudentID, s);
		getline(filein, s, ',');
		cpyString(DA.Member[DA.lengthStudent].FirstName, s);
		getline(filein, s, ',');
		cpyString(DA.Member[DA.lengthStudent].LastName, s);
		getline(filein, s, ',');
		cpyString(DA.Member[DA.lengthStudent].Gender, s);
		filein >> DA.Member[DA.lengthStudent].DateOfBirth.day;
		filein.get(c);
		filein >> DA.Member[DA.lengthStudent].DateOfBirth.month;
		filein.get(c);
		filein >> DA.Member[DA.lengthStudent].DateOfBirth.year;
		filein.get(c);
		filein >> DA.Member[DA.lengthStudent].CCCD;
		filein.get(c);
		getline(filein, s, '\n');
		cpyString(DA.Member[DA.lengthStudent].Postition, s);
		DA.lengthStudent++;
	}
	// Tạo Email
	for (int i = 0; i < DA.lengthStudent; i++) {
		CreateEmail(DA, i);
	}
}
//Hàm đọc danh sách khoa
void ReadListFaculty(ifstream& filein, YearSchool& YeahSch, string pathOfSource) {
	int length = 0;
	char c;
	int a;
	string s;
	filein.open(pathOfSource, ios::in);
	while (!filein.eof()) {
		getline(filein, s, '\n');
		length++;
	}
	filein.seekg(0, ios::beg);
	YeahSch.faculty = new Faculty[length + 1];
	YeahSch.lengthOfFaculty = 1;// đọc vào khoa bắt đầu từ 1
	getline(filein, s, '\n');
	while (!filein.eof()) {
		getline(filein, s, ',');
		filein >> YeahSch.faculty[YeahSch.lengthOfFaculty].symbolFaculty;
		filein.get(c);// đọc kí tự dấy phẩy
		getline(filein, s, '\n');
		cpyString(YeahSch.faculty[YeahSch.lengthOfFaculty].NameFaculty, s);
		YeahSch.lengthOfFaculty++;
	}
	filein.close();
}
// Hàm đọc danh sách toàn bộ lớp của năm học 
void ReadListClass(ifstream& filein, YearSchool& YearSch, string pathOfSource) {
	string s;
	char c;
	filein.open(pathOfSource, ios::in);
	getline(filein, s, '\n');
	DArray temporary;
	while (!filein.eof()) {
		getline(filein, s, ',');// đọc stt
		getline(filein, s, ',');
		cpyString(temporary.NameClass, s);
		filein >> temporary.lengthMaxOfClass;
		filein.get(c);
		getline(filein, s, '\n');
		cpyString(temporary.classOfFaculty, s);
		AllocationClass(YearSch.faculty[0].Class, YearSch.faculty[0].lengthOfClass, temporary);
	}
	filein.close();
}
// Hàm đọc danh sách toàn bộ môn học 
void ReadListCourse(ifstream& filein, YearSchool& YearSch, int HK, string pathOfSource) {
	string s;
	char temp;
	int a;
	filein.open(pathOfSource, ios::in);
	Course temporary;
	getline(filein, s, '\n');
	while (!filein.eof()) {
		getline(filein, s, ',');
		getline(filein, s, ',');
		cpyString(temporary.CourseID, s);
		getline(filein, s, ',');
		cpyString(temporary.CourseName, s);
		getline(filein, s, ',');
		cpyString(temporary.NameTeacher, s);
		getline(filein, s, ',');
		cpyString(temporary.ClassName, s);
		filein >> temporary.NumberCredits;
		filein.get(temp);
		getline(filein, s, ',');
		cpyString(temporary.DayOfTheWeek, s);
		getline(filein, s, ',');
		cpyString(temporary.Session, s);
		filein >> temporary.NumberOfStudent;
		filein.get(temp);
		filein >> temporary.MaximumStudent;
		filein.get(temp);//đọc kí tự xuống dòng
		AllocationCourse(YearSch.faculty[HK].course, YearSch.faculty[HK].lengthOfCourse, temporary);
	}
	filein.close();
}
// Hàm đọc bảng điểm từng môn học
bool ReadScoreBoardOfCourse(ifstream& filein, Course& course, char* pathOfSource) {
	string s;
	char sTemp;
	filein.open(pathOfSource, ios::in);
	if (filein.is_open() == false)return false;
	//course.Score = new ScoreBoard[course.NumberOfStudent];
	getline(filein, s, '\n');
	for (int i = 0; i < course.NumberOfStudent; i++) {
		getline(filein, s, ',');
		getline(filein, s, ',');
		getline(filein, s, ',');
		filein >> course.Score[i].OtherMark;
		filein.get(sTemp);
		filein >> course.Score[i].MidTermMark;
		filein.get(sTemp);
		filein >> course.Score[i].FinalMark;
		filein.get(sTemp);
		filein >> course.Score[i].TotalMark;
		filein.get(sTemp);// Đọc kí tự xuống dòng
	}
	filein.close();
	return true;
}
// Hàm random điểm cho các lớp có sẵn chứ nhập tay lâu quá huhu
void RandomScoreBoard(Course& course, bool Flag) {
	course.Score = new ScoreBoard[course.NumberOfStudent];
	for (int i = 0; i < course.NumberOfStudent; i++) {
		course.Score[i].StudentID = new char[strlen(course.Member[i].StudentID) + 1];
		strcpy(course.Score[i].StudentID, course.Member[i].StudentID);
		course.Score[i].FullName = new char[strlen(course.Member[i].FirstName) + strlen(course.Member[i].LastName) + 2];
		int n1 = strlen(course.Member[i].FirstName);
		int n2 = strlen(course.Member[i].LastName);
		for (int j = 0; j < n1; j++) {
			course.Score[i].FullName[j] = course.Member[i].FirstName[j];
		}
		course.Score[i].FullName[n1] = ' ';
		for (int j = 0; j < n2; j++) {
			course.Score[i].FullName[n1 + j + 1] = course.Member[i].LastName[j];
		}
		if (Flag == false) {
			course.Score[i].FullName[n1 + n2 + 1] = '\0';
			course.Score[i].OtherMark = -1;
			course.Score[i].MidTermMark = -1;
			course.Score[i].FinalMark = -1;
			course.Score[i].TotalMark = -1;
		}
		else {
			course.Score[i].FullName[n1 + n2 + 1] = '\0';
			course.Score[i].OtherMark = (rand() % (10 - 7 + 1) + 7);
			course.Score[i].MidTermMark = (rand() % (10 - 5 + 1) + 5);
			course.Score[i].FinalMark = (rand() % (10 - 4 + 1) + 4);
			course.Score[i].TotalMark = (course.Score[i].OtherMark * 0.2 + course.Score[i].MidTermMark * 0.3 + course.Score[i].FinalMark * 0.5);
		}
	}
}
// Hàm nhập thông tin một môn học từ bàn phím
void inputCourse(Course& Cour) {
	int x = 40, y = 9;
	system("cls");
	gotoXY(x, y++);
	cout << "COURSE ID        : "; gets_s(s);
	gotoXY(x, y++);
	cpychar(Cour.CourseID, s);
	cout << "COURSE NAME      : "; gets_s(s);
	gotoXY(x, y++);
	cpychar(Cour.CourseName, s);
	cout << "TEACHER NAME     : "; gets_s(s);
	gotoXY(x, y++);
	cpychar(Cour.NameTeacher, s);
	cout << "NUMBER OF CREDITS: "; cin >> Cour.NumberCredits;
	gotoXY(x, y++);
	cout << "MAXIUM OF STUDENT: "; cin >> Cour.MaximumStudent;
	gotoXY(x, y++);
	cin.ignore();
	cout << "DAY OF THE WEEK  : "; gets_s(s);
	gotoXY(x, y++);
	cpychar(Cour.DayOfTheWeek, s);
	cout << "SESSION          : "; gets_s(s);
	cpychar(Cour.Session, s);
	y -= 7;
}
// Menu Profile
void MenuProfile(Information infor) {
	int option;
	BoxUsage(1, 0, 19, 5);
	n_Box20(40, 8, 45, 2, 1, 7, option, infor);
	_getch();
}
// Menu tạo học kì mới 
void CreateNewSemester(School* Sch, int& i_Sch) {
	Date a1, a2, a3;
	int option;
	Semester temp;
	char semester1[] = { "Fall" };
	char semester2[] = { "Summer" };
	char semester3[] = { "Autumn" };
	BoxUsage(1, 0, 19, 5);
	switch (Sch[i_Sch].lengthOfSemester) {
	case 0:
		a1 = { 15,9,TIME.year };
		a3 = { 1,9,TIME.year };
		if (compareDate(TIME, a1) == 1 || compareDate(TIME, a3) == -1) {
			BoxNotification(40, 8, 50, 4, 1, 7, "Invalid time!", true);
			return;
		}
		cpychar(temp.NameSemester, semester1);
		break;
	case 1:
		a2 = { 1,2,TIME.year };
		a3 = { 15,2,TIME.year };
		if (compareDate(TIME, a2) == -1 || compareDate(TIME, a3) == 1) {
			BoxNotification(40, 8, 50, 4, 1, 7, "Invalid time!", true);
			return;
		}
		cpychar(temp.NameSemester, semester2);
		break;
	case 2:
		a3 = { 1,7,TIME.year };
		a1 = { 15,7,TIME.year };
		if (compareDate(TIME, a3) == -1 || compareDate(TIME, a1) == 1) {
			BoxNotification(40, 8, 50, 4, 1, 7, "Invalid time!", true);
			return;
		}
		cpychar(temp.NameSemester, semester3);
		break;
	case 3:
		BoxNotification(40, 8, 50, 4, 1, 7, "Can't create more semester!", true);
		return;
	}
	n_Box32(40, 8, 45, 2, 1, 7, option, temp);
	if (checkDay(temp.StartDate) == true && checkDay(temp.EndDate) == true) {
		AllocationSemester(Sch[i_Sch].semester, Sch[i_Sch].lengthOfSemester, temp);
		FLAG2 = false;
		BoxLoading(35, 10, 51, 2, 1, 7);
		BoxNotification(40, 8, 40, 4, 1, 7, "Create semester successfully!", true);
		_getch();
	}
	else {
		BoxNotification(40, 8, 30, 4, 1, 7, "Invalid date!", true);
		_getch();
	}
}
// Menu tạo khoa mới
void CreateNewFaculty(YearSchool& ySch) {
	int lc;
	int x = 39, y = 10;
	system("cls");	gotoXY(x, y++);
	Faculty temp;
	cout << "======== CREATE FACULTY ========";	gotoXY(x, y++);
	cout << " Enter name faculty: "; gets_s(s);
	cpychar(temp.NameFaculty, s); gotoXY(x, y++);
	cout << "=================================";	gotoXY(x + 1, y++);
	cout << "Create semester successfully!.";
	gotoXY(x, y++);
	AllocationFaculty(ySch.faculty, ySch.lengthOfFaculty, temp);
}
// Menu tạo lớp mới
void CreateNewClass(Faculty& Fac) {
	int option;
	int x = 39, y = 10;
	BoxUsage(1, 0, 19, 5);	gotoXY(40, 8);
	DArray temp;
	cout << Fac.NameFaculty << endl; gotoXY(x, y++);
	n_Box34(33, 9, 55, 2, 1, 7, option, temp);

	temp.classOfFaculty = new char[strlen(Fac.NameFaculty) + 1];
	strcpy(temp.classOfFaculty, Fac.NameFaculty);
	if (CheckClass(Fac, temp.NameClass)) {
		AllocationClass(Fac.Class, Fac.lengthOfClass, temp);
		BoxNotification(40, 10, 31, 4, 1, 7, "Create class successfully!", true);
	}
	else {
		BoxNotification(40, 10, 30, 4, 1, 7, "Class already exists!", true);
	}
	/*cout << "========== CREATE CLASS =========";	gotoXY(x, y++);
	cout << " Enter name class: "; gets_s(s);
	cpychar(temp.NameClass, s); gotoXY(x, y++);
	cout << " Enter maximum student: "; cin >> temp.lengthMaxOfClass;
	gotoXY(x, y++);
	temp.classOfFaculty = new char[strlen(Fac.NameFaculty)+1];
	strcpy(temp.classOfFaculty, Fac.NameFaculty);
	cout << "=================================";	gotoXY(x + 1, y++);
	cout << "Create class successfully!."; gotoXY(x, y++);
	system("pause");
	gotoXY(x, y++);*/

}
// Menu tạo một môn học mới từ bàn phím
void CreateNewCourse(Faculty& Fac) {
	int option;
	int x = 39, y = 10;
	BoxUsage(1, 0, 19, 5);
	Course temp;
	n_Box33(33, 5, 55, 2, 1, 7, option, temp);
	if (CheckClass(Fac, temp.ClassName) == false) {
		AllocationCourse(Fac.course, Fac.lengthOfCourse, temp);
		for (int i = 0; i < Fac.lengthOfClass; i++) {
			if (strcmp(temp.ClassName, Fac.Class[i].NameClass) == 0) {
				AllocationCourse(Fac.Class[i].course, Fac.Class[i].lengthOfCourseOfClass, temp);
				break;
			}
		}
		BoxNotification(40, 10, 30, 4, 1, 7, "Create course successfully!", true);
	}
	else {
		BoxNotification(40, 10, 40, 4, 1, 7, "Class does not exist!.Please enter again", true);
	}
}
// Menu tạo một sinh viên từ bàn phím
void CreateNewStudent(Information*& infor, Account*& acc, ScoreBoard*& Score, int& NumberOfStudent, DArray& DA, Faculty faculty) {
	int option;
	int x = 39, y = 10;
	BoxUsage(1, 0, 19, 5);
	Information temp1;
	Account temp2;
	n_Box35(33, 5, 55, 2, 1, 7, option, temp1);
	if (checkDay(temp1.DateOfBirth)) {
		temp1.Postition = new char[10];
		strcpy(temp1.Postition, "STUDENT");
		char emailStudent[] = { "@student.hcmus.edu.vn" };
		CreateID(temp1.StudentID, getK(DA.NameClass), faculty.symbolFaculty, ++faculty.lengthStudent);
		char s1[100];
		for (int i = 0; i < 8; i++) {
			s1[i] = temp1.StudentID[i];
		}
		for (int i = 0; i < strlen(emailStudent); i++) {
			s1[8 + i] = emailStudent[i];
		}
		s1[8 + strlen(emailStudent)] = '\0';
		cpychar(temp1.Email, s1);
		cpychar(temp2.Username, s1);
		char s2[100];
		char s3[100];
		_itoa_s(temp1.DateOfBirth.day, s2, 10);
		if (temp1.DateOfBirth.day < 10) {
			s3[0] = '0';
			s3[1] = s2[0];
		}
		else {
			s3[0] = s2[0];
			s3[1] = s2[1];
		}
		_itoa_s(temp1.DateOfBirth.month, s2, 10);
		if (temp1.DateOfBirth.month < 10) {
			s3[2] = '0';
			s3[3] = s2[0];
		}
		else {
			s3[2] = s2[0];
			s3[3] = s2[1];
		}
		s3[4] = '\0';
		_itoa_s(temp1.DateOfBirth.year, s2, 10);
		strcat_s(s3, s2);
		cpychar(temp2.Password, s3);
		cout << "Create a student successfully!."; gotoXY(x, y++);
		AllocationStudent(infor, acc, NumberOfStudent, temp1, temp2);
		BoxNotification(42, 10, 30, 4, 1, 7, "Create a student successfully!", true);
		Score = new ScoreBoard[NumberOfStudent];
		for (int i = 0; i < NumberOfStudent; i++) {
			Score[i].StudentID = new char[strlen(infor[i].StudentID) + 1];
			strcpy(Score[i].StudentID, infor[i].StudentID);
			Score[i].FullName = new char[strlen(infor[i].FirstName) + strlen(infor[i].LastName) + 2];
			int n11 = strlen(infor[i].FirstName);
			int n22 = strlen(infor[i].LastName);
			for (int j = 0; j < n11; j++) {
				Score[i].FullName[j] = infor[i].FirstName[j];
			}
			Score[i].FullName[n11] = ' ';
			for (int j = 0; j < n22; j++) {
				Score[i].FullName[n11 + j + 1] = infor[i].LastName[j];
			}
			Score[i].FullName[n11 + n22 + 1] = '\0';
			Score[i].OtherMark = -1/*(rand() % (10 - 7 + 1) + 7)*/;
			Score[i].MidTermMark = -1/*(rand() % (10 - 5 + 1) + 5)*/;
			Score[i].FinalMark = -1/*(rand() % (10 - 4 + 1) + 4)*/;
			Score[i].TotalMark = -1 /*(Score[i].OtherMark * 0.2 + Score[i].MidTermMark * 0.3 + Score[i].FinalMark * 0.5)*/;
		}
	}
}
void CreateNewStudent(DArray& DA, Faculty& faculty, YearSchool& ySch/*Information*& infor, Account*& acc, ScoreBoard*& Score, int& NumberOfStudent, DArray& DA, Faculty faculty*/) {
	int option;
	int x = 39, y = 10;
	BoxUsage(1, 0, 19, 5);
	Information temp1;
	Account temp2;
	n_Box35(33, 5, 55, 2, 1, 7, option, temp1);
	if (checkDay(temp1.DateOfBirth)) {
		temp1.Postition = new char[10];
		strcpy(temp1.Postition, "STUDENT");
		char emailStudent[] = { "@student.hcmus.edu.vn" };
		CreateID(temp1.StudentID, getK(DA.NameClass), faculty.symbolFaculty, ++faculty.lengthStudent);
		char s1[100];
		for (int i = 0; i < 8; i++) {
			s1[i] = temp1.StudentID[i];
		}
		for (int i = 0; i < strlen(emailStudent); i++) {
			s1[8 + i] = emailStudent[i];
		}
		s1[8 + strlen(emailStudent)] = '\0';
		cpychar(temp1.Email, s1);
		cpychar(temp2.Username, s1);
		char s2[100];
		char s3[100];
		_itoa_s(temp1.DateOfBirth.day, s2, 10);
		if (temp1.DateOfBirth.day < 10) {
			s3[0] = '0';
			s3[1] = s2[0];
		}
		else {
			s3[0] = s2[0];
			s3[1] = s2[1];
		}
		_itoa_s(temp1.DateOfBirth.month, s2, 10);
		if (temp1.DateOfBirth.month < 10) {
			s3[2] = '0';
			s3[3] = s2[0];
		}
		else {
			s3[2] = s2[0];
			s3[3] = s2[1];
		}
		s3[4] = '\0';
		_itoa_s(temp1.DateOfBirth.year, s2, 10);
		strcat_s(s3, s2);
		cpychar(temp2.Password, s3);
		cout << "Create a student successfully!."; gotoXY(x, y++);
		AllocationStudent(DA.Member, DA.Acc, DA.lengthStudent, temp1, temp2);
		// Cập nhật số lượng sinh viên trong khóa
		AllocationStudent(ySch.student.Member, ySch.student.Acc, ySch.student.lengthStudent, temp1, temp2);
		BoxNotification(42, 10, 30, 4, 1, 7, "Create a student successfully!", true);
	}
}
// Thông tin của lớp
void informationOfOneClass(DArray DA) {
	int quantity;
	BoxUsage(1, 0, 19, 5);
	n_Box21(40, 8, 40, 2, 1, 7, quantity, DA);
	_getch();
}
// Thông tin của môn học
void informationOfOneCourse(Course course) {
	int quantity;
	BoxUsage(1, 0, 19, 5);
	n_Box22(40, 8, 40, 2, 1, 7, quantity, course);
	_getch();
}
// Hàm cập nhật thông tin của môn học
void updateInformationOfCourse(Course& course) {
	int quantity;
	BoxUsage(1, 0, 19, 5);
	n_Box22_1(33, 6, 60, 2, 1, 7, quantity, course);
	BoxLoading(35, 10, 51, 2, 1, 7);
	BoxNotification(20, 8, 40, 4, 1, 7, "Successful subject update!", true);
}
// Hàm xóa 1 sinh viên từ khóa học
void removedOneStudentOfCourse(Course& course, int position) {
	Information* temporary1 = new Information[course.NumberOfStudent];
	Account* temporary2 = new Account[course.NumberOfStudent];
	ScoreBoard* temporary3 = new ScoreBoard[course.NumberOfStudent];
	for (int i = 0; i < course.NumberOfStudent; i++) {
		temporary1[i] = course.Member[i];
		temporary2[i] = course.Acc[i];
		temporary3[i] = course.Score[i];
	}
	delete[]course.Member;
	delete[]course.Acc;
	delete[]course.Score;
	course.NumberOfStudent--;
	course.Member = new Information[course.NumberOfStudent];
	course.Acc = new Account[course.NumberOfStudent];
	course.Score = new ScoreBoard[course.NumberOfStudent];
	for (int i = 0; i < position; i++) {
		course.Member[i] = temporary1[i];
		course.Acc[i] = temporary2[i];
		course.Score[i] = temporary3[i];
	}
	for (int i = position; i < course.NumberOfStudent; i++) {
		course.Member[i] = temporary1[i + 1];
		course.Member[i].No = i + 1;
		course.Acc[i] = temporary2[i + 1];
		course.Score[i] = temporary3[i + 1];
	}
	delete[]temporary1;
	delete[]temporary2;
}
// Hàm xóa khóa học
void removedOneCourse(DArray& DA, int position) {
	Course* temporary = new Course[DA.lengthOfCourseOfClass];
	for (int i = 0; i < DA.lengthOfCourseOfClass; i++) {
		temporary[i] = DA.course[i];
	}
	delete[]DA.course;
	DA.lengthOfCourseOfClass--;
	DA.course = new Course[DA.lengthOfCourseOfClass];
	for (int i = 0; i < position; i++) {
		DA.course[i] = temporary[i];
	}
	for (int i = position; i < DA.lengthOfCourseOfClass; i++) {
		DA.course[i] = temporary[i + 1];
	}
	delete[]temporary;
}
// Hàm trả về 2 số đầu của mã số sinh viên 
int getK(char* ID) {
	char temporary[3];
	temporary[0] = ID[0];
	temporary[1] = ID[1];
	temporary[2] = '\0';
	return atoi(temporary);
}
// Hàm trả về 3 số chứa khoa của sinh viên
int getF(char* ID) {
	char temporary[4];
	temporary[0] = ID[2];
	temporary[1] = ID[3];
	temporary[2] = ID[4];
	temporary[3] = '\0';
	return atoi(temporary);
}
// Hàm trả về  khoa của sinh viên
Faculty getFaculty(School Sch, int position, int year) {
	if (year == 2000 + getK(Sch.DAStudent.Member[position].StudentID)) {
		for (int i = 0; i < Sch.semester[Sch.lengthOfSemester - 1].Freshman.lengthOfFaculty; i++) {
			if (Sch.semester[Sch.lengthOfSemester - 1].Freshman.faculty[i].symbolFaculty == getF(Sch.DAStudent.Member[position].StudentID)) {
				return Sch.semester[Sch.lengthOfSemester - 1].Freshman.faculty[i];
			}
		}
	}
	if (year == 2000 + getK(Sch.DAStudent.Member[position].StudentID) - 1) {
		for (int i = 0; i < Sch.semester[Sch.lengthOfSemester - 11].Sophomore.lengthOfFaculty; i++) {
			if (Sch.semester[Sch.lengthOfSemester - 1].Sophomore.faculty[i].symbolFaculty == getF(Sch.DAStudent.Member[position].StudentID)) {
				return Sch.semester[Sch.lengthOfSemester - 1].Sophomore.faculty[i];
			}
		}
	}
	if (year == 2000 + getK(Sch.DAStudent.Member[position].StudentID) - 2) {
		for (int i = 0; i < Sch.semester[Sch.lengthOfSemester - 1].Thir_Year_Student.lengthOfFaculty; i++) {
			if (Sch.semester[Sch.lengthOfSemester - 1].Thir_Year_Student.faculty[i].symbolFaculty == getF(Sch.DAStudent.Member[position].StudentID)) {
				return Sch.semester[Sch.lengthOfSemester - 1].Thir_Year_Student.faculty[i];
			}
		}
	}
	if (year == 2000 + getK(Sch.DAStudent.Member[position].StudentID) - 3) {
		for (int i = 0; i < Sch.semester[Sch.lengthOfSemester - 1].Fourth_Year_Student.lengthOfFaculty; i++) {
			if (Sch.semester[Sch.lengthOfSemester - 1].Fourth_Year_Student.faculty[i].symbolFaculty == getF(Sch.DAStudent.Member[position].StudentID)) {
				return Sch.semester[Sch.lengthOfSemester - 1].Fourth_Year_Student.faculty[i];
			}
		}
	}
}
// Hàm ghi file danh sách sinh viên
void WriteFile(ofstream& fileout, Information infor, int& count) {
	fileout << "\n" << count++ << "," << infor.StudentID << "," << infor.FirstName << ","
		<< infor.LastName << "," << infor.Gender << "," << infor.DateOfBirth.day << "/"
		<< infor.DateOfBirth.month << "/" << infor.DateOfBirth.year << "," << infor.CCCD << ","
		<< infor.Postition;
}
// Hàm viét toàn bộ sinh viên của từng khóa
void WriteStudentOfYearSchool(School& Sch, int year) {
	ofstream fileout;
	int count = 1;
	fileout.open("File_Freshman.csv", ios::out);
	fileout << "No,StudentID,FirstName,LastName,Gender,Date,CCCD/CMND,Position";
	for (int i = 0; i < Sch.DAStudent.lengthStudent; i++) {
		if (getK(Sch.DAStudent.Member[i].StudentID) == year) {
			WriteFile(fileout, Sch.DAStudent.Member[i], count);
		}
	}
	fileout.close();

	fileout.open("File_Sophomore.csv", ios::out);
	fileout << "No,StudentID,FirstName,LastName,Gender,Date,CCCD/CMND,Position";
	count = 1;
	for (int i = 0; i < Sch.DAStudent.lengthStudent; i++) {
		if (getK(Sch.DAStudent.Member[i].StudentID) == year - 1) {
			WriteFile(fileout, Sch.DAStudent.Member[i], count);
		}
	}
	fileout.close();

	fileout.open("File_ThirdYear.csv", ios::out);
	fileout << "No,StudentID,FirstName,LastName,Gender,Date,CCCD/CMND,Position";
	count = 1;
	for (int i = 0; i < Sch.DAStudent.lengthStudent; i++) {
		if (getK(Sch.DAStudent.Member[i].StudentID) == year - 2) {
			WriteFile(fileout, Sch.DAStudent.Member[i], count);
		}
	}
	fileout.close();

	fileout.open("File_FourthYear.csv", ios::out);
	fileout << "No,StudentID,FirstName,LastName,Gender,Date,CCCD/CMND,Position";
	count = 1;
	for (int i = 0; i < Sch.DAStudent.lengthStudent; i++) {
		if (getK(Sch.DAStudent.Member[i].StudentID) == year - 3) {
			WriteFile(fileout, Sch.DAStudent.Member[i], count);
		}
	}
	fileout.close();
}
void WriteStudent(School& Sch) {
	ofstream fileout;
	int count = 1;
	fileout.open("File_Freshman.csv", ios::out);
	fileout << "No,StudentID,FirstName,LastName,Gender,Date,CCCD/CMND,Position";
	for (int i = 0; i < Sch.semester[Sch.lengthOfSemester - 1].Freshman.student.lengthStudent; i++) {
		WriteFile(fileout, Sch.semester[Sch.lengthOfSemester - 1].Freshman.student.Member[i], count);
	}
	fileout.close();

	fileout.open("File_Sophomore.csv", ios::out);
	fileout << "No,StudentID,FirstName,LastName,Gender,Date,CCCD/CMND,Position";
	count = 1;
	for (int i = 0; i < Sch.semester[Sch.lengthOfSemester - 1].Sophomore.student.lengthStudent; i++) {
		WriteFile(fileout, Sch.semester[Sch.lengthOfSemester - 1].Sophomore.student.Member[i], count);
	}
	fileout.close();

	fileout.open("File_ThirdYear.csv", ios::out);
	fileout << "No,StudentID,FirstName,LastName,Gender,Date,CCCD/CMND,Position";
	count = 1;
	for (int i = 0; i < Sch.semester[Sch.lengthOfSemester - 1].Thir_Year_Student.student.lengthStudent; i++) {
		WriteFile(fileout, Sch.semester[Sch.lengthOfSemester - 1].Thir_Year_Student.student.Member[i], count);
	}
	fileout.close();

	fileout.open("File_FourthYear.csv", ios::out);
	fileout << "No,StudentID,FirstName,LastName,Gender,Date,CCCD/CMND,Position";
	count = 1;
	for (int i = 0; i < Sch.semester[Sch.lengthOfSemester - 1].Fourth_Year_Student.student.lengthStudent; i++) {
		WriteFile(fileout, Sch.semester[Sch.lengthOfSemester - 1].Fourth_Year_Student.student.Member[i], count);
	}
	fileout.close();
}
// Hàm tách sinh viên từ danh danh toàn bộ sinh viên của trường vào từng khóa 
// sẽ lấy thời gian thực
void ReadStudentOfYearSchool(School& Sch) {
	ifstream filein;
	filein.open("File_Freshman.csv", ios::in);
	ReadListFromFile(filein, Sch.semester[Sch.lengthOfSemester - 1].Freshman.student);
	filein.close();

	filein.open("File_Sophomore.csv", ios::in);
	ReadListFromFile(filein, Sch.semester[Sch.lengthOfSemester - 1].Sophomore.student);
	filein.close();

	filein.open("File_ThirdYear.csv", ios::in);
	ReadListFromFile(filein, Sch.semester[Sch.lengthOfSemester - 1].Thir_Year_Student.student);
	filein.close();

	filein.open("File_FourthYear.csv", ios::in);
	ReadListFromFile(filein, Sch.semester[Sch.lengthOfSemester - 1].Fourth_Year_Student.student);
	filein.close();
}
void splitOfSchool(School& Sch, int year) {
	int count = 1;
	string sTemp;
	ofstream fileout;
	ifstream filein;
	WriteStudentOfYearSchool(Sch, year);
	ReadStudentOfYearSchool(Sch);
}
//Hàm tách lớp từ danh sách toàn bộ lớp của trường
void splitOfClass(School& Sch, int year, bool flag, int stSemester) {
	if (flag) {
		for (int i = 0; i < Sch.Data.lengthOfFaculty - 1; i++) {
			AllocationFaculty(Sch.semester[stSemester].Freshman.faculty, Sch.semester[stSemester].Freshman.lengthOfFaculty, Sch.Data.faculty[i + 1]);
			AllocationFaculty(Sch.semester[stSemester].Sophomore.faculty, Sch.semester[stSemester].Sophomore.lengthOfFaculty, Sch.Data.faculty[i + 1]);
			AllocationFaculty(Sch.semester[stSemester].Thir_Year_Student.faculty, Sch.semester[stSemester].Thir_Year_Student.lengthOfFaculty, Sch.Data.faculty[i + 1]);
			AllocationFaculty(Sch.semester[stSemester].Fourth_Year_Student.faculty, Sch.semester[stSemester].Fourth_Year_Student.lengthOfFaculty, Sch.Data.faculty[i + 1]);
		}
	}
	for (int i = 0; i < Sch.Data.faculty[0].lengthOfClass; i++) {
		if (getK(Sch.Data.faculty[0].Class[i].NameClass) == year) {
			for (int j = 0; j < Sch.semester[stSemester].Freshman.lengthOfFaculty; j++) {
				if (strcmp(Sch.Data.faculty[0].Class[i].classOfFaculty, Sch.semester[stSemester].Freshman.faculty[j].NameFaculty) == 0) {
					AllocationClass(Sch.semester[stSemester].Freshman.faculty[j].Class, Sch.semester[stSemester].Freshman.faculty[j].lengthOfClass, Sch.Data.faculty[0].Class[i]);
				}
			}
		}
		else if (getK(Sch.Data.faculty[0].Class[i].NameClass) == year - 1) {
			for (int j = 0; j < Sch.semester[stSemester].Sophomore.lengthOfFaculty; j++) {
				if (strcmp(Sch.Data.faculty[0].Class[i].classOfFaculty, Sch.semester[stSemester].Sophomore.faculty[j].NameFaculty) == 0) {
					AllocationClass(Sch.semester[stSemester].Sophomore.faculty[j].Class, Sch.semester[stSemester].Sophomore.faculty[j].lengthOfClass, Sch.Data.faculty[0].Class[i]);
				}
			}
		}
		else if (getK(Sch.Data.faculty[0].Class[i].NameClass) == year - 2) {
			for (int j = 0; j < Sch.semester[stSemester].Thir_Year_Student.lengthOfFaculty; j++) {
				if (strcmp(Sch.Data.faculty[0].Class[i].classOfFaculty, Sch.semester[stSemester].Thir_Year_Student.faculty[j].NameFaculty) == 0) {
					AllocationClass(Sch.semester[stSemester].Thir_Year_Student.faculty[j].Class, Sch.semester[stSemester].Thir_Year_Student.faculty[j].lengthOfClass, Sch.Data.faculty[0].Class[i]);
				}
			}
		}
		else if (getK(Sch.Data.faculty[0].Class[i].NameClass) == year - 3) {
			for (int j = 0; j < Sch.semester[Sch.lengthOfSemester - 1].Fourth_Year_Student.lengthOfFaculty; j++) {
				if (strcmp(Sch.Data.faculty[0].Class[i].classOfFaculty, Sch.semester[Sch.lengthOfSemester - 1].Fourth_Year_Student.faculty[j].NameFaculty) == 0) {
					AllocationClass(Sch.semester[Sch.lengthOfSemester - 1].Fourth_Year_Student.faculty[j].Class, Sch.semester[Sch.lengthOfSemester - 1].Fourth_Year_Student.faculty[j].lengthOfClass, Sch.Data.faculty[0].Class[i]);
				}
			}
		}
	}
}
// Hàm tách môn học từ danh sách toàn bộ môn học của từng khóa vào lớp
void splitOfCourse(School& Sch, int HK, bool flag1, bool flag2, int stSemester) {
	for (int i = 0; i < Sch.Data.faculty[HK].lengthOfCourse; i++) {// duyệt toàn bộ môn học trong temporary data
		// duyệt từng khối 
		if (flag1) {
			for (int j = 0; j < Sch.semester[stSemester].Freshman.lengthOfFaculty; j++) {// duyệt từng khoa
				for (int k = 0; k < Sch.semester[stSemester].Freshman.faculty[j].lengthOfClass; k++) {// duyệt từng lớp của khoa 
					if (strcmp(Sch.Data.faculty[HK].course[i].ClassName, Sch.semester[stSemester].Freshman.faculty[j].Class[k].NameClass) == 0) {
						AllocationCourse(Sch.semester[stSemester].Freshman.faculty[j].course, Sch.semester[stSemester].Freshman.faculty[j].lengthOfCourse, Sch.Data.faculty[HK].course[i]);
					}
				}
			}
		}
		if (flag2) {
			for (int j = 0; j < Sch.semester[stSemester].Sophomore.lengthOfFaculty; j++) {
				for (int k = 0; k < Sch.semester[stSemester].Sophomore.faculty[j].lengthOfClass; k++) {
					if (strcmp(Sch.Data.faculty[HK].course[i].ClassName, Sch.semester[stSemester].Sophomore.faculty[j].Class[k].NameClass) == 0) {
						AllocationCourse(Sch.semester[stSemester].Sophomore.faculty[j].course, Sch.semester[stSemester].Sophomore.faculty[j].lengthOfCourse, Sch.Data.faculty[HK].course[i]);
					}
				}
			}
			for (int j = 0; j < Sch.semester[stSemester].Thir_Year_Student.lengthOfFaculty; j++) {
				for (int k = 0; k < Sch.semester[stSemester].Thir_Year_Student.faculty[j].lengthOfClass; k++) {
					if (strcmp(Sch.Data.faculty[HK].course[i].ClassName, Sch.semester[stSemester].Thir_Year_Student.faculty[j].Class[k].NameClass) == 0) {
						AllocationCourse(Sch.semester[stSemester].Thir_Year_Student.faculty[j].course, Sch.semester[stSemester].Thir_Year_Student.faculty[j].lengthOfCourse, Sch.Data.faculty[HK].course[i]);
					}
				}

			}
			for (int j = 0; j < Sch.semester[stSemester].Fourth_Year_Student.lengthOfFaculty; j++) {
				for (int k = 0; k < Sch.semester[stSemester].Fourth_Year_Student.faculty[j].lengthOfClass; k++) {
					if (strcmp(Sch.Data.faculty[HK].course[i].ClassName, Sch.semester[stSemester].Fourth_Year_Student.faculty[j].Class[k].NameClass) == 0) {
						AllocationCourse(Sch.semester[stSemester].Fourth_Year_Student.faculty[j].course, Sch.semester[stSemester].Fourth_Year_Student.faculty[j].lengthOfCourse, Sch.Data.faculty[HK].course[i]);
					}
				}
			}
		}
	}
}
// Hàm tách sinh viên vào các lớp
void splitStudentToClass(DArray source, Faculty& destination) {
	for (int i = 0; i < source.lengthStudent; i++) {
		if (getF(source.Member[i].StudentID) == destination.symbolFaculty) {
			destination.lengthStudent++;// lấy số lượng sinh viên của khoa đó
		}
	}
	for (int i = 0; i < destination.lengthOfClass; i++) {
		int count = 0;
		for (int j = i * (destination.lengthStudent / destination.lengthOfClass); j < source.lengthStudent; j++) {
			if (getF(source.Member[j].StudentID) == destination.symbolFaculty) {
				if (i == destination.lengthOfClass - 1 && count >= (destination.lengthStudent - (destination.lengthOfClass - 1) * (destination.lengthStudent / destination.lengthOfClass))) {
					break;
				}
				else if (i != destination.lengthOfClass - 1 && count >= destination.lengthStudent / destination.lengthOfClass) {
					break;
				}
				count++;
				AllocationStudent(destination.Class[i].Member, destination.Class[i].Acc, destination.Class[i].lengthStudent, source.Member[j], source.Acc[j]);
			}
		}
	}
}
// Hàm tách sinh viên
void splitStudent(YearSchool& ySch) {
	for (int i = 0; i < ySch.lengthOfFaculty; i++) {
		splitStudentToClass(ySch.student, ySch.faculty[i]); // IT-HH-VL-SH
	}
}
// Hàm tachmôn học vào từng lớp
void splitCourseToClass(YearSchool& ySch) {
	for (int i = 0; i < ySch.lengthOfFaculty; i++) {
		for (int j = 0; j < ySch.faculty[i].lengthOfCourse; j++) {
			for (int k = 0; k < ySch.faculty[i].lengthOfClass; k++) {
				if (strcmp(ySch.faculty[i].Class[k].NameClass, ySch.faculty[i].course[j].ClassName) == 0) {
					AllocationCourse(ySch.faculty[i].Class[k].course, ySch.faculty[i].Class[k].lengthOfCourseOfClass, ySch.faculty[i].course[j]);
					for (int g = 0; g < ySch.faculty[i].Class[k].lengthStudent; g++) {
						AllocationStudent(ySch.faculty[i].Class[k].course[ySch.faculty[i].Class[k].lengthOfCourseOfClass - 1].Member,
							ySch.faculty[i].Class[k].course[ySch.faculty[i].Class[k].lengthOfCourseOfClass - 1].Acc,
							ySch.faculty[i].Class[k].course[ySch.faculty[i].Class[k].lengthOfCourseOfClass - 1].NumberOfStudent,
							ySch.faculty[i].Class[k].Member[g], ySch.faculty[i].Class[k].Acc[g]);
					}
					RandomScoreBoard(ySch.faculty[i].Class[k].course[ySch.faculty[i].Class[k].lengthOfCourseOfClass - 1], false);
				}
			}
		}
	}
}
// Cấp phát điểm auto
void initScore(YearSchool& ySch) {
	for (int i = 0; i < ySch.lengthOfFaculty; i++) {
		for (int k = 0; k < ySch.faculty[i].lengthOfClass; k++) {
			for (int j = 0; j < ySch.faculty[i].Class[k].lengthOfCourseOfClass; j++) {
				RandomScoreBoard(ySch.faculty[i].Class[k].course[j], true);
			}
		}
	}
}
// Thu hồi bộ  nhớ môn  học
void RecoveryCourse(YearSchool& ySch) {
	for (int i = 0; i < ySch.lengthOfFaculty; i++) {
		for (int j = 0; j < ySch.faculty[i].lengthOfClass; j++) {
			if (ySch.faculty[i].Class[j].lengthOfCourseOfClass != 0) {
				delete[]ySch.faculty[i].Class[j].course;
				ySch.faculty[i].Class[j].lengthOfCourseOfClass = 0;
				ySch.faculty[i].Class[j].course = NULL;
			}
		}
		if (ySch.faculty[i].lengthOfCourse != 0) {
			delete[]ySch.faculty[i].course;
			ySch.faculty[i].lengthOfCourse = 0;
			ySch.faculty[i].course = NULL;
		}
	}
}
// Thu hồi điểm môn học
void RecoveryMark(YearSchool& ySch) {
	for (int i = 0; i < ySch.lengthOfFaculty; i++) {
		for (int j = 0; j < ySch.faculty[i].lengthOfClass; j++) {
			for (int k = 0; k < ySch.faculty[i].Class[j].lengthOfCourseOfClass; k++) {
				for (int g = 0; g < ySch.faculty[i].Class[j].course[k].NumberOfStudent; g++) {
					ySch.faculty[i].Class[j].course[k].Score[g].OtherMark = -1;
					ySch.faculty[i].Class[j].course[k].Score[g].MidTermMark = -1;
					ySch.faculty[i].Class[j].course[k].Score[g].FinalMark = -1;
					ySch.faculty[i].Class[j].course[k].Score[g].TotalMark = -1;
				}
			}
		}
	}
}
// chuyển đổi  môn học  theo từng năm
void convertCourse(Course* course, int lengthOfCourse) {
	for (int i = 0; i < lengthOfCourse; i++) {
		char* sDigit = new  char[2];
		sDigit[0] = course[i].ClassName[0];
		sDigit[1] = course[i].ClassName[1];
		int digit = atoi(sDigit);
		++digit;
		_itoa(digit, sDigit, 10);
		course[i].ClassName[0] = sDigit[0];
		course[i].ClassName[1] = sDigit[1];
	}
}
// chuyển đổi  lop học  theo từng năm
void convertClass(DArray* DA, int lengthOfClass) {
	for (int i = 0; i < lengthOfClass; i++) {
		char* sDigit = new  char[2];
		sDigit[0] = DA[i].NameClass[0];
		sDigit[1] = DA[i].NameClass[1];
		int digit = atoi(sDigit);
		++digit;
		_itoa(digit, sDigit, 10);
		DA[i].NameClass[0] = sDigit[0];
		DA[i].NameClass[1] = sDigit[1];
	}
}
// Hàm hiển thị bảng điểm của một sinh viên
void ViewScoreBoardOfStudent(Faculty faculty, char* MSSV) {
	system("cls");
	BoxTranscriptOfStudent(2, 1, 4 * 15 + 55, 0, 1, 7, faculty, MSSV);
	_getch();
}
// Hàm hiển thị bảng điểm của một lớp
void ViewScoreBoardClass(DArray& DA) {
	system("cls");
	BoxTranscriptOfClass(2, 1, DA.lengthOfCourseOfClass * 10 + 51, DA.lengthStudent + 3, 1, 7, DA);
	_getch();
}
// Hàm hiển thị bảng điểm của một khóa học
void ViewScoreBoardOfCourse(Course course) {
	system("cls");
	BoxTranscriptOfCourse(2, 1, 4 * 15 + 44, course.NumberOfStudent + 3, 1, 7, course);
	_getch();
}
// Hàm hiển thị danh sách sinh viên trong lớp
void ViewListStudent(DArray& DA) {
	BoxStudentOfClass(2, 1, 100, DA.lengthStudent + 3, 1, 7, DA);
	_getch();
}
// Hàm hiển thị danh sách sinh viên trong khóa học
int ViewListStudent(Course course) {
	int option;
	int x = 2, y = 1;
	system("cls");
	gotoXY(x, y);
	cout << "No"; x += 10;
	gotoXY(x, y);
	cout << "ID"; x += 15;
	gotoXY(x, y);
	cout << "Name"; x += 30;
	gotoXY(x, y);
	cout << "Birth"; x += 20;
	gotoXY(x, y);
	cout << "Sex"; x += 10;
	gotoXY(x, y);
	cout << "SocialID";
	for (int i = 0; i < course.NumberOfStudent; i++) {
		x -= 85;
		y++;
		gotoXY(x, y);
		cout << course.Member[i].No; x += 10;
		gotoXY(x, y);
		cout << course.Member[i].StudentID; x += 15;
		gotoXY(x, y);
		cout << course.Member[i].FirstName << " " << course.Member[i].LastName; x += 30;
		gotoXY(x, y);
		cout << course.Member[i].DateOfBirth.day << "/" << course.Member[i].DateOfBirth.month << "/" << course.Member[i].DateOfBirth.year; x += 20;
		gotoXY(x, y);
		cout << course.Member[i].Gender; x += 10;
		gotoXY(x, y);
		cout << course.Member[i].CCCD;
	}
	cout << endl;
	cout << " Enter selection: "; cin >> option;
	return option;
}
// Menu của một môn học
bool MenuOfOneCourse(Course*& course, int position, DArray& DA, Faculty faculty) {
	int option;
	int n;
	bool flag = false;
	ifstream filein;
	char* pathOfSource;
	int x = 35, y = 8;
	do {
		BoxUsage(1, 0, 19, 5);
		MenuGraphic(35, 8, 50, 2, 1, 7, option, n_Box19, Light19);
		if (option == 0)break;
		switch (option) {
		case 1:
			system("cls");
			informationOfOneCourse(course[position]);
			break;
		case 2:
			system("cls");
			n = ViewListStudent(course[position]);
			if (n != 0) {
				MenuProfile(course[position].Member[n - 1]);
			}
			break;
		case 3:
			system("cls");
			ViewScoreBoardOfCourse(course[position]);
			break;
		case 4:
			system("cls");
			x = 40;
			y = 10;
			if (course[position].NumberOfStudent == course[position].MaximumStudent) {
				gotoXY(x, y);
				cout << "The classroom is full of students!";
				_getch();
				return false;
			}
			else {
				CreateNewStudent(course[position].Member, course[position].Acc, course[position].Score, course[position].NumberOfStudent, DA, faculty);
			}
			x = 35; y = 8;
			break;
		case 5:
			system("cls");
			updateInformationOfCourse(course[position]);
			break;
		case 6:
			system("cls");
			removedOneStudentOfCourse(course[position], ViewListStudent(course[position]) - 1);
			break;
		case 7:
			BoxUsage(1, 0, 19, 5); gotoXY(20, 12);
			cout << "Enter file name of score: "; gets_s(s);
			cpychar(pathOfSource, s);
			if (ReadScoreBoardOfCourse(filein, course[position], pathOfSource)) {
				BoxNotification(42, 10, 30, 2, 1, 7, "File import successful!", true);
			}
			else {
				BoxNotification(42, 10, 30, 2, 1, 7, "File import failed!", true);
			}
			break;

		case 8:
			system("cls");
			gotoXY(x, y++);
			return true;
			break;
		default:
			break;
		}
	} while (true);
}
// Hàm hiển thị danh sách môn của lop
void ViewListCourseOfClass(DArray& DA, Faculty faculty) {
	int option;
	bool flag;
	do {
		BoxUsage(1, 0, 19, 5);
		MenuGraphic2(35, 8, 50, 2, 1, 7, option, DA, n_Box17, Light17);
		if (option == 0)break;
		else flag = MenuOfOneCourse(DA.course, option - 1, DA, faculty);
		if (flag == true)removedOneCourse(DA, option - 1);
	} while (true);
}
// Menu của một lớp 
void MenuOfOneClass(DArray*& DA, int position, Faculty faculty) {
	int option;
	int x = 35, y = 9;
	do {
		BoxUsage(1, 0, 19, 5);
		gotoXY(40, 7);
		cout << DA[position].NameClass << " - " << DA[position].classOfFaculty; gotoXY(x, y++);
		MenuGraphic(40, 8, 40, 2, 1, 7, option, n_Box18, Light18);
		if (option == 0)break;
		switch (option) {
		case 1:
			system("cls");
			informationOfOneClass(DA[position]);
			break;
		case 2:
			system("cls");
			ViewListStudent(DA[position]);
			break;
		case 3:
			system("cls");
			ViewListCourseOfClass(DA[position], faculty);
			break;
		case 4:
			system("cls");
			ViewScoreBoardClass(DA[position]);
			break;
		default:
			break;
		}
	} while (true);
}
// Menu danh sách các khoa
void MenuCreateFaculty(YearSchool& ySch, void(*CreateNew)(Faculty&)) {
	int option;
	do {
		BoxUsage(1, 0, 19, 5);	gotoXY(45, 7);
		/*if (ySch.lengthOfSemester >= 1 && ySch.semester[ySch.lengthOfSemester - 1].NameSemester != NULL) {
			cout << ySch.semester[ySch.lengthOfSemester - 1].NameSemester;
		}*/
		MenuGraphic5(45, 8, 30, 2, 1, 7, option, ySch, n_Box30, Light30);
		if (option == 0)break;
		CreateNew(ySch.faculty[option - 1]);
	} while (true);
}
// Hàm hiển thị danh sách môn của khoa
void ViewListCourseOfFaculty(YearSchool& ySch, int position) {
	int option;
	bool flag;
	int x = 40, y = 7;
	do {
		system("cls");	gotoXY(x, y++);
		cout << "============ COURSE ============" << endl;	gotoXY(x, y++);
		for (int i = 0; i < ySch.faculty[position].lengthOfCourse; i++) {
			cout << " " << i + 1 << ". " << ySch.faculty[position].course[i].CourseName; gotoXY(x, y++);
		}
		//cout << " " << ySch.faculty[position].lengthOfCourse + 1 << ". Thoat."; gotoXY(x, y++);
		cout << "===============================" << endl;	gotoXY(x, y++);
		system("pause"); return;
		//cout << "Enter selection: "; cin >> option;
		/*y -= (4 + ySch.faculty[position].lengthOfCourse);
		cin.ignore();
		if (option > ySch.faculty[position].lengthOfCourse)break;*/
		//else flag=MenuOfOneCourse(ySch.faculty[position].course, option - 1);
		//if (flag == true)removedOneCourse(ySch.faculty[position].course, option - 1);
	} while (true);
}
// Hàm hiện thị danh sách lớp của khoa
void ViewListClassOfFaculty(YearSchool& ySch, int position) {
	int option;
	int x = 40, y = 7;
	do {
		BoxUsage(1, 0, 19, 5);
		MenuGraphic1(45, 8, 30, 2, 1, 7, option, position, ySch, n_Box16, Light16);
		if (option == 0)break;
		else MenuOfOneClass(ySch.faculty[position].Class, option - 1, ySch.faculty[position]);
	} while (true);
}
void ViewListClassOfFaculty2(YearSchool& ySch, int position) {
	int option;
	int x = 40, y = 7;
	do {
		BoxUsage(1, 0, 19, 5);
		MenuGraphic1(45, 8, 30, 2, 1, 7, option, position, ySch, n_Box16, Light16);
		if (option == 0)break;
		else CreateNewStudent(ySch.faculty[position].Class[option - 1], ySch.faculty[position], ySch);
	} while (true);
}
// Hàm hiện thị danh sách khóa học của một sinh viên
void ViewListCourseOfStudent(School Sch, int position, int year) {
	int option;
	int x = 40, y = 7;
	int* ArrayClassOfStudent = new int[50];
	int i_ArrayClassOfStudent = 0;
	int* ArrayCourseOfStudent = new int[50];
	int i_ArrayCourseOfStudent = 0;
	Faculty Temporary = getFaculty(Sch, position, year);
	do {
		BoxUsage(1, 0, 19, 5);
		MenuGraphic3(45, 8, 30, 2, 1, 7, option, Sch, Temporary, ArrayClassOfStudent, ArrayCourseOfStudent, i_ArrayClassOfStudent, i_ArrayCourseOfStudent, position, n_Box25, Light25);
		if (option == 0)break;
		else informationOfOneCourse(Temporary.Class[ArrayClassOfStudent[option - 1]].course[ArrayCourseOfStudent[option - 1]]);
	} while (true);
}
// Menu danh sách khoa
void MenuFaculty(YearSchool& ySch, void(*ViewOfFaculty)(YearSchool&, int)) {
	int option;
	do {
		BoxUsage(1, 0, 19, 5);
		MenuGraphic1(45, 8, 30, 2, 1, 7, option, 0, ySch, n_Box15, Light15);
		if (option == 0)break;
		else ViewOfFaculty(ySch, option - 1);
	} while (true);
}
// Menu danh sách các lớp
void MenuClass(YearSchool ySch) {
	int x = 2, y = 1;
	system("cls");
	gotoXY(x, y);
	cout << "No"; x += 10;
	gotoXY(x, y);
	cout << "Name"; x += 20;
	gotoXY(x, y);
	cout << "Faculty"; x += 30;
	gotoXY(x, y);
	cout << "Members"; x += 10;
	int pos = 0;
	for (int i = 0; i < ySch.lengthOfFaculty; i++) {
		for (int j = 0; j < ySch.faculty[i].lengthOfClass; j++) {
			x -= 70;
			y++;
			gotoXY(x, y);
			cout << ++pos; x += 10;
			gotoXY(x, y);
			cout << ySch.faculty[i].Class[j].NameClass; x += 20;
			gotoXY(x, y);
			cout << ySch.faculty[i].Class[j].classOfFaculty; x += 30;
			gotoXY(x, y);
			cout << ySch.faculty[i].Class[j].lengthMaxOfClass; x += 10;
		}
	}
	system("pause");
}
// Menu danh sách các môn học
void MenuCourse(YearSchool ySch) {
	int x = 2, y = 1;
	system("cls");
	gotoXY(x, y);
	cout << "No"; x += 5;
	gotoXY(x, y);
	cout << "ID"; x += 10;
	gotoXY(x, y);
	cout << "Course"; x += 20;
	gotoXY(x, y);
	cout << "Teacher"; x += 20;
	gotoXY(x, y);
	cout << "Class"; x += 10;
	gotoXY(x, y);
	cout << "Credits"; x += 11;
	gotoXY(x, y);
	cout << "Day"; x += 6;
	gotoXY(x, y);
	cout << "Session"; x += 10;
	gotoXY(x, y);
	cout << "Number"; x += 9;
	gotoXY(x, y);
	cout << "MaxNumber"; x += 10;
	int pos = 0;
	for (int i = 0; i < ySch.lengthOfFaculty; i++) {
		for (int j = 0; j < ySch.faculty[i].lengthOfCourse; j++) {
			x -= 111;
			y++;
			gotoXY(x, y);
			cout << ++pos; x += 5;
			gotoXY(x, y);
			cout << ySch.faculty[i].course[j].CourseID; x += 10;
			gotoXY(x, y);
			cout << ySch.faculty[i].course[j].CourseName; x += 20;
			gotoXY(x, y);
			cout << ySch.faculty[i].course[j].NameTeacher; x += 20;
			gotoXY(x, y);
			cout << ySch.faculty[i].course[j].ClassName; x += 10;
			gotoXY(x, y);
			cout << ySch.faculty[i].course[j].NumberCredits; x += 11;
			gotoXY(x, y);
			cout << ySch.faculty[i].course[j].DayOfTheWeek; x += 6;
			gotoXY(x, y);
			cout << ySch.faculty[i].course[j].Session; x += 10;
			gotoXY(x, y);
			cout << ySch.faculty[i].course[j].NumberOfStudent; x += 9;
			gotoXY(x, y);
			cout << ySch.faculty[i].course[j].MaximumStudent; x += 10;
		}
	}
	cout << endl; system("pause");
}
// Menu sinh viên năm nhất
void MenuFreshman(School& Sch) {
	int option;
	do {
		BoxUsage(1, 0, 19, 5); gotoXY(45, 8);
		MenuGraphic(45, 9, 30, 2, 1, 7, option, n_Box9, Light9);
		if (option == 0)break;
		switch (option) {
		case 1:
			system("cls");
			MenuFaculty(Sch.semester[Sch.lengthOfSemester - 1].Freshman, ViewListClassOfFaculty);
			break;
		case 2:
			system("cls");
			MenuFaculty(Sch.semester[Sch.lengthOfSemester - 1].Freshman, ViewListCourseOfFaculty);
			break;
		case 3:
			system("cls");
			ViewListStudent(Sch.semester[Sch.lengthOfSemester - 1].Freshman.student);
			break;
		case 4:
			break;
		default:
			break;
		}
	} while (true);
}
// Menu sinh viên năm hai
void MenuSophomore(School& Sch) {
	int option;
	int x = 40, y = 9;
	do {
		BoxUsage(1, 0, 19, 5); gotoXY(45, 8);
		MenuGraphic(45, 9, 30, 2, 1, 7, option, n_Box10, Light10);
		if (option == 0)break;
		switch (option) {
		case 1:
			system("cls");
			MenuFaculty(Sch.semester[Sch.lengthOfSemester - 1].Sophomore, ViewListClassOfFaculty);
			break;
		case 2:
			system("cls");
			MenuCourse(Sch.semester[Sch.lengthOfSemester - 1].Sophomore);
			break;
		case 3:
			system("cls");
			ViewListStudent(Sch.semester[Sch.lengthOfSemester - 1].Sophomore.student);
			break;
		case 4:
			break;
		default:
			break;
		}
	} while (true);
}
// Menu sinh viên năm ba
void MenuThirdYear(School& Sch) {
	int option;
	int x = 40, y = 9;
	do {
		BoxUsage(1, 0, 19, 5); gotoXY(45, 8);
		MenuGraphic(43, 9, 32, 2, 1, 7, option, n_Box11, Light11);
		if (option == 0)break;
		switch (option) {
		case 1:
			system("cls");
			MenuFaculty(Sch.semester[Sch.lengthOfSemester - 1].Thir_Year_Student, ViewListClassOfFaculty);
			break;
		case 2:
			system("cls");
			MenuCourse(Sch.semester[Sch.lengthOfSemester - 1].Thir_Year_Student);
			break;
		case 3:
			system("cls");
			ViewListStudent(Sch.semester[Sch.lengthOfSemester - 1].Thir_Year_Student.student);
			break;
		case 4:
			break;
		default:
			break;
		}
	} while (true);
}
// Menu sinh viên năm tư
void MenuFourthYear(School& Sch) {
	int option;
	int x = 40, y = 9;
	do {
		BoxUsage(1, 0, 19, 5); gotoXY(45, 8);
		MenuGraphic(43, 9, 33, 2, 1, 7, option, n_Box12, Light12);
		if (option == 0)break;
		switch (option) {
		case 1:
			system("cls");
			MenuFaculty(Sch.semester[Sch.lengthOfSemester - 1].Fourth_Year_Student, ViewListClassOfFaculty);
			break;
		case 2:
			system("cls");
			MenuCourse(Sch.semester[Sch.lengthOfSemester - 1].Fourth_Year_Student);
			break;
		case 3:
			system("cls");
			ViewListStudent(Sch.semester[Sch.lengthOfSemester - 1].Fourth_Year_Student.student);
			break;
		case 4:
			break;
		default:
			break;
		}
	} while (true);
}
// Hàm khởi lại năm học
void initializeYearSchool(YearSchool& init) {
	for (int i = 0; i < init.lengthOfFaculty; i++) {
		for (int j = 0; j < init.faculty[i].lengthOfClass; j++) {
			for (int k = 0; k < init.faculty[i].Class[j].lengthOfCourseOfClass; k++) {
				if (init.faculty[i].Class[j].course[k].NumberOfStudent) {
					delete[]init.faculty[i].Class[j].course[k].Score;
					delete[]init.faculty[i].Class[j].course[k].Acc;
					delete[]init.faculty[i].Class[j].course[k].Member;
				}
				init.faculty[i].Class[j].course[k].NumberOfStudent = 0;
				init.faculty[i].Class[j].course[k].Score = new ScoreBoard[init.faculty[i].Class[j].course[k].NumberOfStudent];
				init.faculty[i].Class[j].course[k].Acc = new Account[init.faculty[i].Class[j].course[k].NumberOfStudent];
				init.faculty[i].Class[j].course[k].Member = new Information[init.faculty[i].Class[j].course[k].NumberOfStudent];
			}
			if (init.faculty[i].Class[j].lengthStudent) {
				delete[]init.faculty[i].Class[j].Acc;
				delete[]init.faculty[i].Class[j].Member;
			}
			if (init.faculty[i].Class[j].lengthOfCourseOfClass) {
				delete[]init.faculty[i].Class[j].course;
			}
			init.faculty[i].Class[j].lengthStudent = 0;
			init.faculty[i].Class[j].lengthOfCourseOfClass = 0;
			init.faculty[i].Class[j].Acc = new Account[init.faculty[i].Class[j].lengthStudent];
			init.faculty[i].Class[j].course = new Course[init.faculty[i].Class[j].lengthOfCourseOfClass];
			init.faculty[i].Class[j].Member = new Information[init.faculty[i].Class[j].lengthStudent];
		}
		init.faculty[i].lengthOfClass = 0;
		delete[]init.faculty[i].Class;
		init.faculty[i].Class = new DArray[init.faculty[i].lengthOfClass];
		if (init.faculty[i].lengthOfCourse) {
			delete[]init.faculty[i].course;
		}
		init.faculty[i].lengthOfCourse = 0;
		init.faculty[i].course = new Course[init.faculty[i].lengthOfCourse];
	}
	/*init.lengthOfSemester = 0;
	delete[]init.semester;
	init.semester = new Semester[init.lengthOfSemester];*/
}
// Hàm khỏi tạo năm học
void init(YearSchool& init) {
	init.lengthOfFaculty = 0;
	//init.lengthOfSemester = 0;
	//init.semester = new Semester[init.lengthOfSemester];
	init.faculty = new Faculty[init.lengthOfFaculty];
}
void initClass(DArray& DA) {
	DA.lengthStudent = 0;
	delete[]DA.Member;
	delete[]DA.Acc;
	DA.Member = new Information[DA.lengthStudent];
	DA.Acc = new Account[DA.lengthStudent];
}
// Menu tạo một năm học mới
void MenuNew1(School* Sch, int& i_Sch) {
	int option;
	ifstream filein;
	int x = 38, y = 10;
	// note : khi năm học chưa đủ 3 học kì thì không được tạo năm học mới
	BoxUsage(1, 0, 19, 5);
	n_Box31(41, 8, 42, 2, 1, 7, option, Sch[i_Sch]);
	if (BoxNotification(34, 15, 55, 4, 1, 7, "Are you sure you want to create year new school ?", false) == 0)return;
	else {
		WriteStudent(Sch[i_Sch]);
		i_Sch++; //  chuyển qua năm học tiếp theo
		AllocationSchoolYear(Sch[i_Sch].SchoolYear, Sch[i_Sch].lengthOfSchoolYear, Sch[i_Sch - 1].SchoolYear[1]);
		AllocationSchoolYear(Sch[i_Sch].SchoolYear, Sch[i_Sch].lengthOfSchoolYear, Sch[i_Sch - 1].SchoolYear[1] + 1);
		Sch[i_Sch].Data = Sch[i_Sch - 1].Data;
		BoxLoading(35, 10, 51, 2, 1, 7);
		BoxNotification(42, 10, 40, 4, 1, 7, "Create a successful new school year!", true);
		FLAG1 = false;
	}
}
// Menu Update Semester
void MenuNew2_1(School* Sch, int& i_Sch, YearSchool& ySch, int stSemester) {
	int option;
	ifstream filein;
	char* pathOfSource;
	if (FLAG2 == false && Sch[i_Sch].lengthOfSemester - 1 == stSemester) {
		BoxNotification(42, 10, 40, 4, 1, 7, "Please enter data for new semester!", true);
		return;
	}
	do {
		BoxUsage(1, 0, 19, 5); gotoXY(45, 7);
		MenuGraphic(45, 10, 30, 2, 1, 7, option, n_Box29, Light29);
		if (option == 0)break;
		switch (option) {
		case 1:
			system("cls");
			gotoXY(45, 7);
			cout << "Temporarily closed feature!" << endl;
			system("pause");
			break;
		case 2:
			system("cls");
			MenuCreateFaculty(ySch, CreateNewClass);
			break;
		case 3:
			system("cls");
			MenuCreateFaculty(ySch, CreateNewCourse);
		case 4:
			MenuFaculty(ySch, ViewListClassOfFaculty2);
			break;
		}
	} while (true);
}
// Meunu danh sách sinh viên năm
void MenuStudent1(School& Sch) {
	int option;
	int x = 40, y = 9;
	do {
		BoxUsage(1, 0, 19, 5);
		//WriteStudent(Sch);
		if (Sch.lengthOfSemester == 0 || FLAG1 == false || FLAG2 == false) {
			//cin.ignore();
			BoxNotification(38, 10, 45, 4, 1, 7, "Please create and import the semester!", true);
			return;
		}
		//cout << Sch.DAStaff.Member[k].StudentID << " - " << Sch.DAStaff.Member[k].FirstName << " " << Sch.DAStaff.Member[k].LastName << endl;	gotoXY(x, y++);
		MenuGraphic(45, 8, 30, 2, 1, 7, option, n_Box8, Light8);
		if (option == 0)break;
		switch (option) {
		case 1:
			system("cls");
			MenuFreshman(Sch);
			break;
		case 2:
			system("cls");
			MenuSophomore(Sch);
			break;
		case 3:
			system("cls");
			MenuThirdYear(Sch);
			break;
		case 4:
			system("cls");
			MenuFourthYear(Sch);
			break;
		default:
			break;
		}
	} while (true);
}
// Meunu danh sách sinh viên năm
void MenuStudent2(School* Sch, int& i_Sch, int& k) {
	int option;
	do {
		BoxUsage(1, 0, 19, 5);
		if (FLAG1 == false) {
			BoxNotification(42, 10, 40, 4, 1, 7, "Please enter data for freshman!", true);
			return;
		}
		else if (FLAG2 == false && Sch[i_Sch].lengthOfSemester - 1 == k) {
			MenuGraphic(45, 8, 30, 2, 1, 7, option, n_Box8_1, Light8_1);
			if (option == 0)break;
			switch (option) {
			case 1:
				MenuNew2_1(Sch, i_Sch, Sch[i_Sch].semester[k].Freshman, k);
				break;
			case 2:
				MenuNew2_1(Sch, i_Sch, Sch[i_Sch].semester[k].Sophomore, k);
				break;
			case 3:
				MenuNew2_1(Sch, i_Sch, Sch[i_Sch].semester[k].Thir_Year_Student, k);
				break;
			case 4:
				MenuNew2_1(Sch, i_Sch, Sch[i_Sch].semester[k].Fourth_Year_Student, k);
				break;
			case 5:
				BoxUsage(1, 0, 19, 5);
				init(Sch[i_Sch].semester[Sch[i_Sch].lengthOfSemester - 1].Freshman);
				init(Sch[i_Sch].semester[Sch[i_Sch].lengthOfSemester - 1].Sophomore);
				init(Sch[i_Sch].semester[Sch[i_Sch].lengthOfSemester - 1].Thir_Year_Student);
				init(Sch[i_Sch].semester[Sch[i_Sch].lengthOfSemester - 1].Fourth_Year_Student);
				// Đọc danh sách sinh viên của từng khóa
				ReadStudentOfYearSchool(Sch[i_Sch]);
				if (TIME.month >= 9) {
					splitOfClass(Sch[i_Sch], TIME.year - 2000, true, k);
				}
				else {
					splitOfClass(Sch[i_Sch], TIME.year - 2000 - 1, true, k);
				}// LOOIX  TOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
				if (k == 0) {
					splitOfCourse(Sch[i_Sch], 0, true, true, k);
				}
				else if (k == 1) {
					splitOfCourse(Sch[i_Sch], 5, true, true, k);

				}
				splitStudent(Sch[i_Sch].semester[Sch[i_Sch].lengthOfSemester - 1].Freshman);
				splitStudent(Sch[i_Sch].semester[Sch[i_Sch].lengthOfSemester - 1].Sophomore);
				splitStudent(Sch[i_Sch].semester[Sch[i_Sch].lengthOfSemester - 1].Thir_Year_Student);
				splitStudent(Sch[i_Sch].semester[Sch[i_Sch].lengthOfSemester - 1].Fourth_Year_Student);
				WriteStudent(Sch[i_Sch]);
				splitCourseToClass(Sch[i_Sch].semester[Sch[i_Sch].lengthOfSemester - 1].Freshman);
				splitCourseToClass(Sch[i_Sch].semester[Sch[i_Sch].lengthOfSemester - 1].Sophomore);
				splitCourseToClass(Sch[i_Sch].semester[Sch[i_Sch].lengthOfSemester - 1].Thir_Year_Student);
				splitCourseToClass(Sch[i_Sch].semester[Sch[i_Sch].lengthOfSemester - 1].Fourth_Year_Student);
				BoxLoading(35, 10, 51, 2, 1, 7);
				BoxNotification(20, 8, 80, 4, 1, 7, "Successfully imported CSV into the system!", true);
				FLAG2 = true;
				break;
			default:
				break;
			}
		}
		else {
			MenuGraphic(45, 8, 30, 2, 1, 7, option, n_Box8, Light8);
			if (option == 0)break;
			switch (option) {
			case 1:
				MenuNew2_1(Sch, i_Sch, Sch[i_Sch].semester[k].Freshman, k);
				break;
			case 2:
				MenuNew2_1(Sch, i_Sch, Sch[i_Sch].semester[k].Sophomore, k);
				break;
			case 3:
				MenuNew2_1(Sch, i_Sch, Sch[i_Sch].semester[k].Thir_Year_Student, k);
				break;
			case 4:
				MenuNew2_1(Sch, i_Sch, Sch[i_Sch].semester[k].Fourth_Year_Student, k);
				break;
			default:
				break;
			}
		}
	} while (true);
}
// Menu học kì
void MenuNew2(School* Sch, int& i_Sch) {
	int option;
	ifstream filein;
	char* pathOfSource;
	int x = 40, y = 9;
	if (Sch[i_Sch].SchoolYear == NULL) {
		system("cls"); gotoXY(x, y++);
		cout << "The new school year hasn't initialized!." << endl;
	}
	else {
		do {
			BoxUsage(1, 0, 19, 5);
			MenuGraphic4(45, 10, 30, 2, 1, 7, option, Sch[i_Sch], n_Box28, Light28);
			if (option == 0)break;
			if (option == 1) {
				CreateNewSemester(Sch, i_Sch);
			}
			else if (FLAG1 == false) {
				if (option == 2) {
					BoxUsage(1, 0, 19, 5); gotoXY(25, 12);
					cout << "Enter file new student: "; gets_s(s);
					cpychar(pathOfSource, s);
					filein.open(pathOfSource, ios::in);
					if (filein.fail()) {
						BoxNotification(20, 8, 40, 4, 1, 7, "File opening failed!", true);
					}
					else {
						BoxLoading(35, 10, 51, 2, 1, 7);
						ReadListFromFile(filein, Sch[i_Sch].semester[Sch[i_Sch].lengthOfSemester - 1].Freshman.student);
						filein.close();
						filein.open("File_ThirdYear.csv", ios::out);
						ReadListFromFile(filein, Sch[i_Sch].semester[Sch[i_Sch].lengthOfSemester - 1].Fourth_Year_Student.student);
						filein.close();
						filein.open("File_Sophomore.csv", ios::out);
						ReadListFromFile(filein, Sch[i_Sch].semester[Sch[i_Sch].lengthOfSemester - 1].Thir_Year_Student.student);
						filein.close();
						filein.open("File_Freshman.csv", ios::out);
						ReadListFromFile(filein, Sch[i_Sch].semester[Sch[i_Sch].lengthOfSemester - 1].Sophomore.student);
						filein.close();

						WriteStudent(Sch[i_Sch]);
						convertCourse(Sch[i_Sch].Data.faculty[0].course, Sch[i_Sch].Data.faculty[0].lengthOfCourse);
						convertClass(Sch[i_Sch].Data.faculty[0].Class, Sch[i_Sch].Data.faculty[0].lengthOfClass);
						convertCourse(Sch[i_Sch].Data.faculty[5].course, Sch[i_Sch].Data.faculty[0].lengthOfCourse);
						BoxNotification(20, 8, 80, 4, 1, 7, "Successfully imported freshman student CSV into the system!", true);
						FLAG1 = true;
					}
				}
				else {
					int n = option - 3;
					MenuStudent2(Sch, i_Sch, n);
				}
			}
			else {
				int n = option - 2;
				MenuStudent2(Sch, i_Sch, n);
			}
		} while (true);
	}
}
// Menu tạo mới
void MenuNew(School* Sch, int& i_Sch) {
	int option;
	int x = 40, y = 9;
	do {
		BoxUsage(1, 0, 19, 5); gotoXY(45, 9);
		/*if (Sch[i_Sch].Freshman.lengthOfSemester >= 1 && Sch[i_Sch].Freshman.semester[Sch[i_Sch].Freshman.lengthOfSemester - 1].NameSemester != NULL) {
			cout << Sch[i_Sch].Freshman.semester[Sch[i_Sch].Freshman.lengthOfSemester - 1].NameSemester;
		}*/
		MenuGraphic(45, 10, 30, 2, 1, 7, option, n_Box7, Light7);

		if (option == 0)break;
		switch (option) {
		case 1:
			MenuNew1(Sch, i_Sch);
			break;
		case 2:
			MenuNew2(Sch, i_Sch);
			break;
		case 3:
			system("cls");
			for (int i = 0; i <= i_Sch; i++) {
				cout << Sch[i].SchoolYear[0] << "-" << Sch[i].SchoolYear[1] << endl;
			}
			system("pause");
			break;
		default:
			break;
		}
	} while (true);
}
// Menu đăng kí học phần 
void MenuRegisterForTheCourse(School* Sch, int& i_Sch, int position, int year) {
	int* ArrayClassOfStudent = new int[50];
	int i_ArrayClassOfStudent = 0;
	int* ArrayCourseOfStudent = new int[50];
	int i_ArrayCourseOfStudent = 0;
	Faculty Temporary = getFaculty(Sch[i_Sch], position, year);
	int count = 0;
	for (int i = 0; i < Temporary.lengthOfClass; i++) {
		for (int j = 0; j < Temporary.Class[i].lengthOfCourseOfClass; j++) {
			for (int k = 0; k < Temporary.Class[i].course[j].NumberOfStudent; k++) {
				if (strcmp(Temporary.Class[i].course[j].Member[k].StudentID, Sch[i_Sch].DAStudent.Member[position].StudentID) == 0) {
					ArrayClassOfStudent[i_ArrayClassOfStudent++] = i;
					ArrayCourseOfStudent[i_ArrayCourseOfStudent++] = j;
				}
			}
		}
	}
	system("cls");
	for (int i = 0; i < Temporary.lengthOfClass; i++) {
		for (int j = 0; j < Temporary.Class[i].lengthOfCourseOfClass; j++) {
			int check = 0;
			for (int k = 0; k < i_ArrayCourseOfStudent; k++) {
				if (strcmp(Temporary.Class[i].course[j].CourseID, Temporary.Class[ArrayClassOfStudent[k]].course[k].CourseID)) {
					check++;
				}
			}
			if (check == i_ArrayCourseOfStudent) {
				cout << ++count << Temporary.Class[i].course[j].CourseName << endl;
			}
		}
	}
	system("pause");
}
// Menu đăng kí học phần
void MenuRegister(School* Sch, int& i_Sch, int position, int year) {
	int option;
	Faculty Temporary = getFaculty(Sch[i_Sch], position, year);
	int x = 40, y = 9;
	do {
		BoxUsage(1, 0, 19, 5); gotoXY(45, 9);
		cout << Sch[i_Sch].DAStudent.Member[position].StudentID << " - " << Sch[i_Sch].DAStudent.Member[position].FirstName << " " << Sch[i_Sch].DAStudent.Member[position].LastName << endl;	gotoXY(x, y++);
		MenuGraphic(45, 10, 30, 2, 1, 7, option, n_Box4, Light4);
		if (option == 0)break;
		switch (option) {
		case 1:
			MenuRegisterForTheCourse(Sch, i_Sch, position, year);
			break;
		case 2:
			ViewListCourseOfStudent(Sch[i_Sch], position, year);
			break;
		default:
			break;
		}
	} while (true);
}
// Menu phản hồi
char* Feedback() {
	system("cls");
	Box(40, 9, 30, 5, 1, 75, "feedback");
	char* feedback = new char[100];
	cout << "\nEnter a feedback: ";
	cin.getline(feedback, 1000);
	return feedback;
}
// Menu quản lý học tập
void MenuLearning(School* Sch, int& i_Sch, int position, int year) {
	int option;
	Faculty Temporary = getFaculty(Sch[i_Sch], position, year);
	int x = 40, y = 9;
	do {
		BoxUsage(1, 0, 19, 5); gotoXY(45, 9);
		cout << Sch[i_Sch].DAStudent.Member[position].StudentID << " - " << Sch[i_Sch].DAStudent.Member[position].FirstName << " " << Sch[i_Sch].DAStudent.Member[position].LastName << endl;	gotoXY(x, y++);
		MenuGraphic(45, 10, 30, 2, 1, 7, option, n_Box5, Light5);
		if (option == 0)break;
		switch (option) {
		case 1:
			for (int i = 0; i < Temporary.lengthOfClass; i++) {
				for (int j = 0; j < Temporary.Class[i].lengthStudent; j++) {
					if (strcmp(Temporary.Class[i].Member[j].StudentID, Sch[i_Sch].DAStudent.Member[position].StudentID) == 0) {
						informationOfOneClass(Temporary.Class[i]);
						break;
					}
				}
			}
			break;
		case 2:
			ViewScoreBoardOfStudent(Temporary, Sch[i_Sch].DAStudent.Member[position].StudentID);
			break;
		case 3:
			ViewListCourseOfStudent(Sch[i_Sch], position, year);
			break;
		default:
			break;
		}
	} while (true);
}
// Menu Portal your a staff
void Menu1a(School* Sch, int& i_Sch, int& k) {
	int option;
	do {
		BoxUsage(1, 0, 19, 5); gotoXY(45, 7);
		//cout << Sch[i_Sch].DAStaff.Member[k].StudentID << " - " << Sch[i_Sch].DAStaff.Member[k].FirstName << " " << Sch[i_Sch].DAStaff.Member[k].LastName << endl;
		MenuGraphic(45, 8, 30, 2, 1, 7, option, n_Box6, Light6);
		if (option == 0)break;
		switch (option) {
		case 1:
			MenuProfile(Sch[0].DAStaff.Member[k]);
			break;
		case 2:
			MenuNew(Sch, i_Sch);
			break;
		case 3:
			MenuStudent1(Sch[i_Sch]);
			break;
		case 4:
			BoxUsage(1, 0, 19, 5);
			if (FLAG2 == true) {
				BoxLoading(35, 10, 51, 2, 1, 7);
				initScore(Sch[i_Sch].semester[Sch[i_Sch].lengthOfSemester - 1].Freshman);
				initScore(Sch[i_Sch].semester[Sch[i_Sch].lengthOfSemester - 1].Sophomore);
				initScore(Sch[i_Sch].semester[Sch[i_Sch].lengthOfSemester - 1].Thir_Year_Student);
				initScore(Sch[i_Sch].semester[Sch[i_Sch].lengthOfSemester - 1].Fourth_Year_Student);
				BoxNotification(42, 10, 30, 2, 1, 7, "Nhap diem thanh cong roi do", true);
			}
			else {
				BoxNotification(42, 10, 30, 2, 1, 7, "Nhap du lieu di thang ngu", true);
			}
			break;
			/*case 4:
				MenuClass(Sch[i_Sch].Data);
				break;
			case 5:
				MenuCourse(Sch[i_Sch].Data);
				break;*/
		case 5:
			ViewListStudent(Sch[i_Sch].DAStudent);
			break;
		default:
			break;
		}
	} while (true);
}
// Menu Portal your a student
void Menu2a(School* Sch, int& i_Sch, int& position) {
	int lc;
	int x = 40, y = 9;
	do {
		BoxUsage(1, 0, 19, 5); gotoXY(45, 9);
		cout << Sch[0].DAStudent.Member[position].StudentID << " - " << Sch[0].DAStudent.Member[position].FirstName << " " << Sch[0].DAStudent.Member[position].LastName << endl;	gotoXY(x, y++);
		MenuGraphic(45, 10, 30, 2, 1, 7, lc, n_Box3, Light3);
		if (lc == 0)break;
		switch (lc) {
		case 1:
			MenuProfile(Sch[0].DAStudent.Member[position]);
			break;
		case 2:
			MenuRegister(Sch, i_Sch, position, TIME.year - 1);
			break;
		case 3:
			MenuLearning(Sch, i_Sch, position, TIME.year - 1);
			break;
		case 4:
			char* feedback = Feedback();
			break;
		}
	} while (true);
}
// Menu giáo viên
void Menu1(School* Sch, int& i_Sch) {
	int lc;
	int n = 0;
	int x = 40, y = 10;

	do {
		BoxUsage(1, 0, 19, 5);
		MenuGraphic(45, 10, 30, 2, 1, 7, lc, n_Box2, Light2); gotoXY(x, y++);
		if (lc == 0)break;
		switch (lc) {
		case 1:
			Account Acc1;
			if (SignIn(Acc1, Sch[0].DAStaff, n, true)) {
			Menu1a(Sch, i_Sch, n);
			}
			break;
		case 2:
			BoxUsage(1, 0, 19, 3);
			BoxNotification(42, 10, 30, 2, 1, 7, "Temporarily closed feature!", true);
			break;
		case 3:
			ChangePassword(Sch[0].DAStaff);
			break;
		default:
			break;
		}
	} while (true);
}
// Menu học sinh
void Menu2(School* Sch, int& i_Sch) {
	int option;
	int n = 0;
	int x = 40, y = 10;
	Account Acc1;
	do {
		BoxUsage(1, 0, 19, 5);
		MenuGraphic(45, 10, 30, 2, 1, 7, option, n_Box2, Light2);
		if (option == 0)break;
		switch (option) {
		case 1:
			if (SignIn(Acc1, Sch[0].DAStudent, n, true)) {
				Menu2a(Sch, i_Sch, n);
			}
			break;
		case 2:
			BoxUsage(1, 0, 19, 3);
			BoxNotification(42, 10, 30, 2, 1, 7, "Temporarily closed feature!", true);
			break;
		case 3:
			ChangePassword(Sch[0].DAStudent);
			break;
		}
	} while (true);
}
void UpdateTime() {
	BoxUsage(1, 0, 19, 5);
	Date a;
	BoxTime(45, 10, 30, 8, 1, 7, a);
	cin.ignore();
	if (checkDay(a) && compareDate(a, TIME) == 1) {
		TIME.day = a.day;
		TIME.month = a.month;
		TIME.year = a.year;
		BoxNotification(42, 10, 30, 4, 1, 7, "Successful time change!", true);
		return;
	}
	BoxNotification(42, 10, 30, 4, 1, 7, "Invalid time!", true);
}

// Menu chính
void Menu(School* Sch, int& i_Sch) {
	int option;
	ifstream filein;
	/* Hàm thời gian thực */
	TimeActually();
	/* TEST SEMESTER */
	Semester temp;
	char test[] = "Fall";
	cpychar(temp.NameSemester, test);
	AllocationSemester(Sch[i_Sch].semester, Sch[i_Sch].lengthOfSemester, temp);
	/*cpychar(temp.NameSemester, test);
	AllocationSemester(Sch[i_Sch].semester, Sch[i_Sch].lengthOfSemester, temp);*/
	init(Sch[i_Sch].semester[Sch[i_Sch].lengthOfSemester - 1].Freshman);
	init(Sch[i_Sch].semester[Sch[i_Sch].lengthOfSemester - 1].Sophomore);
	init(Sch[i_Sch].semester[Sch[i_Sch].lengthOfSemester - 1].Thir_Year_Student);
	init(Sch[i_Sch].semester[Sch[i_Sch].lengthOfSemester - 1].Fourth_Year_Student);
	AllocationSchoolYear(Sch[i_Sch].SchoolYear, Sch[i_Sch].lengthOfSchoolYear, TIME.year - 1);
	AllocationSchoolYear(Sch[i_Sch].SchoolYear, Sch[i_Sch].lengthOfSchoolYear, TIME.year);
	filein.open("File_Staff.csv", ios_base::in);
	ReadListFromFile(filein, Sch[i_Sch].DAStaff);
	filein.close();
	filein.open("File_Student.csv", ios_base::in);// đọc toàn bộ sinh viên
	ReadListFromFile(filein, Sch[i_Sch].DAStudent);
	filein.close();

	// Đọc toàn bộ khoa, lóp, khóa học khi mới bắt đầu chạy ứng dụng
	ReadListFaculty(filein, Sch[i_Sch].Data, "File_Faculty.csv");
	ReadListClass(filein, Sch[i_Sch].Data, "File_Class.csv");
	ReadListCourse(filein, Sch[i_Sch].Data, 0, "File_Course1.csv"); // đọc kì học đầu tiên tương tứng với số 0
	ReadListCourse(filein, Sch[i_Sch].Data, 5, "File_Course2.csv"); // đọc kì học thứ hai tươn ứnng với số 5
	// Tách từng temporary data vào từng khóa 
	splitOfSchool(Sch[i_Sch], 22);
	splitOfClass(Sch[i_Sch], 22, true, Sch[i_Sch].lengthOfSemester - 1);
	splitOfCourse(Sch[i_Sch], 0, true, true, Sch[i_Sch].lengthOfSemester - 1);

	splitStudent(Sch[i_Sch].semester[Sch[i_Sch].lengthOfSemester - 1].Freshman);
	splitStudent(Sch[i_Sch].semester[Sch[i_Sch].lengthOfSemester - 1].Sophomore);
	splitStudent(Sch[i_Sch].semester[Sch[i_Sch].lengthOfSemester - 1].Thir_Year_Student);
	splitStudent(Sch[i_Sch].semester[Sch[i_Sch].lengthOfSemester - 1].Fourth_Year_Student);
	splitCourseToClass(Sch[i_Sch].semester[Sch[i_Sch].lengthOfSemester - 1].Freshman);
	splitCourseToClass(Sch[i_Sch].semester[Sch[i_Sch].lengthOfSemester - 1].Sophomore);
	splitCourseToClass(Sch[i_Sch].semester[Sch[i_Sch].lengthOfSemester - 1].Thir_Year_Student);
	splitCourseToClass(Sch[i_Sch].semester[Sch[i_Sch].lengthOfSemester - 1].Fourth_Year_Student);
	do {
		BoxUsage0(1, 0, 20, 6);
		HCMUS(0, 20);
		MenuGraphic(45, 10, 30, 2, 1, 7, option, n_Box1, Light1);
		if (option == 0)break;
		else if (option == -1) {
			UpdateTime();
		}
		else {
			switch (option) {
			case 1:
				system("cls");
				Menu1(Sch, i_Sch);
				break;
			case 2:
				system("cls");
				Menu2(Sch, i_Sch);
				break;
			default:
				break;
			}
		}
	} while (true);
}

//              FUNCTION GRAPHICS

void MenuGraphic(int x, int y, int w, int h, int b_color, int t_color, int& position, void (*n_Box)(int, int, int, int, int, int, int&), void (*Light)(int, int, int, int, int, int)) {
	ShowCur(0);
	int b_color_sang = 75;
	int quantity;
	n_Box(x, y, w, h, b_color, t_color, quantity);
	int xp = x;
	int xcu = xp;
	int yp = y;
	int ycu = yp;
	bool flag = true;
	while (true) {
		if (flag == true) {
			Light(xcu, ycu, w, h, b_color, (ycu - y + 2) / 2);// reset
			xcu = xp; ycu = yp;
			Light(xp, yp, w, h, b_color_sang, (yp - y + 2) / 2);
			flag = false;
		}
		// _keyboard hit :  If a key has been pressed then it returns a non zero value otherwise returns zero. 
		/* Điều khiển */
		if (_kbhit()) {
			char c = _getch();
			if (c == -32) {
				flag = true;
				c = _getch();
				if (c == 72) { // đi lên
					if (yp == y) {
						yp += (h * (quantity));
					}
					yp -= 2;

				}
				else if (c == 80) { // đi lên
					if (yp == y + (h * (quantity - 1))) {
						yp -= (h * (quantity));
					}
					yp += 2;

				}
			}
			else if (c == 13) {
				TextColor(1);
				SetColor(7);
				position = (yp - y + 2) / 2;
				return;
			}
			else if (c == 9) {
				TextColor(1);
				SetColor(7);
				position = -1;
				return;
			}
			else if (c == 27) {
				TextColor(1);
				SetColor(7);
				position = 0;
				return;
			}
		}
	}
}
void MenuGraphic0(int x, int y, int w, int h, int b_color, int t_color, int& position, void (*n_Box)(int, int, int, int, int, int, int&), void (*Light)(int, int, int, int, int, int)) {
	ShowCur(0);
	int b_color_sang = 75;
	int quantity;
	n_Box(x, y, w, h, b_color, t_color, quantity);
	int xp = x;
	int xcu = xp;
	int yp = y;
	int ycu = yp;
	bool flag = true;
	while (true) {
		if (flag == true) {
			Light(xcu, ycu, w, h, b_color, (ycu - y + 2) / 2);// reset
			xcu = xp; ycu = yp;
			Light(xp, yp, w, h, b_color_sang, (yp - y + 2) / 2);
			flag = false;
		}
		// _keyboard hit :  If a key has been pressed then it returns a non zero value otherwise returns zero. 
		/* Điều khiển */
		if (_kbhit()) {
			char c = _getch();
			if (c == -32) {
				flag = true;
				c = _getch();
				if (c == 72) { // đi lên
					if (yp == y) {
						yp += (h * (quantity));
					}
					yp -= 2;
					if (xp == x) {
						xp += (w * (quantity));
					}
					yp -= 2;
				}
				else if (c == 80) { // đi lên
					if (yp == y + (h * (quantity - 1))) {
						yp -= (h * (quantity));
					}
					yp += 2;

				}
			}
			else if (c == 13) {
				TextColor(1);
				SetColor(7);
				position = (yp - y + 2) / 2;
				return;
			}
			else if (c == 27) {
				TextColor(1);
				SetColor(7);
				position = 0;
				return;
			}
		}
	}
}
void MenuGraphic1(int x, int y, int w, int h, int b_color, int t_color, int& position, int positionFaculty, YearSchool& ySch, void (*n_Box)(int, int, int, int, int, int, int&, YearSchool&, int), void (*Light)(int, int, int, int, int, int, YearSchool&, int)) {
	ShowCur(0);
	int b_color_sang = 75;
	int quantity;
	n_Box(x, y, w, h, b_color, t_color, quantity, ySch, positionFaculty);
	int xp = x;
	int xcu = xp;
	int yp = y;
	int ycu = yp;
	bool flag = true;
	while (true) {
		if (flag == true) {
			Light(xcu, ycu, w, h, b_color, (ycu - y + 2) / 2, ySch, positionFaculty);// reset
			xcu = xp; ycu = yp;
			Light(xp, yp, w, h, b_color_sang, (yp - y + 2) / 2, ySch, positionFaculty);
			flag = false;
		}
		// _keyboard hit :  If a key has been pressed then it returns a non zero value otherwise returns zero. 
		/* Điều khiển */
		if (_kbhit()) {
			char c = _getch();
			if (c == -32) {
				flag = true;
				c = _getch();
				if (c == 72) { // đi lên
					if (yp == y) {
						yp += (h * (quantity));
					}
					yp -= 2;

				}
				else if (c == 80) { // đi lên
					if (yp == y + (h * (quantity - 1))) {
						yp -= (h * (quantity));
					}
					yp += 2;

				}
			}
			else if (c == 13) {
				TextColor(1);
				SetColor(7);
				position = (yp - y + 2) / 2;
				return;
			}
			else if (c == 27) {
				TextColor(1);
				SetColor(7);
				position = 0;
				return;
			}
		}
	}
}
void MenuGraphic2(int x, int y, int w, int h, int b_color, int t_color, int& position, DArray& DA, void (*n_Box)(int, int, int, int, int, int, int&, DArray&), void (*Light)(int, int, int, int, int, int, DArray&)) {
	ShowCur(0);
	int b_color_sang = 75;
	int quantity;
	n_Box(x, y, w, h, b_color, t_color, quantity, DA);
	int xp = x;
	int xcu = xp;
	int yp = y;
	int ycu = yp;
	bool flag = true;
	while (true) {
		if (flag == true) {
			Light(xcu, ycu, w, h, b_color, (ycu - y + 2) / 2, DA);// reset
			xcu = xp; ycu = yp;
			Light(xp, yp, w, h, b_color_sang, (yp - y + 2) / 2, DA);
			flag = false;
		}
		// _keyboard hit :  If a key has been pressed then it returns a non zero value otherwise returns zero. 
		/* Điều khiển */
		if (_kbhit()) {
			char c = _getch();
			if (c == -32) {
				flag = true;
				c = _getch();
				if (c == 72) { // đi lên
					if (yp == y) {
						yp += (h * (quantity));
					}
					yp -= 2;

				}
				else if (c == 80) { // đi lên
					if (yp == y + (h * (quantity - 1))) {
						yp -= (h * (quantity));
					}
					yp += 2;

				}
			}
			else if (c == 13) {
				TextColor(1);
				SetColor(7);
				position = (yp - y + 2) / 2;
				return;
			}
			else if (c == 27) {
				TextColor(1);
				SetColor(7);
				position = 0;
				return;
			}
		}
	}
}
void MenuGraphic3(int x, int y, int w, int h, int b_color, int t_color, int& position, School& Sch, Faculty& faculty, int*& a, int*& b, int& i_a, int& i_b, int positionOfStudent, void (*n_Box)(int, int, int, int, int, int, int&, School&, Faculty&, int*&, int*&, int&, int&, int), void (*Light)(int, int, int, int, int, int, Faculty, int*, int*)) {
	ShowCur(0);
	int b_color_sang = 75;
	int quantity;
	n_Box(x, y, w, h, b_color, t_color, quantity, Sch, faculty, a, b, i_a, i_b, positionOfStudent);
	int xp = x;
	int xcu = xp;
	int yp = y;
	int ycu = yp;
	bool flag = true;
	while (true) {
		if (flag == true) {
			Light(xcu, ycu, w, h, b_color, (ycu - y + 2) / 2, faculty, a, b);// reset
			xcu = xp; ycu = yp;
			Light(xp, yp, w, h, b_color_sang, (yp - y + 2) / 2, faculty, a, b);
			flag = false;
		}
		// _keyboard hit :  If a key has been pressed then it returns a non zero value otherwise returns zero. 
		/* Điều khiển */
		if (_kbhit()) {
			char c = _getch();
			if (c == -32) {
				flag = true;
				c = _getch();
				if (c == 72) { // đi lên
					if (yp == y) {
						yp += (h * (quantity));
					}
					yp -= 2;

				}
				else if (c == 80) { // đi lên
					if (yp == y + (h * (quantity - 1))) {
						yp -= (h * (quantity));
					}
					yp += 2;

				}
			}
			else if (c == 13) {
				TextColor(1);
				SetColor(7);
				position = (yp - y + 2) / 2;
				return;
			}
			else if (c == 27) {
				TextColor(1);
				SetColor(7);
				position = 0;
				return;
			}
		}
	}
}
void MenuGraphic4(int x, int y, int w, int h, int b_color, int t_color, int& position, School& Sch, void (*n_Box)(int, int, int, int, int, int, int&, School&), void (*Light)(int, int, int, int, int, int, School&)) {
	ShowCur(0);
	int b_color_sang = 75;
	int quantity;
	n_Box(x, y, w, h, b_color, t_color, quantity, Sch);
	int xp = x;
	int xcu = xp;
	int yp = y;
	int ycu = yp;
	bool flag = true;
	while (true) {
		if (flag == true) {
			Light(xcu, ycu, w, h, b_color, (ycu - y + 2) / 2, Sch);// reset
			xcu = xp; ycu = yp;
			Light(xp, yp, w, h, b_color_sang, (yp - y + 2) / 2, Sch);
			flag = false;
		}
		// _keyboard hit :  If a key has been pressed then it returns a non zero value otherwise returns zero. 
		/* Điều khiển */
		if (_kbhit()) {
			char c = _getch();
			if (c == -32) {
				flag = true;
				c = _getch();
				if (c == 72) { // đi lên
					if (yp == y) {
						yp += (h * (quantity));
					}
					yp -= 2;

				}
				else if (c == 80) { // đi lên
					if (yp == y + (h * (quantity - 1))) {
						yp -= (h * (quantity));
					}
					yp += 2;

				}
			}
			else if (c == 13) {
				TextColor(1);
				SetColor(7);
				position = (yp - y + 2) / 2;
				return;
			}
			else if (c == 27) {
				TextColor(1);
				SetColor(7);
				position = 0;
				return;
			}
		}
	}
}
void MenuGraphic5(int x, int y, int w, int h, int b_color, int t_color, int& position, YearSchool& ySch, void (*n_Box)(int, int, int, int, int, int, int&, YearSchool&), void (*Light)(int, int, int, int, int, int, YearSchool&)) {
	ShowCur(0);
	int b_color_sang = 75;
	int quantity;
	n_Box(x, y, w, h, b_color, t_color, quantity, ySch);
	int xp = x;
	int xcu = xp;
	int yp = y;
	int ycu = yp;
	bool flag = true;
	while (true) {
		if (flag == true) {
			Light(xcu, ycu, w, h, b_color, (ycu - y + 2) / 2, ySch);// reset
			xcu = xp; ycu = yp;
			Light(xp, yp, w, h, b_color_sang, (yp - y + 2) / 2, ySch);
			flag = false;
		}
		// _keyboard hit :  If a key has been pressed then it returns a non zero value otherwise returns zero. 
		/* Điều khiển */
		if (_kbhit()) {
			char c = _getch();
			if (c == -32) {
				flag = true;
				c = _getch();
				if (c == 72) { // đi lên
					if (yp == y) {
						yp += (h * (quantity));
					}
					yp -= 2;

				}
				else if (c == 80) { // đi lên
					if (yp == y + (h * (quantity - 1))) {
						yp -= (h * (quantity));
					}
					yp += 2;

				}
			}
			else if (c == 13) {
				TextColor(1);
				SetColor(7);
				position = (yp - y + 2) / 2;
				return;
			}
			else if (c == 27) {
				TextColor(1);
				SetColor(7);
				position = 0;
				return;
			}
		}
	}
}

void Light1(int x, int y, int w, int h, int b_color, int position) {
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	if (position == 1) {
		gotoXY(x + ((w / 2) - (strlen("ACADEMIC STAFF") / 2)), y + 1);
		cout << "ACADEMIC STAFF";
	}
	if (position == 2) {
		gotoXY(x + ((w / 2) - (strlen("STUDENT") / 2)), y + 1);
		cout << "STUDENT";
	}
}
void Light2(int x, int y, int w, int h, int b_color, int position) {
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	if (position == 1) {
		gotoXY(x + ((w / 2) - (strlen("SIGN IN") / 2)), y + 1);;
		cout << "SIGN IN";
	}
	if (position == 2) {
		gotoXY(x + ((w / 2) - (strlen("SIGN UP") / 2)), y + 1);
		cout << "SIGN UP";
	}
	else if (position == 3) {
		gotoXY(x + ((w / 2) - (strlen("CHANGE PASSWORD") / 2)), y + 1);
		cout << "CHANGE PASSWORD";
	}
}
void Light3(int x, int y, int w, int h, int b_color, int position) {
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	if (position == 1) {
		gotoXY(x + ((w / 2) - (strlen("Profile") / 2)), y + 1);
		cout << "Profile";
	}
	if (position == 2) {
		gotoXY(x + ((w / 2) - (strlen("Register for the course") / 2)), y + 1);
		cout << "Register for the course";
	}
	else if (position == 3) {
		gotoXY(x + ((w / 2) - (strlen("Learning management") / 2)), y + 1);
		cout << "Learning management";
	}
	else if (position == 4) {
		gotoXY(x + ((w / 2) - (strlen("Feadback") / 2)), y + 1);
		cout << "Feadback";
	}
}
void Light4(int x, int y, int w, int h, int b_color, int position) {
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	if (position == 1) {
		gotoXY(x + ((w / 2) - (strlen("Register") / 2)), y + 1);
		cout << "Register";
	}
	if (position == 2) {
		gotoXY(x + ((w / 2) - (strlen("Registration results") / 2)), y + 1);
		cout << "Registration results";
	}
}
void Light5(int x, int y, int w, int h, int b_color, int position) {
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	if (position == 1) {
		gotoXY(x + ((w / 2) - (strlen("Information class") / 2)), y + 1);
		cout << "Information class";
	}
	if (position == 2) {
		gotoXY(x + ((w / 2) - (strlen("Learning outcomes") / 2)), y + 1);
		cout << "Learning outcomes";
	}
	else if (position == 3) {
		gotoXY(x + ((w / 2) - (strlen("Your course list") / 2)), y + 1);
		cout << "Your course list";
	}
}
void Light6(int x, int y, int w, int h, int b_color, int position) {
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	if (position == 1) {
		gotoXY(x + ((w / 2) - (strlen("Profile") / 2)), y + 1);
		cout << "Profile";
	}
	if (position == 2) {
		gotoXY(x + ((w / 2) - (strlen("New") / 2)), y + 1);
		cout << "New";
	}
	else if (position == 3) {
		gotoXY(x + ((w / 2) - (strlen("Student") / 2)), y + 1);
		cout << "Student";
	}
	if (position == 4) {
		gotoXY(x + ((w / 2) - (strlen("Import score") / 2)), y + 1);
		cout << "Import score";
	}
	/*if (position == 5) {
		gotoXY(x + ((w / 2) - (strlen("Course infor") / 2)), y + 1);
		cout << "Course infor";
	}*/
	else if (position == 5) {
		gotoXY(x + ((w / 2) - (strlen("View list all students") / 2)), y + 1);
		cout << "View list all students";
	}
}
void Light7(int x, int y, int w, int h, int b_color, int position) {
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	if (position == 1) {
		gotoXY(x + ((w / 2) - (strlen("Create a school year") / 2)), y + 1);
		cout << "Create a school year";
	}
	if (position == 2) {
		gotoXY(x + ((w / 2) - (strlen("Update semester") / 2)), y + 1);
		cout << "Update semester";
	}
	if (position == 3) {
		gotoXY(x + ((w / 2) - (strlen("List school yeasr") / 2)), y + 1);
		cout << "List school year";
	}
}
void Light8(int x, int y, int w, int h, int b_color, int position) {
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	if (position == 1) {
		gotoXY(x + ((w / 2) - (strlen("Freshman") / 2)), y + 1);
		cout << "Freshman";
	}
	if (position == 2) {
		gotoXY(x + ((w / 2) - (strlen("Sophomore") / 2)), y + 1);
		cout << "Sophomore";
	}
	else if (position == 3) {
		gotoXY(x + ((w / 2) - (strlen("Third year student") / 2)), y + 1);
		cout << "Third year students";
	}
	else if (position == 4) {
		gotoXY(x + ((w / 2) - (strlen("Fourth year students") / 2)), y + 1);
		cout << "Fourth year students";
	}
}
void Light8_1(int x, int y, int w, int h, int b_color, int position) {
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	if (position == 1) {
		gotoXY(x + ((w / 2) - (strlen("Freshman") / 2)), y + 1);
		cout << "Freshman";
	}
	if (position == 2) {
		gotoXY(x + ((w / 2) - (strlen("Sophomore") / 2)), y + 1);
		cout << "Sophomore";
	}
	else if (position == 3) {
		gotoXY(x + ((w / 2) - (strlen("Third year student") / 2)), y + 1);
		cout << "Third year students";
	}
	else if (position == 4) {
		gotoXY(x + ((w / 2) - (strlen("Fourth year students") / 2)), y + 1);
		cout << "Fourth year students";
	}
	else if (position == 5) {
		gotoXY(x + ((w / 2) - (strlen("Import data for semester") / 2)), y + 1);
		cout << "Import data for semester";
	}

}
void Light9(int x, int y, int w, int h, int b_color, int position) {
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	if (position == 1) {
		gotoXY(x + ((w / 2) - (strlen("Class of freshman") / 2)), y + 1);
		cout << "Class of freshman";
	}
	if (position == 2) {
		gotoXY(x + ((w / 2) - (strlen("Course of freshman") / 2)), y + 1);
		cout << "Course of freshman";
	}
	else if (position == 3) {
		gotoXY(x + ((w / 2) - (strlen("List student of freshman") / 2)), y + 1);
		cout << "List student of freshman";
	}
}
void Light10(int x, int y, int w, int h, int b_color, int position) {
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	if (position == 1) {
		gotoXY(x + ((w / 2) - (strlen("Class of sophomore") / 2)), y + 1);
		cout << "Class of sophomore";
	}
	if (position == 2) {
		gotoXY(x + ((w / 2) - (strlen("Course of sophomore") / 2)), y + 1);
		cout << "Course of sophomore";
	}
	if (position == 3) {
		gotoXY(x + ((w / 2) - (strlen("List student of sophomore") / 2)), y + 1);
		cout << "List student of sophomore";
	}
}
void Light11(int x, int y, int w, int h, int b_color, int position) {
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	if (position == 1) {
		gotoXY(x + ((w / 2) - (strlen("Class of third year") / 2)), y + 1);
		cout << "Class of third year";
	}
	if (position == 2) {
		gotoXY(x + ((w / 2) - (strlen("Course of third year") / 2)), y + 1);
		cout << "Course of third year";
	}
	else if (position == 3) {
		gotoXY(x + ((w / 2) - (strlen("List student of third year") / 2)), y + 1);
		cout << "List student of third year";
	}
}
void Light12(int x, int y, int w, int h, int b_color, int position) {
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	if (position == 1) {
		gotoXY(x + ((w / 2) - (strlen("Class of fourth year") / 2)), y + 1);
		cout << "Class of fourth year";
	}
	if (position == 2) {
		gotoXY(x + ((w / 2) - (strlen("Course of fourth year") / 2)), y + 1);
		cout << "Course of fourth year";
	}
	else if (position == 3) {
		gotoXY(x + ((w / 2) - (strlen("List student of fourth year") / 2)), y + 1);
		cout << "List student of fourth year";
	}
}
void Light15(int x, int y, int w, int h, int b_color, int position, YearSchool& ySch, int positionFacutly) {
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	gotoXY(x + ((w / 2) - (strlen(ySch.faculty[position - 1].NameFaculty) / 2)), y + 1);
	cout << ySch.faculty[position - 1].NameFaculty;
}
void Light16(int x, int y, int w, int h, int b_color, int position, YearSchool& ySch, int positionFaculty) {
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	gotoXY(x + ((w / 2) - (strlen(ySch.faculty[positionFaculty].Class[position - 1].NameClass) / 2)), y + 1);
	cout << ySch.faculty[positionFaculty].Class[position - 1].NameClass;
}
void Light17(int x, int y, int w, int h, int b_color, int position, DArray& DA) {
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	gotoXY(x + ((w / 2) - (strlen(DA.course[position - 1].CourseName) / 2)), y + 1);
	cout << DA.course[position - 1].CourseName;

}
void Light18(int x, int y, int w, int h, int b_color, int position) {
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	if (position == 1) {
		gotoXY(x + ((w / 2) - (strlen("Information of class") / 2)), y + 1);
		cout << "Information of class";
	}
	if (position == 2) {
		gotoXY(x + ((w / 2) - (strlen("List students of class") / 2)), y + 1);
		cout << "List students of class";
	}
	else if (position == 3) {
		gotoXY(x + ((w / 2) - (strlen("List course of class") / 2)), y + 1);
		cout << "List course of class";
	}
	else if (position == 4) {
		gotoXY(x + ((w / 2) - (strlen("Transcript of class") / 2)), y + 1);
		cout << "Transcript of class";
	}
}
void Light19(int x, int y, int w, int h, int b_color, int position) {
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	gotoXY(x + 4, y + 1);
	if (position == 1) {
		gotoXY(x + ((w / 2) - (strlen("Information of course") / 2)), y + 1);
		cout << "Information of course";
	}
	if (position == 2) {
		gotoXY(x + ((w / 2) - (strlen("List students of course") / 2)), y + 1);
		cout << "List students of course";
	}
	else if (position == 3) {
		gotoXY(x + ((w / 2) - (strlen("Transcript of course") / 2)), y + 1);
		cout << "Transcript of course";
	}
	else if (position == 4) {
		gotoXY(x + ((w / 2) - (strlen("Add a student to the course") / 2)), y + 1);
		cout << "Add a student to the course";
	}
	else if (position == 5) {
		gotoXY(x + ((w / 2) - (strlen("Update course information") / 2)), y + 1);
		cout << "Update course information";
	}
	else if (position == 6) {
		gotoXY(x + ((w / 2) - (strlen("Remove a student from the course") / 2)), y + 1);
		cout << "Remove a student from the course";
	}
	else if (position == 7) {
		gotoXY(x + ((w / 2) - (strlen("Import the scoreboard to course") / 2)), y + 1);
		cout << "Import the scoreboard to course";
	}
	else if (position == 8) {
		gotoXY(x + ((w / 2) - (strlen("Delete course") / 2)), y + 1);
		cout << "Delete course";
	}
}
// Light của danh sách học sinh môn học
void Light27(int x, int y, int w, int h, int b_color, int position, Course course) {
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	gotoXY(x + 2, y + 2); cout << course.Member[position - 1].No;
	gotoXY(x + 5 + ((15 / 2) - (strlen(course.Member[position - 1].StudentID) / 2)), y + 2); cout << course.Member[position - 1].StudentID;;
	gotoXY(x + 20 + 2, y + 2); cout << course.Member[position - 1].FirstName << " " << course.Member[position - 1].LastName;
	gotoXY(x + 50 + 2, y + 2); cout << course.Member[position - 1].DateOfBirth.day << "/" << course.Member[position - 1].DateOfBirth.month << "/" << course.Member[position - 1].DateOfBirth.year;
	gotoXY(x + 65 + 6, y + 2); cout << course.Member[position - 1].Gender;
	gotoXY(x + 80 + 5, y + 2); cout << course.Member[position - 1].CCCD;
}
void Light25(int x, int y, int w, int h, int b_color, int position, Faculty faculty, int* a, int* b) {
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	gotoXY(x + ((w / 2) - (strlen(faculty.Class[a[position - 1]].course[b[position - 1]].CourseName) / 2)), y + 1);
	cout << faculty.Class[a[position - 1]].course[b[position - 1]].CourseName;
}
void Light26(int x, int y, int w, int h, int b_color, int position, DArray& DA) {
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	gotoXY(x + ((w / 2) - (strlen(DA.course[position - 1].CourseName) / 2)), y + 1);
	cout << DA.course[position - 1].CourseName;

}
void Light28(int x, int y, int w, int h, int b_color, int position, School& Sch) {
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	if (position == 1) {
		gotoXY(x + ((w / 2) - (strlen("Create semester") / 2)), y + 1);
		cout << "Create semester";
	}
	else if (FLAG1 == false) {
		if (position == 2) {
			gotoXY(x + ((w / 2) - (strlen("Import freshman data") / 2)), y + 1);
			cout << "Import freshman data";
		}
		else {
			gotoXY(x + ((w / 2) - (strlen(Sch.semester[position - 3].NameSemester) / 2)), y + 1);
			cout << Sch.semester[position - 3].NameSemester;
		}
	}
	else {
		gotoXY(x + ((w / 2) - (strlen(Sch.semester[position - 2].NameSemester) / 2)), y + 1);
		cout << Sch.semester[position - 2].NameSemester;
	}
}
void Light29(int x, int y, int w, int h, int b_color, int position) {
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	if (position == 1) {
		gotoXY(x + ((w / 2) - (strlen("Create a new faculty") / 2)), y + 1);
		cout << "Create a new faculty";
	}
	if (position == 2) {
		gotoXY(x + ((w / 2) - (strlen("Create a new class") / 2)), y + 1);
		cout << "Create a newclass";
	}
	else if (position == 3) {
		gotoXY(x + ((w / 2) - (strlen("Create a new course") / 2)), y + 1);
		cout << "Create a new course";
	}
	else if (position == 4) {
		gotoXY(x + ((w / 2) - (strlen("Create a new student") / 2)), y + 1);
		cout << "Create a new student";
	}
}
void Light30(int x, int y, int w, int h, int b_color, int position, YearSchool& ySch) {
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	gotoXY(x + ((w / 2) - (strlen(ySch.faculty[position - 1].NameFaculty) / 2)), y + 1);
	cout << ySch.faculty[position - 1].NameFaculty;
}
void Light01(int x, int y, int w, int h, int b_color, int position) {
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	if (position == 1) {
		gotoXY(x + w / 2 - 10 + 2, y + h + 1 + 1); cout << "YES";
	}
	if (position == 2) {
		gotoXY(x + w / 2 + 5 + 2, y + h + 1 + 1); cout << "NO";
	}
}

void HCMUS(int x, int y) {
	gotoXY(x, y);
	cout << "\t\t                 ____    ____  __________  ____   ____  ____   ____  __________   " << endl;
	cout << "\t\t                /   /   /   / /   ___   / /   /__/   / /   /  /   / /  _______/   " << endl;
	cout << "\t\t               /   /___/   / /   /  /__/ /   _  _   / /   /  /   / /  /______     " << endl;
	cout << "\t\t              /    ___    / /   /  ___  /   / - /  / /   /  /   / /______   /     " << endl;
	cout << "\t\t             /    /  /   / /   /__/  / /   /   /  / /   /__/   / _______/  /      " << endl;
	cout << "\t\t            /____/  /___/ /_________/ /___/   /__/ /__________/ /_________/       " << endl;
}
void BoxLoading(int x, int y, int w, int h, int b_color, int t_color) {
	BoxUsage(1, 0, 19, 5);
	if (h <= 1 || w <= 1)return;
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	TextColor(1);// Chỉnh về màu nền cơ bản (1: màu đen)
	SetColor(t_color);
	for (int ix = x; ix <= x + w; ix++) {
		gotoXY(ix, y);
		cout << char(196);
		gotoXY(ix, y + h);
		cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++) {
		gotoXY(x, iy);
		cout << char(179);
		gotoXY(x + w, iy);
		cout << char(179);
	}
	gotoXY(x, y); cout << char(218);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y); cout << char(191);
	gotoXY(x + w, y + h); cout << char(217);
	for (int ix = x + 1; ix < x + w; ix++) {
		gotoXY(ix, y + 1); cout << char(219); gotoXY(x + w + 1, y + 1); cout << " " << (ix - x) * 2 << " %";
		Sleep(20);
	}
}
void Box(int x, int y, int w, int h, int b_color, int t_color, string s) {
	if (h <= 1 || w <= 1)return;
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	gotoXY(x + ((w / 2) - (s.length() / 2)), y + 1); cout << s;
	TextColor(1);// Chỉnh về màu nền cơ bản (1: màu đen)
	SetColor(t_color);
	for (int ix = x; ix <= x + w; ix++) {
		gotoXY(ix, y);
		cout << char(196);
		gotoXY(ix, y + h);
		cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++) {
		gotoXY(x, iy);
		cout << char(179);
		gotoXY(x + w, iy);
		cout << char(179);
	}
	gotoXY(x, y); cout << char(218);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y); cout << char(191);
	gotoXY(x + w, y + h); cout << char(217);
}
void BoxTime(int x, int y, int w, int h, int b_color, int t_color, Date& a) {
	if (h <= 1 || w <= 1)return;
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	gotoXY(x + ((w / 2) - (strlen("TIME CURRENT") / 2)), y + 1); cout << "TIME CURRENT";
	gotoXY(x + ((w / 2) - (strlen("TIME CURRENT") / 2)), y + 5); cout << " UPDATE TIME";
	gotoXY(x + 5, y + 3); cout << TIME.day;
	gotoXY(x + 15, y + 3); cout << TIME.month;
	gotoXY(x + 23, y + 3); cout << TIME.year;
	TextColor(1);// Chỉnh về màu nền cơ bản (1: màu đen)
	SetColor(t_color);
	for (int ix = x; ix <= x + w; ix++) {
		gotoXY(ix, y);
		cout << char(196);
		gotoXY(ix, y + h);
		cout << char(196);
		gotoXY(ix, y + 2);
		cout << char(196);
		gotoXY(ix, y + 4);
		cout << char(196);
		gotoXY(ix, y + 6);
		cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++) {
		gotoXY(x, iy);
		cout << char(179);
		gotoXY(x + w, iy);
		cout << char(179);
	}
	for (int iy = y + 2; iy <= y + 4; iy++) {
		gotoXY(x + 10, iy);
		cout << char(179);
		gotoXY(x + 20, iy);
		cout << char(179);
	}
	for (int iy = y + 6; iy <= y + 8; iy++) {
		gotoXY(x + 10, iy);
		cout << char(179);
		gotoXY(x + 20, iy);
		cout << char(179);
	}
	/* Căn chỉnh các dấu cộng ở giữa */
	gotoXY(x + 10, y + 2); cout << char(194);
	gotoXY(x + 20, y + 2); cout << char(194);

	gotoXY(x + 10, y + 6); cout << char(194);
	gotoXY(x + 20, y + 6); cout << char(194);

	gotoXY(x + 10, y + 4); cout << char(193);
	gotoXY(x + 20, y + 4); cout << char(193);

	gotoXY(x + 10, y + 8); cout << char(193);
	gotoXY(x + 20, y + 8); cout << char(193);

	/* Căn chỉnh vòng xung quanh */

	gotoXY(x, y); cout << char(218);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y); cout << char(191);
	gotoXY(x + w, y + h); cout << char(217);

	gotoXY(x, y + 2); cout << char(195);
	gotoXY(x, y + 4); cout << char(195);
	gotoXY(x, y + 6); cout << char(195);

	gotoXY(x + w, y + 2); cout << char(180);
	gotoXY(x + w, y + 4); cout << char(180);
	gotoXY(x + w, y + 6); cout << char(180);

	ShowCur(1);
	gotoXY(x + 5, y + 7); cin >> a.day;
	gotoXY(x + 15, y + 7); cin >> a.month;
	gotoXY(x + 23, y + 7); cin >> a.year;
	ShowCur(0);
}
void BoxUsage(int x, int y, int w, int h) {
	system("cls");
	for (int ix = x; ix <= x + w; ix++) {
		gotoXY(ix, y); cout << char(196);
		gotoXY(ix, y + h); cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++) {
		gotoXY(x, iy); cout << char(179);
		gotoXY(x + w, iy); cout << char(179);
	}
	gotoXY(x, y); cout << char(218);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y); cout << char(191);
	gotoXY(x + w, y + h); cout << char(217);
	gotoXY(x + 2, y + 1);
	cout << "[" << char(30) << "]     : UP";
	gotoXY(x + 2, y + 2);
	cout << "[" << char(31) << "]     : DOWN";
	gotoXY(x + 2, y + 3);
	cout << "[ESC]   : EXIT";
	gotoXY(x + 2, y + 4);
	cout << "[ENTER] : SELECT";
	gotoXY(x + 107, y); cout << TIME.day << "/" << TIME.month << "/" << TIME.year;
}
void BoxUsage0(int x, int y, int w, int h) {
	system("cls");
	for (int ix = x; ix <= x + w; ix++) {
		gotoXY(ix, y); cout << char(196);
		gotoXY(ix, y + h); cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++) {
		gotoXY(x, iy); cout << char(179);
		gotoXY(x + w, iy); cout << char(179);
	}
	gotoXY(x, y); cout << char(218);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y); cout << char(191);
	gotoXY(x + w, y + h); cout << char(217);
	gotoXY(x + 2, y + 1);
	cout << "[" << char(30) << "]     : UP";
	gotoXY(x + 2, y + 2);
	cout << "[" << char(31) << "]     : DOWN";
	gotoXY(x + 2, y + 3);
	cout << "[ESC]   : EXIT";
	gotoXY(x + 2, y + 4);
	cout << "[ENTER] : SELECT";
	gotoXY(x + 2, y + 5);
	cout << "[TAB]   : SETTING";
	gotoXY(x + 107, y); cout << TIME.day << "/" << TIME.month << "/" << TIME.year;
}
int BoxNotification(int x, int y, int w, int h, int b_color, int t_color, string s, bool flag) {
	if (flag) {
		BoxUsage(1, 0, 19, 5);
	}
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	gotoXY(x + ((w / 2) - (s.length() / 2)), y + h / 2); cout << s;
	TextColor(1);// Chỉnh về màu nền cơ bản (1: màu đen)
	SetColor(t_color);
	for (int ix = x; ix <= x + w; ix++) {
		gotoXY(ix, y);
		cout << char(196);
		gotoXY(ix, y + h);
		cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++) {
		gotoXY(x, iy);
		cout << char(179);
		gotoXY(x + w, iy);
		cout << char(179);
	}
	gotoXY(x, y); cout << char(218);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y); cout << char(191);
	gotoXY(x + w, y + h); cout << char(217);

	/*for (int ix = x+w / 2 - 10; ix <= x + w / 2 - 4; ix++) {
		gotoXY(ix, y + h + 1);
		cout << char(196);
		gotoXY(ix, y + h + 3);
		cout << char(196);
	}
	for (int ix = x + w / 2 +4; ix <= x + w / 2 +  10; ix++) {
		gotoXY(ix, y + h + 1);
		cout << char(196);
		gotoXY(ix, y + h + 3);
		cout << char(196);
	}
	for (int iy = y + h + 1; iy <= y + h + 3; iy++) {
		gotoXY(x + w / 2 - 10, iy);
		cout << char(179);
		gotoXY(x + w / 2 + 10, iy);
		cout << char(179);
		gotoXY(x + w / 2 - 4, iy);
		cout << char(179);
		gotoXY(x + w / 2 + 4, iy);
		cout << char(179);
	}
	gotoXY(x + w / 2 - 10, y + h + 1); cout << char(218);
	gotoXY(x + w / 2 - 10, y + h + 3); cout << char(192);
	gotoXY(x + w / 2 - 4, y + h + 1); cout << char(191);
	gotoXY(x + w / 2 - 4, y + h + 3); cout << char(217);
	gotoXY(x + w / 2 - 10 + 2, y + h + 1 + 1); cout << "YES";

	gotoXY(x + w / 2 + 4, y + h + 1); cout << char(218);
	gotoXY(x + w / 2 + 4, y + h + 3); cout << char(192);
	gotoXY(x + w / 2 + 10, y + h + 1); cout << char(191);
	gotoXY(x + w / 2 + 10, y + h + 3); cout << char(217);
	gotoXY(x + w / 2 + 5 + 2, y + h + 1 + 1); cout << "NO";*/
	cin.ignore();
	if (_kbhit()) {
		char character = _getch();
		if (character == 13) {
			TextColor(1);
			SetColor(7);
			return 1;
		}
		else if (character == 27) {
			TextColor(1);
			SetColor(7);
			return 0;
		}
	}
	else return 1;
}
void BoxNotification1(int x, int y, int w, int h, int b_color, int t_color, string s) {
	//if (h <= 1 || w <= 1)return;
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	gotoXY(x + ((w / 2) - (s.length() / 2)), y + h / 2); cout << s;
	TextColor(1);// Chỉnh về màu nền cơ bản (1: màu đen)
	SetColor(t_color);
	for (int ix = x; ix <= x + w; ix++) {
		gotoXY(ix, y);
		cout << char(196);
		gotoXY(ix, y + h);
		cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++) {
		gotoXY(x, iy);
		cout << char(179);
		gotoXY(x + w, iy);
		cout << char(179);
	}
	gotoXY(x, y); cout << char(218);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y); cout << char(191);
	gotoXY(x + w, y + h); cout << char(217);

	/* Vẽ YES NO*/
	for (int ix = w + h / 2 - 5; ix <= x + w / 2 - 5; ix++) {
		gotoXY(ix, y + h + 2);
		cout << char(196);
		gotoXY(ix, y + h + 4);
		cout << char(196);
	}
}
void BoxSignIn(int x, int y, int w, int h, int b_color, int t_color, string s) {
	if (h <= 1 || w <= 1)return;
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	gotoXY(x + 2, y + 1); cout << s;
	TextColor(1);// Chỉnh về màu nền cơ bản (1: màu đen)
	SetColor(t_color);
	for (int ix = x; ix <= x + w; ix++) {
		gotoXY(ix, y);
		cout << char(196);
		gotoXY(ix, y + h);
		cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++) {
		gotoXY(x, iy);
		cout << char(179);
		gotoXY(x + w, iy);
		cout << char(179);
		gotoXY(x + 12, iy);
		cout << char(179);
	}
	gotoXY(x, y); cout << char(218);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y); cout << char(191);
	gotoXY(x + w, y + h); cout << char(217);
	gotoXY(x + 12, y); cout << char(194);
	gotoXY(x + 12, y + h); cout << char(193);
}
void BoxProfile(int x, int y, int w, int h, int b_color, int t_color, Information infor) {
	if (h <= 1 || w <= 1)return;
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	gotoXY(x + 2, y + 1); cout << "No         :  " << infor.No;
	gotoXY(x + 2, y + 2); cout << "ID         :  " << infor.StudentID;
	gotoXY(x + 2, y + 3); cout << "CCCD/CMND  :  " << infor.CCCD;
	gotoXY(x + 2, y + 4); cout << "Name       :  " << infor.FirstName << " " << infor.LastName;
	gotoXY(x + 2, y + 5); cout << "Sex        :  " << infor.Gender;
	gotoXY(x + 2, y + 6); cout << "Date       :  " << infor.DateOfBirth.day << "/" << infor.DateOfBirth.month << "/" << infor.DateOfBirth.year;
	gotoXY(x + 2, y + 7); cout << "EMAIL      :  " << infor.Email;
	gotoXY(x + 2, y + 8); cout << "Position   :  " << infor.Postition;
	TextColor(1);// Chỉnh về màu nền cơ bản (1: màu đen)
	SetColor(t_color);
	for (int ix = x; ix <= x + w; ix++) {
		gotoXY(ix, y);
		cout << char(196);
		gotoXY(ix, y + h);
		cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++) {
		gotoXY(x, iy);
		cout << char(179);
		gotoXY(x + w, iy);
		cout << char(179);
	}
	gotoXY(x, y); cout << char(218);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y); cout << char(191);
	gotoXY(x + w, y + h); cout << char(217);
}
void BoxInformationOfClass(int x, int y, int w, int h, int b_color, int t_color, DArray DA) {
	if (h <= 1 || w <= 1)return;
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	/*cout << "============ CLASS ============" << endl;                                 gotoXY(x, y++);
	cout << "  Name     : " << DA.NameClass << endl;                                   gotoXY(x, y++);
	cout << "  Member   : " << DA.lengthStudent << "/" << DA.lengthMaxOfClass << endl; gotoXY(x, y++);
	cout << "  Faculty  : " << DA.classOfFaculty << endl;                              gotoXY(x, y++);
	cout << "===============================" << endl;                                 gotoXY(x, y++);
	cout << "             Enter [x] to exit." << endl; ShowCur(0); */
	SetColor(7);
	gotoXY(x + 2, y + 1); cout << "Name       :  " << DA.NameClass;
	gotoXY(x + 2, y + 2); cout << "Member     :  " << DA.lengthStudent << "/" << DA.lengthMaxOfClass;
	gotoXY(x + 2, y + 3); cout << "Faculty    :  " << DA.classOfFaculty;;
	TextColor(1);// Chỉnh về màu nền cơ bản (1: màu đen)
	SetColor(t_color);
	for (int ix = x; ix <= x + w; ix++) {
		gotoXY(ix, y);
		cout << char(196);
		gotoXY(ix, y + h);
		cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++) {
		gotoXY(x, iy);
		cout << char(179);
		gotoXY(x + w, iy);
		cout << char(179);
	}
	gotoXY(x, y); cout << char(218);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y); cout << char(191);
	gotoXY(x + w, y + h); cout << char(217);
}
void BoxInformationOfCourse(int x, int y, int w, int h, int b_color, int t_color, Course& course) {
	if (h <= 1 || w <= 1)return;
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	gotoXY(x + 2, y + 1); cout << "ID         :  " << course.CourseID;
	gotoXY(x + 2, y + 2); cout << "Name       :  " << course.CourseName;
	gotoXY(x + 2, y + 3); cout << "Class      :  " << course.ClassName;
	gotoXY(x + 2, y + 4); cout << "Teacher    :  " << course.NameTeacher;
	gotoXY(x + 2, y + 5); cout << "Credits    :  " << course.NumberCredits;
	gotoXY(x + 2, y + 6); cout << "Member     :  " << course.NumberOfStudent << "/" << course.MaximumStudent;
	gotoXY(x + 2, y + 7); cout << "Time       :  " << course.Session << " - " << course.DayOfTheWeek;
	TextColor(1);// Chỉnh về màu nền cơ bản (1: màu đen)
	SetColor(t_color);
	for (int ix = x; ix <= x + w; ix++) {
		gotoXY(ix, y);
		cout << char(196);
		gotoXY(ix, y + h);
		cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++) {
		gotoXY(x, iy);
		cout << char(179);
		gotoXY(x + w, iy);
		cout << char(179);
	}
	gotoXY(x, y); cout << char(218);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y); cout << char(191);
	gotoXY(x + w, y + h); cout << char(217);
}
void BoxUpdateCourse(int x, int y, int w, int h, int b_color, int t_color, Course& course) {
	if (h <= 1 || w <= 1)return;
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	gotoXY(x + 2, y + 1); cout << "ID             " << course.CourseID;
	gotoXY(x + 2, y + 3); cout << "Name           " << course.CourseName;
	gotoXY(x + 2, y + 5); cout << "Teacher        " << course.NameTeacher;
	gotoXY(x + 2, y + 7); cout << "Credits        " << course.NumberCredits;
	gotoXY(x + 2, y + 9); cout << "Maximum        " << course.MaximumStudent;
	gotoXY(x + 2, y + 11); cout << "Session        " << course.Session;
	gotoXY(x + 2, y + 13); cout << "DayOfTheWeek   " << course.DayOfTheWeek;
	TextColor(1);// Chỉnh về màu nền cơ bản (1: màu đen)
	SetColor(t_color);
	for (int ix = x; ix <= x + w; ix++) {
		gotoXY(ix, y);
		cout << char(196);
		gotoXY(ix, y + h);
		cout << char(196);
		gotoXY(ix, y + 2);
		cout << char(196);
		gotoXY(ix, y + 4);
		cout << char(196);
		gotoXY(ix, y + 6);
		cout << char(196);
		gotoXY(ix, y + 8);
		cout << char(196);
		gotoXY(ix, y + 10);
		cout << char(196);
		gotoXY(ix, y + 12);
		cout << char(196);
	}

	for (int iy = y; iy <= y + h; iy++) {
		gotoXY(x, iy);
		cout << char(179);
		gotoXY(x + w, iy);
		cout << char(179);
		gotoXY(x + 15, iy);
		cout << char(179);
		gotoXY(x + 40, iy);
		cout << char(179);
	}
	gotoXY(x + 15, y + 0); cout << char(194);
	gotoXY(x + 15, y + 14); cout << char(193);
	gotoXY(x + 40, y + 0); cout << char(194);
	gotoXY(x + 40, y + 14); cout << char(193);
	for (int i = 1; i <= 6; i++) {
		gotoXY(x + 15, y + i * 2); cout << char(197);
		gotoXY(x + 40, y + i * 2); cout << char(197);
		gotoXY(x + 0, y + i * 2); cout << char(195);
		gotoXY(x + w, y + i * 2); cout << char(180);
	}


	gotoXY(x, y); cout << char(195);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y); cout << char(180);
	gotoXY(x + w, y + h); cout << char(217);
	ShowCur(1);
	/*delete[]course.CourseID;*/ course.CourseID = NULL;
	/*delete[]course.CourseName;*/ course.CourseName = NULL;
	/*delete[]course.NameTeacher;*/ course.NameTeacher = NULL;
	/*delete[]course.Session;*/ course.Session = NULL;
	/*delete[]course.DayOfTheWeek; */course.DayOfTheWeek = NULL;
	gotoXY(x + 42, y + 1); gets_s(s); cpychar(course.CourseID, s);
	gotoXY(x + 42, y + 3); gets_s(s); cpychar(course.CourseName, s);
	gotoXY(x + 42, y + 5); gets_s(s); cpychar(course.NameTeacher, s);
	gotoXY(x + 42, y + 7); cin >> course.NumberCredits;
	gotoXY(x + 42, y + 9); cin >> course.MaximumStudent; cin.ignore();
	gotoXY(x + 42, y + 11); gets_s(s); cpychar(course.Session, s);
	gotoXY(x + 42, y + 13); gets_s(s); cpychar(course.DayOfTheWeek, s);
	ShowCur(0);
}
void BoxTranscriptOfClass(int x, int y, int w, int h, int b_color, int t_color, DArray DA) {
	if (h <= 1 || w <= 1)return;
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	TextColor(1);// Chỉnh về màu nền cơ bản (1: màu đen)
	SetColor(t_color);
	for (int ix = x; ix <= x + w; ix++) {
		gotoXY(ix, y); cout << char(196);// vẽ hai chiều ngang
		gotoXY(ix, y + h); cout << char(196);
		gotoXY(ix, y + 2); cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++) {
		gotoXY(x, iy); cout << char(179);// vẽ chiều dọc đầu
		gotoXY(x + w, iy); cout << char(179);// vẽ chiều dọc cuối
		gotoXY(x + 5, iy); cout << char(179);
		gotoXY(x + 20, iy); cout << char(179);
		gotoXY(x + 45, iy); cout << char(179);
		for (int i = 0; i < DA.lengthOfCourseOfClass - 1; i++) {
			gotoXY(x + 45 + 11 * (i + 1), iy); cout << char(179);
		}
	}
	/* Xử lý các cạnh dọc */
	gotoXY(x + 5, y); cout << char(194);
	gotoXY(x + 5, y + h); cout << char(193);
	gotoXY(x + 5, y + 2); cout << char(197);

	gotoXY(x + 20, y); cout << char(194);
	gotoXY(x + 20, y + h); cout << char(193);
	gotoXY(x + 20, y + 2); cout << char(197);

	gotoXY(x + 45, y); cout << char(194);
	gotoXY(x + 45, y + h); cout << char(193);
	gotoXY(x + 45, y + 2); cout << char(197);

	for (int i = 0; i < DA.lengthOfCourseOfClass - 1; i++) {
		gotoXY(x + 45 + 11 * (i + 1), y); cout << char(194);
		gotoXY(x + 45 + 11 * (i + 1), y + h); cout << char(193);
		gotoXY(x + 45 + 11 * (i + 1), y + 2); cout << char(197);
	}
	/* Xử lý hình bên ngoài */
	gotoXY(x, y); cout << char(218);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y); cout << char(191);
	gotoXY(x + w, y + h); cout << char(217);

	gotoXY(x, y + 2); cout << char(195);
	gotoXY(x + w, y + 2); cout << char(180);

	/* Contents */
	SetColor(7);
	gotoXY(x + 2, y + 1); cout << "No";
	gotoXY(x + 5 + ((15 / 2) - (strlen("StudentID") / 2)), y + 1); cout << "StudentID";
	gotoXY(x + 18 + ((30 / 2) - (strlen("FullName") / 2)), y + 1); cout << "FullName";
	for (int i = 0; i < DA.lengthOfCourseOfClass; i++) {
		gotoXY(x + 45 + 11 * i + ((10 / 2) - (strlen(DA.course[i].CourseID) / 2)) + 1, y + 1); cout << DA.course[i].CourseID;
	}
	for (int i = 0; i < DA.lengthStudent; i++) {
		y += 1;
		gotoXY(x + 2, y + 2); cout << DA.Member[i].No;
		gotoXY(x + 5 + ((15 / 2) - (strlen(DA.Member[i].StudentID) / 2)), y + 2); cout << DA.Member[i].StudentID;;
		gotoXY(x + 22, y + 2); cout << DA.Member[i].FirstName << " " << DA.Member[i].LastName;
		for (int j = 0; j < DA.lengthOfCourseOfClass; j++) {
			gotoXY(x + 5 + 45 + 11 * j, y + 2);
			if (DA.course[j].Score[i].TotalMark > -1)
				cout << DA.course[j].Score[i].TotalMark;
		}
	}
}
void BoxTranscriptOfCourse(int x, int y, int w, int h, int b_color, int t_color, Course& course) {
	if (h <= 1 || w <= 1)return;
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	TextColor(1);// Chỉnh về màu nền cơ bản (1: màu đen)
	SetColor(t_color);
	for (int ix = x; ix <= x + w; ix++) {
		gotoXY(ix, y); cout << char(196);// vẽ hai chiều ngang
		gotoXY(ix, y + h); cout << char(196);
		gotoXY(ix, y + 2); cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++) {
		gotoXY(x, iy); cout << char(179);// vẽ chiều dọc đầu
		gotoXY(x + w, iy); cout << char(179);// vẽ chiều dọc cuối
		gotoXY(x + 5, iy); cout << char(179);
		gotoXY(x + 20, iy); cout << char(179);
		gotoXY(x + 45, iy); cout << char(179);
		gotoXY(x + 60, iy); cout << char(179);
		gotoXY(x + 75, iy); cout << char(179);
		gotoXY(x + 90, iy); cout << char(179);
	}
	/* Xử lý các cạnh dọc */
	gotoXY(x + 5, y); cout << char(194);
	gotoXY(x + 5, y + h); cout << char(193);
	gotoXY(x + 5, y + 2); cout << char(197);

	gotoXY(x + 20, y); cout << char(194);
	gotoXY(x + 20, y + h); cout << char(193);
	gotoXY(x + 20, y + 2); cout << char(197);

	gotoXY(x + 45, y); cout << char(194);
	gotoXY(x + 45, y + h); cout << char(193);
	gotoXY(x + 45, y + 2); cout << char(197);

	gotoXY(x + 60, y); cout << char(194);
	gotoXY(x + 60, y + h); cout << char(193);
	gotoXY(x + 60, y + 2); cout << char(197);

	gotoXY(x + 75, y); cout << char(194);
	gotoXY(x + 75, y + h); cout << char(193);
	gotoXY(x + 75, y + 2); cout << char(197);

	gotoXY(x + 90, y); cout << char(194);
	gotoXY(x + 90, y + h); cout << char(193);
	gotoXY(x + 90, y + 2); cout << char(197);

	/* Xử lý hình bên ngoài */
	gotoXY(x, y); cout << char(218);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y); cout << char(191);
	gotoXY(x + w, y + h); cout << char(217);

	gotoXY(x, y + 2); cout << char(195);
	gotoXY(x + w, y + 2); cout << char(180);

	/* Contents */
	SetColor(7);
	gotoXY(x + 2, y + 1); cout << "No";
	gotoXY(x + 5 + ((15 / 2) - (strlen("StudentID") / 2)), y + 1); cout << "StudentID";
	gotoXY(x + 18 + ((30 / 2) - (strlen("FullName") / 2)), y + 1); cout << "FullName";
	gotoXY(x + 45 + ((15 / 2) - (strlen("OtherMark") / 2)), y + 1); cout << "OtherMark";
	gotoXY(x + 60 + ((15 / 2) - (strlen("MidtermMark") / 2)), y + 1); cout << "MidtermMark";
	gotoXY(x + 75 + ((15 / 2) - (strlen("FinalMark") / 2)), y + 1); cout << "FinalMark";
	gotoXY(x + 90 + ((15 / 2) - (strlen("TotalMark") / 2)), y + 1); cout << "TotalMark";
	for (int i = 0; i < course.NumberOfStudent; i++) {
		++y;
		gotoXY(x + 2, y + 2); cout << i + 1;
		gotoXY(x + 5 + ((15 / 2) - (strlen(course.Score[i].StudentID) / 2)), y + 2); cout << course.Score[i].StudentID;
		gotoXY(x + 22, y + 2); cout << course.Score[i].FullName;
		gotoXY(x + 45 + 7, y + 2); if (course.Score[i].OtherMark > -1) cout << course.Score[i].OtherMark;
		gotoXY(x + 60 + 7, y + 2); if (course.Score[i].MidTermMark > -1) cout << course.Score[i].MidTermMark;
		gotoXY(x + 75 + 7, y + 2); if (course.Score[i].FinalMark > -1) cout << course.Score[i].FinalMark;
		gotoXY(x + 90 + 7, y + 2); if (course.Score[i].TotalMark > -1)cout << course.Score[i].TotalMark;
	}
}
void BoxTranscriptOfStudent(int x, int y, int w, int h, int b_color, int t_color, Faculty faculty, char* MSSV) {
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	/* Contents */
	SetColor(7);
	gotoXY(x + 2, y + 1); cout << "No";
	gotoXY(x + 5 + ((15 / 2) - (strlen("CourseID") / 2)), y + 1); cout << "CourseID";
	gotoXY(x + 18 + ((35 / 2) - (strlen("NameCourse") / 2)), y + 1); cout << "NameCourse";
	gotoXY(x + 55 + ((15 / 2) - (strlen("OtherMark") / 2)), y + 1); cout << "OtherMark";
	gotoXY(x + 70 + ((15 / 2) - (strlen("MidtermMark") / 2)), y + 1); cout << "MidtermMark";
	gotoXY(x + 85 + ((15 / 2) - (strlen("FinalMark") / 2)), y + 1); cout << "FinalMark";
	gotoXY(x + 100 + ((15 / 2) - (strlen("TotalMark") / 2)), y + 1); cout << "TotalMark";
	h = y;
	for (int i = 0; i < faculty.lengthOfClass; i++) {
		for (int j = 0; j < faculty.Class[i].lengthOfCourseOfClass; j++) {
			for (int k = 0; k < faculty.Class[i].course[j].NumberOfStudent; k++) {
				if (strcmp(MSSV, faculty.Class[i].course[j].Member[k].StudentID) == 0) {
					++y;
					gotoXY(x + 2, y + 2); cout << y - 1;
					gotoXY(x + 5 + ((15 / 2) - (strlen(faculty.Class[i].course[j].CourseID) / 2)), y + 2); cout << faculty.Class[i].course[j].CourseID;
					gotoXY(x + 22, y + 2); cout << faculty.Class[i].course[j].CourseName;
					gotoXY(x + 55 + 7, y + 2); if (faculty.Class[i].course[j].Score[k].OtherMark > -1)cout << faculty.Class[i].course[j].Score[k].OtherMark;
					gotoXY(x + 70 + 7, y + 2); if (faculty.Class[i].course[j].Score[k].MidTermMark > -1)cout << faculty.Class[i].course[j].Score[k].MidTermMark;
					gotoXY(x + 85 + 7, y + 2); if (faculty.Class[i].course[j].Score[k].FinalMark > -1)cout << faculty.Class[i].course[j].Score[k].FinalMark;
					gotoXY(x + 100 + 7, y + 2); if (faculty.Class[i].course[j].Score[k].TotalMark > -1)cout << faculty.Class[i].course[j].Score[k].TotalMark;
				}
			}
		}
	}
	int temp = y;// số lượng môn học
	y = h; // gán lại vị trí cho y
	h = temp; //
	h += 2;
	TextColor(1);// Chỉnh về màu nền cơ bản (1: màu đen)
	SetColor(t_color);
	for (int ix = x; ix <= x + w; ix++) {
		gotoXY(ix, y); cout << char(196);// vẽ hai chiều ngang
		gotoXY(ix, y + h); cout << char(196);
		gotoXY(ix, y + 2); cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++) {
		gotoXY(x, iy); cout << char(179);// vẽ chiều dọc đầu
		gotoXY(x + w, iy); cout << char(179);// vẽ chiều dọc cuối
		gotoXY(x + 5, iy); cout << char(179);
		gotoXY(x + 20, iy); cout << char(179);
		gotoXY(x + 55, iy); cout << char(179);
		gotoXY(x + 70, iy); cout << char(179);
		gotoXY(x + 85, iy); cout << char(179);
		gotoXY(x + 100, iy); cout << char(179);
	}
	/* Xử lý các cạnh dọc */
	gotoXY(x + 5, y); cout << char(194);
	gotoXY(x + 5, y + h); cout << char(193);
	gotoXY(x + 5, y + 2); cout << char(197);

	gotoXY(x + 20, y); cout << char(194);
	gotoXY(x + 20, y + h); cout << char(193);
	gotoXY(x + 20, y + 2); cout << char(197);

	gotoXY(x + 55, y); cout << char(194);
	gotoXY(x + 55, y + h); cout << char(193);
	gotoXY(x + 55, y + 2); cout << char(197);

	gotoXY(x + 70, y); cout << char(194);
	gotoXY(x + 70, y + h); cout << char(193);
	gotoXY(x + 70, y + 2); cout << char(197);

	gotoXY(x + 85, y); cout << char(194);
	gotoXY(x + 85, y + h); cout << char(193);
	gotoXY(x + 85, y + 2); cout << char(197);

	gotoXY(x + 100, y); cout << char(194);
	gotoXY(x + 100, y + h); cout << char(193);
	gotoXY(x + 100, y + 2); cout << char(197);

	/* Xử lý hình bên ngoài */
	gotoXY(x, y); cout << char(218);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y); cout << char(191);
	gotoXY(x + w, y + h); cout << char(217);

	gotoXY(x, y + 2); cout << char(195);
	gotoXY(x + w, y + 2); cout << char(180);
}
void BoxStudentOfClass(int x, int y, int w, int h, int b_color, int t_color, DArray DA) {
	if (h <= 1 || w <= 1)return;
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	TextColor(1);// Chỉnh về màu nền cơ bản (1: màu đen)
	SetColor(t_color);
	for (int ix = x; ix <= x + w; ix++) {
		gotoXY(ix, y); cout << char(196);// vẽ hai chiều ngang
		gotoXY(ix, y + h); cout << char(196);
		gotoXY(ix, y + 2); cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++) {
		gotoXY(x, iy); cout << char(179);// vẽ chiều dọc đầu
		gotoXY(x + w, iy); cout << char(179);// vẽ chiều dọc cuối

		gotoXY(x + 5, iy); cout << char(179);
		gotoXY(x + 20, iy); cout << char(179);
		gotoXY(x + 50, iy); cout << char(179);
		gotoXY(x + 65, iy); cout << char(179);
		gotoXY(x + 80, iy); cout << char(179);
		gotoXY(x + 100, iy); cout << char(179);
	}
	/* Xử lý các cạnh dọc */
	gotoXY(x + 5, y); cout << char(194);
	gotoXY(x + 5, y + h); cout << char(193);
	gotoXY(x + 5, y + 2); cout << char(197);

	gotoXY(x + 20, y); cout << char(194);
	gotoXY(x + 20, y + h); cout << char(193);
	gotoXY(x + 20, y + 2); cout << char(197);

	gotoXY(x + 50, y); cout << char(194);
	gotoXY(x + 50, y + h); cout << char(193);
	gotoXY(x + 50, y + 2); cout << char(197);

	gotoXY(x + 65, y); cout << char(194);
	gotoXY(x + 65, y + h); cout << char(193);
	gotoXY(x + 65, y + 2); cout << char(197);

	gotoXY(x + 80, y); cout << char(194);
	gotoXY(x + 80, y + h); cout << char(193);
	gotoXY(x + 80, y + 2); cout << char(197);

	gotoXY(x + 100, y); cout << char(194);
	gotoXY(x + 100, y + h); cout << char(193);
	gotoXY(x + 100, y + 2); cout << char(197);

	/* Xử lý hình bên ngoài */
	gotoXY(x, y); cout << char(218);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y); cout << char(191);
	gotoXY(x + w, y + h); cout << char(217);

	gotoXY(x, y + 2); cout << char(195);
	gotoXY(x + w, y + 2); cout << char(180);

	/* Contents */
	SetColor(7);
	gotoXY(x + 2, y + 1); cout << "No";
	gotoXY(x + 5 + ((15 / 2) - (strlen("StudentID") / 2)), y + 1); cout << "StudentID";
	gotoXY(x + 20 + ((30 / 2) - (strlen("FullName") / 2)), y + 1); cout << "FullName";
	gotoXY(x + 50 + ((15 / 2) - (strlen("BirthOfDate") / 2)), y + 1); cout << "BirthOfDate";
	gotoXY(x + 65 + ((15 / 2) - (strlen("Gender") / 2)), y + 1); cout << "Gender";
	gotoXY(x + 80 + ((20 / 2) - (strlen("SocialID") / 2)), y + 1); cout << "SocialID";
	for (int i = 0; i < DA.lengthStudent; i++) {
		y += 1;
		gotoXY(x + 2, y + 2); cout << DA.Member[i].No;
		gotoXY(x + 5 + ((15 / 2) - (strlen(DA.Member[i].StudentID) / 2)), y + 2); cout << DA.Member[i].StudentID;;
		gotoXY(x + 20 + 2, y + 2); cout << DA.Member[i].FirstName << " " << DA.Member[i].LastName;
		gotoXY(x + 50 + 2, y + 2); cout << DA.Member[i].DateOfBirth.day << "/" << DA.Member[i].DateOfBirth.month << "/" << DA.Member[i].DateOfBirth.year;
		gotoXY(x + 65 + 6, y + 2); cout << DA.Member[i].Gender;
		gotoXY(x + 80 + 5, y + 2); cout << DA.Member[i].CCCD;
	}
}
void BoxStudentOfCourse(int x, int y, int w, int h, int b_color, int t_color, Course course) {
	if (h <= 1 || w <= 1)return;
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	TextColor(1);// Chỉnh về màu nền cơ bản (1: màu đen)
	SetColor(t_color);
	for (int ix = x; ix <= x + w; ix++) {
		gotoXY(ix, y); cout << char(196);// vẽ hai chiều ngang
		gotoXY(ix, y + h); cout << char(196);
		gotoXY(ix, y + 2); cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++) {
		gotoXY(x, iy); cout << char(179);// vẽ chiều dọc đầu
		gotoXY(x + w, iy); cout << char(179);// vẽ chiều dọc cuối

		gotoXY(x + 5, iy); cout << char(179);
		gotoXY(x + 20, iy); cout << char(179);
		gotoXY(x + 50, iy); cout << char(179);
		gotoXY(x + 65, iy); cout << char(179);
		gotoXY(x + 80, iy); cout << char(179);
		gotoXY(x + 100, iy); cout << char(179);
	}
	/* Xử lý các cạnh dọc */
	gotoXY(x + 5, y); cout << char(194);
	gotoXY(x + 5, y + h); cout << char(193);
	gotoXY(x + 5, y + 2); cout << char(197);

	gotoXY(x + 20, y); cout << char(194);
	gotoXY(x + 20, y + h); cout << char(193);
	gotoXY(x + 20, y + 2); cout << char(197);

	gotoXY(x + 50, y); cout << char(194);
	gotoXY(x + 50, y + h); cout << char(193);
	gotoXY(x + 50, y + 2); cout << char(197);

	gotoXY(x + 65, y); cout << char(194);
	gotoXY(x + 65, y + h); cout << char(193);
	gotoXY(x + 65, y + 2); cout << char(197);

	gotoXY(x + 80, y); cout << char(194);
	gotoXY(x + 80, y + h); cout << char(193);
	gotoXY(x + 80, y + 2); cout << char(197);

	gotoXY(x + 100, y); cout << char(194);
	gotoXY(x + 100, y + h); cout << char(193);
	gotoXY(x + 100, y + 2); cout << char(197);

	/* Xử lý hình bên ngoài */
	gotoXY(x, y); cout << char(218);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y); cout << char(191);
	gotoXY(x + w, y + h); cout << char(217);

	gotoXY(x, y + 2); cout << char(195);
	gotoXY(x + w, y + 2); cout << char(180);

	/* Contents */
	SetColor(7);
	gotoXY(x + 2, y + 1); cout << "No";
	gotoXY(x + 5 + ((15 / 2) - (strlen("StudentID") / 2)), y + 1); cout << "StudentID";
	gotoXY(x + 20 + ((30 / 2) - (strlen("FullName") / 2)), y + 1); cout << "FullName";
	gotoXY(x + 50 + ((15 / 2) - (strlen("BirthOfDate") / 2)), y + 1); cout << "BirthOfDate";
	gotoXY(x + 65 + ((15 / 2) - (strlen("Gender") / 2)), y + 1); cout << "Gender";
	gotoXY(x + 80 + ((20 / 2) - (strlen("SocialID") / 2)), y + 1); cout << "SocialID";
	for (int i = 0; i < course.NumberOfStudent; i++) {
		y += 1;
		gotoXY(x + 2, y + 2); cout << course.Member[i].No;
		gotoXY(x + 5 + ((15 / 2) - (strlen(course.Member[i].StudentID) / 2)), y + 2); cout << course.Member[i].StudentID;;
		gotoXY(x + 20 + 2, y + 2); cout << course.Member[i].FirstName << " " << course.Member[i].LastName;
		gotoXY(x + 50 + 2, y + 2); cout << course.Member[i].DateOfBirth.day << "/" << course.Member[i].DateOfBirth.month << "/" << course.Member[i].DateOfBirth.year;
		gotoXY(x + 65 + 6, y + 2); cout << course.Member[i].Gender;
		gotoXY(x + 80 + 5, y + 2); cout << course.Member[i].CCCD;
	}
}
void BoxCreateSchoolYear(int x, int y, int w, int h, int b_color, int t_color, School& Sch) {
	if (h <= 1 || w <= 1)return;
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	TextColor(1);// Chỉnh về màu nền cơ bản (1: màu đen)
	SetColor(t_color);
	for (int ix = x; ix <= x + w; ix++) {
		gotoXY(ix, y); cout << char(196);// vẽ hai chiều ngang
		gotoXY(ix, y + h); cout << char(196);
		gotoXY(ix, y + 2); cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++) {
		gotoXY(x, iy); cout << char(179);// vẽ chiều dọc đầu
		gotoXY(x + w, iy); cout << char(179);// vẽ chiều dọc cuối

		gotoXY(x + 30, iy); cout << char(179);
	}
	/* Xử lý các cạnh dọc */
	gotoXY(x + 30, y); cout << char(194);
	gotoXY(x + 30, y + h); cout << char(193);
	gotoXY(x + 30, y + 2); cout << char(197);

	/* Xử lý hình bên ngoài */
	gotoXY(x, y); cout << char(218);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y); cout << char(191);
	gotoXY(x + w, y + h); cout << char(217);

	gotoXY(x, y + 2); cout << char(195);
	gotoXY(x + w, y + 2); cout << char(180);

	/* Contents */
	SetColor(7);
	gotoXY(x + 2, y + 1); cout << "Current school year";
	gotoXY(x + 32, y + 1); cout << Sch.SchoolYear[0] << "-" << Sch.SchoolYear[1];
	gotoXY(x + 2, y + 3); cout << "Next school year";
	gotoXY(x + 32, y + 3); cout << Sch.SchoolYear[1] << "-" << Sch.SchoolYear[1] + 1;
}
void BoxCreateSemester(int x, int y, int w, int h, int b_color, int t_color, Semester& temp) {
	if (h <= 1 || w <= 1)return;
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	TextColor(1);// Chỉnh về màu nền cơ bản (1: màu đen)
	SetColor(t_color);
	for (int ix = x; ix <= x + w; ix++) {
		gotoXY(ix, y); cout << char(196);// vẽ hai chiều ngang
		gotoXY(ix, y + h); cout << char(196);
		gotoXY(ix, y + 2); cout << char(196);
		gotoXY(ix, y + 4); cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++) {
		gotoXY(x, iy); cout << char(179);// vẽ chiều dọc đầu
		gotoXY(x + w, iy); cout << char(179);// vẽ chiều dọc cuối

		gotoXY(x + 30, iy); cout << char(179);
	}
	/* Xử lý các cạnh dọc */
	gotoXY(x + 30, y); cout << char(194);
	gotoXY(x + 30, y + h); cout << char(193);
	gotoXY(x + 30, y + 2); cout << char(197);
	gotoXY(x + 30, y + 4); cout << char(197);

	/* Xử lý hình bên ngoài */
	gotoXY(x, y); cout << char(195);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y); cout << char(180);
	gotoXY(x + w, y + h); cout << char(217);

	gotoXY(x, y + 2); cout << char(195);
	gotoXY(x + w, y + 2); cout << char(180);
	gotoXY(x, y + 4); cout << char(195);
	gotoXY(x + w, y + 4); cout << char(180);

	/* Contents */
	SetColor(7);
	gotoXY(x + 2, y + 1); cout << "Enter name semester";
	gotoXY(x + 2, y + 3); cout << "Enter start date (dd/mm/yy)";
	gotoXY(x + 2, y + 5); cout << "Enter end date (dd/mm/yy)";
	ShowCur(1);
	gotoXY(x + 32, y + 1); cout << temp.NameSemester;
	//gets_s(s);
	//cpychar(temp.NameSemester, s);

	gotoXY(x + 32, y + 3);
	cin >> temp.StartDate.day; gotoXY(x + 32 + 2, y + 3);
	cout << "/"; cin >> temp.StartDate.month; gotoXY(x + 32 + 5, y + 3);
	cout << "/"; cin >> temp.StartDate.year;

	gotoXY(x + 32, y + 5); cin >> temp.EndDate.day;  gotoXY(x + 32 + 2, y + 5);
	cout << "/"; cin >> temp.EndDate.month;  gotoXY(x + 32 + 5, y + 5);
	cout << "/"; cin >> temp.EndDate.year;
	ShowCur(0);
}
void BoxCreateCourse(int x, int y, int w, int h, int b_color, int t_color, Course& temp) {
	if (h <= 1 || w <= 1)return;
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	TextColor(1);// Chỉnh về màu nền cơ bản (1: màu đen)
	SetColor(t_color);
	for (int ix = x; ix <= x + w; ix++) {
		gotoXY(ix, y); cout << char(196);// vẽ hai chiều ngang
		gotoXY(ix, y + h); cout << char(196);
		gotoXY(ix, y + 2); cout << char(196);
		gotoXY(ix, y + 4); cout << char(196);
		gotoXY(ix, y + 6); cout << char(196);
		gotoXY(ix, y + 8); cout << char(196);
		gotoXY(ix, y + 10); cout << char(196);
		gotoXY(ix, y + 12); cout << char(196);
		gotoXY(ix, y + 14); cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++) {
		gotoXY(x, iy); cout << char(179);// vẽ chiều dọc đầu
		gotoXY(x + w, iy); cout << char(179);// vẽ chiều dọc cuối

		gotoXY(x + 25, iy); cout << char(179);
	}
	/* Xử lý các cạnh dọc */
	gotoXY(x + 25, y); cout << char(194);
	gotoXY(x + 25, y + h); cout << char(193);
	gotoXY(x + 25, y + 2); cout << char(197);
	gotoXY(x + 25, y + 4); cout << char(197);
	gotoXY(x + 25, y + 6); cout << char(197);
	gotoXY(x + 25, y + 8); cout << char(197);
	gotoXY(x + 25, y + 10); cout << char(197);
	gotoXY(x + 25, y + 12); cout << char(197);
	gotoXY(x + 25, y + 14); cout << char(197);

	/* Xử lý hình bên ngoài */
	gotoXY(x, y); cout << char(195);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y); cout << char(180);
	gotoXY(x + w, y + h); cout << char(217);

	gotoXY(x, y + 2); cout << char(195);
	gotoXY(x + w, y + 2); cout << char(180);
	gotoXY(x, y + 4); cout << char(195);
	gotoXY(x + w, y + 4); cout << char(180);
	gotoXY(x, y + 6); cout << char(195);
	gotoXY(x + w, y + 6); cout << char(180);
	gotoXY(x, y + 8); cout << char(195);
	gotoXY(x + w, y + 8); cout << char(180);
	gotoXY(x, y + 10); cout << char(195);
	gotoXY(x + w, y + 10); cout << char(180);
	gotoXY(x, y + 12); cout << char(195);
	gotoXY(x + w, y + 12); cout << char(180);
	gotoXY(x, y + 14); cout << char(195);
	gotoXY(x + w, y + 14); cout << char(180);
	/*cout << " Enter name course: "; gets_s(s);
cpychar(temp.CourseName, s); gotoXY(x, y++);
cout << " Enter courseID: "; gets_s(s);
cpychar(temp.CourseID, s); gotoXY(x, y++);
cout << " Enter name teacher: "; gets_s(s);
cpychar(temp.NameTeacher, s); gotoXY(x, y++);
cout << " Enter number credits: "; cin >> temp.NumberCredits;
gotoXY(x, y++);
cout << " Enter maximum student: "; cin >> temp.MaximumStudent;
gotoXY(x, y++);
cin.ignore();
cout << " Enter day of the week: "; gets_s(s);
cpychar(temp.DayOfTheWeek, s); gotoXY(x, y++);
cout << " Enter session: "; gets_s(s);
cpychar(temp.Session, s);
do {
	gotoXY(x, y++);
	cout << " Enter name class: "; gets_s(s);
	if (CheckClass(Fac, s) == false) {
		cpychar(temp.ClassName, s);
	}
	else {
		gotoXY(x, y - 1);
		cout << " Class does not exist!.Please enter again: ";
		gotoXY(x, y);
	}
} while (CheckClass(Fac, s) == true);
gotoXY(x, y++);*/
/* Contents */
	SetColor(7);
	gotoXY(x + 2, y + 1); cout << "Enter name course";
	gotoXY(x + 2, y + 3); cout << "Enter courseID";
	gotoXY(x + 2, y + 5); cout << "Enter name teacher";
	gotoXY(x + 2, y + 7); cout << "Enter number credits";
	gotoXY(x + 2, y + 9); cout << "Enter maximum student";
	gotoXY(x + 2, y + 11); cout << "Enter day of the week";
	gotoXY(x + 2, y + 13); cout << "Enter session";
	gotoXY(x + 2, y + 15); cout << "Enter name class";
	ShowCur(1);
	gotoXY(x + 27, y + 1); gets_s(s);
	cpychar(temp.CourseName, s);
	gotoXY(x + 27, y + 3); gets_s(s);
	cpychar(temp.CourseID, s);
	gotoXY(x + 27, y + 5); gets_s(s);
	cpychar(temp.NameTeacher, s);
	gotoXY(x + 27, y + 7);
	cin >> temp.NumberCredits;
	gotoXY(x + 27, y + 9);
	cin >> temp.MaximumStudent; cin.ignore();
	gotoXY(x + 27, y + 11); gets_s(s);
	cpychar(temp.DayOfTheWeek, s);
	gotoXY(x + 27, y + 13); gets_s(s);
	cpychar(temp.Session, s);
	gotoXY(x + 27, y + 15); gets_s(s);
	cpychar(temp.ClassName, s);
	ShowCur(0);
}
void BoxCreateClass(int x, int y, int w, int h, int b_color, int t_color, DArray& temp) {
	if (h <= 1 || w <= 1)return;
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	TextColor(1);// Chỉnh về màu nền cơ bản (1: màu đen)
	SetColor(t_color);
	for (int ix = x; ix <= x + w; ix++) {
		gotoXY(ix, y); cout << char(196);// vẽ hai chiều ngang
		gotoXY(ix, y + h); cout << char(196);
		gotoXY(ix, y + 2); cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++) {
		gotoXY(x, iy); cout << char(179);// vẽ chiều dọc đầu
		gotoXY(x + w, iy); cout << char(179);// vẽ chiều dọc cuối

		gotoXY(x + 25, iy); cout << char(179);
	}
	/* Xử lý các cạnh dọc */
	gotoXY(x + 25, y); cout << char(194);
	gotoXY(x + 25, y + h); cout << char(193);
	gotoXY(x + 25, y + 2); cout << char(197);

	/* Xử lý hình bên ngoài */
	gotoXY(x, y); cout << char(195);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y); cout << char(180);
	gotoXY(x + w, y + h); cout << char(217);

	gotoXY(x, y + 2); cout << char(195);
	gotoXY(x + w, y + 2); cout << char(180);
	SetColor(7);
	/*cout << "========== CREATE CLASS =========";	gotoXY(x, y++);
	cout << " Enter name class: "; gets_s(s);
	cpychar(temp.NameClass, s); gotoXY(x, y++);
	cout << " Enter maximum student: "; cin >> temp.lengthMaxOfClass;
	gotoXY(x, y++);
	temp.classOfFaculty = new char[strlen(Fac.NameFaculty) + 1];
	strcpy(temp.classOfFaculty, Fac.NameFaculty);
	cout << "=================================";	gotoXY(x + 1, y++);
	cout << "Create class successfully!."; gotoXY(x, y++); */
	gotoXY(x + 2, y + 1); cout << "Enter name class";
	gotoXY(x + 2, y + 3); cout << "Enter maximum student";
	ShowCur(1);
	gotoXY(x + 27, y + 1); gets_s(s);
	cpychar(temp.NameClass, s);
	gotoXY(x + 27, y + 3); cin >> temp.lengthMaxOfClass;
	cin.ignore();
	ShowCur(0);
}
void BoxCreateStudent(int x, int y, int w, int h, int b_color, int t_color, Information& temp) {
	if (h <= 1 || w <= 1)return;
	TextColor(b_color);
	for (int iy = y + 1; iy < y + h; iy++) {
		for (int ix = x + 1; ix < x + w; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	TextColor(1);// Chỉnh về màu nền cơ bản (1: màu đen)
	SetColor(t_color);
	for (int ix = x; ix <= x + w; ix++) {
		gotoXY(ix, y); cout << char(196);// vẽ hai chiều ngang
		gotoXY(ix, y + h); cout << char(196);
		gotoXY(ix, y + 2); cout << char(196);
		gotoXY(ix, y + 4); cout << char(196);
		gotoXY(ix, y + 6); cout << char(196);
		gotoXY(ix, y + 8); cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++) {
		gotoXY(x, iy); cout << char(179);// vẽ chiều dọc đầu
		gotoXY(x + w, iy); cout << char(179);// vẽ chiều dọc cuối
		gotoXY(x + 25, iy); cout << char(179);
	}
	/* Xử lý các cạnh dọc */
	gotoXY(x + 25, y); cout << char(194);
	gotoXY(x + 25, y + h); cout << char(193);
	gotoXY(x + 25, y + 2); cout << char(197);
	gotoXY(x + 25, y + 4); cout << char(197);
	gotoXY(x + 25, y + 6); cout << char(197);
	gotoXY(x + 25, y + 8); cout << char(197);
	/* Xử lý hình bên ngoài */
	gotoXY(x, y); cout << char(195);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y); cout << char(180);
	gotoXY(x + w, y + h); cout << char(217);

	gotoXY(x, y + 2); cout << char(195);
	gotoXY(x + w, y + 2); cout << char(180);
	gotoXY(x, y + 4); cout << char(195);
	gotoXY(x + w, y + 4); cout << char(180);
	gotoXY(x, y + 6); cout << char(195);
	gotoXY(x + w, y + 6); cout << char(180);
	gotoXY(x, y + 8); cout << char(195);
	gotoXY(x + w, y + 8); cout << char(180);

	SetColor(7);
	gotoXY(x + 2, y + 1); cout << "Enter FirstName";
	gotoXY(x + 2, y + 3); cout << "Enter LastNam";
	gotoXY(x + 2, y + 5); cout << "Enter Gender";
	gotoXY(x + 2, y + 7); cout << "Enter CCCD/CMND";
	gotoXY(x + 2, y + 9); cout << "Enter Date (dd/mm/yy)";
	ShowCur(1);
	gotoXY(x + 27, y + 1); gets_s(s);
	cpychar(temp.FirstName, s);
	gotoXY(x + 27, y + 3); gets_s(s);
	cpychar(temp.LastName, s);
	gotoXY(x + 27, y + 5); gets_s(s);
	cpychar(temp.Gender, s);
	gotoXY(x + 27, y + 7); cin >> temp.CCCD;
	gotoXY(x + 27, y + 9);
	cin >> temp.DateOfBirth.day; gotoXY(x + 27 + 2, y + 9);
	cout << "/"; cin >> temp.DateOfBirth.month; gotoXY(x + 27 + 5, y + 9);
	cout << "/"; cin >> temp.DateOfBirth.year;
	ShowCur(0);
}

void n_Box1(int x, int y, int w, int h, int b_color, int t_color, int& quantity) {
	quantity = 2;
	for (int i = 0; i < quantity; i++) {
		if (i * 2 == 0) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "ACADEMIC STAFF");
		}
		else if (i * 2 == 2) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "STUDENT");
		}
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}
void n_Box2(int x, int y, int w, int h, int b_color, int t_color, int& quantity) {
	quantity = 3;
	for (int i = 0; i < quantity; i++) {
		if (i * 2 == 0) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "SIGN IN");
		}
		else if (i * 2 == 2) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "SIGN UP");
		}
		else if (i * 2 == 4) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "CHANGE PASSWORD");
		}
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}
void n_Box3(int x, int y, int w, int h, int b_color, int t_color, int& quantity) {
	quantity = 4;
	for (int i = 0; i < quantity; i++) {
		if (i * 2 == 0) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Profile");
		}
		else if (i * 2 == 2) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Register for the course");
		}
		else if (i * 2 == 4) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Learning management");
		}
		else if (i * 2 == 6) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Feedback");
		}
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}
void n_Box4(int x, int y, int w, int h, int b_color, int t_color, int& quantity) {
	quantity = 2;
	for (int i = 0; i < quantity; i++) {
		if (i * 2 == 0) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Register");
		}
		else if (i * 2 == 2) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Registration results");
		}
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}
void n_Box5(int x, int y, int w, int h, int b_color, int t_color, int& quantity) {
	quantity = 3;
	for (int i = 0; i < quantity; i++) {
		if (i * 2 == 0) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Information class");
		}
		else if (i * 2 == 2) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Learning outcomes");
		}
		else if (i * 2 == 4) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Your course list");
		}
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}
void n_Box6(int x, int y, int w, int h, int b_color, int t_color, int& quantity) {
	quantity = 5;
	for (int i = 0; i < quantity; i++) {
		if (i * 2 == 0) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Profile");
		}
		else if (i * 2 == 2) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "New");
		}
		else if (i * 2 == 4) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Student");
		}
		else if (i * 2 == 6) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Import score");
		}
		/*else if (i * 2 == 8) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Course infor");
		}*/
		else if (i * 2 == 8) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "View list all students");
		}
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}
void n_Box7(int x, int y, int w, int h, int b_color, int t_color, int& quantity) {
	quantity = 3;
	for (int i = 0; i < quantity; i++) {
		if (i * 2 == 0) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Create a school year");
		}
		else if (i * 2 == 2) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Update semester");
		}
		else if (i * 2 == 4) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "List school year");
		}
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}
void n_Box8(int x, int y, int w, int h, int b_color, int t_color, int& quantity) {
	quantity = 4;
	for (int i = 0; i < quantity; i++) {
		if (i * 2 == 0) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Freshman");
		}
		else if (i * 2 == 2) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Sophomore");
		}
		else if (i * 2 == 4) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Third year students");
		}
		else if (i * 2 == 6) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Fourth year students");
		}
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}
void n_Box8_1(int x, int y, int w, int h, int b_color, int t_color, int& quantity) {
	quantity = 5;
	for (int i = 0; i < quantity; i++) {
		if (i * 2 == 0) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Freshman");
		}
		else if (i * 2 == 2) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Sophomore");
		}
		else if (i * 2 == 4) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Third year students");
		}
		else if (i * 2 == 6) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Fourth year students");
		}
		else if (i * 2 == 8) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Import data for semester");
		}
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}
void n_Box9(int x, int y, int w, int h, int b_color, int t_color, int& quantity) {
	quantity = 3;
	for (int i = 0; i < quantity; i++) {
		if (i * 2 == 0) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Class of freshman");
		}
		else if (i * 2 == 2) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Course of freshman");
		}
		else if (i * 2 == 4) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "List student of freshman");
		}
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}
void n_Box10(int x, int y, int w, int h, int b_color, int t_color, int& quantity) {
	quantity = 3;
	for (int i = 0; i < quantity; i++) {
		if (i * 2 == 0) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Class of sophomore");
		}
		else if (i * 2 == 2) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Course of sophomore");
		}
		else if (i * 2 == 4) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "List student of sophomore");
		}
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}
void n_Box11(int x, int y, int w, int h, int b_color, int t_color, int& quantity) {
	quantity = 3;
	for (int i = 0; i < quantity; i++) {
		if (i * 2 == 0) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Class of third year");
		}
		else if (i * 2 == 2) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Course of third year");
		}
		else if (i * 2 == 4) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "List student of third year");
		}
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}
void n_Box12(int x, int y, int w, int h, int b_color, int t_color, int& quantity) {
	quantity = 3;
	for (int i = 0; i < quantity; i++) {
		if (i * 2 == 0) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Class of fourth year");
		}
		else if (i * 2 == 2) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Course of fourth year");
		}
		else if (i * 2 == 4) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "List student of fourth year");
		}
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}
void n_Box13(int x, int y, int w, int h, int b_color, int t_color, int& quantity, Account& Acc) {
	quantity = 2;
	for (int i = 0; i < quantity; i++) {
		if (i * 2 == 0) {
			BoxSignIn(x, y + (i * 2), w, h, b_color, t_color, "Username");
		}
		else if (i * 2 == 2) {
			BoxSignIn(x, y + (i * 2), w, h, b_color, t_color, "Password");
		}
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
	gotoXY(x + 12, y + h); cout << char(197);
	gotoXY(x + 14, y + 1);
	ShowCur(1);
	gets_s(s); cpychar(Acc.Username, s);
	gotoXY(x + 14, y + 3);
	gets_s(s); cpychar(Acc.Password, s);
	ShowCur(0);
}
void n_Box14(int x, int y, int w, int h, int b_color, int t_color, int& quantity, Account& Acc) {
	quantity = 2;
	for (int i = 0; i < quantity; i++) {
		if (i * 2 == 0) {
			BoxSignIn(x, y + (i * 2), w, h, b_color, t_color, "NewPass");
		}
		else if (i * 2 == 2) {
			BoxSignIn(x, y + (i * 2), w, h, b_color, t_color, "AgainPass");
		}
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
	gotoXY(x, y); cout << char(195);
	gotoXY(x + 12, y + 2); cout << char(197);
	gotoXY(x + 12, y); cout << char(197);
	gotoXY(x + w, y); cout << char(180);
	gotoXY(x + 14, y + 1);
	ShowCur(1);
	gets_s(s); cpychar(Acc.Username, s);
	gotoXY(x + 14, y + 3);
	gets_s(s); cpychar(Acc.Password, s);
	ShowCur(0);
}
void n_Box15(int x, int y, int w, int h, int b_color, int t_color, int& quantity, YearSchool& ySch, int positionFaculty) {
	quantity = ySch.lengthOfFaculty;
	for (int i = 0; i < quantity; i++) {
		Box(x, y + (i * 2), w, h, b_color, t_color, ySch.faculty[i].NameFaculty);
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}
void n_Box16(int x, int y, int w, int h, int b_color, int t_color, int& quantity, YearSchool& ySch, int positionFaculty) {
	quantity = ySch.faculty[positionFaculty].lengthOfClass;
	for (int i = 0; i < quantity; i++) {
		Box(x, y + (i * 2), w, h, b_color, t_color, ySch.faculty[positionFaculty].Class[i].NameClass);
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}
void n_Box17(int x, int y, int w, int h, int b_color, int t_color, int& quantity, DArray& DA) {
	quantity = DA.lengthOfCourseOfClass;
	for (int i = 0; i < quantity; i++) {
		Box(x, y + (i * 2), w, h, b_color, t_color, DA.course[i].CourseName);
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}
void n_Box18(int x, int y, int w, int h, int b_color, int t_color, int& quantity) {
	quantity = 4;
	for (int i = 0; i < quantity; i++) {
		if (i * 2 == 0) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Information of class");
		}
		else if (i * 2 == 2) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "List students of class");
		}
		else if (i * 2 == 4) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "List course of class");
		}
		else if (i * 2 == 6) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Transcript of class");
		}
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}
void n_Box19(int x, int y, int w, int h, int b_color, int t_color, int& quantity) {
	quantity = 8;
	for (int i = 0; i < quantity; i++) {
		if (i * 2 == 0) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Information of course");
		}
		else if (i * 2 == 2) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "List students of course");
		}
		else if (i * 2 == 4) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Transcript of course");
		}
		else if (i * 2 == 6) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Add a student to the course");
		}
		else if (i * 2 == 8) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Update course information");
		}
		else if (i * 2 == 10) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Remove a student from the course");
		}
		else if (i * 2 == 12) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Import the scoreboard to course");
		}
		else if (i * 2 == 14) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Delete course");
		}
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}
void n_Box20(int x, int y, int w, int h, int b_color, int t_color, int& quantity, Information infor) {
	quantity = 2;
	for (int i = 0; i < quantity; i++) {
		if (i * 2 == 0) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "PROFILE");
		}
		else if (i * 2 == 2) {
			BoxProfile(x, y + (i * 2), w, h + 7, b_color, t_color, infor);
		}
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}
void n_Box21(int x, int y, int w, int h, int b_color, int t_color, int& quantity, DArray DA) {
	quantity = 2;
	for (int i = 0; i < quantity; i++) {
		if (i * 2 == 0) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "CLASS");
		}
		else if (i * 2 == 2) {
			BoxInformationOfClass(x, y + (i * 2), w, h + 2, b_color, t_color, DA);
		}
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}
void n_Box22(int x, int y, int w, int h, int b_color, int t_color, int& quantity, Course& course) {
	quantity = 2;
	for (int i = 0; i < quantity; i++) {
		if (i * 2 == 0) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "COURSE");
		}
		else if (i * 2 == 2) {
			BoxInformationOfCourse(x, y + (i * 2), w, h + 6, b_color, t_color, course);
		}
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}
void n_Box22_1(int x, int y, int w, int h, int b_color, int t_color, int& quantity, Course& course) {
	quantity = 2;
	for (int i = 0; i < quantity; i++) {
		if (i * 2 == 0) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "UPDATE COURSE");
		}
		else if (i * 2 == 2) {
			BoxUpdateCourse(x, y + (i * 2), w, h + 12, b_color, t_color, course);
		}
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}
void n_Box23(int x, int y, int w, int h, int b_color, int t_color, int& quantity, Account& Acc) {
	quantity = 2;
	for (int i = 0; i < quantity; i++) {
		if (i * 2 == 0) {
			BoxSignIn(x, y + (i * 2), w, h, b_color, t_color, "Username");
		}
		else if (i * 2 == 2) {
			BoxSignIn(x, y + (i * 2), w, h, b_color, t_color, "Password");
		}
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
	gotoXY(x + 12, y + h); cout << char(197);
	gotoXY(x + 14, y + 1);
	gets_s(s); cpychar(Acc.Username, s);
	gotoXY(x + 14, y + 3);
	gets_s(s); cpychar(Acc.Password, s);
}
void n_Box25(int x, int y, int w, int h, int b_color, int t_color, int& quantity, School& Sch, Faculty& faculty, int*& a, int*& b, int& i_a, int& i_b, int position) {
	quantity = 0;
	for (int i = 0; i < faculty.lengthOfClass; i++) {
		for (int j = 0; j < faculty.Class[i].lengthOfCourseOfClass; j++) {
			for (int k = 0; k < faculty.Class[i].course[j].NumberOfStudent; k++) {
				if (strcmp(faculty.Class[i].course[j].Member[k].StudentID, Sch.DAStudent.Member[position].StudentID) == 0) {
					Box(x, y + (quantity * 2), w, h, b_color, t_color, faculty.Class[i].course[j].CourseName);
					a[i_a++] = i;
					b[i_b++] = j;
					if (quantity != 0) {
						gotoXY(x, y + (quantity * 2)); cout << char(195);
						gotoXY(x + w, y + (quantity * 2)); cout << char(180);
					}
					++quantity;
				}
			}
		}
	}
}
void n_Box28(int x, int y, int w, int h, int b_color, int t_color, int& quantity, School& Sch) {
	quantity = Sch.lengthOfSemester + 1;
	if (FLAG1 == false && Sch.lengthOfSemester > 0) {
		quantity++;
	}
	for (int i = 0; i < quantity; i++) {
		if (i * 2 == 0) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Create semester");
		}
		else if (FLAG1 == false && Sch.lengthOfSemester > 0) {
			if (i * 2 == 2) {
				Box(x, y + (i * 2), w, h, b_color, t_color, "Import freshman data");
			}
			else {
				Box(x, y + (i * 2), w, h, b_color, t_color, Sch.semester[i - 2].NameSemester);
			}
		}
		else {
			Box(x, y + (i * 2), w, h, b_color, t_color, Sch.semester[i - 1].NameSemester);
		}
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}
void n_Box29(int x, int y, int w, int h, int b_color, int t_color, int& quantity) {
	quantity = 4;
	for (int i = 0; i < quantity; i++) {
		if (i * 2 == 0) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Create a new faculty");
		}
		else if (i * 2 == 2) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Create a new class");
		}
		else if (i * 2 == 4) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Create a new course");
		}
		else if (i * 2 == 6) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "Create a new student");
		}
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}
void n_Box30(int x, int y, int w, int h, int b_color, int t_color, int& quantity, YearSchool& ySch) {
	quantity = ySch.lengthOfFaculty;
	for (int i = 0; i < quantity; i++) {
		Box(x, y + (i * 2), w, h, b_color, t_color, ySch.faculty[i].NameFaculty);
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}
void n_Box31(int x, int y, int w, int h, int b_color, int t_color, int& quantity, School& Sch) {
	quantity = 2;
	for (int i = 0; i < quantity; i++) {
		if (i * 2 == 0) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "CREATE SCHOOL YEAR");
		}
		else if (i * 2 == 2) {
			BoxCreateSchoolYear(x, y + (i * 2), w, h + 2, b_color, t_color, Sch);
		}
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}
void n_Box32(int x, int y, int w, int h, int b_color, int t_color, int& quantity, Semester& temp) {
	quantity = 2;
	for (int i = 0; i < quantity; i++) {
		if (i * 2 == 0) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "CREATE SEMESTER");
		}
		else if (i * 2 == 2) {
			BoxCreateSemester(x, y + (i * 2), w, h + 4, b_color, t_color, temp);
		}
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}
void n_Box33(int x, int y, int w, int h, int b_color, int t_color, int& quantity, Course& temp) {
	quantity = 2;
	for (int i = 0; i < quantity; i++) {
		if (i * 2 == 0) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "CREATE COURSE");
		}
		else if (i * 2 == 2) {
			BoxCreateCourse(x, y + (i * 2), w, h + 14, b_color, t_color, temp);
		}
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}
void n_Box34(int x, int y, int w, int h, int b_color, int t_color, int& quantity, DArray& temp) {
	quantity = 2;
	for (int i = 0; i < quantity; i++) {
		if (i * 2 == 0) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "CREATE CLASS");
		}
		else if (i * 2 == 2) {
			BoxCreateClass(x, y + (i * 2), w, h + 2, b_color, t_color, temp);
		}
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}
void n_Box35(int x, int y, int w, int h, int b_color, int t_color, int& quantity, Information& temp) {
	quantity = 2;
	for (int i = 0; i < quantity; i++) {
		if (i * 2 == 0) {
			Box(x, y + (i * 2), w, h, b_color, t_color, "CREATE NEW STUDENT");
		}
		else if (i * 2 == 2) {
			BoxCreateStudent(x, y + (i * 2), w, h + 8, b_color, t_color, temp);
		}
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}

int whereX() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
// Lấy tạo độ y của con trỏ hiện tại 
int whereY() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}
// Định vị con trỏ hiện tại đến điểm có tọa độ (x,y)
void gotoXY(int x, int y) {
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x,y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
// Đặt màu cho chữ
void SetColor(WORD color) {
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;
	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
//Làm ẩn trỏ chuột
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
//Trả về mã phím người dùng bấm
int inputKey() {
	if (_kbhit()) {
		int key = _getch();
		if (key == 224) {
			key = _getch();
			return key + 1000;
		}
		return key;
	}
}
// Màu 
void TextColor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}