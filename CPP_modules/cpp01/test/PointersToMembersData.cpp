#include <iostream>

class C {public: int m; };
class Base {public: int m; };
class Derived : public Base {};

class Base2 { public: int m; };
class Derived2 : public Base2 {  };

class A { 
public: 
    int m; 
    int A::* const p; 
};

int main()
{
    // 클래스 C의 멤버 변수 m에 대한 포인터
    {
    int C::* p = &C::m;          
    int Base::* bp = &Base::m;
    int Derived::* dp = bp;
	
	C c = {7};
	Derived d;

    std::cout << c.*p << std::endl;   // 7 출력
    C* cp = &c;
    cp->m = 10;
    std::cout << cp->*p << std::endl; // 10 출력
	d.m = 1;
	std::cout << d.*dp << ' ' << d.*bp << std::endl; // 1 1 출력
    }
    std::cout << "==================================" << std::endl;
    // 파생 클래스의 멤버 변수에 대한 포인터에서 비모호한 비가상 기본 클래스의 멤버 변수에 대한 포인터로 변환
    {
    int Derived2::* dp = &Derived2::m;
    // static_cast 및 명시적 캐스트를 통한 변환
    int Base2::* bp = static_cast<int Base2::*>(dp);

    Derived2 d;
    d.m = 7;
    std::cout << d.*bp << std::endl; // 정상: 7 출력

    Base2 b;
    std::cout << b.*bp << std::endl; // 정의되지 않은 동작
    }
    std::cout << "==================================" << std::endl;
    // 상수 포인터, 비상수 멤버에 대한 포인터
    {
    int A::* const A::* p1 = &A::p;

    const A a = {1, &A::m};
    std::cout << a.*(a.*p1) << std::endl; // 1 출력

    // 멤버에 대한 상수 포인터에 대한 비상수 포인터
    int A::* const* p2 = &a.p;
    std::cout << a.**p2 << std::endl; // 1 출력
    }
}
