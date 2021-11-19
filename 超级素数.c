#include<stdio.h>
//$p^ q + q ^ p$是一个素数， $p$和$q$也是素数， 求$p$和$q$
long mi(long q, long p)
{
	if (p == 1) return q;
	 return q * mi(q, p - 1);
}

int shu(long p)
{
	for (int i = 2; i < p / i; i++)
	{
		if (p % i == 0) return 0;
	}
	return 1;
}
int main()
{
	long long sum = 2;
	long p = 2, q = 2;
	for (;; p++)
	{
		if (!(shu(p))) continue;
		for (q = 2; q < 10000; q++)
		{
			if (!(shu(q))) continue;
			if(shu(q)&&shu(p))
			sum = mi(q, p) + mi(p, q);
		if (shu(sum)) { printf("%ld   %ld", q, p); return 0; }
		}
	}

	return 0;
}