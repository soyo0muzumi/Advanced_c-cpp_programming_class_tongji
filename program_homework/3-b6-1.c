#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int test() {
	printf("ÇëÊäÈë[0-100 ÒÚ)Ö®¼äµÄÊý×Ö:\n");
    double price;
    scanf("%lf", &price);
    int integerPart = (price / 10);
    int _d = integerPart;
    double __d = price / 10 - _d;
    __d *= 1000;
    int ___d = __d;
    if ((__d - ___d) * 10 > 5) ___d++;
    int decimalPart = ___d % 100;
    int gewei = ___d / 100;

    // ´¦ÀíÕûÊý²¿·Ö
    if (integerPart == 0) {
        printf("ÁãÔª");
    }
    else {
        int billionSection = integerPart / 10000000;
        if (billionSection != 0) {
            if ((billionSection / 10) % 10 != 0) {
                if ((billionSection / 10) % 10 == 1) {
                    printf("Ò¼Ê°");
                }
                else {
                    switch ((billionSection / 10) % 10) {
                    case 2: printf("·¡Ê°"); break;
                    case 3: printf("ÈþÊ°"); break;
                    case 4: printf("ËÁÊ°"); break;
                    case 5: printf("ÎéÊ°"); break;
                    case 6: printf("Â½Ê°"); break;
                    case 7: printf("ÆâÊ°"); break;
                    case 8: printf("°ÆÊ°"); break;
                    case 9: printf("¾ÁÊ°"); break;
                    }
                }
            }
            if (billionSection % 10 != 0) {
                switch (billionSection % 10) {
                case 1: printf("Ò¼"); break;
                case 2: printf("·¡"); break;
                case 3: printf("Èþ"); break;
                case 4: printf("ËÁ"); break;
                case 5: printf("Îé"); break;
                case 6: printf("Â½"); break;
                case 7: printf("Æâ"); break;
                case 8: printf("°Æ"); break;
                case 9: printf("¾Á"); break;
                }
            }
            printf("ÒÚ");
        }
        int millionSection = (integerPart / 1000) % 10000;
        if (millionSection != 0) {
            if (millionSection / 1000 != 0) {
                switch (millionSection / 1000) {
                case 1: printf("Ò¼Çª"); break;
                case 2: printf("·¡Çª"); break;
                case 3: printf("ÈþÇª"); break;
                case 4: printf("ËÁÇª"); break;
                case 5: printf("ÎéÇª"); break;
                case 6: printf("Â½Çª"); break;
                case 7: printf("ÆâÇª"); break;
                case 8: printf("°ÆÇª"); break;
                case 9: printf("¾ÁÇª"); break;
                }
            }
            else if ((millionSection / 1000) == 0 && (millionSection/100 != 0)) {
                printf("Áã");
            }
            if ((millionSection / 100) % 10 != 0) {
                switch ((millionSection / 100) % 10) {
                case 1: printf("Ò¼°Û"); break;
                case 2: printf("·¡°Û"); break;
                case 3: printf("Èþ°Û"); break;
                case 4: printf("ËÁ°Û"); break;
                case 5: printf("Îé°Û"); break;
                case 6: printf("Â½°Û"); break;
                case 7: printf("Æâ°Û"); break;
                case 8: printf("°Æ°Û"); break;
                case 9: printf("¾Á°Û"); break;
                }
            }
            else if (millionSection / 100 == 0 || (millionSection / 10 != 0)) {
                printf("Áã");
            }
            if ((millionSection / 10) % 10 != 0) {
                if ((millionSection / 10) % 10 == 1) {
                    printf("Ò¼Ê°");
                }
                else {
                    switch ((millionSection / 10) % 10) {
                    case 2: printf("·¡Ê°"); break;
                    case 3: printf("ÈþÊ°"); break;
                    case 4: printf("ËÁÊ°"); break;
                    case 5: printf("ÎéÊ°"); break;
                    case 6: printf("Â½Ê°"); break;
                    case 7: printf("ÆâÊ°"); break;
                    case 8: printf("°ÆÊ°"); break;
                    case 9: printf("¾ÁÊ°"); break;
                    }
                }
            }
            if (millionSection % 10 != 0) {
                switch (millionSection % 10) {
                case 1: printf("Ò¼"); break;
                case 2: printf("·¡"); break;
                case 3: printf("Èþ"); break;
                case 4: printf("ËÁ"); break;
                case 5: printf("Îé"); break;
                case 6: printf("Â½"); break;
                case 7: printf("Æâ"); break;
                case 8: printf("°Æ"); break;
                case 9: printf("¾Á"); break;
                }
            }
            printf("Íò");
        }
        int thousandSection = integerPart % 1000;
        if (thousandSection / 100 != 0) {
            switch (thousandSection / 100) {
            case 1: printf("Ò¼Çª"); break;
            case 2: printf("·¡Çª"); break;
            case 3: printf("ÈþÇª"); break;
            case 4: printf("ËÁÇª"); break;
            case 5: printf("ÎéÇª"); break;
            case 6: printf("Â½Çª"); break;
            case 7: printf("ÆâÇª"); break;
            case 8: printf("°ÆÇª"); break;
            case 9: printf("¾ÁÇª"); break;
            }
        }
        else if ((thousandSection / 100) == 0 && (thousandSection / 10 != 0)) {
            printf("Áã");
        }
        if ((thousandSection / 10) % 10 != 0) {
            switch ((thousandSection / 10) % 10) {
            case 1: printf("Ò¼°Û"); break;
            case 2: printf("·¡°Û"); break;
            case 3: printf("Èþ°Û"); break;
            case 4: printf("ËÁ°Û"); break;
            case 5: printf("Îé°Û"); break;
            case 6: printf("Â½°Û"); break;
            case 7: printf("Æâ°Û"); break;
            case 8: printf("°Æ°Û"); break;
            case 9: printf("¾Á°Û"); break;
            }
        }
        else if ((thousandSection / 10) == 0 && (thousandSection != 0)) {
            printf("Áã");
        }
        if (thousandSection % 10 != 0) {
            if (thousandSection % 10 == 1) {
                printf("Ò¼Ê°");
            }
            else {
                switch (thousandSection % 10) {
                case 2: printf("·¡Ê°"); break;
                case 3: printf("ÈþÊ°"); break;
                case 4: printf("ËÁÊ°"); break;
                case 5: printf("ÎéÊ°"); break;
                case 6: printf("Â½Ê°"); break;
                case 7: printf("ÆâÊ°"); break;
                case 8: printf("°ÆÊ°"); break;
                case 9: printf("¾ÁÊ°"); break;
                }
            }
        }
        
        if (gewei != 0) {
            switch (gewei % 10) {
            case 1: printf("Ò¼"); break;
            case 2: printf("·¡"); break;
            case 3: printf("Èþ"); break;
            case 4: printf("ËÁ"); break;
            case 5: printf("Îé"); break;
            case 6: printf("Â½"); break;
            case 7: printf("Æâ"); break;
            case 8: printf("°Æ"); break;
            case 9: printf("¾Á"); break;
            }
        }
        printf("Ôª");
    }

    // ´¦ÀíÐ¡Êý²¿·Ö
    if (decimalPart / 10 != 0) {
        switch (decimalPart / 10) {
        case 1: printf("Ò¼"); break;
        case 2: printf("·¡"); break;
        case 3: printf("Èþ"); break;
        case 4: printf("ËÁ"); break;
        case 5: printf("Îé"); break;
        case 6: printf("Â½"); break;
        case 7: printf("Æâ"); break;
        case 8: printf("°Æ"); break;
        case 9: printf("¾Á"); break;
        }
        printf("½Ç");
    }
    if (decimalPart % 10 != 0) {
        if (decimalPart / 10 == 0) {
            printf("Áã");
        }
        switch (decimalPart % 10) {
        case 1: printf("Ò¼"); break;
        case 2: printf("·¡"); break;
        case 3: printf("Èþ"); break;
        case 4: printf("ËÁ"); break;
        case 5: printf("Îé"); break;
        case 6: printf("Â½"); break;
        case 7: printf("Æâ"); break;
        case 8: printf("°Æ"); break;
        case 9: printf("¾Á"); break;
        }
        printf("·Ö");
    }
    else if (decimalPart / 10 != 0) {
        printf("Õû");
    }
    else {
        printf("Õû");
    }
    printf("\n");

    return 0;
}

int main() {
    while (1) {
        test();
    }

    return 0;
}