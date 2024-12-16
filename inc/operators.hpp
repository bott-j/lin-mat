/*
 * MIT License
 *
 * Copyright(c) 2024 James Bott
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files(the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions :
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
*/
#ifndef LINMAT_OPERATORS_HPP_
#define LINMAT_OPERATORS_HPP_

#include "mat.hpp"

namespace linmat
{
	// Overloaded operators in namespace scope
	template <typename T>
	std::ostream& operator<<(std::ostream& os, const mat<T>& m);
	template <typename T>
	mat<T> operator+(const mat<T>& lhs, const mat<T>& rhs);
	template <typename T>
	mat<T> operator-(const mat<T>& lhs, const mat<T>& rhs);
	template <typename T>
	mat<T> operator*(const mat<T>& lhs, const mat<T>& rhs);
	template <typename T>
	mat<T> operator*(const mat<T>& lhs, const T& rhs);
	template <typename T>
	mat<T> operator*(const T& lhs, const mat<T>& rhs);
	template <typename T>
	mat<T> operator/(const mat<T>& lhs, const mat<T>& rhs);
	template <typename T>
	mat<T> operator/(const mat<T>& lhs, const T& rhs);
	template <typename T>
	mat<T> operator/(const T& lhs, const mat<T>& rhs);
}

#endif