// Copyright 2021 Evgenzayts evgenzaytsev2002@yandex.ru

#include <Investigation.h>
#include <My_arr.h>
#include <cmath>

void one_investigation(const std::vector<double>& cache_size,
                       const std::string& mode) {
  if (cache_size.empty()) {
    throw std::runtime_error("Empty array");
  }

  std::vector< std::pair<double, double> > times;

  double i = 0;
  while ((0.5 * cache_size[0] <= pow(2, i)) &&
         (pow(2, i)) <= (1.5 * cache_size.back())) {
    My_arr arr(size_t(pow(2, i)) * 1024 * 1024);
    times.emplace_back(std::make_pair(size_t(pow(2, i)),
                                      arr.time_check(mode)));
    ++i;
  }
  My_arr arr(size_t(1.5 * cache_size.back() * 1024 * 1024));
  times.emplace_back(std::make_pair(1.5 * cache_size.back(),
                                    arr.time_check(mode)));

  print_travel(mode, times);
}

void full_investigation(const std::vector<double>& cache_size) {
  one_investigation(cache_size, "direct");
  one_investigation(cache_size, "reverse");
  one_investigation(cache_size, "random");
}

void print_travel(const std::string& mode,
                  const std::vector< std::pair<double, double> >& times) {
  std::cout << "investigation:" << std::endl <<
               "  travel_variant: " << mode << std::endl <<
               "  experiments:" << std::endl;
  for (size_t i = 0; i < times.size(); ++i) {
    std::cout << "  - experiment:" << std::endl <<
                 "      number: " << i + 1 << std::endl <<
                 "      input_data:" << std::endl <<
                 "        buffer_size: " << times[i].first
                                        << " mb" << std::endl <<
                 "      results:" << std::endl <<
                 "        duration: " << times[i].second << " s" << std::endl;
  }
}
