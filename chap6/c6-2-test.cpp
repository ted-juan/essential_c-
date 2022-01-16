#include "c6-2.cpp"

int main() {	
  Matrix<float> identity(4, 4);

	cout << "Matrix identity: " << endl << identity << endl;
	float arr1[16] = {
		1.0, 0.0, 0.0, 0.0,
		0.0, 1.0, 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0,
		0.0, 0.0, 0.0, 1.0
	};

	for (int i = 0, k = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			identity(i, j) = arr1[k++];

	cout << "Matrix identity now: " << endl << identity << endl;
	Matrix<float> mat1(identity);
	cout << "Matrix 1: " << endl << mat1 << endl;
	Matrix<float> mat2(8, 12);
	cout << "Matrix 2 8*12: " << endl << mat2 << endl;
	mat2 = mat1;
	cout << "Matrix 2 now: " << endl << mat2 << endl;

	float arr2[16] = {
		1.3f, 0.4f, 2.6f, 8.2f,
		6.2f, 1.7f, 1.3f, 8.3f,
		4.2f, 7.4f, 2.7f, 1.9f,
		6.3f, 8.1f, 5.6f, 6.6f
	};

	Matrix<float> mat3(4, 4);
	for (int ix = 0, jx = 0; ix < 4; ++ix)
		for (int kx = 0; kx < 4; ++kx)
			mat3(ix, kx) = arr2[jx++];

	cout << "Matrix 3: " << endl << mat3 << endl;
	Matrix<float> mat4 = mat3 * identity;
	cout << "Matrix 4: " << endl << mat4 << endl;
	Matrix<float> mat5 = mat3 + mat4;
	cout << "Matrix 5: " << endl << mat5 << endl;
	mat3 += mat4;
	cout << "Matrix 3 now: " << endl << mat3 << endl;
	return 0;
}