// Copyright 2021 Evgenzayts evgenzaytsev2002@yandex.ru

#include <My_arr.h>

My_arr::My_arr(const size_t& size) {
  _arr = new int[size];
  _size = size;
  for (size_t i = 0; i < size; ++i) {
    _arr[i] = rand();
  }
}

My_arr::My_arr() {
  _arr = new int[64];
  _size = 64;
  for (size_t i = 0; i < 64; ++i) {
    _arr[i] = rand();
  }
}
void My_arr::warmup() {
  [[maybe_unused]] int k = 0;
  for (size_t i = 0; i < _size; i += 16) {
    k = _arr[i];
  }
}
void My_arr::read_direct() {
  [[maybe_unused]] int k = 0;
  for (size_t i = 0; i < 1000; ++i) {
    for (size_t j = 0; j < _size; j += 16) {
      k = _arr[j];
    }
  }
}

void My_arr::read_reverse() {
  [[maybe_unused]] int k = 0;
  for (size_t i = 0; i < 1000; ++i) {
    for (size_t j = _size; j > 0; j -= 16) {
      k = _arr[j];
    }
  }
}

void My_arr::read_rand() {
  [[maybe_unused]] int k = 0;
  for (size_t i = 0; i < 1000; ++i) {
    for (size_t j = 0, count = 0; count < _size; j = rand() % _size, ++count) {
      k = _arr[j];
    }
  }
}

size_t My_arr::time_check(const std:: string& mode) {
  warmup();

  auto start = clock();
  if (mode == "direct") {
    read_direct();
  } else if (mode == "reverse") {
    read_reverse();
  } else if (mode == "random") {
    read_rand();
  } else {
    throw std::runtime_error("Incorrect read mode");
  }
  auto end = clock();

  size_t result = double(end - start) / CLOCKS_PER_SEC * 1000000;
  return result;
}

My_arr::~My_arr() {
  delete _arr;
}
