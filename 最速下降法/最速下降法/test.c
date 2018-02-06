#include <stdio.h>
#include <math.h>

long int k = -1;
float fun(float);
float jintuifa(float, float);
float gedianfa();
float a1, a2, a3;
float x[2][1000], d[2][1000];

int main() {
	float a[1000], e1, X[2];
	double t;
	printf("请输入初值x0(x1,x2):");
	scanf("%f,%f", &x[0][0], &x[1][0]);
	printf("请输入精度e1:");
	scanf("%f", &e1);
	do {
		k++;
		d[0][k] = -(2 * x[0][k] - 2 * x[1][k] - 4);
		d[1][k] = -(4 * x[1][k] - 2 * x[0][k]);
		a[k] = gedianfa();
		x[0][k + 1] = x[0][k] + a[k] * d[0][k];
		x[1][k + 1] = x[1][k] + a[k] * d[1][k];
		t = sqrt((x[0][k + 1] - x[0][k])*(x[0][k + 1] - x[0][k]) + (x[1][k + 1] - x[1][k])*(x[1][k + 1] - x[1][k]));
	} while ( t >= e1);
	X[0] = x[0][k + 1];
	X[1] = x[1][k + 1];
	printf("极小点为:(%f,%f)\nk=%d", X[0], X[1], k);
	system("pause");
	return 0;
}

float fun1(float x1, float x2) {
	return x1*x1 + 2 * x2*x2 - 4 * x1 - 2 * x1*x2;
}
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
float fun(float a) {
	return fun1(x[0][k] + a*d[0][k], x[1][k] + a*d[1][k]);
}

float gedianfa() {
	int n = 10, i, pos;
	float x[100], y[100];
	float temp, e = 0.001;
	jintuifa(0, 0.2);
	if (a1 > a3) {
		temp = a1;
		a1 = a3;
		a3 = temp;
	}
	//printf("请输入等分点数n:");
	//scanf_s("%d", &n);
	//printf("请输入精度e:");
	//scanf_s("%f", &e);
loop2:
	for (i = 1; i < n; i++) {
		x[i] = a1 + (a3 - a1) / (n + 1)*i;
		y[i] = fun(x[i]);
	}
	pos = 1;
	for (i = 1; i < n; i++) {
		if (y[i] <= y[pos])
			pos = i;
	}
	a1 = x[pos - 1];
	a3 = x[pos + 1];
	if ((a3 - a1) > e) {
		goto loop2;
	}
	else {
		//printf("最优解为:%f", x[pos]);
	}
	return x[pos];
}