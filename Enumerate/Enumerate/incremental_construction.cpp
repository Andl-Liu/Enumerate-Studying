//#define _CRT_SECURE_NO_WARNINGS
//#include <cstdio>
//
//using namespace std;
//
//void print_subset_A(int n, int* A, int cur)
//{
//	for (int i = 0; i < cur; i++)
//	{
//		printf("%d ", A[i]);
//	}
//	printf("\n");
//	for (int i = (cur ? A[cur - 1] + 1 : 0); i < n; i++)
//	{
//		A[cur] = i;
//		print_subset_A(n, A, cur + 1);
//	}
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int* A = new int[n];
//	print_subset_A(n, A, 0);
//	delete[] A;
//	return 0;
//}