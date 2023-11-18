#include <stdio.h>

float calculateTotalAmount(float unitPrice, float gstPercentage, int quantity, float discountPercentage) {
    float gstAmount = (unitPrice * gstPercentage / 100) * quantity;
    float totalAmount = (unitPrice * quantity + gstAmount) * (1 - discountPercentage / 100);
    return totalAmount;
}

int main() {

    char products[][20] = {"Leather Wallet", "Umbrella", "Cigarette", "Honey"};
    float unitPrices[] = {1100, 900, 200, 100};
    float gstPercentages[] = {18, 12, 28, 0};
    int quantities[] = {1, 4, 3, 2};
    float discountPercentage = 5;


    float maxGstAmount = 0;
    char maxGstProduct[20];

    
    float totalAmount;
    for (int i = 0; i < 4; i++) {
        totalAmount = calculateTotalAmount(unitPrices[i], gstPercentages[i], quantities[i], discountPercentage);
        printf("%s - Total Amount: %.2f\n", products[i], totalAmount);


        if ((unitPrices[i] * gstPercentages[i] / 100) * quantities[i] > maxGstAmount) {
            maxGstAmount = (unitPrices[i] * gstPercentages[i] / 100) * quantities[i];
            strcpy(maxGstProduct, products[i]);
        }
    }


    printf("\nProduct with Maximum GST Amount: %s\n", maxGstProduct);

    
    float totalPayment = 0;
    for (int i = 0; i < 4; i++) {
        totalPayment += calculateTotalAmount(unitPrices[i], gstPercentages[i], quantities[i], discountPercentage);
    }
    printf("Total Amount to be Paid: %.2f\n", totalPayment);
    return 0;
}
