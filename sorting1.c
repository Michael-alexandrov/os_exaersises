#include <stdio.h>
int main(){
	int a[20], i, j, c, e, r;
	for (i = 0; i < 20; i++)
		scanf("%d,", &a[i]);
	for (i = 3; i < 20; i++){  //первые три элемента упорядочены изначально. Метод простой вставки.
		r = 1;
		j = 0;
		while ((r == 1) && (j < i)){
			if (a[i] < a[j]) {
				c = a[i];
				for (e = i; e > j; e--){
					a[e] = a[e - 1];
				}
				a[j] = c;
				r = 2;
			}
			j++;
		}
	}
		for (i = 0; i < 20; i++)
			printf("%d ", a[i]);
			return 0;
}
