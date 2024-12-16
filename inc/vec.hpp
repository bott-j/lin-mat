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
#ifndef LINMAT_VEC_HPP_
#define LINMAT_VEC_HPP_
#include "mat.hpp"

namespace linmat
{
	/// <summary>
	///   Real-valued row vector.
	/// </summary>
	/// <typeparam name="T">Element floating-point type (i.e. double).</typeparam>
	template <typename T>
	class rvec : public mat<T>
	{
	public:

		// Constructors
		rvec(unsigned int cols);	
		rvec(const std::initializer_list<T>& args);

		// Overloaded operators
		rvec<T>& operator= (const mat<T>& m);
		const rvec<T>& operator= (const mat<T>& m) const;
		T& operator[] (unsigned int i);
		const T& operator[] (unsigned int i) const;

	};

	/// <summary>
	///   Real-valued column vector.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	template <typename T>
	class cvec : public mat<T>
	{
	public:

		// Constructors
		cvec(unsigned int rows);
		cvec(const std::initializer_list<T>& args);

		// Overloaded operators
		cvec<T>& operator= (const mat<T>& m);
		const cvec<T>& operator= (const mat<T>& m) const;
		T& operator[] (unsigned int i);
		const T& operator[] (unsigned int i) const;

	};
};

#endif