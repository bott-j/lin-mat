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
#include "../inc/vec.hpp"

namespace matlinalg
{
	/// <summary>
	///   Row vector class constructor.
	/// </summary>
	/// <typeparam name="T">Element floating - point type(i.e. double).</typeparam>
	/// <param name="cols">Number of columns.</param>
	template <typename T>
	rvec<T>::rvec(unsigned int cols)
		: mat<T>(1, cols)
	{
	}

	/// <summary>
	///   Row vector class constructor from initializer.
	/// </summary>
	/// <typeparam name="T">Element floating - point type(i.e. double).</typeparam>
	/// <param name="cols">Number of columns.</param>
	template <typename T>
	rvec<T>::rvec(const std::initializer_list<T>& args)
		: mat<T>{args}
	{
	}

	/// <summary>
	///   Assignment operator.
	/// </summary>
	/// <typeparam name="T">Element floating-point type (i.e. double).</typeparam>
	/// <param name="m">The matrix operaand.</param>
	/// <returns>A row vector.</returns>
	template <typename T>
	rvec<T>& rvec<T>::operator= (const mat<T>& m) 
	{
		// Enforce row vector shape
		if (m.rows() != 1 || m.cols() < 1)
			throw std::runtime_error("Not a row vector.");

		rvec<T> v(m.cols());

		for (unsigned int i = 0; i < m.cols(); i++)
			v[i] = m[0][i];

		return v;
	}

	/// <summary>
	///   Assignment operator for constant operand.
	/// </summary>
	/// <typeparam name="T">Element floating-point type (i.e. double).</typeparam>
	/// <param name="m">The matrix operaand.</param>
	/// <returns>A row vector.</returns>
	template <typename T>
	const rvec<T>& rvec<T>::operator= (const mat<T>& m) const
	{
		// Enforce row vector shape
		if (m.rows() != 1 || m.cols() < 1)
			throw std::runtime_error("Not a row vector.");

		rvec<T> v(m.cols());

		for(unsigned int i = 0; i < m.cols(); i++)
			v[i] = m[0][i];

		return v;
	}

	/// <summary>
	///   Subscript operator for constant operand.
	/// </summary>
	/// <typeparam name="T">Element floating-point type (i.e. double).</typeparam>
	/// <param name="i">The index.</param>
	/// <returns>A scalar value.</returns>
	template <typename T>
	T& rvec<T>::operator[] (unsigned int i)
	{
		return this->m_elements[0][i];
	}

	/// <summary>
	///   Subscript operator for constant operand.
	/// </summary>
	/// <typeparam name="T">Element floating-point type (i.e. double).</typeparam>
	/// <param name="i">The index.</param>
	/// <returns>A scalar value.</returns>
	template <typename T>
	const T& rvec<T>::operator[] (unsigned int i) const
	{
		return this->m_elements[0][i];
	}

	/// <summary>
	///   Column vector class constructor.
	/// </summary>
	/// <typeparam name="T">Element floating - point type(i.e. double).</typeparam>
	/// <param name="rows">Number of rows.</param>
	template <typename T>
	cvec<T>::cvec(unsigned int rows)
		: mat<T>(rows, 1)
	{
	}

	/// <summary>
	///   Column vector class constructor from initializer.
	/// </summary>
	/// <typeparam name="T">Element floating - point type(i.e. double).</typeparam>
	/// <param name="cols">Number of rows.</param>
	template <typename T>
	cvec<T>::cvec(const std::initializer_list<T>& args)
		: mat<T>(args.size(), 1)
	{
		auto i = 0;
		for (const T& arg : args)
		{
			this->m_elements[i][0] = arg;
			i++;
		}
	}

	/// <summary>
	///   Assignment operator.
	/// </summary>
	/// <typeparam name="T">Element floating-point type (i.e. double).</typeparam>
	/// <param name="m">The matrix operaand.</param>
	/// <returns>A column vector.</returns>
	template <typename T>
	cvec<T>& cvec<T>::operator= (const mat<T>& m)
	{
		// Enforce column vector shape
		if (m.rows() < 1 || m.cols() != 1)
			throw std::runtime_error("Not a column vector.");

		cvec<T> v(m.rows());

		for (unsigned int i = 0; i < m.rows(); i++)
			v[i] = m[i][0];

		return v;
	}

	/// <summary>
	///   Assignment operator for constant operand.
	/// </summary>
	/// <typeparam name="T">Element floating-point type (i.e. double).</typeparam>
	/// <param name="m">The matrix operaand.</param>
	/// <returns>A column vector.</returns>
	template <typename T>
	const cvec<T>& cvec<T>::operator= (const mat<T>& m) const
	{
		// Enforce column vector shape
		if (m.rows() < 1 || m.cols() != 1)
			throw std::runtime_error("Not a column vector.");

		cvec<T> v(m.rows());

		for (unsigned int i = 0; i < m.rows(); i++)
			v[i] = m[i][0];

		return v;
	}

	/// <summary>
	///   Subscript operator for constant operand.
	/// </summary>
	/// <typeparam name="T">Element floating-point type (i.e. double).</typeparam>
	/// <param name="i">The index.</param>
	/// <returns>A scalar value.</returns>
	template <typename T>
	T& cvec<T>::operator[] (unsigned int i) 
	{
		return this->m_elements[i][0];
	}

	/// <summary>
	///   Subscript operator for constant operand.
	/// </summary>
	/// <typeparam name="T">Element floating-point type (i.e. double).</typeparam>
	/// <param name="i">The index.</param>
	/// <returns>A scalar value.</returns>
	template <typename T>
	const T& cvec<T>::operator[] (unsigned int i) const
	{
		return this->m_elements[i][0];
	}

	// Explicit template instantiations
	template class rvec<float>;
	template class rvec<double>;
	template class rvec<long double>;
	template class cvec<float>;
	template class cvec<double>;
	template class cvec<long double>;
};
