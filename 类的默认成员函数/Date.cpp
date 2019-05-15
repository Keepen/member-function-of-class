#include <iostream>
using std::cout;
using std::endl;

class Date {
private:
	int _year;
	int _month;
	int _day;
public:
	Date(int year , int month, int day);
	Date(const Date&d);		//��������
	void Print();		//��ӡ����
	Date operator=(const Date& d);	//��ֵ�����������
	Date* operator&();
	Date* operator&()const;
	~Date();
};

//���캯��
Date::Date(int year = 1900, int month = 1, int day = 1) {
	_year = year;
	_month = month;
	_day = day;
}

//��������
Date::Date(const Date& d) {
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

//��ӡ����
void Date::Print() {

	cout <<  _year << "-" << _month << "-" << _day << endl;
}

//��ֵ�����������
Date Date::operator=(const Date& d) {
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}

//ȡַ�����&������
Date* Date::operator&() {
	return this;
}

//const�����ȡֵ�����&������
Date* Date::operator&()const {
	return (Date*)0;
}



//��������
Date::~Date() {
	cout << this->_year << "��~Date()" << endl;
}

void test() {
	Date d1(2019, 5, 15);
	d1.Print();
	Date d2(2018);
	d2.Print();

	Date d3(2017);
	d3.Print();

	Date d4(2016);
	d1 = d2 = d3;
	//d4 = d1;
	d4.Print();  
}

int main() {
	test();
	system("pause");
	return 0;
}
