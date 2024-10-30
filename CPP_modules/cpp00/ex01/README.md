## INDEX
- [CPP\_00: EX\_01](#cpp_00-ex_01)
  - [Description](#description)
  - [Implement](#implement)
  - [P.S.](#ps)
    - [cin이 eof를 만나게 된다면 feat. getline()](#cin이-eof를-만나게-된다면-feat-getline)
    - [cin과 getline의 만남](#cin과-getline의-만남)

---

# CPP_00: EX_01

## Description

두개의 클래스를 구현하라

- PhoneBook(전화번호부)   
	- It has an array of contacts.
		(연락처 배열을 가지고 있어야 한다)   
	- It can store a maximum of 8 contacts. If the user tries to add a 9th contact, replace the oldest one by the new one.   
		(최대 8개의 연락처를 저장할 수 있으며, 만약 9번째 연락처를 추가하고자 한다면, 가장 오래된 연락처를 새 연락처로 교체해야 한다)
	- Please note that dynamic allocation is forbidden.   
		(동적 할당은 금지되어 있다)

- Contact(연락처)
  - Stands for a phonebook contact.
	(전화번호부의 연락처를 나타낸다)


In your code, the phonebook must be instantiated as an instance of the PhoneBook class.     
(전화번호부는 PhoneBook 클래스의 인스턴스로 생성되어야 한다)

Same thing for the contacts.    
(연락처도 동일하다)

Each one of them must be instantiated as an instance of the Contact class.    
(Contact 클래스의 인스턴스로 각 연락처를 생성하여야 한다)

You’re free to design the classes as you like but keep in mind that anything that will always be used inside a class is private, and that anything that can be used outside a class is public.   
(클래스 설계는 자유롭게 할 수 있지만, 클래스 내에서 항상 사용되는 항목은 pirvate로, 외부에서 사용해야하는 항목은 public으로 설정하여야 한다)

On program start-up, the phonebook is empty and the user is prompted to enter one of three commands.    
(프로그램이 시작되면, 전화번호부는 비어있으며, 사용자에게 3가지 명령중 하나를 입력하라는 프롬프트가 나타난다)

The program only accepts ADD, SEARCH and EXIT.   
(프로그램은 오직 ADD, SEARCH, EXIT 명령만 받아 들인다)

- ADD: save a new contact   
	(추가: 새로운 연락처 저장)

	- If the user enters this command, they are prompted to input the information of the new contact one field at a time.    
		(사용자가 이 명령을 입력하면, 연락처 정보를 하나씩 입력하도록 프롬프트가 나타난다)
  	Once all the fields have been completed, add the contact to the phonebook.   
		(모든 필드가 입력되면 연락처를 전화번호부에 추가해야 한다)
	The contact fields are: first name, last name, nickname, phone number, and darkest secret.    
		(연락처의 필드는 다음과 같다: 이름, 성, 별명, 전화번호, 가장 어두운 비밀)
	A saved contact can’t have empty fields.
		(저장된 연락처는 빈 필드를 가질 수 없다)

- SEARCH: display a specific contact   
	(탐색: 특정 연락처 보기)
    - Display the saved contacts as a list of 4 columns: index, first name, last name and nickname.   
		(저장된 연락처를 4개의 열로 나누어 표시한다:
		인덱스, 이름, 성, 별명) 
	Each column must be 10 characters wide.
		(각 열의 너비는 10자이다) 
	A pipe character (’|’) separates them.   
		(각 열은 '|'로 구분된다)
	The text must be right-aligned. 
		(텍스트는 오른쪽 정렬로 이루어져 있어야 한다)
	If the text is longer than the column, it must be truncated and the last displayable character must be replaced by a dot (’.’).   
		(텍스트가 열의 너비보다 길면, 마지막 글자를 '.'으로 대체하여 잘라낸다)
    - Then, prompt the user again for the index of the entry to display.
		(그러고, 다시 인덱스를 입력하도록 프롬프트를 표시애야 한다)
	If the index is out of range or wrong, define a relevant behavior.    
		(만일 인덱스가 범위를 벗어나거나 잘못된 경우, 적절한 동작을 정의 해야한다)
	Otherwise, display the contact information, one field per line.
		(올바른 인덱스인 경우 해당 연락처의정보를 한 줄씩 표시해야 한다)
    
- EXIT   
	(종료)
    - The program quits and the contacts are lost forever!
		(프로그램을 종료하고 모든 연락처를 영원히 잃게 된다)

Any other input is discarded.   
	(그 외의 입력은 무시된다)

	Once a command has been correctly executed, the program waits for another one.   
	(명령이 정상적으로 실행된 후, 프로그램은 다른 명령을 기다린다)  

	It stops when the user inputs EXIT.    
	(사용자가 EXIT를 입력하면 프로그램이 종료된다)
	
Give a relevant name to your executable.   
(실행파일에는 적절한 이름을 지어 주어라)

[string](http://www.cplusplus.com/reference/string/string/)      
[iomanip](http://www.cplusplus.com/reference/iomanip/)      



## Implement

연락처 정보를 가지고 있는 Contact 클래스, Contact 클래스를 최대 8개까지 가지고 있는 PhoneBook 클래스를 구현해야 한다

그리고 추가적으로 ADD, SEARCH, EXIT 함수를 추가적으로 구현해주어야 한다

이 과제를 처음 보고 이해했을때, 나는 위의 세 기능을 어느 클래스에 추가해야할지 의문이었다

처음에는 독립된 함수로서 두 클래스를 이용하는 일반적인 함수로 사용 하려고 했으나, 어떻게보면 PhoneBook의 기능이라 판단하여 PhoneBook 클래스에 넣기로 했다

또한, 임의의 연락처와 전화번호부의 정보에 접근하지 못하도록 변수들을 전부 private 접근 제어자로 막아두었다

contact 클래스의 멤버변수를 배열로 선언해 phonebook클래스의 멤버변수로 선언하고 싶었으나 contact 클래스의 멤버변수를 public에 선언해야한다는 점이 맘에 들지 않아 그냥 일반적인 [8][5] 배열로 선언하고 매크로를 통해 지정해 두었다   

SEARCH 입력시 나오는 출력문을 `<iomanip>` 헤더를 사용해 출력문을 조정하였다

기본적인 stream과 클래스 선언 및 구조를 알아갈 수 있는 과제였다

## P.S.

### cin이 eof를 만나게 된다면 feat. getline()

`cin이` `eof`를 만나게 된다면 `std::ios_base::iostate`에 있는 `eofbit`를 `1`로 설정하게 된다   
우리는 이를 통해 프로그램의 로직에 따라 프로그램의 흐름을 제어 할 수 있게 된다

지금 현재 만들고자하는 전화번호부 프로그램을 예시로 들어보자,   
우리는 터미널을 통해 연락처의 정보를 받고 이를 전화번호부에 저장을 한다   
허나, 연락처 필드는 모두 값이 존재해야하고, 

[std::ios_base::iostate](https://en.cppreference.com/w/cpp/io/ios_base/iostate)
에서 std::getline과 basic_istream::operator>>를 통해 eofbit가 1로 설정됨을 알 수 있다

`cin.clear()`를 통해 비트를 모두 초기화 하고 다시 이어나갈수 있음

하지만 여기서 문제가 생기는데 `cin stream`의 `iostate`의 비트들을 분명히 초기화 했음에도 불구하고 getline()함수를 실행할때 eofbit가 다시 설정되어 입력이 제대로 이루어지지 않음을 볼 수 있었다

이는 `clearerr(stdin)`라는 함수를 통해 해결할 수 있었다

[clearerr()](http://www.jbox.dk/sanos/source/lib/stdio.c.html)
해당 함수를 보면 FILE 구조체 내부에서 입출력을 제어하는 flag를 초기화 해주는것을 볼 수 있다

`cin.clear()`가 초기화하는 대상은 stream 객체이며 `clearerr()`가 초기화 하는 대상은 FILE구조체이므로 이 둘의 메모리 영역은 같을 가능성이 매우 낮다고 판단이 들었다   

그렇다면 `getline()` 함수에서 참조하는 `iostate`가 `cin.clear()`가 초기화 하는 `iostate`가 아니라 FILE 구조체가 아닐까? 하는 생각이 들었다   
하지만 찾아본 결과 `getline()`이 참조하는것은 매개변수로 들어온 `stream의 iostate`를 참조하는것을 알 수 있었다(std::cin의 iostate)   
`cin.clear()`가 초기화 하는 메모리영역과 `getline()`이 참조하는 메모리 영역이 같음으로 의문은 더 깊어져갔다   

```c++
template <class _CharT, class _Traits>
basic_istream<_CharT, _Traits>::sentry::sentry(basic_istream<_CharT, _Traits>& __is,
                                               bool __noskipws)
    : __ok_(false)
{
    if (__is.good())
    {
        if (__is.tie())
            __is.tie()->flush();
        if (!__noskipws && (__is.flags() & ios_base::skipws))
        {
            typedef istreambuf_iterator<_CharT, _Traits> _Ip;
            const ctype<_CharT>& __ct = use_facet<ctype<_CharT> >(__is.getloc());
            _Ip __i(__is);
            _Ip __eof;
            for (; __i != __eof; ++__i)
                if (!__ct.is(__ct.space, *__i))
                    break;
            if (__i == __eof)
                __is.setstate(ios_base::failbit | ios_base::eofbit);
        }
        __ok_ = __is.good();
    }
    else
        __is.setstate(ios_base::failbit);
}
```


```c++
template<class _CharT, class _Traits, class _Allocator>
basic_istream<_CharT, _Traits>&
getline(basic_istream<_CharT, _Traits>& __is,
        basic_string<_CharT, _Traits, _Allocator>& __str, _CharT __dlm)
{
    ios_base::iostate __state = ios_base::goodbit;
    typename basic_istream<_CharT, _Traits>::sentry __sen(__is, true);
    if (__sen)
    {
#ifndef _LIBCPP_NO_EXCEPTIONS
        try
        {
#endif
            __str.clear();
            streamsize __extr = 0;
            while (true)
            {
                typename _Traits::int_type __i = __is.rdbuf()->sbumpc();
                if (_Traits::eq_int_type(__i, _Traits::eof()))
                {
                   __state |= ios_base::eofbit;
                   break;
                }
                ++__extr;
                _CharT __ch = _Traits::to_char_type(__i);
                if (_Traits::eq(__ch, __dlm))
                    break;
                __str.push_back(__ch);
                if (__str.size() == __str.max_size())
                {
                    __state |= ios_base::failbit;
                    break;
                }
            }
            if (__extr == 0)
               __state |= ios_base::failbit;
#ifndef _LIBCPP_NO_EXCEPTIONS
        }
        catch (...)
        {
            __state |= ios_base::badbit;
            __is.__setstate_nothrow(__state);
            if (__is.exceptions() & ios_base::badbit)
            {
                throw;
            }
        }
#endif
        __is.setstate(__state);
    }
    return __is;
}
```
위에서 스트림의 iostate를 참조하는것을 볼 수 있다

그렇다면 getline() 함수에서의 문제가 아닌 stream 내부에서 C의 파일디스크립터 flag를 확인하는게 아닐까? 하는 생각이들었다   
그렇게 stream 내부를 조사를 하였고 전부 확인은 하지 못하였으나 <cstdio>를 그대로 가져와 사용하는 몇몇 모습을 볼 수 있었는데 이로 유추할수 있는 내용으로는 stream에서 eofbit를 확인하는 과정에서 C의 I/O를 먼저 확인하는 어떤 조치가 취해졌음을 알 수 있다
그렇기에 두 곳의 flag들을 초기화 시켜주어야 다시 입력을 받을 수 있는 초기상태로 돌아올 수 있는 것이다


### cin과 getline의 만남

`cin >>` 은 iostream에 `\n`을 남겨둔다   
getline이 `cin >>` 뒤에 사용되면 getline은 이 `\n`을 보고 이 줄이 끝났다고 판단하여 더이상 읽지 않는다

```c++
#include <iostream>
using namespace std;

int	main(void) {
	std::string cin_input;
	std::string	getline_input;

	cout << "enter name" << endl;

	cin >> cin_input;
	getline(cin, getline_input);

	cout << "your name is" << endl;

	cout << cin_input << endl;
	cout << getline_input << endl;
}
```
```bash
enter name
jiwojung
your name is
jiwojung

```

이러한 문제를 해결하기 위해서는 이 순서를 반대로 두거나, getline을 호출하기전에 남은 줄바꿈 문자를 없애는 방법이 있다   

줄바꿈 문자를 지우는 방법에는 getline을 그 전에 한번 호출하거나 `cin.ignore(100, '\n');` 과 같은 코드를 사용한다   
해당 코드의 내용을 해석하면 100개의 문자 or `\n`을 만나기 전까지 문자를 무시하고 건너뛰는 것이다
