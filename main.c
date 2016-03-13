#include <stdio.h>
#include <stdlib.h>

void makeNext(const char P[], int *next)
{
	int q, k;//q:模版字符串下标；k:最大前后缀长度
	int m = strlen(P);//模版字符串长度
	next[0] = 0;//模版字符串的第一个字符的最大前后缀长度为0
	for (q = 1, k = 0; q < m; ++q)//for循环，从第二个字符开始，依次计算每一个字符对应的next值
	{
		while (k > 0 && P[q] != P[k])//递归的求出P[0]···P[q]的最大的相同的前后缀长度k
			k = next[k - 1];          //不理解没关系看下面的分析，这个while循环是整段代码的精髓所在，确实不好理解  
		if (P[q] == P[k])//如果相等，那么最大相同前后缀长度加1
		{
			k++;
		}
		next[q] = k;
	}
}

void kmp_match(const char t[], const char p[], int *next)
{
	int     m, n, i, j;//m，i给text。   n，j给p
	m = strlen(t);
	n = strlen(p);
	i = j = 0;
	while (i < m) //没有匹配到最后一位时
	{
		//for (j = next[j]; j < n && p[j] == t[i]; )

		if (p[j] == t[i])
		{
			i++;
			j++;
		}
		else if (j>0)
		{
			j = next[j - 1];
		}
		else
		{
			i++;
			j = next[j];
		}
		if (j == n)
		{
			printf("Pattern occurs with shift:%d\n", (i - n + 1));
		}

	}
}


int main()
{
	char p[20];
	char t[50];
	printf("input target:\n");
	gets(t);
	printf("input pattern:\n");
	gets(p);
	int *next = (char*)malloc(strlen(p)*sizeof(int));
	makeNext(p, next);
	printf("the 'next' arg:");
	for (int i = 0;i < strlen(p);i++)
	{
		printf("%d ", next[i]);
	}
	printf("\n");
	kmp_match(t, p, next);
	system("pause");
	return 0;

}