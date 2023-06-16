#include<stdio.h>
#define OPTIMAL_APPROACH
#define ARRAY_BOUND 10

struct hash {
	int offset;
	int sum;
};

struct hash map[ARRAY_BOUND];

int main()
{
	int i, j, k, a[ARRAY_BOUND] = {1,2,3,1,1,1,1}, s = 0;

#ifdef BRUTE_FORCE_APPROACH
	for(i=0;i<sizeof(a)/sizeof(int);i++) {
		s=0;
		for(j=i;j<sizeof(a)/sizeof(int);j++) {
			s += a[j];
		}
		if(s == 15)
			printf("sum at i:%d, j:%d\n", i, j);
	}
#endif

#ifdef OPTIMAL_APPROACH
	int gvalue = a[0], temp = 0;
	for(i=0;i<sizeof(a)/sizeof(int);i++) {
		map[i].offset = i;
		s += a[i];
		map[i].sum = s;
		if(gvalue < a[i]) {
			temp = s;
			gvalue = a[i];
		}
	}
	printf("sum : %d\n", temp);
#endif

	return 0;
}
