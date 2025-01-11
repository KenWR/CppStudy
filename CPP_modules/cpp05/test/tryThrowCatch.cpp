#include <iostream>
#include <string>

int main()
{
    try
    {
        throw -1; // int형 예외를 발생생
    }
    catch (double) // catch 블록에서 전달된 예외 객체를 사용하지 않을 경우, 매개변수 이름 생략 가능능
    {
        std::cerr << "We caught an exception of type double\n";
    }
    catch (int x)
    {
        std::cerr << "We caught an int exception with value: " << x << '\n';
    }
    catch (const std::string&)
    {
        std::cerr << "We caught an exception of type std::string reference\n";
    }

    // 예외 처리 후 코드 계속 실행
    std::cout << "Our code didn't stop anyway\n";

    return 0;
}

// 예외 처리는 try 블록에서 예외가 발생할 경우 catch 블록으로 제어를 전달하는 것을 말한다.
// try 블록에서 예외가 발생하지 않으면 catch 블록은 실행되지 않는다.
// try 블록에서 발생한 예외를 throw 키워드를 사용하여 catch 블록으로 전달하며,
// 이 과정에서 적절한 catch 블록을 찾아가게 된다.