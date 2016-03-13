#include <stdio.h>
#include <stdlib.h>

void makeNext(const char P[], int *next)
{
	int q, k;//q:ģ���ַ����±ꣻk:���ǰ��׺����
	int m = strlen(P);//ģ���ַ�������
	next[0] = 0;//ģ���ַ����ĵ�һ���ַ������ǰ��׺����Ϊ0
	for (q = 1, k = 0; q < m; ++q)//forѭ�����ӵڶ����ַ���ʼ�����μ���ÿһ���ַ���Ӧ��nextֵ
	{
		while (k > 0 && P[q] != P[k])//�ݹ�����P[0]������P[q]��������ͬ��ǰ��׺����k
			k = next[k - 1];          //�����û��ϵ������ķ��������whileѭ�������δ���ľ������ڣ�ȷʵ�������  
		if (P[q] == P[k])//�����ȣ���ô�����ͬǰ��׺���ȼ�1
		{
			k++;
		}
		next[q] = k;
	}
}

void kmp_match(const char t[], const char p[], int *next)
{
	int     m, n, i, j;//m��i��text��   n��j��p
	m = strlen(t);
	n = strlen(p);
	i = j = 0;
	while (i < m) //û��ƥ�䵽���һλʱ
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