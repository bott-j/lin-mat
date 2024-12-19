# lin-mat

Linear algebra class library in C++ supporting matrix operations and matrix inversion. The class library has minimal dependencies and only uses the STL library for data structures, exceptions and console I/O. 

## Getting Started

An example program is provided in "example.cpp" in the root directory.

Matrix and vector objects can be created using class constructors, factory methods and initializer lists.

For example, creating a 3x3 matrix with entries initialized to zero:

```
mat<double> m1(3,3);
```

Factory methods are also provided which create matrices with entries set to ones or an identity matrix:

```
mat<double> m2 = mat<double>::make_ones(3, 3);
mat<double> I = mat<double>::make_eye(3, 3);
```

The following example uses an initializer list to initialize a 4x4 matrix.

```
mat<double> m3{ {9,7,2,3},
                {2,4,7,7},
                {4,3,8,5},
                {5,5,2,3} };
```

Row and column vectors can also be created similarly:

```
rvec<double> v1{1,2,3,4};
cvec<double> v2{1,2,3,4};
```

A subscript operator can be used to access and modify entries:

```
// Set entries
m1[0][0] = 1;
m1[2][0] = 2;
m1[0][2] = 3;
```

Element-wise addition, subtraction and multiplication is supported through operator overloads.

The following example shows addition with console output.

```
// Matrix element-wise addition
std::cout << "m1 is:" << std::endl;
std::cout << m1 << std::endl;
std::cout << "m2 is:" << std::endl;
std::cout << m2 << std::endl;
std::cout << "m1 + m2 is:" << std::endl;
std::cout << m1 + m2 << std::endl;
```

The following output is generated.

```
m1 is:
[ 1 0 3 ]
[ 0 0 0 ]
[ 2 0 0 ]

m2 is:
[ 1 1 1 ]
[ 1 1 1 ]
[ 1 1 1 ]

m1 + m2 is:
[ 2 1 4 ]
[ 1 1 1 ]
[ 3 1 1 ]
```

Matrix multiplication is supported with the mult() method:

```
// Matrix multiplication
std::cout << "m1.m2 is:" << std::endl;
std::cout << m1.mult(m2) << std::endl;
std::cout << "m1.I is:" << std::endl;
std::cout << m1.mult(I) << std::endl;
```

Resulting in the following output.

```
m1.m2 is:
[ 4 4 4 ]
[ 0 0 0 ]
[ 2 2 2 ]

m1.I is:
[ 1 0 3 ]
[ 0 0 0 ]
[ 2 0 0 ]
```

Matrix inversion is calculated analytically for the case of 2x2 and 3x3 matrices, and using the numerical Newton-Shulz method for the general case of an mxn matrix.

```
// Matrix inverse
std::cout << "m3 is:" << std::endl;
std::cout << m3 << std::endl;
std::cout << "Inverse of m3 is:" << std::endl;
std::cout << m3.inv() << std::endl;
```

The following output is produced for the 4x4 matrix inversion example:

```
m3 is:
[ 9 7 2 3 ]
[ 2 4 7 7 ]
[ 4 3 8 5 ]
[ 5 5 2 3 ]

Inverse of m3 is:
[ 1 0.4 -0.2 -1.6 ]
[ -1.5 -0.8 0.4 2.7 ]
[ -0.785714 -0.542857 0.485714 1.24286 ]
[ 1.35714 1.02857 -0.657143 -2.32857 ]
```

Determinants, Spectral (l2) and Frobenius norms may be calculated for matrices:

```
// Norms
std::cout << "Determinant of m3 is:" << std::endl;
std::cout << m3.det() << std::endl;
std::cout << "Spectral norm of m3 is:" << std::endl;
std::cout << m3.spectral_norm() << std::endl;
std::cout << "Frobenius norm of m3 is:" << std::endl;
std::cout << m3.frobenius_norm() << std::endl;
```

Below is the output for the 4x4 example:

```
Determinant of m3 is:
-70
Spectral norm of m3 is:
19.1573
Frobenius norm of m3 is:
20.9284
```

LU decomposition is performed using the lu_decomposition() method:

```
// LU Decomposition
mat<double> L(4,4);
mat<double> U(4,4);
m3.lu_decomposition(L, U);
std::cout << "The LU decomposition of m3 is:" << std::endl;
std::cout << "L:" << std::endl;
std::cout << L << std::endl;
std::cout << "U:" << std::endl;
std::cout << U << std::endl;
std::cout << "The product of L and U is:" << std::endl;
std::cout << L.mult(U) << std::endl;
```

The following L and U factors are produced for the example above:

```
The LU decomposition of m3 is:
L:
[ 1 0 0 0 ]
[ 0.222222 1 0 0 ]
[ 0.444444 -0.0454545 1 0 ]
[ 0.555556 0.454545 -0.282209 1 ]

U:
[ 9 7 2 3 ]
[ 0 2.44444 6.55556 6.33333 ]
[ 0 0 7.40909 3.95455 ]
[ 0 0 0 -0.429448 ]

The product of L and U is:
[ 9 7 2 3 ]
[ 2 4 7 7 ]
[ 4 3 8 5 ]
[ 5 5 2 3 ]
```

Row and column vector classes are derived from the general matrix class and support similar operations:

```
// Vectors
std::cout << "v1 is:" << std::endl;
std::cout << v1 << std::endl;
std::cout << "v2 is:" << std::endl;
std::cout << v2 << std::endl;
std::cout << "Dot product of v1 and v2 is:" << std::endl;
std::cout << v1.mult(v2) << std::endl;
```

The following output results from the vector multiplication:

```
v1 is:
[ 1 2 3 4 ]

v2 is:
[ 1 ]
[ 2 ]
[ 3 ]
[ 4 ]

Dot product of v1 and v2 is:
[ 30 ]
```
