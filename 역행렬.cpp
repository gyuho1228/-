#include <iostream>
using namespace std;
void main() {
	// matrix in 2D
	int N = 2, K = 2, M = 1;	//행렬 크기 정의 (N x K) x (K x M) = NxM
	float A[2][2] = { {1,2},{4,5} }, ** B, ** C, **D;	//A*B=C, A역행렬 = D
	B = new float* [K];
	for (int k = 0; k < K; k++) B[k] = new float[M];
	C = new float* [N];
	for (int n = 0; n < N; n++) C[n] = new float[M];
	D = new float* [N];
	for (int n = 0; n < N; n++) D[n] = new float[K];

	C[0][0] = 4;
	C[1][0] = 7;


	float detA = A[0][0] * A[1][1] - A[1][0] * A[0][1];

	D[0][0] = A[1][1] / detA;
	D[0][1] = -(A[0][1] / detA);
	D[1][0] = -(A[1][0] / detA);
	D[1][1] = A[0][0] / detA;

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			B[n][m] = 0;	//초기화
			for (int k = 0; k < K; k++)
				B[n][m] += D[n][k] * C[k][m];	//B = D*C
		}
	}
	// show results
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			cout << B[n][m] << "  ";
		}
		cout << endl;
	}
	for (int n = 0; n < N; n++) { delete[] B[n]; delete C[n]; delete D[n];
	}
	delete[] B;
	delete[] C;
	delete[] D;	//  delete은 new의 역순
}

















