## INDEX

- [EX 00](#ex-00)
	- [Description](#description)

---
# EX 00

## Description

Template을 공부하는 과제

3개의 템플릿 함수를 작성하라.   

• swap: 인자로 주어지는 두 값을 swap 하고 아무것도 반환하지 않는 함수   

• min: 인자로 주어진 두 값을 비교하고 그 중 작은 것을 반환한다. (둘다 같다면 두 번째 인자를 반환한다)   

• max: 인자로 주어진 두 값을 비교하고 그 중 큰 것을 반환한다. (둘다 같다면 두 번째 인자를 반환한다)   

이 함수들은 모든 타입의 인자들로부터 호출되어야 한다.   
두 인자들은 타입이 동일해야 하며 모든 비교 연산자를 지원해야 한다.    

템플릿들은 헤더 파일에 선언되어야 한다.    

다음 코드를 실행할 수 있어야 한다:   
```c++
int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}
```

출력:   
```bash
a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2
```