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
#include "../inc/operators.hpp"
#include "../inc/mat.hpp"

namespace matlinalg
{
	/// <summary>
	///   Pipe operator for output stream.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="os">The output stream.</param>
	/// <param name="m">A matrix type to print to the stream.</param>
	/// <returns>The output stream.</returns>
	template <typename T>
	std::ostream& operator<<(std::ostream& os, const mat<T>& m)
	{
		for (unsigned int i = 0; i < m.rows(); i++)
		{
			os << "[ ";
			for (unsigned int j = 0; j < m.cols(); j++)
			{
				T x = m[i][j];
				os << x << " ";
			}
			os << "]" << std::endl;
		}
		return os;
	}

	/// <summary>
	///   Addition operator between matrices.
	/// </summary>
	/// <typeparam name="T">Element floating-point type(i.e. double).</typeparam>
	/// <param name="lhs">Left side matrix.</param>
	/// <param name="rhs">Right side matrix.</param>
	/// <returns>The element-wise sum of the two matrices.</returns>
	template <typename T>
	mat<T> operator+(const mat<T>& lhs, const mat<T>& rhs)
	{
		mat<T> result(lhs.rows(), lhs.cols());

		if (lhs.rows() != rhs.rows() || lhs.cols() != rhs.cols())
			throw std::runtime_error("Matrix dimensions must be equivalent for element-wise addition.");

		for (unsigned int i = 0; i < lhs.rows(); i++)
			for (unsigned int j = 0; j < lhs.cols(); j++)
				result[i][j] = lhs[i][j] + rhs[i][j];

		return result;
	}

	/// <summary>
	///   Subtraction operator between matrices.
	/// </summary>
	/// <typeparam name="T">Element floating-point type(i.e. double).</typeparam>
	/// <param name="lhs">The left side matrix.</param>
	/// <param name="rhs">The right side matrix.</param>
	/// <returns>The result of the element-wise subtraction as a matrix.</returns>
	template <typename T>
	mat<T> operator-(const mat<T>& lhs, const mat<T>& rhs)
	{
		mat<T> result(lhs.rows(), lhs.cols());

		if (lhs.rows() != rhs.rows() || lhs.cols() != rhs.cols())
			throw std::runtime_error("Matrix dimensions must be equivalent for element-wise subtraction.");

		for (unsigned int i = 0; i < lhs.rows(); i++)
			for (unsigned int j = 0; j < lhs.cols(); j++)
				result[i][j] = lhs[i][j] - rhs[i][j];

		return result;
	}

	/// <summary>
	///   Element-wise multiplication between matrices.
	/// </summary>
	/// <typeparam name="T">Element floating-point type(i.e. double).</typeparam>
	/// <param name="lhs">The left matrix operand.</param>
	/// <param name="rhs">The right matrix operand.</param>
	/// <returns>A new matrix which is the result of the element-wise multiplication.</returns>
	template <typename T>
	mat<T> operator*(const mat<T>& lhs, const mat<T>& rhs)
	{
		mat<T> result(lhs.rows(), lhs.cols());

		if (lhs.rows() != rhs.rows() || lhs.cols() != rhs.cols())
			throw std::runtime_error("Matrix dimensions must be equivalent for element-wise multiplication.");

		for (unsigned int i = 0; i < lhs.rows(); i++)
			for (unsigned int j = 0; j < lhs.cols(); j++)
				result[i][j] = lhs[i][j] * rhs[i][j];

		return result;
	}

	/// <summary>
	///    Element-wise matrix multiplication with a scalar.
	/// </summary>
	/// <typeparam name="T">Element floating-point type(i.e. double).</typeparam>
	/// <param name="lhs">The left matrix operand.</param>
	/// <param name="rhs">The right scalar operand.</param>
	/// <returns>A new matrix which is the result of the element-wise multiplicaiton.</returns>
	template <typename T>
	mat<T> operator*(const mat<T>& lhs, const T& rhs) {
		mat<T> result(lhs.rows(), lhs.cols());

		for (unsigned int i = 0; i < lhs.rows(); i++)
			for (unsigned int j = 0; j < lhs.cols(); j++)
				result[i][j] = lhs[i][j] * rhs;

		return result;
	}

	/// <summary>
	///   Element-wise matrix multiplication with a scalar.
	/// </summary>
	/// <typeparam name="T">Element floating-point type(i.e. double).</typeparam>
	/// <param name="lhs">The left scalar operand.</param>
	/// <param name="rhs">The right matrix operand.</param>
	/// <returns>A new matrix which is the result of the element-wise multiplication.</returns>
	template <typename T>
	mat<T> operator*(const T& lhs, const mat<T>& rhs) {
		mat<T> result(rhs.rows(), rhs.cols());

		for (unsigned int i = 0; i < rhs.rows(); i++)
			for (unsigned int j = 0; j < rhs.cols(); j++)
				result[i][j] = rhs[i][j] * lhs;

		return result;
	}

	/// <summary>
	///   Element-wise matrix division.
	/// </summary>
	/// <typeparam name="T">Element floating-point type(i.e. double).</typeparam>
	/// <param name="lhs">The left matrix operand.</param>
	/// <param name="rhs">The right matrix operand.</param>
	/// <returns>A new matrix which is a result of the element-wise division.</returns>
	template <typename T>
	mat<T> operator/(const mat<T>& lhs, const mat<T>& rhs) {
		mat<T> result(lhs.rows(), lhs.cols());

		for (unsigned int i = 0; i < lhs.rows(); i++)
			for (unsigned int j = 0; j < lhs.cols(); j++)
				result[i][j] = lhs[i][j] / rhs[i][j];

		return result;
	}

	/// <summary>
	///   Element-wise matrix division with a scalar.
	/// </summary>
	/// <typeparam name="T">Element floating-point type(i.e. double).</typeparam>
	/// <param name="lhs">The left matrix operand.</param>
	/// <param name="rhs">The right scalar operand.</param>
	/// <returns>A new matrix which is the reuslt of the element-wise division.</returns>
	template <typename T>
	mat<T> operator/(const mat<T>& lhs, const T& rhs) {
		mat<T> result(lhs.rows(), lhs.cols());

		for (unsigned int i = 0; i < lhs.rows(); i++)
			for (unsigned int j = 0; j < lhs.cols(); j++)
				result[i][j] = lhs[i][j] / rhs;

		return result;
	}

	/// <summary>
	///    Element-wise matrix division with a scalar.
	/// </summary>
	/// <typeparam name="T">Element floating-point type(i.e. double).</typeparam>
	/// <param name="lhs">The left scalar operand.</param>
	/// <param name="rhs">The right matrix operand.</param>
	/// <returns>A new matrix which is a result of the element-wise division.</returns>
	template <typename T>
	mat<T> operator/(const T& lhs, const mat<T>& rhs) {
		mat<T> result(rhs.rows(), rhs.cols());

		for (unsigned int i = 0; i < rhs.rows(); i++)
			for (unsigned int j = 0; j < rhs.cols(); j++)
				result[i][j] = rhs[i][j] / lhs;

		return result;
	}

	// Explicit template instantiations
	template std::ostream& operator<<(std::ostream&, const mat<float>& m);
	template std::ostream& operator<<(std::ostream&, const mat<double>& m);
	template std::ostream& operator<<(std::ostream&, const mat<long double>& m);
	template mat<float> operator+(const mat<float>& lhs, const mat<float>& rhs);
	template mat<double> operator+(const mat<double>& lhs, const mat<double>& rhs);
	template mat<long double> operator+(const mat<long double>& lhs, const mat<long double>& rhs);
	template mat<float> operator-(const mat<float>& lhs, const mat<float>& rhs);
	template mat<double> operator-(const mat<double>& lhs, const mat<double>& rhs);
	template mat<long double> operator-(const mat<long double>& lhs, const mat<long double>& rhs);
	template mat<float> operator*(const mat<float>& lhs, const mat<float>& rhs);
	template mat<double> operator*(const mat<double>& lhs, const mat<double>& rhs);
	template mat<long double> operator*(const mat<long double>& lhs, const mat<long double>& rhs);
	template mat<float> operator*(const mat<float>& lhs, const float& rhs);
	template mat<double> operator*(const mat<double>& lhs, const double& rhs);
	template mat<long double> operator*(const mat<long double>& lhs, const long double& rhs);
	template mat<float> operator*(const float& lhs, const mat<float>& rhs);
	template mat<double> operator*(const double& lhs, const mat<double>& rhs);
	template mat<long double> operator*(const long double& lhs, const mat<long double>& rhs);
	template mat<float> operator/(const mat<float>& lhs, const mat<float>& rhs);
	template mat<double> operator/(const mat<double>& lhs, const mat<double>& rhs);
	template mat<long double> operator/(const mat<long double>& lhs, const mat<long double>& rhs);
	template mat<float> operator/(const mat<float>& lhs, const float& rhs);
	template mat<double> operator/(const mat<double>& lhs, const double& rhs);
	template mat<long double> operator/(const mat<long double>& lhs, const long double& rhs);
	template mat<float> operator/(const float& lhs, const mat<float>& rhs);
	template mat<double> operator/(const double& lhs, const mat<double>& rhs);
	template mat<long double> operator/(const long double& lhs, const mat<long double>& rhs);
}