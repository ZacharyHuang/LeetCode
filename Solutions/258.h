#include "common.h"

// > if num = 0
// result = 0
// > if num > 0, it can be presented as following
// num = 10^k * a_k + 10^(k-1) * a_k-1 + ... + 10 * a_1 + a_0
//     = (10^k - 1) * a_k + a_k + (10^(k-1) - 1) * a_k-1 + a_k-1 + ... + 9 * a_1 + a_1 + a_0
// Obviously (10^k - 1) = 99...9 = 9 * N (N is an any integer)
// So num = 9 * N + a_k + a_k-1 + ... + a_1 + a_0
// then set num' = a'_k' + ak-1 + ... + a_1 + a_0
//               = 10^k' * a'_k' + 10^(k'-1) * a'_k'-1 + ... + 10 * a'_1 + a'_0
//               = 9 * N' + a_k' + a'_k'-1 + ... + a'_1 + a'_0
// finally when num' in a recurrence is just a*_0, which means num' is 1 ~ 9
// then we can stop recurrence and set a*_0 as the result
// so finally num can be presented as following
// num = 9 * N + 9 * N' + 9 * N'' + ... + a*_0
//     = 9 * N* + a*_0
// the ressult a*_0 is 1 ~ 9
// if a*_0 != 9
// a*_0 = a*_0 % 9
//      = 0 + (a*_0 % 9)
//      = ((9 * N*) % 9) + (a*_0 % 9)
//      = (9 * N* + a*_0) % 9
//      = num % 9
// but if a*_0 = ((9 * N*) % 9) + (9 % 9)
//             = 0
// so if num % 9 == 0, then result is 9
// for example
// 38 = 10 * 3 + 8
//    = 9 * 3 + (3 + 8)
//    = 9 * 3 + 10 * 1 + 1
//    = 9 * 3 + 9 * 1 + (1 + 1)
//    = 9 * 3 + 9 * 4 + 2 --> stop recurrence
// result will be 2
// let's see (38 % 9) = 2 is same as the result.
// 189 % 9 == 0
// let's se whether its result is 9:
// 189 = 1 + 8 + 9 = 18 = 1 + 8 = 9
// summary:
// if (num == 0) return 0;
// if (num % 9 == 0) return 9;
// if (num % 9 != 0) return num % 9;
int addDigits(int num) {
	return num ? ((num %= 9) ? num : 9) : 0;
}

void Test()
{
	printf("%d\n", addDigits(38));
}