#pragma once
#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include"Windows.h"
#define KEY_NONE -1
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
using ll = long long;
struct Date {
	int day;
	int month;
	int year;
};
struct Account {
	char* Username;
	char* Password;
};
struct Information {
	int No;
	char* Email;
	char* StudentID;
	char* FirstName;
	char* LastName;
	char* Gender;
	Date DateOfBirth;
	ll CCCD;
	char* Postition;
};
struct ScoreBoard {
	char* StudentID;
	char* FullName;
	float TotalMark = -1;
	float FinalMark = -1;
	float MidTermMark = -1;
	float OtherMark = -1;
};
struct Course {
	char* CourseID;
	char* CourseName;
	char* ClassName;
	char* NameTeacher;
	int NumberCredits;
	int NumberOfStudent = 0;
	int MaximumStudent;
	char* DayOfTheWeek;
	char* Session;
	/* cấu trúc của các sinh viên có trong khóa học */
	ScoreBoard* Score;
	Information* Member;
	Account* Acc;
};
struct DArray {//class
	char* NameClass;               // tên lớp
	int lengthStudent = 0;           // số lượng sinh vien
	int lengthMaxOfClass = 0;        // Sô lượng max thành viên của lớp
	char* classOfFaculty;          // Lớp thuộc khoa
	Course* course;                // Lưu các môn học của lớp
	int lengthOfCourseOfClass = 0;   // Số lượng môn học của lớp
	Information* Member;           // Thành viên lớp
	Account* Acc;                  // Thành viên lớp
};
struct Faculty {
	int symbolFaculty;          // mã số ký hiệu khoa 
	char* NameFaculty = NULL;   // Tên khoa
	int lengthOfCourse = 0;     // Số lượng môn học của khoa
	Course* course;             // Môn học của khoa
	int lengthOfClass = 0;      // Số lượng lớp của khoa
	DArray* Class;              // Lớp của khoa
	int lengthStudent = 0;      // Số lượng sinh viên của khoa
};
struct YearSchool {
	int lengthOfFaculty = 0;          // Số lượng khoa
	Faculty* faculty;                 // Mảng Động khoa;
	DArray student;                   // mảng lưa trữ toàn bộ sinh viên của khóa (vd K22)
};
struct Semester {
	char* NameSemester = NULL;       // tên học kì
	Date StartDate;                  // ngày bắt đầu học kì
	Date EndDate;                    // ngày kết thúc học kì
	YearSchool Freshman;             // sinh viên năm nhất
	YearSchool Sophomore;            // sinh viên năm hai
	YearSchool Thir_Year_Student;    // sinh viên năm ba
	YearSchool Fourth_Year_Student;  // sinh viên năm tư
};
struct School {
	int* SchoolYear = NULL;         // liên khóa
	int lengthOfSchoolYear = 0;     // số lượng liên khóa (default: 2) 
	DArray DAStaff;                 // danh sách lưu giữ cán bộ 
	DArray DAStudent;               // danh sách lưu giữ toàn bộ sinh viên
	Semester* semester;             // danh sách lưu giữ các học kì
	int lengthOfSemester = 0;       // số lương học kì
	YearSchool Data;                // Dữ liệu của toàn năm

};
int maxDay(Date a);
bool checkDay(Date a);
void cpychar(char*& Destination, char Source[]);
void cpyString(char*& Destination, string Source);
void cpycharPoint(char*& Destination, char* Source);
void AllocationSchoolYear(int*& SchoolYear, int& lengthOfSchoolYear, int temp);
void AllocationSemester(Semester*& Ster, int& s_Ster, Semester temp);
void AllocationFaculty(Faculty*& Fac, int& s_Fac, Faculty temp);
void AllocationCourse(Course*& Cour, int& s_Cour, Course temp);
void AllocationClass(DArray*& DAClass, int& s_class, DArray temp);
void AllocationScoreBoard(ScoreBoard*& Score, int& lengthOfScoreBoard, ScoreBoard temp);
void AllocationStudent(Information*& infor, Account*& Acc, int& s_Student, Information temp1, Account temp2);
bool CheckAccount(Account Acc1, Account* Acc2, int n, int& k);
bool CheckClass(Faculty Fac, char* nameclass);
bool SignIn(Account& Acc1, DArray& DA, int& k, bool notification);
bool ChangePassword(DArray& DA);
void CreateEmail(DArray& DA, int vitri);
void CreateID(char*& ID, int K, int F, int No);
void ReadListFromFile(ifstream& filein, DArray& DA);
void ReadListFaculty(ifstream& filein, YearSchool& YeahSch, string pathOfSource);
void ReadListClass(ifstream& filein, YearSchool& YearSch, string pathOfSource);
void ReadListCourse(ifstream& filein, YearSchool& YearSch, int HK, string pathOfSource);
bool ReadScoreBoardOfCourse(ifstream& filein, Course& course, char* pathOfSource);
void RandomScoreBoard(Course& course, bool Flag);
void inputCourse(Course& Cour);
void MenuProfile(Information infor);
void CreateNewSemester(School* Sch, int& i_Sch);
void CreateNewFaculty(YearSchool& ySch);
void CreateNewClass(Faculty& Fac);
void CreateNewCourse(Faculty& Fac);
void CreateNewStudent(Information*& infor, Account*& acc, ScoreBoard*& Score, int& NumberOfStudent, DArray& DA, Faculty faculty);
void informationOfOneClass(DArray DA);
void informationOfOneCourse(Course course);
void updateInformationOfCourse(Course& course);
void removedOneStudentOfCourse(Course& course, int position);
void removedOneCourse(DArray& DA, int position);
int getK(char* ID);
int getF(char* ID);
void CreateEmail(DArray& DA, int vitri);
void ReadListFromFile(ifstream& filein, DArray& DA);
bool ReadScoreBoardOfCourse(ifstream& filein, Course& course, char* pathOfSource);
Faculty getFaculty(School Sch, int position, int year);
void WriteFile(ofstream& fileout, Information infor, int& count);
void WriteStudentOfYearSchool(School& Sch, int year);
void splitOfSchool(School& Sch, int year);
void splitOfClass(School& Sch, int year, bool flag, int stSemester);
void splitOfCourse(School& Sch, int HK, bool flag1, bool flag2, int stSemester);
void splitStudentToClass(DArray source, Faculty& destination);
void splitStudent(YearSchool& ySch);
void splitCourseToClass(YearSchool& ySch);
void initScore(YearSchool& ySch);
void RecoveryCourse(YearSchool& ySch);
void RecoveryMark(YearSchool& ySch);
void convertCourse(Course* course, int lengthOfCourse);
void convertClass(DArray* DA, int lengthOfClass);
void ViewScoreBoardOfStudent(Faculty faculty, char* MSSV);
void ViewScoreBoardClass(DArray& DA);
void ViewScoreBoardOfCourse(Course course);
void ViewListStudent(DArray& DA);
int ViewListStudent(Course course);
bool MenuOfOneCourse(Course*& course, int position, DArray& DA, Faculty faculty);
void MenuOfOneClass(DArray*& DA, int position, Faculty faculty);
void ViewListCourseOfClass(DArray& DA, Faculty faculty);
void MenuCreateFaculty(YearSchool& ySch, void(*CreateNew)(Faculty&));
void ViewListCourseOfFaculty(YearSchool& ySch, int position);
void ViewListClassOfFaculty(YearSchool& ySch, int position);
void ViewListCourseOfStudent(School Sch, int position, int year);
void MenuFaculty(YearSchool& ySch, void(*ViewOfFaculty)(YearSchool&, int));
void MenuClass(YearSchool ySch);
void MenuCourse(YearSchool ySch);
void MenuFreshman(School& Sch);
void MenuSophomore(School& Sch);
void MenuThirdYear(School& Sch);
void MenuFourthYear(School& Sch);
void initializeYearSchool(YearSchool& init);
void init(YearSchool& init);
void initClass(DArray& DA);
void MenuNew1(School* Sch, int& i_Sch);
void MenuNew2_1(School* Sch, int& i_Sch, YearSchool& ySch, int stSemester);
void MenuStudent1(School& Sch);
void MenuStudent2(School* Sch, int& i_Sch, int& k);
void MenuNew2(School* Sch, int& i_Sch);
void MenuNew(School* Sch, int& i_Sch);
void MenuRegisterForTheCourse(School* Sch, int& i_Sch, int position, int year);
void MenuRegister(School* Sch, int& i_Sch, int position, int year);
void MenuLearning(School* Sch, int& i_Sch, int position, int year);
void MenuProfile(Information infor);
void Menu1a(School& Sch, int& k);
void Menu2a(School* Sch, int& i_Sch);
void Menu1(School* Sch, int& i_Sch);
void Menu2(School* Sch, int& i_Sch);
void Menu(School* Sch, int& i_Sch);

int whereX();
int whereY();
void gotoXY(int x, int y);
void SetColor(WORD color);
void ShowCur(bool CursorVisibility);
int inputKey();
void TextColor(int x);

void Light1(int x, int y, int w, int h, int b_color, int position);
void Light2(int x, int y, int w, int h, int b_color, int position);
void Light3(int x, int y, int w, int h, int b_color, int position);
void Light4(int x, int y, int w, int h, int b_color, int position);
void Light5(int x, int y, int w, int h, int b_color, int position);
void Light6(int x, int y, int w, int h, int b_color, int position);
void Light7(int x, int y, int w, int h, int b_color, int position);
void Light8(int x, int y, int w, int h, int b_color, int position);
void Light8_1(int x, int y, int w, int h, int b_color, int position);
void Light9(int x, int y, int w, int h, int b_color, int position);
void Light10(int x, int y, int w, int h, int b_color, int position);
void Light11(int x, int y, int w, int h, int b_color, int position);
void Light12(int x, int y, int w, int h, int b_color, int position);
void Light15(int x, int y, int w, int h, int b_color, int position, YearSchool& ySch, int positionFaculty);
void Light16(int x, int y, int w, int h, int b_color, int position, YearSchool& ySch, int positionFaculty);
void Light17(int x, int y, int w, int h, int b_color, int position, DArray& DA);
void Light18(int x, int y, int w, int h, int b_color, int position);
void Light19(int x, int y, int w, int h, int b_color, int position);
void Light25(int x, int y, int w, int h, int b_color, int position, Faculty faculty, int* a, int* b);
void Light28(int x, int y, int w, int h, int b_color, int position, School& Sch);
void Light29(int x, int y, int w, int h, int b_color, int position);
void Light30(int x, int y, int w, int h, int b_color, int position, YearSchool& ySch);
void n_Box32(int x, int y, int w, int h, int b_color, int t_color, int& quantity, Semester& temp);

void HCMUS(int x, int y);
void BoxLoading(int x, int y, int w, int h, int b_color, int t_color);
void Box(int x, int y, int w, int h, int b_color, int t_color, string s);
void BoxTime(int x, int y, int w, int h, int b_color, int t_color, Date& a);
void BoxUsage(int x, int y, int w, int h);
void BoxUsage0(int x, int y, int w, int h);
void BoxSignIn(int x, int y, int w, int h, int b_color, int t_color, string s);
int BoxNotification(int x, int y, int w, int h, int b_color, int t_color, string s, bool flag);
void BoxProfile(int x, int y, int w, int h, int b_color, int t_color, Information infor);
void BoxInformationOfClass(int x, int y, int w, int h, int b_color, int t_color, DArray DA);
void BoxInformationOfCourse(int x, int y, int w, int h, int b_color, int t_color, Course& course);
void BoxTranscriptOfClass(int x, int y, int w, int h, int b_color, int t_color, DArray DA);
void BoxTranscriptOfCourse(int x, int y, int w, int h, int b_color, int t_color, Course& course);
void BoxTranscriptOfStudent(int x, int y, int w, int h, int b_color, int t_color, Faculty faculty, char* MSSV);
void BoxStudentOfClass(int x, int y, int w, int h, int b_color, int t_color, DArray DA);
void BoxStudentOfCourse(int x, int y, int w, int h, int b_color, int t_color, Course course);
void BoxCreateSchoolYear(int x, int y, int w, int h, int b_color, int t_color, School& Sch);

void n_Box1(int x, int y, int w, int h, int b_color, int t_color, int& quantity);
void n_Box2(int x, int y, int w, int h, int b_color, int t_color, int& quantity);
void n_Box3(int x, int y, int w, int h, int b_color, int t_color, int& quantity);
void n_Box4(int x, int y, int w, int h, int b_color, int t_color, int& quantity);
void n_Box5(int x, int y, int w, int h, int b_color, int t_color, int& quantity);
void n_Box6(int x, int y, int w, int h, int b_color, int t_color, int& quantity);
void n_Box7(int x, int y, int w, int h, int b_color, int t_color, int& quantity);
void n_Box8(int x, int y, int w, int h, int b_color, int t_color, int& quantity);
void n_Box8_1(int x, int y, int w, int h, int b_color, int t_color, int& quantity);
void n_Box9(int x, int y, int w, int h, int b_color, int t_color, int& quantity);
void n_Box10(int x, int y, int w, int h, int b_color, int t_color, int& quantity);
void n_Box11(int x, int y, int w, int h, int b_color, int t_color, int& quantity);
void n_Box12(int x, int y, int w, int h, int b_color, int t_color, int& quantity);
void n_Box13(int x, int y, int w, int h, int b_color, int t_color, int& quantity, Account& Acc);
void n_Box14(int x, int y, int w, int h, int b_color, int t_color, int& quantity, Account& Acc);
void n_Box15(int x, int y, int w, int h, int b_color, int t_color, int& quantity, YearSchool& ySch, int positionFaculty);
void n_Box16(int x, int y, int w, int h, int b_color, int t_color, int& quantity, YearSchool& ySch, int positionFaculty);
void n_Box17(int x, int y, int w, int h, int b_color, int t_color, int& quantity, DArray& DA);
void n_Box18(int x, int y, int w, int h, int b_color, int t_color, int& quantity);
void n_Box19(int x, int y, int w, int h, int b_color, int t_color, int& quantity);
void n_Box20(int x, int y, int w, int h, int b_color, int t_color, int& quantity, Information infor);
void n_Box21(int x, int y, int w, int h, int b_color, int t_color, int& quantity, DArray DA);
void n_Box22(int x, int y, int w, int h, int b_color, int t_color, int& quantity, Course& course);
void n_Box22_1(int x, int y, int w, int h, int b_color, int t_color, int& quantity, Course& course);
void n_Box25(int x, int y, int w, int h, int b_color, int t_color, int& quantity, School& Sch, Faculty& faculty, int*& a, int*& b, int& i_a, int& i_b, int position);
void n_Box28(int x, int y, int w, int h, int b_color, int t_color, int& quantity, School& Sch);
void n_Box29(int x, int y, int w, int h, int b_color, int t_color, int& quantity);
void n_Box30(int x, int y, int w, int h, int b_color, int t_color, int& quantity, YearSchool& ySch);
void n_Box31(int x, int y, int w, int h, int b_color, int t_color, int& quantity, School& Sch);
void n_Box33(int x, int y, int w, int h, int b_color, int t_color, int& quantity, Course& temp);
void n_Box34(int x, int y, int w, int h, int b_color, int t_color, int& quantity, DArray& temp);
void n_Box35(int x, int y, int w, int h, int b_color, int t_color, int& quantity, Information& temp);

void MenuGraphic(int x, int y, int w, int h, int b_color, int t_color, int& position, void (*n_Box)(int, int, int, int, int, int, int&), void (*Light)(int, int, int, int, int, int));
void MenuGraphic1(int x, int y, int w, int h, int b_color, int t_color, int& position, int positionFaculty, YearSchool& ySch, void (*n_Box)(int, int, int, int, int, int, int&, YearSchool&, int), void (*Light)(int, int, int, int, int, int, YearSchool&, int));
void MenuGraphic2(int x, int y, int w, int h, int b_color, int t_color, int& position, DArray& DA, void (*n_Box)(int, int, int, int, int, int, int&, DArray&), void (*Light)(int, int, int, int, int, int, DArray&));
void MenuGraphic3(int x, int y, int w, int h, int b_color, int t_color, int& position, School& Sch, Faculty& faculty, int*& a, int*& b, int& i_a, int& i_b, int positionOfStudent, void (*n_Box)(int, int, int, int, int, int, int&, School&, Faculty&, int*&, int*&, int&, int&, int), void (*Light)(int, int, int, int, int, int, Faculty, int*, int*));
void MenuGraphic4(int x, int y, int w, int h, int b_color, int t_color, int& position, School& Sch, void (*n_Box)(int, int, int, int, int, int, int&, School&), void (*Light)(int, int, int, int, int, int, School&));
void MenuGraphic5(int x, int y, int w, int h, int b_color, int t_color, int& position, YearSchool& ySch, void (*n_Box)(int, int, int, int, int, int, int&, YearSchool&), void (*Light)(int, int, int, int, int, int, YearSchool&));