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
#include <cmath>

/**
 * A function for converting an integer value of any size into a string representation,
 * where bytes are separated by a dot and each byte is represented by a decimal number.
 *
 * @tparam T - a type of function argument
 *
 * @param value - a value for converting
 *
 * @return - a string with dot separated decimal numbers
 */
template<typename T>
std::enable_if_t<std::is_integral_v<T>,
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


/**
 * A function for converting an floating point value of any size into a string representation.
 * This function always returns en empty string, because there are no rules for converting.
 *
 * @tparam T - a type of function argument
 *
 * @param value - a value for converting
 *
 * @return - an empty string
 */
template<typename T>
std::enable_if_t<std::is_floating_point_v<T>,
        std::string>
ip_to_string(const T &value) {
    return "";
}


/**
 * A compile time expression to determinate type "std::string".
 * @tparam T - a type for check
 */
template<typename T>
inline constexpr bool is_std_string = std::is_same_v<typename std::string,
        std::remove_const_t<std::remove_reference_t<T>>>;


/**
 * A function for converting a string value into a string representation.
 * This function always returns the value as is.
 *
 * @tparam T - a type of function argument
 *
 * @param value - a value for converting
 *
 * @return - the argument 'value' as is.
 */
template<typename T>
std::enable_if_t<is_std_string<T>,
        std::string>
ip_to_string(const T &value) {
    return value;
}

/**
 * A function for converting a collections into a string representation,
 * where collection items are separated by a dot.
 *
 * @tparam T - a type of function argument
 *
 * @param value - a value for converting
 *
 * @return - the argument 'value' as is.
 */
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

/**
 * This function overload is necessary to terminate the recursive iteration of elements.
 *
 * @tparam I The index of the current element being processed.
 * @tparam T The tuple type.
 * @tparam Elements The types of the elements in the tuple.
 * @param ss The output stringstream object where the string representation will be written.
 * @param t The tuple object to be converted.
 */
template<std::size_t I = 0, typename T, typename... Elements>
inline typename std::enable_if_t<I == std::tuple_size<T>::value>
toStringStream(std::stringstream &ss, T &t) {
    // This function overload is empty as it serves as the termination condition for the recursive iteration.
    // No further elements need to be processed.
}


/**
 * Converts a tuple of elements to a string representation, with items separated by a dot.
 *
 * @tparam I The index of the current element being processed.
 * @tparam T The tuple type.
 * @tparam Elements The types of the elements in the tuple.
 * @param ss The output stringstream object where the string representation will be written.
 * @param t The tuple object to be converted.
 */
template<std::size_t I = 0, typename T, typename... Elements>
inline typename std::enable_if_t<I < std::tuple_size<T>::value>
toStringStream(std::stringstream &ss, T &t) {
    ss << std::get<I>(t) << ((I != std::tuple_size<T>::value - 1) ? "." : "");
    toStringStream<I + 1, Elements...>(ss, t);
}

/**
 * A function for converting a tuple and pair into a string representation,
 * where tuple or pair items are separated by a dot.
 *
 * @tparam T - a type of function argument
 *
 * @param value - a value for converting
 *
 * @return - the argument 'value' as is.
 */
template<typename T, typename... Elements>
std::enable_if_t<(std::tuple_size<T>::value > 1), std::string>
ip_to_string(const T &value) {
    std::stringstream ss;
    toStringStream(ss, value);
    return ss.str();
}
