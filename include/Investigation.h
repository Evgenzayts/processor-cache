// Copyright 2021 Evgenzayts evgenzaytsev2002@yandex.ru

#ifndef TEMPLATE_INVESTIGATION_H
#define TEMPLATE_INVESTIGATION_H

#include <iostream>
#include <vector>

void one_investigation(const std::vector<size_t>& cache_size,
                       const std::string& mode);
void full_investigation(const std::vector<size_t>& cache_size);
void print_travel(const std::string& mode, const std::vector<size_t>& times);

#endif  // TEMPLATE_INVESTIGATION_H
