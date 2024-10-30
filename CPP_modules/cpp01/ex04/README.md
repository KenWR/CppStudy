## INDEX

- [CPP\_01: EX\_04](#cpp_01-ex_04)
	- [Description](#description)
	- [Implement](#implement)

---
# CPP_01: EX_04

## Description

stream 편집기를 구현 하라   

## Implement

**open()** 을 사용했던 C와는 달리 직접 Input/Output file Stream 객체의 인스턴스를 선언하여 손쉽게 사용할 수 있다   

```c++
std::string filename(argv[1]);

std::ifstream 	inputFile(filename.c_str());
std::ofstream 	outputFile((filename + REPLACE).c_str());
```

문제는 파일 스트림객체 생성자 매개변수로 **std::string**을 넘기는 것은 `C++11` 부터 가능하기에 **c_str()** 으로 **char\*** 변환하여 사용 하였다   


```c++
std::ofstream stream;

stream.open(filename + REPLACE);
stream.close();
```

원래는 객체 자체를 선언하여 객체의 **open()** 멤버 함수를 사용하면 string을 매개변수로 넘겨 사용 할 수 있으나 이는 일일이 **close()** 멤버 함수를 통해 닫아주어야 하기에 편리성을 위해 위의 방법을 사용 하였다   

