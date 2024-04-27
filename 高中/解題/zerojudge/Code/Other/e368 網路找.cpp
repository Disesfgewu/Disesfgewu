#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int date = 20000101;	//2020/01/01 ~ 2999/12/31

int year = 2000;
int month = 01;
int day = 01;

int leapYear(int);

void nextDay(void);

int days_in_month(int, int);

int isPrime(int);

int main(void) {
	//count
	int primeDay;
	int count;
	while(date <= 29991231) {
		//split date
		count = 8;
		primeDay = 1;
		while(count != 0) {
			if(isPrime(date % (int)(pow(10, count)))) {
				count--;
			} else {
				primeDay = 0;
				break;
			}
		}
		
		if(primeDay) {
			printf("%4d/%02d/%02d\n", year, month, day);
		}
		
		nextDay();
	}
	
	return 0;
}

int leapYear(int y) {
	if((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
		return 1;
	else
		return 0;
}

int isPrime(int n) {
	if(n % 2 == 0) {	//even
		if(n != 2)
			return 0;
		else
			return 1;
	} else {
		if(n == 1)
			return 0;
		else {
			for(int factor = 3; factor * factor <= n; factor += 2) {
				if(n % factor == 0)
					return 0;
			}
			return 1;
		}
	}
}

void nextDay(void) {
	day++;
	if(day > days_in_month(year, month)) {
		day = 1;
		month++;
		if(month == 13) {
			month = 1;
			year++;
		}
	}
	date = year * 10000 + month * 100 + day;
}

int days_in_month(int yr, int m) {
	switch(m) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
		case 2: return 28 + leapYear(yr);
		default: return 30;
	}
}
