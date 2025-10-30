#include <stdio.h>

#define MAX 100

void calculateSpan(int price[], int n, int span[]) {
    int stack[MAX];
    int top = -1;

    // First day span is always 1
    span[0] = 1;
    stack[++top] = 0;

    printf("Day 0: Price = %d, Span = 1\n", price[0]);

    for (int i = 1; i < n; i++) {
        // Pop prices from stack while stack is not empty and price at top is <= current price
        while (top != -1 && price[stack[top]] <= price[i]) {
            printf("  Popping index %d (Price = %d) from stack\n", stack[top], price[stack[top]]);
            top--;
        }

        // If stack is empty, all previous prices are smaller
        span[i] = (top == -1) ? (i + 1) : (i - stack[top]);
        printf("Day %d: Price = %d, Span = %d\n", i, price[i], span[i]);

        // Push this day's index to stack
        stack[++top] = i;
        printf("  Pushing index %d to stack\n", i);
    }
}

int main() {
    int price[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(price) / sizeof(price[0]);
    int span[n];

    printf("📊 Stock Prices: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", price[i]);
    }
    printf("\n\n🔍 Calculating Span Values...\n\n");

    calculateSpan(price, n, span);

    printf("\n📈 Final Span Values:\n");
    for (int i = 0; i < n; i++) {
        printf("Day %d: Span = %d\n", i, span[i]);
    }

    return 0;
}