#include <iostream>

class Base {
public:
  void f(int n) { std::cout << n << '\n'; }
};
class Derived : public Base {};

// class Base {};
// class Derived : public Base { public: void f(int n) { std::cout << n << '\n';
// } };

int main() {
  void (Derived::*dp)(int) = &Derived::f;
  void (Base::*bp)(int) = static_cast<void (Base::*)(int)>(dp);

  Derived d;
  (d.*bp)(1); // okay: prints 1

  Base b;
  (b.*bp)(223123); // undefined behavior
                   /**
                    * 여기서 동작이 잘 되는것을 볼 수 있는데 위의 주석처리된 클래스 선언처럼
                    * 반대로 선언해도 각각 Base클래스와 Derived 클래스 안에 있는 f함수를 d와 b가
                    * 가리키고 있음을 볼 수 있다                  이에 대해 stackoverflow에 질문한 결과                  문법적
                    * 오류가 명백하고 undefined behavior는 말 그대로 동작을 확신 할 수 없다는
                    * 의미 이기에                  이러한 문법은 결론적으로 오류가 있으며 현재 MacOS와 Window에서
                    * 잘 돌아가는 이유는                  이를 컴파일러가 문법적 오류를 고친것으로 판단된다
                    */
}
