#include <stdio.h>
#include <math.h>
float fun(float);
float jintuifa(float,float);
float a1, a2, a3;

float jintuifa(float a0, float h0) {
	float h, y1, y2, y3;
	a1 = a0, h = h0;
	a2 = a1 + h;
	y1 = fun(a1);
	y2 = fun(a2);
	if (y2 > y1) {
		h = -h;
		a3 = a1;
		y3 = y1;

	loop:
		a1 = a2;
		y1 = y2;
		a2 = a3;
		y2 = y3;
	}
	a3 = a2 + h;
	y3 = fun(a3);
	if (y3 < y2) {
		h = 2 * h;
		goto loop;
	}
	return 0;
}
float fun(float x) {
	return (x + 3)*(x - 4);
}

int main(){
	int n,k, pos;
	float x[100],y[100];
	float temp,e;
	jintuifa(0,0.2);
	if (a1 > a3) {
		temp=a1;
		a1 = a3;
		a3 = temp;
	}
	printf("请输入等分点数n:");
	scanf("%d", &n);
	printf("请输入精度e:");
	scanf("%f", &e);
	loop2:
	for (k = 1; k < n; k++) {
		x[k]=a1+(a3-a1)/(n+1)*k;
		y[k]=fun(x[k]);
	}
	pos=1;
	for (k = 1; k < n; k++) {
		if(y[k]<=y[pos])
			pos=k;
	}
	a1=x[pos-1];
	a3=x[pos+1];
	if ((a3 - a1) > e) {
		goto loop2;
	}
	else {
		printf("最优解为:%f",x[pos]);
	}
	//system("pause");
	return 0;
}
