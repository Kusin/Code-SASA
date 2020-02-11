#include <cstdio>
using namespace std;

int a[500000];
char buf[10000010], buf2[10000010];

int dq[500000];

inline int ri()
{
	static int i = 0;
	bool b = false;
	if (buf[i] == '-')
	{
		i++;
		b = true;
	}
	int ret = buf[i++] - '0';
	while (buf[i] >= '0')
	{
		ret *= 10;
		ret += buf[i++] - '0';
	}
	++i;
	return (b ? -ret : ret);
}

int ii;
void g(int x)
{
	if (x < 0)
	{
		x = -x;
		buf2[ii++] = '-';
	}
	char s[8];
	int j = 0;
	do {
		s[j++] = x % 10 + '0';
		x /= 10;
	} while (x);
	while (j--)
		buf2[ii++] = s[j];
	buf2[ii++] = ' ';
}

int main()
{
	fread(buf, 1, sizeof buf, stdin);
	
	int n, l, i;
	n = ri();
	l = ri();
	for (i = 1; i <= n; i++)
		a[i] = ri();

	int f = 0, b = -1;

	for (i=1; i <= n; i++)
	{
		while (f <= b && dq[f] <= i - l)
			f++;
		while (f <= b && a[i] > a[dq[b]])
			b--;
		dq[++b] = i;
		g(dq[f]);
	}

	for(i=n+1;i<n+l;i++)
	{
		while (f <= b && dq[f] <= i - l)
			f++;
		g(dq[f]);
	} 
	fwrite(buf2, 1, ii, stdout);
}
