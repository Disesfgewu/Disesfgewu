#include <bits/stdc++.h>
using namespace std;


int n;
long long int result;
int player[200005];

void radixSort(int*, int, int);
int getDigit(int, int);

int main(void) {
	while(scanf("%d", &n) != EOF) {
		for(int i = 1; i <= n; i++) {
			scanf("%d", &player[i]);
		}
		
		//sort
		radixSort(player, 1, n);
		
		//solve
		int weight = n - 1;
		result = 0;
		for(int i = n; i > 0; i--) {
			result += (long long int)player[i] * (weight);
			weight -= 2;
		}
		
		//print
		printf("%lld\n", result);
	}
	return 0;
}

void radixSort(int arr[], int start, int end) {
	//init
	int bucket[10][end - start + 1];
	int bucket_count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	//get max num
	int max_num = arr[start];
	for(int i = start + 1; i <= end; i++) {
		if(arr[i] > max_num) {
			max_num = arr[i];
		}
	}
	
	//get max pow
	int max_pow = -1;
	while(max_num > 0) {
		max_pow++;
		max_num /= 10;
	}
	
	//sort
	for(int pow = 0; pow <= max_pow; pow++) {
		//append into bucket
		int value;
		for(int i = start; i <= end; i++) {
			value = getDigit(arr[i], pow + 1);
			bucket[value][bucket_count[value]] = arr[i];
			bucket_count[value]++;
		}
		
		//take out
		int i = start;
		for(int val = 0; val < 10; val++) {
			for(int j = 0; j < bucket_count[val]; j++) {
				arr[i] = bucket[val][j];
				i++;
			}
			bucket_count[val] = 0;
		}
	}
}

int getDigit(int num, int digit) {
	int d[50];
	int i = 1;
	while(num > 0) {
		d[i] = num % 10;
		num /= 10;
		i++;
	}
	
	if(digit < i) {
		return d[digit];
	} else {
		return 0;
	}
}
