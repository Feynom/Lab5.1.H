#include "Triangle_Public.h"

void Triangle_Public::SetA(Angle A)
{
	this->A.Angle::SetGrades(A.GetGrades());
	this->A.Angle::SetMinutes(A.GetMinutes());
}
void Triangle_Public::SetB(Angle B)
{
	this->B.Angle::SetGrades(B.GetGrades());
	this->B.Angle::SetMinutes(B.GetMinutes());
}
void Triangle_Public::SetC(Angle C)
{
	this->C.Angle::SetGrades(C.GetGrades());
	this->C.Angle::SetMinutes(C.GetMinutes());
}

void Triangle_Public::Set_a(double value) { a = value; }
void Triangle_Public::Set_b(double value) { b = value; }
void Triangle_Public::Set_c(double value) { c = value; }

Angle& Triangle_Public::GetA() { return A; }
Angle& Triangle_Public::GetB() { return B; }
Angle& Triangle_Public::GetC() { return C; }

double Triangle_Public::Get_a() const { return a; }
double Triangle_Public::Get_b() const { return b; }
double Triangle_Public::Get_c() const { return c; }

ostream& operator << (ostream& out, const Triangle_Public& A)
{
	out << string(A);
	return out;
}
istream& operator >> (istream& in, Triangle_Public& X)
{
	cout << "Angle A: " << endl;
	in >> X.A;
	cout << "Angle B: " << endl;
	in >> X.B;
	cout << "Angle C: " << endl;
	in >> X.C;

	cout << "\nEnter a side 'a' : "; in >> X.a;
	cout << "Enter a side 'b' : "; in >> X.b;
	cout << "Enter a side 'c' : "; in >> X.c;

	return in;
}
Triangle_Public::operator string() const
{
	stringstream ss;
	ss << "Angle A Grades is equal to " << A.GetGrades() << endl;
	ss << "Angle A minutes is equal to " << A.GetMinutes() << endl;

	ss << "Angle B Grades is equal to " << B.GetGrades() << endl;
	ss << "Angle B Minutes is equal to " << B.GetMinutes() << endl;

	ss << "Angle C Grades is equal to " << C.GetGrades() << endl;
	ss << "Angle C Minutes is equal to " << C.GetMinutes() << endl;

	ss << "\nSide a is equal to " << a << endl;
	ss << "Side b is equal to " << b << endl;
	ss << "Side c is equal to " << c << endl;

	return ss.str();
}

double Triangle_Public::Square() const
{
	double p = Perimeter() / 2.;
	return sqrt(p * (p - Get_a()) * (p - Get_b()) * (p - Get_c()));
}
double Triangle_Public::Perimeter() const { return Get_a() + Get_b() + Get_c(); }
double Triangle_Public::Altitude(int tmp) const
{
	switch (tmp)
	{
	case 1:
		return (2 * Square()) / (Get_a() * 1.);
	case 2:
		return (2 * Square()) / (Get_b() * 1.);
	case 3:
		return (2 * Square()) / (Get_c() * 1.);
	}
}
void Triangle_Public::TypeOFTriangle()
{
	if ((Get_a() == Get_b()) && (Get_b() == Get_c()))
		cout << "Equilateral triangle" << endl; //рівносторонній
	else if ((Get_a() == Get_b() && Get_a() != Get_c()) ||
		(Get_a() == Get_c() && Get_a() != Get_b()) ||
		(Get_c() == Get_b() && Get_c() != Get_a()))
		cout << "Isosceles triangle" << endl;//рівнобедрений
	else if (A.to360() == 90 || B.to360() == 90 || C.to360() == 90)
		cout << "Rectangular triangle" << endl;//прямокутний
	else if (A.to360() > 90 || B.to360() > 90 || C.to360() > 90)
		cout << "Obtuse triangle" << endl;// тупокутний 
	else if (A.to360() < 90 && B.to360() < 90 && C.to360() < 90)
		cout << "Oxygon" << endl;// гострокутний
}
void Triangle_Public::Equalizetriangle(int tmp)
{
	switch (tmp)
	{
	case 1:
		Set_b((Get_a() * B.getSin()) / (A.getSin() * 1.));
		Set_c((Get_a() * C.getSin()) / (A.getSin() * 1.));
		break;
	case 2:
		Set_a((Get_b() * A.getSin()) / (B.getSin() * 1.));
		Set_c((Get_b() * C.getSin()) / (B.getSin() * 1.));
		break;
	case 3:
		Set_a((Get_c() * A.getSin()) / (C.getSin() * 1.));
		Set_b((Get_c() * B.getSin()) / (C.getSin() * 1.));
		break;
	}
}