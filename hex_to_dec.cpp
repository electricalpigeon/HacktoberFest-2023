/**
 * Converting Hexadecimal to Decimal in C++  
 */


#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<math.h>


unsigned long HexToDec(char hex[]) {
  char *hexstr;
  int length = 0;
  const int base = 16;     // Base of Hexadecimal Number
  unsigned long decnum = 0;
  int i;

  // Find the length of Hexadecimal Number
  for (hexstr = hex; *hexstr != '\0'; hexstr++) {
      length++;
    }

  //Find Hexadecimal Number
  hexstr = hex;
  for (i = 0; *hexstr != '\0' && i < length; i++, hexstr++) {
      // Compare *hexstr with ASCII values
      if (*hexstr >= 48 && *hexstr <= 57) {  // is *hexstr Between 0-9
          decnum += (((int)(*hexstr)) - 48) * pow(base, length - i - 1);
        }
      else if ((*hexstr >= 65 && *hexstr <= 70))  {  // is *hexstr Between A-F
          decnum += (((int)(*hexstr)) - 55) * pow(base, length - i - 1);
        }
      else if (*hexstr >= 97 && *hexstr <= 102) {  // is *hexstr Between a-f
          decnum += (((int)(*hexstr)) - 87) * pow(base, length - i - 1);
        }
      else {
          std::cout<<"Invalid Hexadecimal Number \n";

        }
    }
  return decnum;
}

void main() {
  unsigned long decnum;
  char hex[9];     // 8 characters for 32-bit Hexadecimal Number and one for ' '

  std::cout<<" Enter 32-bit Hexadecimal Number : ";
  std::cin>>hex;

  decnum = HexToDec(hex);
  std::cout<<"Value in Decimal Number is "<<decnum<<"\n";

  getch();
}


/*
OUTPUT:
Enter 32-bit Hexadecimal Number : 10
Value in Decimal Number is 16

*/
