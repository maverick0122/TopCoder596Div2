TopCoder596Div2
===============

TopCoder SRM 596 Div2

第3题解题报告

类型：数论  难度：2

题意：给出lo,hi,div三个数，定义函数 F(n) = (n - 0^2) * (n - 1^2) * (n - 2^2) * (n - 3^2) * ... * (n - k^2) 


k是满足n-k^2>0的最大整数。

求在[lo,hi]区间内满足F(n)能被div整除的数的个数。

 

分析：直接遍历[lo,hi]的所有数并判定F(n)能否被div整除不可行，应为hi-lo的数量级在10^12。

这里想到计算素数的思想（从小到大找素数，将素数的整数倍标记为非素数），考虑若F(n)能被div整除，那么F(n)的因式 (n-k^2)，0<=k<√n 必定至少有一个能被div整除，也就是说 n-y^2 = div*x，所以考虑 div*x+y^2，x>=1，y>=0 这个式子的值，如果这个式子的值落在[lo,hi]区间，那么这个数就是满足要求的。那么，遍历x,y，将落在区间内的值加入一个结果set集保证不重，最后统计set的大小就是结果。但是复杂度仍高，考虑当div=2时，复杂度为10^12 * 10^6，显然不能接受。一定把复杂度降低到10^6。

 

考虑简化上一种方法，由于外层循环是遍历x，寻找落在区间内的 div*x +y^2，那么若能知道每个 [div*x,div*(x+1)) 区间内的合法的n的个数，那么再乘以x落在区间内的可能值，就能在O(1)算出结果。运用这个思路，再进一步细化，并注意边界条件。

设rc[i]表示 y^2 % div = i 时，y^2 / div 的值再加1，表示这个余数最开始在div的第几个倍数中出现。遍历所有的y，1<=y<√hi，得到rc数组的值。

再计算rc数组中出现的余数的数目cnt，即每div个数有多少个满足条件。再计算所有rc数组的最大值st，即从div的第几个倍数开始，后续的每div个数都一定有cnt个满足要求的数。

之后就是考虑lo，hi两个数的边界条件，记录[lo,div*left)区间和[div*right,hi]区间内满足要求的数的个数，left取满足div*left >=lo的最小值，right取满足div*right<=hi的最大值

再然后，考虑此时的left和st的关系，若left<st，则此时每div个数符合要求的数还不到cnt个，需遍历rc数组，递增left，直到left=st。

之后就可以计算[left,right]区间内的符合要求的个数，即cnt*(right-left)。

