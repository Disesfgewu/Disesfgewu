#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
char c;

int main(void) {
	scanf("%d ", &n);
	while(n--) {
		int ans = 0;
		int left = 0;
		while(1) {
			c = getchar_unlocked();
			if(c == '\n')
				break;
			else {
				if(c == 'p')
					left++;
				else if(c == 'q')
					if(left > 0) {
						left--;
						ans++;
					}
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
