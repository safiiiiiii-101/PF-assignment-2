#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int BinaryToDecimal(int number);
int DecimalToBinary(int number);
void DecimalToHexadecimal(int number);
void HexadecimalToDecimal(char hexNumber[]);
void BinaryToHexadecimal(int number);
void HexadecimalToBinary(char hexNumber[]);

int main(void) 
{
    int choice;

    do 
    {
        printf("\nMenu:\n");
        printf("1) Binary to Decimal\n");
        printf("2) Decimal to Binary\n");
        printf("3) Decimal to Hexadecimal\n");
        printf("4) Hexadecimal to Decimal\n");
        printf("5) Binary to Hexadecimal\n");
        printf("6) Hexadecimal to Binary\n");
        printf("0) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                {
                    int binary;
                    printf("Enter a binary number: ");
                    scanf("%d", &binary);
                    printf("Decimal equivalent: %d\n", BinaryToDecimal(binary));
                }
                break;

            case 2:
                {
                    int decimal;
                    printf("Enter a decimal number: ");
                    scanf("%d", &decimal);
                    printf("Binary equivalent: %d\n", DecimalToBinary(decimal));
                }
                break;

            case 3:
                {
                    int decimal;
                    printf("Enter a decimal number: ");
                    scanf("%d", &decimal);
                    printf("Hexadecimal equivalent: ");
                    DecimalToHexadecimal(decimal);
                }
                break;

            case 4:
                {
                    char hex[20];
                    printf("Enter a hexadecimal number: ");
                    scanf("%s", hex);
                    HexadecimalToDecimal(hex);
                }
                break;

            case 5:
                {
                    int binary;
                    printf("Enter a binary number: ");
                    scanf("%d", &binary);
                    printf("Hexadecimal equivalent: ");
                    BinaryToHexadecimal(binary);
                }
                break;

            case 6:
                {
                    char hex[20];
                    printf("Enter a hexadecimal number: ");
                    scanf("%s", hex);
                    printf("Binary equivalent: ");
                    HexadecimalToBinary(hex);
                }
                break;

            case 0:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice! Please enter a number between 0 and 6.\n");
        }
    } while (choice != 0);

    return 0;
}

int BinaryToDecimal(int number) 
{
    int decimal = 0;
    int base = 1;

    while (number > 0) 
    {
        int last_digit = number % 10;
        number = number / 10;
        decimal += last_digit * base;
        base *= 2;
    }

    return decimal;
}

int DecimalToBinary(int number) 
{
    int binary = 0, remainder, base = 1;

    while (number > 0) 
    {
        remainder = number % 2;
        binary += remainder * base;
        number /= 2;
        base *= 10;
    }

    return binary;
}

void DecimalToHexadecimal(int number) 
{
    char hex[20];
    int i = 0;

    while (number != 0) 
    {
        int temp = number % 16;
        if (temp < 10) 
            hex[i++] = temp + '0';
        else 
            hex[i++] = temp - 10 + 'A';
        number /= 16;
    }

    for (int j = i - 1; j >= 0; j--) 
    {
        printf("%c", hex[j]);
    }
    printf("\n");
}

void HexadecimalToDecimal(char hexNumber[]) 
{
    int decimal = 0;
    int base = 1;
    int len = strlen(hexNumber);

    for (int i = len - 1; i >= 0; i--) 
    {
        if (hexNumber[i] >= '0' && hexNumber[i] <= '9') 
        {
            decimal += (hexNumber[i] - '0') * base;
        } 
        else if (hexNumber[i] >= 'A' && hexNumber[i] <= 'F') 
        {
            decimal += (hexNumber[i] - 'A' + 10) * base;
        } 
        else if (hexNumber[i] >= 'a' && hexNumber[i] <= 'f') 
        {
            decimal += (hexNumber[i] - 'a' + 10) * base;
        } 
        else 
        {
            printf("Invalid hexadecimal input.\n");
            return;
        }
        base *= 16;
    }

    printf("Decimal equivalent: %d\n", decimal);
}

void BinaryToHexadecimal(int number) 
{
    int decimal = BinaryToDecimal(number);
    DecimalToHexadecimal(decimal);
}

void HexadecimalToBinary(char hexNumber[]) 
{
    for (int i = 0; hexNumber[i] != '\0'; i++) 
    {
        switch (hexNumber[i]) 
        {
            case '0': 
                printf("0000"); 
                break;
            case '1': 
                printf("0001"); 
                break;
            case '2': 
                printf("0010"); 
                break;
            case '3': 
                printf("0011"); 
                break;
            case '4': 
                printf("0100"); 
                break;
            case '5': 
                printf("0101"); 
                break;
            case '6': 
                printf("0110"); 
                break;
            case '7': 
                printf("0111"); 
                break;
            case '8': 
                printf("1000"); 
                break;
            case '9': 
                printf("1001"); 
                break;
            case 'A': case 'a': 
                printf("1010"); 
                break;
            case 'B': case 'b': 
                printf("1011"); 
                break;
            case 'C': case 'c': 
                printf("1100"); 
                break;
            case 'D': case 'd': 
                printf("1101"); 
                break;
            case 'E': case 'e': 
                printf("1110"); 
                break;
            case 'F': case 'f': 
                printf("1111"); 
                break;
            default: 
                printf("Invalid hexadecimal input.\n");
                return;
        }
    }
    printf("\n");
}
