#include "Header.h"
#pragma comment(lib,"winmm.lib") 
#include<windows.h>
#pragma comment(lib,"winmm.lib") 

void main(void)
{
	//	DWORD t1, t2;
	//	t1 = timeGetTime();
	long long index;
	long long size = 4500000000;
	cout << "input index of prime" << endl;
	cin >> index;
	if (index < 1000000)
		size = floor(1.6 * index);
	else if (1000000 <= index && index < 5000000)
		size = floor(1.8 * index);
	else if (5000000 <= index && index < 10000000)
		size = floor(1.8 * index);
	else if (10000000 <= index && index < 30000000)
		size = floor(2 * index);
	else if (30000000 <= index && index < 50000000)
		size = floor(2 * index);
	else if (50000000 <= index && index < 150000000)
		size = floor(2.1 * index);
	else if (150000000 <= index && index < 200000000)
		size = floor(2.2 * index);
	else
		size = floor(2.5 * index);


	long long half = size / 2;
	bool* p = new bool[half];
	int sn = (int)sqrt(size);
	for (long long i = 0; i < half; i++)
		p[i] = true;// 初始化全部奇数为素数。p[0]对应3，即p[i]对应2*i+3   
	for (long long i = 0; i < sn; i++) {
		if (p[i]){
			for (long long k = i + i + 3, j = k*i + k + i; j < half; j += k)
				p[j] = false;
		}

	}

	//	cout << p[i] << ' ';
	long long  count = 1;
	for (long long i = 0; i < half; i++){
		if (p[i])
			count++;
		if (count == index){
			cout << (2 * i + 3) << endl;
			break;
		}
	}
	//	t2 = timeGetTime();
	//	cout << endl << (t2 - t1)*1.0 / 1000 << endl;

	system("pause");
}