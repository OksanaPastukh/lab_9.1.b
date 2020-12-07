#include "pch.h"
#include "CppUnitTest.h"
#include "../Project9.1/project9.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest91a
{
	TEST_CLASS(UnitTest91a)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int c;
			int N = 5;
			Student* p = new Student[N];
			p[0].prizv = "Pastukh";
			p[0].specialty = ComputerScience;
			p[0].grades_in_programming = 5;
			p[1].prizv = "Petrov";
			p[1].specialty = Informatics;
			p[1].grades_in_numerical_methods = 4;
			p[2].prizv = "Ivanov";
			p[2].specialty = Mathematics;
			p[2].grades_in_pedagogy = 3;
			p[3].prizv = "Abramov";
			p[3].specialty = ComputerScience;
			p[3].grades_in_programming = 4;
			p[4].prizv = "Karginov";
			p[4].specialty = Physics;
			p[4].grades_in_pedagogy = 4;
			c = LineSearch_count(p, N);
			Assert::AreEqual(c, 2);
		}
	};
}
