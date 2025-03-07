#include <iostream>
using namespace std;

int gloval = 0;
const int global_const = 0;

int main() {
  int local = 0;
  const int local_const = 0;
  int *heap = new int(0);
  const int *heap_const = new int(0);

  cout << "global: " << &gloval << endl;
  cout << "global_const: " << &global_const << endl;
  cout << "local: " << &local << endl;
  cout << "local_const: " << &local_const << endl;
  cout << "heap: " << heap << endl;
  cout << "heap_const: " << heap_const << endl;

  delete heap;
  delete heap_const;
  return 0;
}

/**
 * Output in windows:
 * 	global: 0x7ff6cc957030
 * 	global_const: 0x7ff6cc954000
 * 	local: 0xefdfdffd9c
 * 	local_const: 0xefdfdffd98
 * 	heap: 0x2d267e553a0
 * 	heap_const: 0x2d267e4eec0
 *
 *
 * Output in MACOS:
 * 	global: 0x1000080d0
 * 	global_const: 0x100003f60
 * 	local: 0x1049146c8
 * 	local_const: 0x1049146c4
 * 	heap: 0x10082c680
 * 	heap_const: 0x10082c6d0
 * global: 0x7ff6cc957030
 */