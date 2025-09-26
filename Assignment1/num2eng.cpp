#include <iostream>
using namespace std;

int main() {
    int amount;
    cout << "Enter an amount in figures: ";
    cin >>  amount;

    cout << "In words:";
    if (amount == 0) {
        cout << " Zero";
        return 0;
    }

    if (amount < 0) {
        cout << " Negative ";
        amount = -amount;
    }

    int thousands = amount / 1000; 
    int remainder = amount % 1000; 

    if (thousands > 0) {
        int hundreds = thousands / 100; 
        int tens = (thousands % 100) / 10;
        int unit = thousands % 10;

        if (hundreds > 0) {
            switch (hundreds) {
                case 1: cout << "One hundred "; break;
                case 2: cout << "Two hundred "; break;
                case 3: cout << "Three hundred "; break;
                case 4: cout << "Four hundred "; break;
                case 5: cout << "Five hundred "; break;
                case 6: cout << "Six hundred "; break;
                case 7: cout << "Seven hundred "; break;
                case 8: cout << "Eight hundred "; break;
                case 9: cout << "Nine hundred "; break;
            }
        }

        if (tens == 1) { 
            switch (unit) {
                        case 0: cout << "Ten "; break;
                        case 1: cout << "Eleven "; break;
                        case 2: cout << "Twelve "; break;
                        case 3: cout << "Thirteen "; break;
                        case 4: cout << "Fourteen "; break;
                        case 5: cout << "Fifteen "; break;
                        case 6: cout << "Sixteen "; break;
                        case 7: cout << "Seventeen "; break;
                        case 8: cout << "Eighteen "; break;
                        case 9: cout << "Nineteen "; break;
                    }
        } else {
            switch (tens) { 
                case 2: cout << "Twenty "; break;
                case 3: cout << "Thirty "; break;
                case 4: cout << "Forty "; break;
                case 5: cout << "Fifty "; break;
                case 6: cout << "Sixty "; break;
                case 7: cout << "Seventy "; break;
                case 8: cout << "Eighty "; break;
                case 9: cout << "Ninety "; break;
            }
            switch (unit) { 
                case 1: cout << "One "; break;
                case 2: cout << "Two "; break;
                case 3: cout << "Three "; break;
                case 4: cout << "Four "; break;
                case 5: cout << "Five "; break;
                case 6: cout << "Six "; break;
                case 7: cout << "Seven "; break;
                case 8: cout << "Eight "; break;
                case 9: cout << "Nine "; break;
            }
        }
        cout << "thousand ";
    }
    int hundreds2 = remainder / 100; 
    int tens2 = (remainder % 100) / 10; 
    int units2 = remainder % 10; 

    if (hundreds2 > 0) {
        switch (hundreds2) {
            case 1: cout << "One hundred "; break;
            case 2: cout << "Two hundred "; break;
            case 3: cout << "Three hundred "; break;
            case 4: cout << "Four hundred "; break;
            case 5: cout << "Five hundred "; break;
            case 6: cout << "Six hundred "; break;
            case 7: cout << "Seven hundred "; break;
            case 8: cout << "Eight hundred "; break;
            case 9: cout << "Nine hundred "; break;
        }
    }
    if (tens2 == 1) { 
        switch (units2) {
                    case 0: cout << "Ten "; break;
                    case 1: cout << "Eleven "; break;
                    case 2: cout << "Twelve "; break;
                    case 3: cout << "Thirteen "; break;
                    case 4: cout << "Fourteen "; break;
                    case 5: cout << "Fifteen "; break;
                    case 6: cout << "Sixteen "; break;
                    case 7: cout << "Seventeen "; break;
                    case 8: cout << "Eighteen "; break;
                    case 9: cout << "Nineteen "; break;
                }
    } else {
        switch (tens2) { 
            case 2: cout << "Twenty "; break;
            case 3: cout << "Thirty "; break;
            case 4: cout << "Forty "; break;
            case 5: cout << "Fifty "; break;
            case 6: cout << "Sixty "; break;
            case 7: cout << "Seventy "; break;
            case 8: cout << "Eighty "; break;
            case 9: cout << "Ninety "; break;
        }
        switch (units2) {
            case 1: cout << "One "; break;
            case 2: cout << "Two "; break;
            case 3: cout << "Three "; break;
            case 4: cout << "Four "; break;
            case 5: cout << "Five "; break;
            case 6: cout << "Six "; break;
            case 7: cout << "Seven "; break;
            case 8: cout << "Eight "; break;
            case 9: cout << "Nine "; break;
        }
    }
    cout << endl;
    return 0;
}