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
#include <iostream>
#include <initializer_list>
#include <vector>
#include <random>
#include "inc/linmat.hpp"

using namespace linmat;

int main()
{
	// Create some matrices
	mat<double> m1(3,3);
	mat<double> m2 = mat<double>::make_ones(3, 3);
	mat<double> I = mat<double>::make_eye(3, 3);
	mat<double> m3{ {9,7,2,3},
		            {2,4,7,7},
		            {4,3,8,5},
		            {5,5,2,3} };
	rvec<double> v1{1,2,3,4};
	cvec<double> v2{1,2,3,4};

	// Set entries
	m1[0][0] = 1;
	m1[2][0] = 2;
	m1[0][2] = 3;

	// Matrix element-wise addition
	std::cout << "m1 is:" << std::endl;
	std::cout << m1 << std::endl;
	std::cout << "m2 is:" << std::endl;
	std::cout << m2 << std::endl;
	std::cout << "m1 + m2 is:" << std::endl;
	std::cout << m1 + m2 << std::endl;

	// Matrix multiplication
	std::cout << "m1.m2 is:" << std::endl;
	std::cout << m1.mult(m2) << std::endl;
	std::cout << "m1.I is:" << std::endl;
	std::cout << m1.mult(I) << std::endl;

	// Matrix inverse
	std::cout << "m3 is:" << std::endl;
	std::cout << m3 << std::endl;
	std::cout << "Inverse of m3 is:" << std::endl;
	std::cout << m3.inv() << std::endl;

	// Norms
	std::cout << "Determinant of m3 is:" << std::endl;
	std::cout << m3.det_leibniz() << std::endl;
	std::cout << "Spectral norm of m3 is:" << std::endl;
	std::cout << m3.spectral_norm() << std::endl;
	std::cout << "Frobenius norm of m3 is:" << std::endl;
	std::cout << m3.frobenius_norm() << std::endl;

	// Vectors
	std::cout << "v1 is:" << std::endl;
	std::cout << v1 << std::endl;
	std::cout << "v2 is:" << std::endl;
	std::cout << v2 << std::endl;
	std::cout << "Dot product of v1 and v2 is:" << std::endl;
	std::cout << v1.mult(v2) << std::endl;
}

