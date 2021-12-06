#include <Investigation.h>
#include <example.hpp>
#include <iostream>

int main() {

  const std::vector<size_t> cache_size{256 * 1024, 1024 * 1024, 8 * 1024 * 1024};
  full_investigation(cache_size);

  example();
  return 0;
}