## INDEX

- [CPP 05](#cpp-05)
	- [Exceptions](#exceptions)
		- [Concepts](#concepts)
		- [How to work?](#how-to-work)
			- [요약](#요약)
		- [Stack unwinding](#stack-unwinding)

---
# CPP 05

**Repetition and Exceptions**

## Exceptions

### Concepts

일반적으로 오류처리를 `return -1`과 같이 반환값에 담아 처리했다    
이러한 방식은 간단하다는 장점이 있으나 여러 단점들이 있었다   
1. 반환하는 값 자체가 난해하여 문서를 참조해야한다는 것것    
2. 결과값과 오류 코드 둘다 반환하고자 하였을때, 둘중 하나를 담을 포인터/참조조 매개변수를 추가해야 한다는 것것   
3. 여러 단계에서 발생하는 에러에 대한 적절한 대응들이 필요하다면 코드가 장황해지고 본래의 의도를 잃게 되는 경우   
4. 생성자에서 발생한 문제를 반환 코드 방식으로 해결할 수 없는 경우    
5. 호출자가 에러를 처리하지 못하는 경우   

개인적인 경험을 추가하자면 함수가 함수를 여러번 호출하였을때, 호출자가 에러를 처리하지 못하면 에러코드가 호출된 함수들을 타고 에러 코드를 온전히 가지고 나와야 하는데 이는 설계와 코드 레이아웃 작성에 있어 큰 제약이 생기게 된다   

위와 같은 문제들을 해결하기 위해 Exception은은 예외 처리를 통해 코드의 흐름에서 예외 처리를 분리하는 메커니즘을 제공한다   

### How to work?

C++의 Exception은 세가지 키워드 **throw**, **try**, **catch**를 통해 구현된다   

- **thorw**   
	
	**throw** 문은 예외 혹은 오류 케이스가 발생했음을 알리는 데 사용된다   

	```c++
	throw -1; // throw a literal integer value
	throw ENUM_INVALID_INDEX; // throw an enum value
	throw "Can not take square root of negative number"; // throw a literal C-style (const char*) string
	throw dX; // throw a double variable that was previously defined
	throw MyException("Fatal Error"); // Throw an object of class MyException
	```


위와 같이 다양한 방식으로 예외 발생을 알린다   

- **try**   

	**try** 키워드는 try 블록이라는 statment 집합을 정의한다   
	**try 블록**은 관찰자 역할을 하여 블록 내의 statment들 중 어떤 statement가 예외를 **throw** 했는지 감시한다   
	
	**try 블록**은 예외를 어떻게 처리할지 정의하지 않고 그저 블록 내부에서 일어난 **throw**를 **catch** 하는 **try**를 할 뿐이다   

	```c++
	try
	{
		// Statements that may throw exceptions you want to handle go here
		throw -1; // here's a trivial throw statement
	}
	```


- **catch**   

	**catch** 키워드는 예외를 처리하는 코드 블록을 정의하는 데 사용된다   

	**catch 블록**은 일반적으로 다음과 같은 역할을 수행한다   
	- 에러 출력   
	- 값 변환   
	- 새로운 예외 발생   
		기존 예외를 처리한 뒤 새로운 예외를 **throw**하여 상위 **try 블록**에서 처리   
	- 프로그램 종료   

	```c++
	catch (int x)
	{
		// Handle an exception of type int here
		std::cerr << "We caught an int exception with value" << x << '\n';
	}

	catch (double) // no variable name since we don't use the exception itself in the catch block below
    {
        // Any exceptions of type double thrown within the above try block get sent here
        std::cerr << "We caught an exception of type double\n";
    }

	catch (const std::string&) // catch classes by const reference
    {
        // Any exceptions of type std::string thrown within the above try block get sent here
        std::cerr << "We caught an exception of type std::string\n";
    }
	```

#### 요약

1. 예외 발생
	- **throw** 문을 사용해 예외 발생시 가장 가까운 **try** 블록을 찾는다   
	- 블록에 연결된 **catch** 핸들러중 예외 타입과 일치하는 핸들러를 찾아 실행    
	- 예외가 처리된 후, 프로그램은 정상적으로 실행이 이어진다   

2. 적절한 **catch** 핸들러를 찾지 못했을 때    
	- 가장 가까운 **try** 블록에서 예외를 처리하지 못하면, 프로그램은 다음으로 둘러싸고 있는 상위 **try** 블록을 탐색한다   
	- 만약 프로그램 종료 전까지 적합한 핸들러를 찾이 못하면, 프로그램은 `runtime exception error`와 함께 종료   

3. 타입 변환 없음
	- **catch** 블록은 예외 타입이 정확히 일치할 때만 예외를 처리할 수 있다   
	- 하지만 파생 클래스에서 부모 클래스로의 형 변한은 가능하다   


### Stack unwinding

try block은 놀랍게도 해당 블록 내의 throw를 감지하는 것 외에도 호출된 함수가 throw하는 예외도 감지할 수 있다   
**Exception**의 가장 유용한 속성중 하나는 **throw statement**가 *try block* 안에 직접 배치될 필요가 없다는 것인데, 함수의 어디에서나 **throw**될 수 있으며, 이러한 **exception**은 호출자의 **try block**에서 **catch**될 수 있다   
이런 방식으로 **exception**이 **catch**되면 실행은 **exception**이 **throw**된 지점에서 예외를 처리하는 **catch** 블록으로 점프한다    

```c++
#include <cmath>
#include <iostream>

double devide(double leftNum, double rightNum) {
	
}

```






