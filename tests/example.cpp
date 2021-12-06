// Copyright 2021 Evgenzayts evgenzaytsev2002@yandex.ru

#include <stdexcept>
#include <gtest/gtest.h>
#include <Investigation.h>

#include <example.hpp>

auto example() -> void {
    one_investigation({64, 128, 256}, "mode");
}

TEST(CacheTest, ModeError) {
    EXPECT_THROW(example(), std::runtime_error);
}
