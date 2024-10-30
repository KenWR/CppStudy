## INDEX  

- [CPP\_02: EX\_02](#cpp_02-ex_02)
	- [Description](#description)
	- [Implement](#implement)
	

---

# CPP_02: EX_02

## Description

연산자 오버로딩을 통한 고정 소수점 연산을 구현하라

## Implement

산술, 비교, 증감 연산자와 min, max를 정의하였다

이들은 모두 비슷하지만 Fixed는 고정소수점을 표현하는 클래스로서 +, - 연산은 고정소수점의 장점을 살리는것이 좋다고 판단하였다   

```c++
// 고정소수점 연산 사용
Fixed Fixed::operator+(const Fixed& src) const {
	return static_cast<float>(this->getRawBits() + src.getRawBits()) / BITS_MOVE;
}

Fixed Fixed::operator-(const Fixed& src) const {
	return static_cast<float>(this->getRawBits() - src.getRawBits()) / BITS_MOVE;
}

// 부동소수점 연산 사용
Fixed Fixed::operator*(const Fixed& src) const {
	return this->toFloat() * src.toFloat();
}

Fixed Fixed::operator/(const Fixed& src) const {
	return this->toFloat() / src.toFloat();
}
```

