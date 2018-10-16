#include <stdio.h>

long get_magic(long input, long input_2) {
`       long sum;
        long sum_2;

        sum = input%10 + (input/100)%10 + (input/10000);
        sum = sum%10;

        sum_2 = input_2%10 + (input_2/100)%10 + (input_2/10000);
        sum_2 = sum_2%10;

        return sum;
}

int main(void){
        long input = 0;
        long input_2 = 0;

        scanf("%ld", &input);
        printf("%ld\n", get_magic(input, input_2));

        scanf("%ld", &input_2);
        printf("%ld\n", get_magic(input, input_2));
        return 0;
}
