#include <iostream>
#include <exception>

class MyException : public std::exception {
private:
    const int& ref; // 스택 변수 참조

public:
    MyException(const int& r) : ref(r) {}
    const char* what() const noexcept override { return "Exception occurred!"; }
};

void faultyFunction() {
    int localValue = 42; // 지역 변수 (스택에 할당됨)
    throw MyException(localValue); // 예외 객체가 스택 변수를 참조
}

int main() {
    try { faultyFunction(); }
    catch (const MyException& e) { std::cerr << e.what() << '\n'; }
}

// 이 코드는 `아마도` 동작할 것이다
// 하지만 100% 동작을 보장하지 않는다 그렇기에 Undefined behavior가 된다
// Stack unwinding 되면서 참조로 받은 const int& ref 멤버변수에서 문제가 생길 것이다
// 여기서 구조가 좀더 복잡해서 몇몇 레지스터들이 새로 쓰여지면 문제가 발생할 확률이 올라가게 될 것이다
