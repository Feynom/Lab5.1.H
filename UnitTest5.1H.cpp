#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5.1H/Angle.h"
#include "../Lab5.1H/Angle.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest51H
{
	TEST_CLASS(UnitTest51H)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Angle A(90, 0), B(180, 0);
			Assert::AreEqual(round(A.getSin()), 1.);
			Assert::AreEqual(round(B.getSin()), 0.);
		}
	};
}
