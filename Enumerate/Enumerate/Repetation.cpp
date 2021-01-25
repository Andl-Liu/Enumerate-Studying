//#define _CRT_SECURE_NOWARNINGS
//#include <cstdio>
//
//using namespace std;
//
//void print_permutation(int n, int cur, int* A,int *P) 
//{
//	if (n == cur)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			printf("%d ", A[i]);
//		}
//		printf("\n");
//		return;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		if (!(i == 0 || P[i - 1] != P[i]))
//			continue;
//		int c1 = 0, c2 = 0;
//		for (int j = 0; j < n; j++)
//			if (P[i] == P[j])
//				c1++;
//		for (int j = 0; j < cur; j++)
//			if (P[i] == A[j])
//				c2++;
//		if (c2 < c1)
//		{
//			A[cur] = P[i];
//			print_permutation(n, cur + 1, A, P);
//		}
//	}
//}
//
//int main()
//{
//	int n = 3;
//	int P[] = { 1,1,2 };
//	int* A = new int[n];
//	print_permutation(n, 0, A, P);
//	delete[] A;
//	return 0;
//}