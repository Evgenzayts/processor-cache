// Copyright 2021 Evgenzayts evgenzaytsev2002@yandex.ru

#ifndef TEMPLATE_MY_ARR_H
#define TEMPLATE_MY_ARR_H

#include <iostream>

class My_arr {
 private:
  int* _arr;
  size_t _size;

 public:
  My_arr();
  My_arr(const size_t& size);

 private:
  void warmup();
  void read_direct();
  void read_reverse();
  void read_rand();

 public:
  size_t time_check(const std::string& mode);

  ~My_arr();
};

#endif  // TEMPLATE_MY_ARR_H
