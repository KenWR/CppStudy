#include "Data.hpp"
#include "Serializer.hpp"

#include <cstddef>
#include <iostream>
#include <stdint.h>

int main() {
  Data data1;

  data1.type = "Hello, World!";
  data1.size = 13;

  uintptr_t raw = Serializer::serialize(&data1);
  Data *data2 = Serializer::deserialize(raw);

  std::cout << data2->type << '\n';
  std::cout << data2->size << '\n';
}