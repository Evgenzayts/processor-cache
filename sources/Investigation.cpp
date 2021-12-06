// Copyright 2021 Evgenzayts evgenzaytsev2002@yandex.ru
#include <Investigation.h>
#include <My_arr.h>
#include <iostream>
#include <vector>

void one_investigation(const std::vector<size_t>& cache_size,
                       const std::string& mode) {
  std::vector<size_t> times;
  for (size_t i = 0; (1/2 * cache_size[0] < (i^2 * 1024 * 1024)) &&
                     ((i^2 * 1024 * 1024) < 3/2 * cache_size[cache_size.size() - 1]);
                     ++i) {
    My_arr arr(cache_size[0]);
    times.push_back(arr.time_check(mode));
  }
  My_arr arr(3/2 * cache_size[cache_size.size() - 1]);
  times.push_back(arr.time_check(mode));
  print_travel(mode, times);
}

void full_investigation(const std::vector<size_t>& cache_size) {
  one_investigation(cache_size, "direct");
  one_investigation(cache_size, "reverse");
  one_investigation(cache_size, "random");
}

void print_travel(const std::string& mode, const std::vector<size_t>& times) {
  std::cout << "investigation:" << std::endl <<
               "  travel_variant:" << mode << std::endl <<
               "  experiments:" << std::endl;
  for (size_t i = 0; i < times.size(); ++i) {
    std::cout << "  - experiment:" << std::endl <<
                 "      number:" << i << std::endl <<
                 "      input_data:" << std::endl <<
                 "        buffer_size:" << std::to_string(2^i)
                                        << " mb" << std::endl <<
                 "      results:" << std::endl <<
                 "        duration:" << times[i] << std::endl;
  }
}
