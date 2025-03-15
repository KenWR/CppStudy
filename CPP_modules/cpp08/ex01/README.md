## INDEX

- [EX 01](#ex-01)
	- [Description](#description)

---
# EX 01

## Description

최대 N개의 정수를 받을 수 있는 Span 클래스를 개발하라.   

N은 unsigned int 타입으로 오직 생성자의 매개변수로만 받을 수 있다.   

Span 클래스에 숫자 하나를 추가하는 addNumber() 멤버 함수를 추가하라.   
이 함수는 순서대로 숫자를 채운다.   
이미 N개의 요소들을 저장하고 있다면 예외를 던져야 한다.   

두개의 멤버 함수를 구현하라.   
shortestSpan()   
저장된 모든 숫자들로부터 가장 가까운 거리를 찾아내어 반환하는 함수.   
longestSpan()   
저장된 모든 숫자들로부터 가장 먼 거리를 찾아내어 반환하는 함수.   

숫자가 하나밖에 없거나 아예 없어서 Span을 구할 수 없는 경우, 예외를 던진다.   

최소한 10 000 개의 숫자들로 테스트 해보라.

아래와 같은 코드가 동작할 수 있어야 한다:   
```
int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}
```

Should output:   
```
$> ./ex01
2
14
$>
```

Last but not least, it would be wonderful to fill your Span using a range of iterators.
Making thousands calls to addNumber() is so annoying. Implement a member function
to add many numbers to your Span in one call.
If you don’t have a clue, study the Containers. Some member
functions take a range of iterators in order to add a sequence of
elements to the container.
