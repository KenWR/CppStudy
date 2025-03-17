## INDEX

- [EX 02](#ex-02)
	- [Description](#description)

---
# EX 02

## Description

Now, time to move on more serious things. Let’s develop something weird.
이제, 진지한 주제로 넘어가서 뭔가 이상한걸 만들어 보자.      

`std::stack` 컨테이너는 아주 훌륭하다.    
하지만 안타깝게도 STL 컨테이너들 중에서 유일하게 반복자를 사용하지 못한다.    
참으로 안타깝다.        

하지만 그렇다고 우리가 이러한 상황을 받아들여야 하는가?   
특히 원래 stack을 변형하여 누락된 기능을 추가할 수 있음에도 불구하고 말이다.     

이 부당함을 바로잡기 위해, 너는 반복자가 존재하는 `std::stack` 컨테이너를 만들어야 한다.      

MutantStack 클래스를 작성하라 이는 `std::stack`을 기반으로 구현 되어야 한다.      


`std::stack`의 모든 멤버 함수를 제공하는 동시에, 추가적인 기능으로 반복자를 제공하여야 한다.     

물론, 모든 기능이 제대로 동작하는지 확인하기 위해 직접 테스트를 작성하고 제출하여야 한다.     

아래에 테스트 예제가 있다.    

```c++
int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}
```

먼저 `MutantStack`을 사용하여 테스트를 실행한 후, MutantStack을 예를 들어 `std::list`로 교체하여 다시 실행했을 때, 두 출력이 동일해야 한다.      

당연히, 다른 컨테이너를 테스트할 때에는 아래 코드에서 적절한 멤버 함수로 수정해야 한다.   
(push() -> push_back())   



**Solution:**

stack은 기존의 컨테이너(`std::deque`)를 기반으로 동작하는 `Container Adapter`이다.   
그렇기에 직접 반복자를 제공하지 않는다.    

`Container Adapter`는 특정 목적에 맞게 사용하기 쉽게 만든 컨테이너로 `std::stack`은 LIFO를 보장함과 동시에 사용하기 쉽게 설계된 어댑터이다.   

이러한 컨테이너 어댑터에 반복자를 추가함으로서 `std::list` 와 같은 반복자를 사용하는 다른 컨테이너 처럼 동작할 수 있어야 한다는 것이다.   