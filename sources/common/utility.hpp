/**
 * @file utility.hpp
 * @author Qingyu Chen (chen_qingyu@qq.com, https://chen-qingyu.github.io/)
 * @brief Utility functions for HelloDS.
 * @date 2023.01.05
 *
 * @copyright Copyright (C) 2023
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <algorithm> // std::copy
#include <climits>   // INT_MAX
#include <cmath>     // std::abs
#include <stdexcept> // std::runtime_error
#include <utility>   // std::initializer_list std::move

namespace hellods::internal
{

// Check whether the index is valid (begin <= pos < end).
static inline void check_bounds(int pos, int begin, int end)
{
    if (pos < begin || pos >= end)
    {
        throw std::runtime_error("Error: Index out of range.");
    }
}

// Check whether is not empty.
static inline void check_empty(int size)
{
    if (size == 0)
    {
        throw std::runtime_error("Error: The container is empty.");
    }
}

// Check whether there is any remaining capacity.
static inline void check_full(int size, int capacity)
{
    if (size >= capacity)
    {
        throw std::runtime_error("Error: The container has reached the maximum size.");
    }
}

// Swap the content of the two elements.
template <typename T>
static inline void swap(T& e1, T& e2)
{
    auto tmp = std::move(e1);
    e1 = std::move(e2);
    e2 = std::move(tmp);
}

} // namespace hellods::internal

#endif // UTILITY_HPP