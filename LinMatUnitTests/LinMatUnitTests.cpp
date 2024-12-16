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
#include "pch.h"
#include "CppUnitTest.h"
#include "../inc/linmat.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace linmat;

namespace MatLinAlgUnitTests
{
	TEST_CLASS(MatLinAlgUnitTests)
	{
	public:

		TEST_METHOD(TestConstructor)
		{
			const unsigned int rows = 2;
			const unsigned int cols = 3;
			const double expected = 0;

			// Evaluate dimensions
			mat<double> m(rows, cols);
			Assert::AreEqual(m.rows(), rows);
			Assert::AreEqual(m.cols(), cols);

			// Evaluate elements
			for (unsigned int i = 0; i < rows; i++)
				for (unsigned int j = 0; j < cols; j++)
					Assert::AreEqual(expected, m[i][j]);
		}

		TEST_METHOD(TestConstructorInitializerList)
		{
			const unsigned int rows = 2;
			const unsigned int cols = 3;
			const double expected = 2;

			// Evaluate dimensions
			mat<double> m{ {2, 2, 2}, {2, 2, 2} };
			Assert::AreEqual(m.rows(), rows);
			Assert::AreEqual(m.cols(), cols);

			// Evaluate elements
			for (unsigned int i = 0; i < rows; i++)
				for (unsigned int j = 0; j < cols; j++)
					Assert::AreEqual(expected, m[i][j]);
		}

		TEST_METHOD(TestMakeZeros)
		{
			const unsigned int rows = 3;
			const unsigned int cols = 4;
			const double expected = 0;

			// Evaluate dimensions
			mat<double> m = mat<double>::make_zeros(rows, cols);
			Assert::AreEqual(m.rows(), rows);
			Assert::AreEqual(m.cols(), cols);

			// Evaluate elements
			for (unsigned int i = 0; i < rows; i++)
				for (unsigned int j = 0; j < cols; j++)
					Assert::AreEqual(expected, m[i][j]);
		}

		TEST_METHOD(TestMakeOnes)
		{
			const unsigned int rows = 4;
			const unsigned int cols = 3;
			const double expected = 1;

			// Evaluate dimensions
			mat<double> m = mat<double>::make_ones(rows, cols);
			Assert::AreEqual(m.rows(), rows);
			Assert::AreEqual(m.cols(), cols);

			// Evaluate elements
			for (unsigned int i = 0; i < rows; i++)
				for (unsigned int j = 0; j < cols; j++)
					Assert::AreEqual(expected, m[i][j]);
		}

		TEST_METHOD(TestMakeEye)
		{
			const unsigned int rows = 4;
			const unsigned int cols = 3;

			// Evaluate dimensions
			mat<double> m = mat<double>::make_eye(rows, cols);
			Assert::AreEqual(m.rows(), rows);
			Assert::AreEqual(m.cols(), cols);

			// Evaluate elements
			for (unsigned int i = 0; i < rows; i++)
				for (unsigned int j = 0; j < cols; j++)
				{
					if(i == j)
						Assert::AreEqual(static_cast<double>(1), m[i][j]);
					else
						Assert::AreEqual(static_cast<double>(0), m[i][j]);
				}
		}

		TEST_METHOD(TestMultiplicationElementWise)
		{
			const unsigned int rows = 4;
			const unsigned int cols = 3;
			const double c1 = 2;
			const double c2 = 3;
			const double c3 = 9;

			// Setup matrices
			mat<double> m1 = mat<double>::make_ones(rows, cols);
			mat<double> m2 = mat<double>::make_ones(rows, cols);
			mat<double> m3 = mat<double>::make_eye(rows, cols);

			// Matrix multiplied with scalar
			m2 = m1 * c1;

			// Evaluate multiplication by scalar
			for (unsigned int i = 0; i < rows; i++)
				for (unsigned int j = 0; j < cols; j++)
					Assert::AreEqual(m2[i][j], c1);

			// Scalar multiplied with matrix
			m2 = c2 * m1;

			// Evaluate multiplication by scalar
			for (unsigned int i = 0; i < rows; i++)
				for (unsigned int j = 0; j < cols; j++)
					Assert::AreEqual(m2[i][j], c2);

			// Matrix multiplication element-wise
			m2 = c2 * m1;
			m2 = m2 * m2;

			// Evaluate matrix multiplication
			for (unsigned int i = 0; i < rows; i++)
				for (unsigned int j = 0; j < cols; j++)
					Assert::AreEqual(c3, m2[i][j]);
		}

		TEST_METHOD(TestMultiplication)
		{
			const unsigned int rows = 3;
			const unsigned int cols = 3;
			const double c1 = 3;

			// Setup matrices
			mat<double> m1 = mat<double>::make_ones(rows, cols);
			mat<double> m2(rows, cols);
			mat<double> I = mat<double>::make_eye(rows, cols);

			// Matrix multiplication
			m1 = m1 * c1;
			m2 = m1.mult(I);

			// Evaluate result
			for (unsigned int i = 0; i < rows; i++)
				for (unsigned int j = 0; j < cols; j++)
					Assert::AreEqual(m2[i][j], m1[i][j]);
		}

		TEST_METHOD(TestAddition)
		{
			const unsigned int rows = 3;
			const unsigned int cols = 3;
			const double c1 = 2;
			const double c2 = 3;
			const double c3 = 5;

			mat<double> m1(rows, cols);
			mat<double> m2(rows, cols);
			mat<double> m3(rows, cols);

			// Setup matrices
			for (unsigned int i = 0; i < rows; i++)
			{
				for(unsigned int j = 0; j < cols; j++)
				{
					m1[i][j] = c1;
					m2[i][j] = c2;
				}
			}

			// Matrix addition element-wise
			m3 = m1 + m2;

			// Evaluate result
			for (unsigned int i = 0; i < rows; i++)
				for (unsigned int j = 0; j < cols; j++)
					Assert::AreEqual(c3, m3[i][j]);
		}

		TEST_METHOD(TestSubtraction)
		{
			const unsigned int rows = 3;
			const unsigned int cols = 3;
			const double c1 = 2;
			const double c2 = 3;
			const double c3 = -1;

			mat<double> m1(rows, cols);
			mat<double> m2(rows, cols);
			mat<double> m3(rows, cols);

			// Setup matrices
			for (unsigned int i = 0; i < rows; i++)
			{
				for (unsigned int j = 0; j < cols; j++)
				{
					m1[i][j] = c1;
					m2[i][j] = c2;
				}
			}

			// Perform subtraction
			m3 = m1 - m2;

			// Evaluate result
			for (unsigned int i = 0; i < rows; i++)
				for (unsigned int j = 0; j < cols; j++)
					Assert::AreEqual(c3, m3[i][j]);
		}

		TEST_METHOD(TestSpectralNorm)
		{
			unsigned int rows = 3;
			unsigned int cols = 3;
			double c1 = 2;
			double c2 = 3;
			double c3 = 8;

			mat<double> m1(rows, cols);

			// Setup matrix
			for (unsigned int i = 0; i < rows; i++)
				for (unsigned int j = 0; j < cols; j++)
					if (i == j)
						m1[i][j] = c1;
					else
						m1[i][j] = c2;

			// Evaluate result
			Assert::AreEqual(c3, m1.spectral_norm());
		}

		TEST_METHOD(TestFrobeniusNorm)
		{
			unsigned int rows = 3;
			unsigned int cols = 3;
			double c1 = 2;
			double c2 = 3;
			double c3 = 8.124;

			mat<double> m1(rows, cols);

			// Setup matrix
			for (unsigned int i = 0; i < rows; i++)
				for (unsigned int j = 0; j < cols; j++)
					if (i == j)
						m1[i][j] = c1;
					else
						m1[i][j] = c2;

			// Evaluate result
			Assert::AreEqual(c3, m1.frobenius_norm(), 0.001);
		}

		TEST_METHOD(TestPower)
		{
			unsigned int rows = 3;
			unsigned int cols = 3;
			double c1 = 2;
			double c2 = 12;

			mat<double> m1(rows, cols);

			// Setup matrix
			for (unsigned int i = 0; i < rows; i++)
				for (unsigned int j = 0; j < cols; j++)
					m1[i][j] = c1;

			// Calculate power
			m1 = m1.pow(2);

			// Evaluate result
			for (unsigned int i = 0; i < rows; i++)
				for (unsigned int j = 0; j < cols; j++)
					Assert::AreEqual(c2, m1[i][j]);
		}

		TEST_METHOD(TestInv3)
		{
			unsigned int rows = 3;
			unsigned int cols = 3;
			double c1 = 2;

			// Setup matrix
			mat<double> m1{ {2, 1, 5}, {2, 2, 4}, {1, 2, 3} };
			mat<double> m2{ {-2.0 / 4, 7.0 / 4, -6.0 / 4}, {-2.0 / 4, 1.0 / 4, 2.0 / 4}, {2.0 / 4, -3.0 / 4, 2.0 / 4} };

			// Calculate the inverse
			m1 = m1.inv_3();

			// Evaluate result
			for (unsigned int i = 0; i < rows; i++)
				for (unsigned int j = 0; j < cols; j++)
					Assert::AreEqual(m2[i][j], m1[i][j], 0.001);
		}

		TEST_METHOD(TestInvSchulz)
		{
			unsigned int rows = 2;
			unsigned int cols = 2;
			double c1 = 2;

			// Setup matrix
			mat<double> m1{ {2, 1}, {2, 2} };
			mat<double> m2{ {1, -0.5}, {-1, 1} };

			// Calculate the inverse
			m1 = m1.inv_shulz();

			// Evaluate result
			for (unsigned int i = 0; i < rows; i++)
				for (unsigned int j = 0; j < cols; j++)
						Assert::AreEqual(m2[i][j], m1[i][j], 0.001);
		}

		TEST_METHOD(TestInv2)
		{
			unsigned int rows = 2;
			unsigned int cols = 2;
			double c1 = 2;

			// Setup matrix
			mat<double> m1{ {2, 1}, {2, 2} };
			mat<double> m2{ {1, -0.5}, {-1, 1} };

			// Calculate the inverse
			m1 = m1.inv_2();

			// Evaluate result
			for (unsigned int i = 0; i < rows; i++)
				for (unsigned int j = 0; j < cols; j++)
					Assert::AreEqual(m2[i][j], m1[i][j], 0.001);
		}

		TEST_METHOD(TestTranspose)
		{
			unsigned int rows = 3;
			unsigned int cols = 3;
			double c1 = 2;

			mat<double> m1(rows, cols);

			// Setup matrix
			for (unsigned int i = 0; i < rows; i++)
				m1[i][0] = c1;

			// Calculate the transpose
			m1 = m1.transpose();

			// Evaluate result
			for (unsigned int i = 0; i < rows; i++)
				for (unsigned int j = 0; j < cols; j++)
					if(i == 0)
						Assert::AreEqual(c1, m1[i][j]);
					else
						Assert::AreEqual(0.0, m1[i][j]);
		}

		TEST_METHOD(TestTrace)
		{
			unsigned int rows = 3;
			unsigned int cols = 3;
			double c1 = 2;
			double c2 = 6;

			mat<double> m1(rows, cols);

			// Setup matrix
			for (unsigned int i = 0; i < rows; i++)
				for (unsigned int j = 0; j < cols; j++)
					m1[i][j] = c1;

			// Evaluate result
			Assert::AreEqual(c2, m1.trace());
		}
	};
}
