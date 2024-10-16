## INDEX

- [GOAL](#goal)
- [IMPLEMENT](#implement)
		- [static\_cast 를 사용해야하는이유](#static_cast-를-사용해야하는이유)
---   

# GOAL

메가폰 서브젝트

아주 간단한 서브젝트이다   
주어진 문자열들을 전부 대문자로 반환하는 프로그램을 작성하면 된다

e.g.
```bash
$>./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
$>
```

Solve the exercises in a C++ manner.
(C++스럽게 문제를 풀어라)

여기서 주의해야 할 부분은 다음과 같다
```bash
$>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
$>
```
아무것도 입력 받지 않았을 때, "* LOUD AND UNBEARABLE FEEDBACK NOISE *" 를 stdout으로 출력해야한다


# IMPLEMENT

소문자로 들어온 charactor를 <cctype> 헤더에 선언된 toupper() 함수를 사용하여 대문자로 바꿔 주었고

해당 toupper() 함수의 원형은   
```c++
int toupper(int c);
```
이기에 std::cout의 특성상 int형을 그대로 출력하기에 char 로 형변환하여 출력하도록 하였다

문제는 C++스러운게 무엇인가에 꽂혔다   
사실 이 질문을 같이 공부하시는 분으로부터 받았는데 `cout`, `cin`만으로 충분하다고 여겼으나 그게 아니었던 것 같다
그래서 반복문 부분에서 인덱스로 하나하나 접근하는 것을 `iterator`를 이용하여 풀기로 했다

```c++
for (int i = 1; av[i]; i++) {
	for (int j = 0; av[i][j]; j++) {
		std::cout << (char)toupper(av[i][j]);
	}
}
```
에서
```c++
for (char **arg = argv + 1; *arg != nullptr; ++arg) {
    std::string str = *arg;
	for (std::string::iterator it = str.begin(); it != str.end(); it++) {
		std::cout << (char)toupper(*it);
	}
}
```
로

이러면 좀더 c++스러워지지 않았을까..?

### static_cast 를 사용해야하는이유

컴파일단계에서 타입 변환 에러를 감지할 수 있기에 사용하는것이 안전하다고 한다

[stack overflow](https://stackoverflow.com/questions/103512/why-use-static-casttx-instead-of-tx)
