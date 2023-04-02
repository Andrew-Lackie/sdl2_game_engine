#include <stdio.h>

void func(char *url) {
	printf("%s\n", url);
}


int main() {
	char url[] = "Hello";
	char *pUrl;

	pUrl = &url;

	func(pUrl);

	return 0;
}
