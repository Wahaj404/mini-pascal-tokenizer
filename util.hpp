#ifndef __UTIL_HPP__
#define __UTIL_HPP__

#include <string>

std::string csv(int const i);
template <typename... Ts>
std::string csv(int const i, Ts... args);

std::string csv(std::string const &s);
template <typename... Ts>
std::string csv(std::string const &s, Ts... args);

template <typename... Ts>
std::string csv(int const i, Ts... args) {
    return std::to_string(i) + ',' + csv(args...);
}

template <typename... Ts>
std::string csv(std::string const &s, Ts... args) {
    return '"' + s + '"' + ',' + csv(args...);
}

#endif // __UTIL_HPP__
