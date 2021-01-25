#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

void print_subset(int n, int* B, int cur)
{
	if (cur == n)
	{
		for (int i = 0; i < n; i++)
		{
			if (B[i] == 1)
			{
				printf("%d ", i);
			}
		}
		printf("\n");
		return;
	}
	B[cur] = 1;
	print_subset(n, B, cur + 1);
	B[cur] = 0;
	print_subset(n, B, cur + 1);
}

//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int* B = new int[n];
//	print_subset(n, B, 0);
//	delete[] B;
//	return 0;
//}