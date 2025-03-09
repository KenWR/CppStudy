## INDEX

- [ex02](#ex02)
	- [Description](#description)
	- [Solution](#solution)

---
# ex02
 

## Description

이전 과제는 Bureaucrat 클래스를 통해 Form 클래스에 서명을 하는 것 이었다면, Form 클래스를 실행(execute)하는 과제이다   

이전 과제의 Form 클래스를 상속받는 3개의 concrete 클래스를 만들어라.      
이 클래스들은 ***target*** 을 인자로 받는 생성자를 통해 생성된다.   

- ShrubberyCreationForm    
	sign: 145, exec: 137   
	ASCII trees가 그려진 `target_shrubbery` 라는 파일을 현재 디렉토리에 생성   
- RobotomyRequestForm    
	sign: 72, exec: 45   
	드릴 소리를 낸 후, `target`이 50% 확률로 Lobotomy(전두엽 절제 시술)에 성공/실패 했음을 알린다.   
- PresidentialPardonForm    
	sign: 25, exec: 5   
	`target`이 Zaphod Beeblebrox에 의해 사면되었음을 알린다   
	Zaphod Beeblebrox는 `The Hitchhiker's Guide to the Galaxy`에 등장하는 은하계 대통령이다.   


이제 Base가 되는 Form 클래스는 AForm으로 이름이 변경된다.    
Base Form에 `execute(Bureaucrat const & executor) const` 멤버 함수를 추가하라 이는 세 concrete 클래스들에서 구현이 된다.    


`execute(Bureaucrat const & executor) const` 멤버 함수는 Form이 서명되었는지 확인하며 실행하려는 Bureaucrat의 grade를 확인하며, 적절하지 않은 상황에서는 예외를 던진다.   
던지는 예외를 Base Form에서 처리할지 Concrete Form 에서 처리할지는 구현자의 선택에 따른다.    
(Base Form에서 전부 처리하는 것이 깔끔한 방식이긴 하다.)    


Bureaucrat 클래스에 `executeForm(AForm const & form)` 멤버 함수를 추가하라.   
이 함수는 Form 클래스의 `execute(Bureaucrat const & executor) const` 멤버 함수를 실행하려고 시도 해야 한다.   
성공시 다음과 같은 메시지를 출력하라.   
`bureaucrat` executed `form`
실패시에는 명확한 이유를 포함한 오류 메시지를 출력하라.    

마지막으로 모든 기능이 예상대로 동작하는지 확인할 수 있도록 테스트를 구현하고 제출하라.   

## Solution

우선, Form 클래스가 AForm이 됨으로서 추상클래스가 되었음을 확인할 수 있다.   
이는 곧 `execute(Bureaucrat const & executor) const` 멤버 함수가 AForm 에서는 순수 가상 함수임을 알 수 있다.   
`virtual execute(Bureaucrat const & executor) const = 0`

3개의 concrete 클래스들은 모두 AForm 클래스를 상속받고 위의 순수 가상 함수를 각자의 동작에 맞게 구현하면 된다.    
문제는 Base Form에서 예외를 처리하게 두어야 한다면 `execute(Bureaucrat const & executor) const` 멤버 함수는 순수 가상 함수가 되지 못한다.   
그렇게 되면 AForm 이라는 추상 클래스의 이름에 어긋나므로 따로 `executeForm()` 이라는 순수 가상 함수를 `execute()` 함수 내에서 호출하도록 하고, `executeForm()` 함수를 오버라이딩 하도록 구현한다.

외에는 전부 작성된 대로 구현하면 된다.   

