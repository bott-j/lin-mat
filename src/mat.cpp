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
#include <ctime>
#include <stdexcept>
#include "../inc/mat.hpp"
#include "../inc/operators.hpp"
#include "../inc/constants.hpp"

namespace linmat {

	/// <summary>
	///   Subscript operator.
	/// </summary>
	/// <typeparam name="T">Element floating-point type (i.e. double).</typeparam>
	/// <param name="i">The row index.</param>
	/// <returns>A row vector.</returns>
	template <typename T>
	std::vector<T>& mat<T>::operator[] (unsigned int i)
	{
		return m_elements[i];
	}

	/// <summary>
	///   Subscript operator for constant operand.
	/// </summary>
	/// <typeparam name="T">Element floating-point type (i.e. double).</typeparam>
	/// <param name="i">The row index.</param>
	/// <returns>A row vector.</returns>
	template <typename T>
	const std::vector<T>& mat<T>::operator[] (unsigned int i) const
	{
		return m_elements[i];
	}

	/// <summary>
	///   Returns a unique pointer to a new matrix of ones.
	/// </summary>
	/// <typeparam name="T">Element floating-point type (i.e. double).</typeparam>
	/// <param name="rows">Number of rows.</param>
	/// <param name="cols">Number of columns.</param>
	/// <returns>A unique_ptr to a new matrix of ones.</returns>
	template <typename T>
	std::unique_ptr<mat<T>> mat<T>::unique_make_ones(unsigned int m, unsigned int n)
	{
		std::unique_ptr<mat<T>> obj = std::make_unique<mat<T>>(m, n);
		for (unsigned int j = 0; j < m; j++)
			std::fill((*obj)[j].begin(), (*obj)[j].end(), 1);

		return obj;
	}

	/// <summary>
	///   Returns a unique pointer to a new zeromatrix.
	/// </summary>
	/// <typeparam name="T">Element floating-point type (i.e. double).</typeparam>
	/// <param name="rows">Number of rows.</param>
	/// <param name="cols">Number of columns.</param>
	/// <returns>A unique_ptr to a new zero matrix.</returns>
	template <typename T>
	std::unique_ptr<mat<T>> mat<T>::unique_make_zeros(unsigned int m, unsigned int n)
	{
		std::unique_ptr<mat<T>> obj = std::make_unique<mat<T>>(m, n);
		return obj;
	}

	/// <summary>
	///   Returns a unique pointer to a new identity matrix.
	/// </summary>
	/// <typeparam name="T">Element floating-point type (i.e. double).</typeparam>
	/// <param name="rows">Number of rows.</param>
	/// <param name="cols">Number of columns.</param>
	/// <returns>A unique_ptr to a new identity matrix.</returns>
	template <typename T>
	std::unique_ptr<mat<T>> mat<T>::unique_make_eye(unsigned int rows, unsigned int cols)
	{
		std::unique_ptr<mat<T>> obj = std::make_unique<mat<T>>(rows, cols);
		for (unsigned int i = 0; i < rows && i < cols; i++)
			(*obj)[i][i] = 1;
		return obj;
	}

	/// <summary>
	///   Factory function which returns a matrix of ones.
	/// </summary>
	/// <typeparam name="T">Element floating-point type (i.e. double).</typeparam>
	/// <param name="rows">Number of rows.</param>
	/// <param name="cols">Number of columns.</param>
	/// <returns>A new matrix with all elements having the value 1.</returns>
	template <typename T>
	mat<T> mat<T>::make_ones(unsigned int rows, unsigned int cols)
	{
		mat<T> m(rows, cols);
		for (unsigned int i = 0; i < rows; i++)
			std::fill(m[i].begin(), m[i].end(), 1);
		return m;
	}

	/// <summary>
	///   Factory function which returns a matrix of zeros.
	/// </summary>
	/// <typeparam name="T">Element floating-point type (i.e. double).</typeparam>
	/// <param name="rows">Number of rows.</param>
	/// <param name="cols">Number of columns.</param>
	/// <returns>A new matrix with all entries zeroed.</returns>
	template <typename T>
	mat<T> mat<T>::make_zeros(unsigned int rows, unsigned int cols)
	{
		mat<T> m(rows, cols);
		return m;
	}

	/// <summary>
	///   Factory function which returns an identity matrix.
	/// </summary>
	/// <typeparam name="T">Element floating-point type (i.e. double).</typeparam>
	/// <param name="rows">Number of rows.</param>
	/// <param name="cols">Number of columns.</param>
	/// <returns>A new matrix which is an identity matrix.</returns>
	template <typename T>
	mat<T> mat<T>::make_eye(unsigned int rows, unsigned int cols)
	{
		mat<T> m(rows, cols);
		for (unsigned int i = 0; i < rows && i < cols; i++)
			m[i][i] = 1;
		return m;
	}

	/// <summary>
	///   Matrix default constructor.
	/// </summary>
	/// <typeparam name="T">Element floating-point type (i.e. double).</typeparam>
	template <typename T>
	mat<T>::mat()
		: m_rows(0)
		, m_cols(0)
	{
	}

	/// <summary>
	///   Matrix constructor.
	/// </summary>
	/// <typeparam name="T">Element floating-point type (i.e. double).</typeparam>
	/// <param name="rows">Number of rows.</param>
	/// <param name="cols">Number of columns.</param>
	template <typename T>
	mat<T>::mat(unsigned int rows, unsigned int cols)
		: m_elements(rows, std::vector<T>(cols))
	{
		m_rows = rows;
		m_cols = cols;
	}

	/// <summary>
	///   Matrix constructor from initializer list.
	/// </summary>
	/// <typeparam name="T">Element floating-point type (i.e. double).</typeparam>
	/// <param name="rows">Number of rows.</param>
	/// <param name="cols">Number of columns.</param>
	template <typename T>
	mat<T>::mat(std::initializer_list<std::initializer_list<T>> args)
		: m_rows(args.size())
		, m_cols(args.size() ? args.begin()->size() : 0)

	{
		for (auto row : args)
			m_elements.push_back(std::vector<T>(row));
	}

	/// <summary>
	///   Calculates matrix multiplication.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="other">The matrix on the right side of the multiplication.</param>
	/// <returns>A new matrix which is the product.</returns>
	template <typename T>
	mat<T> mat<T>::mult(const mat<T>& other)
	{
		mat result(m_rows, other.cols());

		// Validate arguments
		if (m_cols != other.rows())
			throw std::runtime_error("Rows in right matrix must match columns in left matrix.");

		// Perform matrix multiplication
		for (unsigned int i = 0; i < m_rows; i++)
			for (unsigned int j = 0; j < other.cols(); j++)
				for (unsigned int k = 0; k < m_cols; k++)
					result[i][j] += (*this)[i][k] * other[k][j];

		return result;
	}

	/// <summary>
	///   Calculates the matrix raised to a power.
	/// </summary>
	/// <typeparam name="T">Element floating-point type (i.e. double).</typeparam>
	/// <param name="n">The power to raise the matrix to.</param>
	/// <returns>A new matrix which is the original matrix raised to a power.</returns>
	template <typename T>
	mat<T> mat<T>::pow(unsigned int n)
	{
		mat<T> result = mat<T>::make_eye(m_rows, m_cols);

		// Calculate power
		for (unsigned int i = 0; i < n; i++)
			result = result.mult((*this));

		return result;
	}

	/// <summary>
	///   Calculates the trace of the matrix.
	/// </summary>
	/// <typeparam name="T">Element floating-point type (i.e. double).</typeparam>
	/// <returns>The scalar valued trace of the matrix.</returns>
	template <typename T>
	T mat<T>::trace(void)
	{
		T result = 0;

		// Calculate the trace as the sum of the diagonals
		for (unsigned int i = 0; i < m_rows && i < m_cols; i++)
			result += (*this)[i][i];

		return result;
	}

	/// <summary>
	///   Calculates the transpose of the matrix.
	/// </summary>
	/// <typeparam name="T">Element floating-point type (i.e. double).</typeparam>
	/// <returns>A new matrix which is the transpose.</returns>
	template <typename T>
	mat<T> mat<T>::transpose(void)
	{
		mat result(m_cols, m_rows);

		// Swap elements
		for (unsigned int i = 0; i < m_rows; i++)
			for (unsigned int j = 0; j < m_cols; j++)
				result[j][i] = (*this)[i][j];

		return result;
	}

	/// <summary>
	///   Calculates the Frobenius norm.
	/// </summary>
	/// <typeparam name="T">Element floating-point type (i.e. double).</typeparam>
	/// <returns>Scalar valued norm of the matrix.</returns>
	template <typename T>
	T mat<T>::frobenius_norm(void)
	{
		T result = 0;

		// Calculate the Frobenius norm
		for (unsigned int i = 0; i < m_rows; i++)
			for (unsigned int j = 0; j < m_cols; j++)
				result += std::pow(std::fabs((*this)[i][j]),2);

		return std::sqrt(result);
	}

	/// <summary>
	///   Calculates the spectral (l2) norm of the matrix. 
	/// </summary>
	/// <typeparam name="T">Element floating-point type (i.e. double).</typeparam>
	/// <returns>The scalar valued spectral norm.</returns>
	template <typename T>
	T mat<T>::spectral_norm(void)
	{
		// The spectral norm of matrix A can be found from the square-root of 
		// the largest eigenvalue of (A^T).(A)
		mat<T> b_k(m_rows, 1);
		mat<T> At = (*this).transpose();
		T lambda_max;

		// Initialize random number generator
		std::srand(static_cast<unsigned int>(std::time(0)));

		// Randomize initial guess 
		for (unsigned int i = 0; i < m_cols; i++)
			b_k[i][0] = static_cast<T>(rand()) / RAND_MAX;

		// Largest eigenvalue by power iteration
		for (unsigned int i = 0; i < constants::MAX_ITER; i++)
		{
			b_k = At.mult((*this).mult(b_k / b_k.frobenius_norm()));
		}

		// Find the largest eigenvalue
		lambda_max = b_k.frobenius_norm();

		// Return square root
		return std::sqrt(lambda_max);
	}

	/// <summary>
	///   Calculates determinant of a 2x2 matrix using analytical solution.
	/// </summary>
	/// <typeparam name="T">Element floating-point type (i.e. double).</typeparam>
	/// <returns>The matrix determinant.</returns>
	template <typename T>
	T mat<T>::det_2(void)
	{
		// Enforce 2x2 condition
		if (m_rows != 2 || m_cols != 2)
			throw std::runtime_error("Requires 2x2 matrix.");

		// Return determinant
		return (m_elements[0][0] * m_elements[1][1]
			- m_elements[0][1] * m_elements[1][0]);
	}

	/// <summary>
	///   Calculates determinant of a 3x3 matrix using analytical solution.
	/// </summary>
	/// <typeparam name="T">Element floating-point type (i.e. double).</typeparam>
	/// <returns>The matrix determinant.</returns>
	template <typename T>
	T mat<T>::det_3(void)
	{
		// Enforce 3x3 condition
		if (m_rows != 3 || m_cols != 3)
			throw std::runtime_error("Requires 3x3 matrix.");

		// Calculate determinant using analytical solution
		T A = (m_elements[1][1] * m_elements[2][2] - m_elements[1][2] * m_elements[2][1]);
		T B = -(m_elements[1][0] * m_elements[2][2] - m_elements[1][2] * m_elements[2][0]);
		T C = (m_elements[1][0] * m_elements[2][1] - m_elements[1][1] * m_elements[2][0]);

		return m_elements[0][0] * A
			+ m_elements[0][1] * B
			+ m_elements[0][2] * C;
	}

	/// <summary>
	///   Calculates inverse of a 2x2 matrix using analytical solution.
	/// </summary>
	/// <typeparam name="T">Element floating-point type (i.e. double).</typeparam>
	/// <returns>The matrix inverse.</returns>
	template <typename T>
	mat<T> mat<T>::inv_2(void)
	{
		mat<T> m(m_rows, m_cols);
		T det;

		// Enforce 2x2 condition
		if (m_rows != 2 || m_cols != 2)
			throw std::runtime_error("Requires 2x2 matrix.");

		det = det_2();

		// Matrix is singular
		if (det == 0)
			throw std::runtime_error("Matrix is singular.");

		// Calculate inverse using analytical solution
		m[0][0] = m_elements[1][1];
		m[0][1] = -m_elements[0][1];
		m[1][0] = -m_elements[1][0];
		m[1][1] = m_elements[0][0];

		m = m * (1 / det);

		return m;
	}

	/// <summary>
	///   Calculates inverse of a 3x3 matrix using analytical solution.
	/// </summary>
	/// <typeparam name="T">Element floating-point type (i.e. double).</typeparam>
	/// <returns>The matrix inverse.</returns>
	template <typename T>
	mat<T> mat<T>::inv_3(void)
	{
		mat<T> m(m_rows, m_cols);
		T det;

		// Enforce 2x2 condition
		if (m_rows != 3 || m_cols != 3)
			throw std::runtime_error("Requires 3x3 matrix.");

		det = det_3();

		// Matrix is singular
		if (det == 0)
			throw std::runtime_error("Matrix is singular.");

		// Calculate inverse using analytical solution
		m[0][0] = (m_elements[1][1] * m_elements[2][2] - m_elements[1][2] * m_elements[2][1]);
		m[0][1] = -(m_elements[0][1] * m_elements[2][2] - m_elements[0][2] * m_elements[2][1]);
		m[0][2] = (m_elements[0][1] * m_elements[1][2] - m_elements[0][2] * m_elements[1][1]);
		m[1][0] = -(m_elements[1][0] * m_elements[2][2] - m_elements[1][2] * m_elements[2][0]);
		m[1][1] = (m_elements[0][0] * m_elements[2][2] - m_elements[0][2] * m_elements[2][0]);
		m[1][2] = -(m_elements[0][0] * m_elements[1][2] - m_elements[0][2] * m_elements[1][0]);
		m[2][0] = (m_elements[1][0] * m_elements[2][1] - m_elements[1][1] * m_elements[2][0]);		
		m[2][1] = -(m_elements[0][0] * m_elements[2][1] - m_elements[0][1] * m_elements[2][0]);
		m[2][2] = (m_elements[0][0] * m_elements[1][1] - m_elements[0][1] * m_elements[1][0]);

		m = m / det;

		return m;
	}

	/// <summary>
	///     Calculates the inverse of the matrix.
	/// </summary>
	/// <typeparam name="T">Element floating-point type (i.e. double).</typeparam>
	/// <returns>A new matrix which is the inverse</returns>
	template <typename T>
	mat<T> mat<T>::inv(void)
	{
		mat<T> m(m_rows, m_cols);

		// If 2x2
		if (m_rows == 2 && m_cols == 2)
			m = inv_2();
		// If 3x3
		else if (m_rows == 3 && m_cols == 3)
			m = inv_3();
		// Otherwise
		else
			m = inv_shulz();
		
		return m;
	}

	/// <summary>
	///     Calculates the inverse of the matrix using Newton-Schulz iteration.
	/// </summary>
	/// <typeparam name="T">Element floating-point type (i.e. double).</typeparam>
	/// <returns>A new matrix which is the inverse</returns>
	template <typename T>
	mat<T> mat<T>::inv_shulz(void)
	{
		mat<T> X(m_rows, m_cols);
		mat<T> X_1(m_rows, m_cols);
		mat<T> D(m_rows, m_cols);
		mat<T> I = mat<T>::make_eye(m_rows, m_cols);
		float done = false;

		// Find alpha
		T alpha = static_cast<T>(0.5 * 2 / std::pow(spectral_norm(), 2));
		
		// Set the initial conditions for X
		X = transpose() * alpha;

		// Find matrix inverse by Schulz iteration
		for (unsigned int i = 0; i < constants::MAX_ITER && !done; i++)
		{
			X_1 = ((I * static_cast<T>(2) - X.mult(*this)).mult(X));
			D = (X_1 - X) / X;
			X = X_1;

			// Evaluate convergence
			done = true;
			for (unsigned int i = 0; i < m_rows; i++)
				for (unsigned int j = 0; j < m_cols; j++)
					if (std::abs(D[i][j]) > constants::CONV_TOL)
						done = false;
		}

		return X;
	}

	/// <summary>
	///     Uses Heap's algorithm to calculate set of permutations.
	/// </summary>
	/// <typeparam name="T">Element floating-point type (i.e. double).</typeparam>
	/// <param name="k">Used for tracking depth of recursion.</param>
	/// <param name="p">The current permutation.</param>
	/// <param name="ps">The accumulated set of permutations.</param>
	/// <param name="ss">The accumulated set of signs.</param>
	/// <param name="s">The sign of the current permutation.</param>
	/// <returns>N/A</returns>
	template <typename T>
	void mat<T>::permutations(
		unsigned int k,
		std::vector<unsigned int> &p,
		std::vector<std::vector<unsigned int>>& ps,
		std::vector<T> &ss,
		T& s)
	{
		// Base case
		if (k == 1)
		{
			// Store result
			ps.push_back(p);
			ss.push_back(s);
		}
		// Iterative case
		else
		{
			permutations(k - 1, p, ps, ss, s);

			// For remaining permutations
			for (unsigned int i = 0; i < k - 1; i++)
			{
				// If even
				if ((k & 1) == 0)
					std::swap(p[i], p[k - 1]);
				// Otherwise if odd
				else
					std::swap(p[0], p[k - 1]);
				// Track the sign of swap operations
				s = -s;
				permutations(k - 1, p, ps, ss, s);
			}
		}
	}
	
	/// <summary>
	///		Calculates the determinant of an mxm matrix using Leibniz formula. 
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <returns>The determinant.</returns>
	template <typename T>
	T mat<T>::det_leibniz(void)
	{
		std::vector<std::vector<unsigned int>> ps;
		std::vector<unsigned int> p0;
		std::vector<T> ss; 
		T s = 1;
		T result = 0.0;

		// Enforce square matrix
		if (m_cols != m_rows)
			throw std::runtime_error("Determinant is undefined for a rectangular matrix.");

		// There are m! permutations, find them
		for (int i = 0; i < m_cols; i++)
			p0.push_back(i);
		permutations(m_cols, p0, ps, ss, s);

		// Iterate over permutations, compute and sum terms
		for (unsigned int j = 0; j < ps.size(); j++)
		{
			T term = ss[j];
			for (unsigned int i = 0; i < m_cols; i++) 
				term *= m_elements[i][ps[j][i]];
			
			result += term;
		}

		return result;
	}

	/// <summary>
	///   Calculates the determinant of the mxm matrix.
	/// </summary>
	/// <typeparam name="T">Element floating-point type (i.e. double).</typeparam>
	/// <returns>The determinant.</returns>
	template <typename T>
	T mat<T>::det(void)
	{
		T result;

		// If 2x2
		if (m_rows == 2 && m_cols == 2)
			result = det_2();
		// If 3x3
		else if (m_rows == 3 && m_cols == 3)
			result = det_3();
		// Otherwise
		else
			result = det_leibniz();
		
		return result;
	}

	/// <summary>
	///   Performs LU decomposition (factorization) of the matrix into
	///   lower triangular matrix L and upper triangular matrix U using
	///   The Doolittle algorithm. Also reffered to as the LR decomposition.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="L">An empty matrix L which will be written to.</param>
	/// <param name="U">An empty matrix U which will be written to.</param>
	template <typename T>
	void mat<T>::lu_decomposition(mat<T>& L,mat<T>& U)
	{
		// Enforce square matrix
		if (m_cols != m_rows)
			throw std::runtime_error("LU decomposition is undefined for a rectangular matrix.");

		// Handle edge case
		if (m_cols < 2)
			throw std::runtime_error("Matrix dimensions must be greater than one.");

		// Initialize L and U
		L = mat<T>::make_eye(m_rows, m_cols);
		U = (*this);

		
		for (int i = 0; i < m_rows; i++)
		{
			for (int j = i + 1; j < m_rows; j++)
			{
				L[j][i] = U[j][i] / U[i][i];

				// Calculate U[j] = U[j] - L[j][i] * U[i]
				for (int k = 0; k < m_rows; k++)
					U[j][k] -= L[j][i] * U[i][k];
			}
		}
	}

	/// <summary>
	///   Performs Cholesky decomposition (factorization) of the Hermitian 
	///   positive-definite matrix into a lower triangular matrix L, such 
	///   that A = LL^T. This implementation uses the Cholesky-Banachiewicz 
	///   algorithm.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="L">An empty matrix L which will be written to.</param>
	template <typename T>
	void mat<T>::cholesky_decomposition(mat<T>& L)
	{
		T s;

		// Enforce square matrix
		if (m_cols != m_rows)
			throw std::runtime_error("LU decomposition is undefined for a rectangular matrix.");

		// Enforce Hermitian
		for (unsigned int i = 0; i < m_rows; i++)
			for (unsigned int j = 0; j <= i; j++)
				if ((*this)[i][j] != (*this)[j][i])
					throw std::runtime_error("Matrix must be Hermitian.");

		// Handle edge case
		if (m_cols < 2)
			throw std::runtime_error("Matrix dimensions must be greater than one.");

		// Initialize L and U
		L = mat<T>::make_zeros(m_rows, m_cols);;

		// For each row
		for (unsigned int i = 0; i < m_rows; i++)
		{
			// For each column in the lower diagonal
			for (unsigned int j = 0; j <= i; j++)
			{
				s = 0;
				for (unsigned int k = 0; k < j; k++)
					s += L[i][k] * L[j][k];
				if (i == j)
					L[i][j] = std::sqrt((*this)[i][j] - s);
				else
					L[i][j] = ((*this)[i][j] - s) / L[j][j];
			}
		}
	}

	// Explicit template instantiations
	template class mat<float>;
	template class mat<double>;
	template class mat<long double>;
}

