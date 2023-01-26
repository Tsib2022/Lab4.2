#include <iostream>
#include <cstdint>
#include <string>
#include <algorithm>
#include <cassert>
 
char nibble_to_hex(uint8_t i) {
  assert(0x0 <= i && i <= 0xf);
  if (0 <= i && i < 10) {
    return '0' + i;
  } else {
    return 'A' + i - 10;
  }
}
 
void print_in_hex(uint8_t byte) {
  std::cout << nibble_to_hex(byte >> 4);
  std::cout << nibble_to_hex((byte & 0xF));
}
 
void print_in_binary(uint8_t byte) {
  uint8_t mask = 1u << 7;
  while (mask != 0) {
    std::cout << ((byte & mask) == mask);
    mask >>= 1;
  }
 
}
 
const uint8_t* as_bytes(const void* data) {
  return reinterpret_cast<const uint8_t*>(data);
}
 
void print_in_hex(const void* data, size_t size) {
  const uint8_t* bytes = as_bytes(data);
  for (size_t i = 0; i < size; ++i) {
    print_in_hex(bytes[i]);
    if ((i + 1) % 16 == 0) {
      std::cout << std::endl;
    } else {
      std::cout << " ";
    }
  }
}
 
void print_in_binary(const void* data, size_t size) {
  const uint8_t* bytes = as_bytes(data);
  for (size_t i = 0; i < size; ++i) {
    print_in_binary(bytes[i]);
    if ((i + 1) % 4 == 0) {
      std::cout << std::endl;
    } else {
      std::cout << " ";
    }
  }
}
 
int main() {
  uint16_t first, second;
  char op;
  std::cin >> first >> op >> second;
  uint16_t result = 0;
  switch (op) {
    case '&':
      result = first & second;
    break;
    case '|':
      result = first | second;
    break;
    case '^':
      result = first ^ second;
    break;
  }
  print_in_hex(&first, sizeof(first));
  std::cout << op << " ";
  print_in_hex(&second, sizeof(first));
  std::cout << "= ";
  print_in_hex(&result, sizeof(first));
 
  std::cout << "\n";
  print_in_binary(&first, sizeof(first));
  std::cout << op << " \n";
  print_in_binary(&second, sizeof(first));
  std::cout << "= \n";
  print_in_binary(&result, sizeof(first));
  std::cout << "\n";
 
}
