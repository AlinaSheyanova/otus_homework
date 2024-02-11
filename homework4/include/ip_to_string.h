/**
 * @file ip_to_string.h
 * @author Smirnova Alina
 * @date 11 Feb 2024
 * @brief otus homework #4
 */

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cstdint>
#include <sstream>
#include <tuple>


template<typename T>
std::enable_if_t<std::is_arithmetic_v<T> && std::is_trivial_v<T>,
        std::string>
ip_to_string(const T &value) {
    size_t count = sizeof(T);
    std::stringstream ss;
    uint8_t *source = (uint8_t *) &value;
    for (int i = count - 1; i >= 0; --i) {
        auto e = source[i];
        ss << (int) e << ((i != 0) ? "." : "");
    }
    return ss.str();
}

template<typename T>
inline constexpr bool is_std_string = std::is_same_v<typename std::string,
        std::remove_const_t<std::remove_reference_t<T>>>;


template<typename T>
std::enable_if_t<is_std_string<T>,
        std::string>
ip_to_string(const T &value) {
    return value;
}

template<typename T>
std::enable_if_t<std::is_same_v<decltype(begin(std::declval<T>()), end(std::declval<T>()), T()), T>
                 && !is_std_string<T>,
        std::string>
ip_to_string(const T &value) {
    std::stringstream ss;
    std::string delim = "";
    for (auto e : value) {
        ss << delim << e;
        delim = ".";
    }
    return ss.str();
}

template<std::size_t I = 0, typename T, typename... Elements>
inline typename std::enable_if_t<I == std::tuple_size<T>::value>
toStringStream(std::stringstream &ss, T &t) {
}

template<std::size_t I = 0, typename T, typename... Elements>
inline typename std::enable_if_t<I < std::tuple_size<T>::value>
toStringStream(std::stringstream &ss, T &t) {
    ss << std::get<I>(t) << ((I != std::tuple_size<T>::value - 1) ? "." : "");
    toStringStream<I + 1, Elements...>(ss, t);
}

template<typename T, typename... Elements>
std::enable_if_t<(std::tuple_size<T>::value > 1), std::string>
ip_to_string(const T &value) {
    std::stringstream ss;
    toStringStream(ss, value);
    return ss.str();
}
