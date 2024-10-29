#include <iostream>

class MyClass {
public:
	static void memberStaticFunction() {
		std::cout << "Member static function" << std::endl;
	}

    void memberFunction() {
        std::cout << "Member function" << std::endl;
    }
};

int main() {
    MyClass obj;

	// 일반 멤버 함수 포인터로 정적 멤버 함수 선언 및 초기화
	void (*ptr1)() = &MyClass::memberStaticFunction;
	// 일반 멤버 함수 포인터로 멤버 함수 선언 및 초기화 불가능
	// void (*ptr2)() = &MyClass::memberFunction;


    // pointer to member function으로 정적 멤버 함수 선언 및 초기화 불가능
	// void (MyClass::*ptr3)() = &MyClass::memberStaticFunction;
	// pointer to member function으로 정적 멤버 함수 선언 및 초기화
    void (MyClass::*ptr4)() = &MyClass::memberFunction;

    // 멤버 함수 호출 (객체와 함께 호출해야 함)
	ptr1();	// 출력: Member static function
    (obj.*ptr4)();	// 출력: Member function

    return 0;
}

