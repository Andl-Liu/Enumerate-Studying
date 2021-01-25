//#define _CRT_SECURE_NO_WARNINGS
//#include <cstdio>
//
//using namespace std;
//
//void print_permutation(int n, int cur, int* A)
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
//		int ok = 1;
//		for (int j = 0; j < cur; j++)
//		{
//			if (i == A[j])
//			{
//				ok = 0;
//				break;
//			}
//		}
//		if (ok)
//		{
//			A[cur] = i;
//			print_permutation(n, cur + 1, A);
//		}
//	}
//}
//
//int main()
//{
//	int n = 3;
//	int* A = new int[4];
//	print_permutation(n, 0, A);
//	delete[] A;
//	return 0;
//}