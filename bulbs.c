#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO get string
    string message = get_string("Message: ");

    // go through each character of string
    for (int i = 0, n = strlen(message); i < n; i++)
    {
        int binary[] = {0, 0, 0, 0, 0, 0, 0, 0};
        // convert to ASCII
        int decimal = message[i];
        // convert to binary
        int j = 0;
        while (decimal > 0)
        {
            binary[j] = decimal % 2;
            decimal = decimal / 2;
            j++;
        }
        // print in reverse because it must go right to left not left to right.
        for (int k = BITS_IN_BYTE - 1; k >= 0; k--)
        {
            print_bulb(binary[k]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
