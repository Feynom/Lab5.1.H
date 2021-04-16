#pragma once
#include "Angle.h"

class Triangle_Public : public Angle
{
private:
	Angle A, B, C;
	double a, b, c;
public:
	void SetA(Angle A);
	void SetB(Angle B);
	void SetC(Angle C);

	void Set_a(double value);
	void Set_b(double value);
	void Set_c(double value);

	Angle& GetA();
	Angle& GetB();
	Angle& GetC();

	double Get_a() const;
	double Get_b() const;
	double Get_c() const;

	friend ostream& operator << (ostream&, const Triangle_Public&);
	friend istream& operator >> (istream&, Triangle_Public&);
	operator string() const;

	double Square() const;
	double Perimeter() const;
	double Altitude(int tmp) const;
	void TypeOFTriangle();
	void Equalizetriangle(int tmp);
};

