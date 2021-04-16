#include "Angle.h"

void Angle::SetGrades(double grades) { this->grades = grades; }
void Angle::SetMinutes(double minutes) { this->minutes = minutes; }

double Angle::GetGrades() const { return grades; }
double Angle::GetMinutes() const { return minutes; }

Angle::Angle()
{
	grades = 0; minutes = 0;
}
Angle::Angle(double grades = 0, double minutes = 0) throw(invalid_argument, bad_exception, MyException, const char*)
{
	if (grades == 1 && minutes == 1)
		throw invalid_argument("Invalid_argument");
	else if (grades == 2 && minutes == 2)
		throw bad_exception();
	else if (grades == 3 && minutes == 3)
		throw MyException("MyException");
	else if (grades == 4 && minutes == 4)
		throw "Exception";

	this->grades = grades;
	this->minutes = minutes;
}
Angle::Angle(const Angle& A)
{
	grades = A.GetGrades();
	minutes = A.GetMinutes();
}

Angle& Angle::operator = (const Angle& A)
{
	grades = A.grades;
	minutes = A.minutes;

	return *this;
}
ostream& operator << (ostream& out, const Angle& A)
{
	out << string(A);
	return out;
}
istream& operator >> (istream& in, Angle& A)
{
	cout << "Enter a grades of angle: "; in >> A.grades;
	cout << "Enter a minutes of angle "; in >> A.minutes;
	return in;
}
Angle::operator string() const
{
	stringstream ss;
	ss << "Grades of angle is equal to " << grades << endl;
	ss << "Minutes of pair is equal to " << minutes << endl;
	return ss.str();
}

Angle& Angle::operator ++ ()
{
	grades++;
	return *this;
}
Angle& Angle::operator -- ()
{
	grades--;
	return *this;
}
Angle Angle::operator ++ (int)
{
	Angle t(*this);
	minutes++;
	return t;
}
Angle Angle::operator -- (int)
{
	Angle t(*this);
	minutes--;
	return t;
}

double Angle::to360() const { return GetGrades() + GetMinutes() / 60.; }
double Angle::toRadian()const { return (to360() * 3.141592) / 180.; }

Angle operator + (const Angle A, const Angle B)
{
	Angle t(A.GetGrades() + B.GetGrades(),
		A.GetMinutes() + B.GetMinutes());
	return t;
}
Angle operator - (const Angle A, const Angle B)
{
	Angle t(A.GetGrades() - B.GetGrades(),
		A.GetMinutes() - B.GetMinutes());
	return t;
}
Angle operator / (const Angle A, const double value)
{
	Angle t(A.GetGrades() / 2., A.GetMinutes() / 2.);
	return t;
}

void Angle::Increase(Angle X, Angle& A, Angle& B, Angle& C, int tmp)
{
	switch (tmp)
	{
	case 1:
		A = A + X;
		B = B - X / 2.;
		C = C - X / 2.;
		break;
	case 2:
		B = B + X;
		A = A - X / 2.;
		C = C - X / 2.;
		break;
	case 3:
		C = C + X;
		A = A - X / 2.;
		B = B - X / 2.;
		break;
	}
}
void Angle::Decrease(Angle X, Angle& A, Angle& B, Angle& C, int tmp)
{
	Angle minus(-1 * X.GetGrades(), -1 * X.GetMinutes());
	minus.Increase(minus, A, B, C, tmp);
}

double Angle::getSin() const { return sin(toRadian() * 1.); }

bool operator > (const Angle A, const Angle B)
{
	if (A.to360() > B.to360())
		return 1;
	else
		return 0;
}
bool operator < (const Angle A, const Angle B)
{
	if (A.to360() < B.to360())
		return 1;
	else
		return 0;
}
bool operator == (const Angle A, const Angle B)
{
	if (A.to360() == B.to360())
		return 1;
	else
		return 0;
}

void Angle::Comparison(Angle A, Angle B)
{
	if (A > B)
		cout << "First angle > Second angle" << endl;
	if (A < B)
		cout << "First angle < Second angle" << endl;
	if (A == B)
		cout << "First angle = Second angle" << endl;
}
