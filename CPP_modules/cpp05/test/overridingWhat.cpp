#include <exception>
#include <iostream>
#include <string>

class ArrayException : public std::exception {
private:
	std::string m_error;

public:
	ArrayException(std::string error) : m_error(error) {}
	// std::runtime_error를 상속받는다면 std::runtime_error는 문자열을 처리할 수 있는 기능이 있기에 std::exception 보다 널리 사용됨
	// ArrayException(std::string& error) : m_error(error) {} 

	// std::runtime_error를 상속받는다면 별도로 문자열 처리를 위한 overriding필요 없음
	const char* what() const noexcept override { return m_error.c_str(); }
};

class IntArray {
private:
	int m_data[3];

public:
	IntArray() {}
	int getLength() const { return 3; }
	int& operator[](const int index) {
		if (index < 0 || index >= getLength()) throw ArrayException("Invalid index");
		return m_data[index];
	}
};

int main() {
	IntArray array;

	try { int value(array[5]); }
	catch (const ArrayException& exception) { std::cerr << exception.what() << std::endl; }
	catch (const std::exception& exception) { std::cerr << exception.what() << std::endl; }
}

// exception클래스로부터 상속을 받아 ArrayException를 직접 정의
// what 함수를 오버라이딩하여 원하는 메시지를 예외 발생시 반환하도록 설정