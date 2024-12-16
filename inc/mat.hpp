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
#ifndef LINMAT_MAT_HPP_
#define LINMAT_MAT_HPP_
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

namespace linmat
{
	/// <summary>
	///		Real-valued matrix.
	/// </summary>
	/// <typeparam name="T">Element floating-point type (i.e. double).</typeparam>
	template<typename T>
	class mat {
	public:

		// Factory methods
		static std::unique_ptr<mat<T>> unique_make_ones(unsigned int m, unsigned int n);
		static std::unique_ptr<mat<T>> unique_make_zeros(unsigned int m, unsigned int n);
		static std::unique_ptr<mat<T>> unique_make_eye(unsigned int m, unsigned int n);
		static mat<T> make_ones(unsigned int rows, unsigned int cols);
		static mat<T> make_zeros(unsigned int rows, unsigned int cols);
		static mat<T> make_eye(unsigned int rows, unsigned int cols);

		// Constructors
		mat();
		mat(unsigned int rows, unsigned int cols);
		mat(std::initializer_list<std::initializer_list<T>> args);

		// Methods
		T det_2(void);
		T det_3(void);
		mat<T> inv(void);
		mat<T> inv_2(void);
		mat<T> inv_3(void);
		mat<T> inv_shulz(void);
		mat<T> mult(const mat<T>& other);
		mat<T> pow(unsigned int n);
		mat<T> transpose(void);
		T frobenius_norm(void);
		T spectral_norm(void);
		T trace(void);

		// Accessor methods
		unsigned int rows() const { return m_rows; }
		unsigned int cols() const { return m_cols; }

		// Overloaded operators in class scope
		std::vector<T>& operator[] (unsigned int i);
		const std::vector<T>& operator[] (unsigned int i) const;

	protected:

		// Data is stored in a vector of vectors encapsulating type T 
		std::vector<std::vector<T>> m_elements;

		// m and n are the number of rows and columns respectively
		unsigned int m_rows, m_cols;
	};
}

#endif