#include <iostream>

class IntPtr {
public:
	int *int_ptr_;

	IntPtr(int n) { 
		int_ptr_ = new int(n); 
		std::cout << "IntPtr constructor\n";
	}
	~IntPtr() { 
		delete int_ptr_; 
		std::cout << "IntPtr destructor\n";
	}
};

class Throwing {
public:
	IntPtr int_ptr;

	Throwing(int n) : int_ptr(n) { 
		std::cout << "Throwing constructor\n";
	 	throw -1; 
	};
	~Throwing() { std::cout << "Throwing destructor\n"; }
};

int main() {
	try { Throwing resource_allocated_but_throw_exception(5); }
	catch (int) { std::cerr << "Catch exception!\n"; }
}

// 출력 예상:
// IntPtr constructor
// Throwing constructor
// IntPtr destructor
// Catch exception!

// IntPtr이라는 자원을 할당받는 멤버 변수를 Throwing 객체에 포함시켜, Throwing 객체의 ife cycle에 따라 자동으로 관리되도록 하였다
// 생성자에서 예외 발생시 Throwing 객체는 소멸자가 아직 만들어지지 않아 소멸자가 호출되지 않는다
// 하지만 이미 생성된 멤버 객체 IntPtr은 정상적으로 소멸자가 호출되어 자원 누수가 발생하지 않는다
// 즉, IntPtr의 소유권을 Throwing 객체가 가지게 되며 이는 RAII 기법이 적용된 모습으로 자원을 안전하게 관리할 수 있다  
// 대표적인 RAII의 예시로는 스마트 포인터(unique, shared)가 존재한다