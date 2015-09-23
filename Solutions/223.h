#include "common.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
	int l = MAX(A, E);
	int r = MIN(C, G);
	int b = MAX(B, F);
	int t = MIN(D, H);
	return (C - A) * (D - B) + (G - E) * (H - F) - ((r > l && t > b) ? (r - l) * (t - b) : 0);
}

void Test()
{
	printf("%d\n", computeArea(-3, 0, 3, 4, 0, -1, 9, 2));
}