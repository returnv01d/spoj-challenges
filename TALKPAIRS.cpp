// https://www.spoj.com/problems/TALKPAIRS/
// Done with @arturperec https://github.com/arturperec

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    unsigned long * tab = new unsigned long [n];
	for(int i = 0;i < n;i++) cin >> tab[i];

    int current, next, highest, second_highest;
    int sum = 0;

    for(int i = 0; i < n; i++){
        current = tab[i];
        highest = 0;
        second_highest = 0;

        for(int a = i + 1; a < n; a++){
            next = tab[a];

			// Case when first next number is bigger, we dont have max yet
			if(current <= next){
              sum++;
              break;
            }

            if(current <= highest){
              sum++;
              break;
            }
            if(next <= highest || next <= second_highest) continue;

            sum++;

			// Update highest and second highest numbers
            if(next > highest) {
                second_highest = highest;
                highest = next;
            }
            if(next >= second_highest && next < highest ) second_highest = next;
        }
    }

    cout << sum;

	delete tab;

	return 0;
}
