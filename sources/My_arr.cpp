// Copyright 2021 Evgenzayts evgenzaytsev2002@yandex.ru

#include <My_arr.h>

unsigned int* seed = new unsigned int;

My_arr::My_arr(const size_t& size) {
  _arr = new int[size];
  _size = size;
  for (size_t i = 0; i < _size; ++i) {
    _arr[i] = rand_r(seed);
  }
}

My_arr::My_arr() {
  _arr = new int[64];
  _size = 64;
  for (size_t i = 0; i < 64; ++i) {
    _arr[i] = rand_r(seed);
  }
}
void My_arr::warmup() {
  [[maybe_unused]] int k = 0;
  for (size_t i = 0; i < _size; i += 16) {
    k = _arr[i];
  }
}
double My_arr::read_direct() {
  [[maybe_unused]] int k = 0;
  auto start = clock();
  for (size_t i = 0; i < 1000; ++i) {
    for (size_t j = 0; j < _size; j += 16) {
      k = _arr[j];
    }
  }
  auto end = clock();

  double result = static_cast<double>(end - start) / CLOCKS_PER_SEC;

  return result;
}

double My_arr::read_reverse() {
  [[maybe_unused]] int k = 0;
  auto start = clock();
  for (size_t i = 0; i < 1000; ++i) {
    for (int j = _size - 1; j >= 0; j -= 16) {
      k = _arr[j];
    }
  }
  auto end = clock();

  double result = static_cast<double>(end - start) / CLOCKS_PER_SEC;

  return result;
}

double My_arr::read_rand() {
  [[maybe_unused]] int k = 0;



  auto start = clock();
  for (size_t i = 0; i < 1000; ++i) {
    for (size_t j = 0, count = 0;
         count < _size;
         j = rand_r(seed) % _size, count += 16) {
      k = _arr[j];
    }
  }
  auto end = clock();

  double result = static_cast<double>(end - start) / CLOCKS_PER_SEC;

  return result;
}

double My_arr::time_check(const std:: string& mode) {
  warmup();

  double result;

  if (mode == "direct") {
    result = read_direct();
  } else if (mode == "reverse") {
    result = read_reverse();
  } else if (mode == "random") {
    result = read_rand();
  } else {
    throw std::runtime_error("Incorrect read mode");
  }

  return result;
}

My_arr::~My_arr() {
  delete _arr;
}
