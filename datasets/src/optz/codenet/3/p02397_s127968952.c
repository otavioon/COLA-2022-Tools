int main(void)
{
    long i, xx, yy, j;
	long x[3000];
	long y[3000];
	i = 0;
	do{
		scanf("%d%d", &x[i], &y[i]);
		xx = x[i];
		yy = y[i];
		i++;
	} while (xx != 0 || yy != 0);
	i = i - 1;
	for (j = 0; j < i; j++){
		if (x[j] <= y[j]) printf("%d %d\n", x[j], y[j]);
		else			  printf("%d %d\n", y[j], x[j]);
		}
	return 0;
}