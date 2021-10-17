#include <stdio.h>
#include <stdlib.h>
#define TAXRATE_300 .15
#define TAXRATE_150 .20
#define TAXRATE_REST .25
#define OVERTIME 40
int main()
{
   int hours = 0;
   int payrate=0;
   double grossPay = 0.0;
   double taxes = 0.0;
   double netPay = 0.0;
   printf("Enter the Basic Pay rate: ");
   scanf("%d", &payrate);
   printf("Please enter the number of hours worked this week: ");
   scanf("%d", &hours);
   if (hours <= 40)
       grossPay = hours * payrate;
   else
   {
     grossPay = 40 * payrate;
     double overTimePay = (hours - 40) * (payrate * 1.5);
     grossPay += overTimePay;
   }
   if (grossPay <= 300)
   {
       taxes = grossPay * TAXRATE_300;
   }
   else if(grossPay > 300 && grossPay <= 450)
   {
       taxes = 300 * TAXRATE_300;
       taxes += (grossPay - 300) * TAXRATE_150;
   }
   else if (grossPay > 450)
   {
       taxes = 300 * TAXRATE_300;
       taxes += 150 * TAXRATE_150;
       taxes += (grossPay - 450) * TAXRATE_REST;
   }
   netPay = grossPay - taxes;
   printf("Your gross pay this week is: %.2f\n", grossPay);
   printf("Your taxes this week is: %.2f\n", taxes);
   printf("Your net pay this week is: %.2f\n", netPay);
   return 0;
}
