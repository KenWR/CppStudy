#include <iostream>
using namespace std;

int main() {
  int a = 0;
  int z = 10;

  // 값 변경 불가
  const int *b = &a;
  a = 1;
  // *b = 1;
  b = &z;
  cout << *b << endl;

  // 주소 변경 불가
  int *const c = &a;
  a = 2;
  *c = 2;
  // c = &z;
  cout << *c << endl;

  // 값 변경, 주소 변경 불가
  const int *const d = &a;
  a = 3;
  // *d = 21;
  // d = &z;
  cout << *d << endl;

  return 0;
}