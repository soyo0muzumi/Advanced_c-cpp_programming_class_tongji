#include <iostream>
using namespace std;

int main() {
    cout << "ÇëÊäÈë[0-100 ÒÚ)Ö®¼äµÄÊı×Ö:" << endl;

    double price;
    cin >> price;
    int integerPart = (price / 10);
    int _d = integerPart;
    double __d = price / 10 - _d;
    __d *= 1000;
    int ___d = __d;
    if ((__d - ___d) * 10 > 5) ___d++;
    int decimalPart = ___d % 100;
    int gewei = ___d / 100;

    // ´¦ÀíÕûÊı²¿·Ö ×¢ÒâÃ»ÓĞ¸öÎ»
    // °´Ç§Î»·Ö×é
    if (integerPart == 0) {
        cout << "ÁãÔª";
    }
    else {
        int billionSection = integerPart / 10000000;
        if (billionSection != 0) {
            if ((billionSection / 10) % 10 != 0) {
                if ((billionSection / 10) % 10 == 1) {
                    cout << "Ò¼Ê°";
                }
                else {
                    switch ((billionSection / 10) % 10) {
                    case 2: cout << "·¡Ê°"; break;
                    case 3: cout << "ÈşÊ°"; break;
                    case 4: cout << "ËÁÊ°"; break;
                    case 5: cout << "ÎéÊ°"; break;
                    case 6: cout << "Â½Ê°"; break;
                    case 7: cout << "ÆâÊ°"; break;
                    case 8: cout << "°ÆÊ°"; break;
                    case 9: cout << "¾ÁÊ°"; break;
                    }
                }
            }
            if (billionSection % 10 != 0) {
                switch (billionSection % 10) {
                case 1: cout << "Ò¼"; break;
                case 2: cout << "·¡"; break;
                case 3: cout << "Èş"; break;
                case 4: cout << "ËÁ"; break;
                case 5: cout << "Îé"; break;
                case 6: cout << "Â½"; break;
                case 7: cout << "Æâ"; break;
                case 8: cout << "°Æ"; break;
                case 9: cout << "¾Á"; break;
                }
            }
            cout << "ÒÚ";
        }
        int millionSection = (integerPart / 1000) % 10000;
        if (millionSection != 0) {
            if (millionSection / 1000 != 0) {
                switch (millionSection / 1000) {
                case 1: cout << "Ò¼Çª"; break;
                case 2: cout << "·¡Çª"; break;
                case 3: cout << "ÈşÇª"; break;
                case 4: cout << "ËÁÇª"; break;
                case 5: cout << "ÎéÇª"; break;
                case 6: cout << "Â½Çª"; break;
                case 7: cout << "ÆâÇª"; break;
                case 8: cout << "°ÆÇª"; break;
                case 9: cout << "¾ÁÇª"; break;
                }
            }
            else if ((millionSection / 1000) == 0 && (millionSection / 100 != 0)) {
                cout << "Áã";
            }
            if ((millionSection / 100) % 10 != 0) {
                switch ((millionSection / 100) % 10) {
                case 1: cout << "Ò¼°Û"; break;
                case 2: cout << "·¡°Û"; break;
                case 3: cout << "Èş°Û"; break;
                case 4: cout << "ËÁ°Û"; break;
                case 5: cout << "Îé°Û"; break;
                case 6: cout << "Â½°Û"; break;
                case 7: cout << "Æâ°Û"; break;
                case 8: cout << "°Æ°Û"; break;
                case 9: cout << "¾Á°Û"; break;
                }
            }
            else if (millionSection / 100 == 0 || (millionSection / 10 != 0)) {
                cout << "Áã";
            }
            if ((millionSection / 10) % 10 != 0) {
                if ((millionSection / 10) % 10 == 1) {
                    cout << "Ò¼Ê°";
                }
                else {
                    switch ((millionSection / 10) % 10) {
                    case 2: cout << "·¡Ê°"; break;
                    case 3: cout << "ÈşÊ°"; break;
                    case 4: cout << "ËÁÊ°"; break;
                    case 5: cout << "ÎéÊ°"; break;
                    case 6: cout << "Â½Ê°"; break;
                    case 7: cout << "ÆâÊ°"; break;
                    case 8: cout << "°ÆÊ°"; break;
                    case 9: cout << "¾ÁÊ°"; break;
                    }
                }
            }
            if (millionSection % 10 != 0) {
                switch (millionSection % 10) {
                case 1: cout << "Ò¼"; break;
                case 2: cout << "·¡"; break;
                case 3: cout << "Èş"; break;
                case 4: cout << "ËÁ"; break;
                case 5: cout << "Îé"; break;
                case 6: cout << "Â½"; break;
                case 7: cout << "Æâ"; break;
                case 8: cout << "°Æ"; break;
                case 9: cout << "¾Á"; break;
                }
            }
            cout << "Íò";
        }
        int thousandSection = integerPart % 1000;
        if (thousandSection / 100 != 0) {
            switch (thousandSection / 100) {
            case 1: cout << "Ò¼Çª"; break;
            case 2: cout << "·¡Çª"; break;
            case 3: cout << "ÈşÇª"; break;
            case 4: cout << "ËÁÇª"; break;
            case 5: cout << "ÎéÇª"; break;
            case 6: cout << "Â½Çª"; break;
            case 7: cout << "ÆâÇª"; break;
            case 8: cout << "°ÆÇª"; break;
            case 9: cout << "¾ÁÇª"; break;
            }
        }
        else if ((thousandSection / 100) == 0 && (thousandSection / 10 != 0)) {
            cout << "Áã";
        }
        if ((thousandSection / 10) % 10 != 0) {
            switch ((thousandSection / 10) % 10) {
            case 1: cout << "Ò¼°Û"; break;
            case 2: cout << "·¡°Û"; break;
            case 3: cout << "Èş°Û"; break;
            case 4: cout << "ËÁ°Û"; break;
            case 5: cout << "Îé°Û"; break;
            case 6: cout << "Â½°Û"; break;
            case 7: cout << "Æâ°Û"; break;
            case 8: cout << "°Æ°Û"; break;
            case 9: cout << "¾Á°Û"; break;
            }
        }
        else if (thousandSection / 10 == 0 && (thousandSection % 10 == 0)) {
            cout << "Áã";
        }
        if (thousandSection % 10 != 0) {
            if (thousandSection % 10 == 1) {
                cout << "Ò¼Ê°";
            }
            else {
                switch (thousandSection % 10) {
                case 2: cout << "·¡Ê°"; break;
                case 3: cout << "ÈşÊ°"; break;
                case 4: cout << "ËÁÊ°"; break;
                case 5: cout << "ÎéÊ°"; break;
                case 6: cout << "Â½Ê°"; break;
                case 7: cout << "ÆâÊ°"; break;
                case 8: cout << "°ÆÊ°"; break;
                case 9: cout << "¾ÁÊ°"; break;
                }
            }
        }
        
        if (gewei != 0) {
            switch (gewei % 10) {
            case 1: cout << "Ò¼"; break;
            case 2: cout << "·¡"; break;
            case 3: cout << "Èş"; break;
            case 4: cout << "ËÁ"; break;
            case 5: cout << "Îé"; break;
            case 6: cout << "Â½"; break;
            case 7: cout << "Æâ"; break;
            case 8: cout << "°Æ"; break;
            case 9: cout << "¾Á"; break;
            }
        }
        cout << "Ôª";
    }

    // ´¦ÀíĞ¡Êı²¿·Ö
    if (decimalPart / 10 != 0) {
        switch (decimalPart / 10) {
        case 1: cout << "Ò¼"; break;
        case 2: cout << "·¡"; break;
        case 3: cout << "Èş"; break;
        case 4: cout << "ËÁ"; break;
        case 5: cout << "Îé"; break;
        case 6: cout << "Â½"; break;
        case 7: cout << "Æâ"; break;
        case 8: cout << "°Æ"; break;
        case 9: cout << "¾Á"; break;
        }
        cout << "½Ç";
    }
    if (decimalPart % 10 != 0) {
        if (decimalPart / 10 == 0) {
            cout << "Áã";
        }
        switch (decimalPart % 10) {
        case 1: cout << "Ò¼"; break;
        case 2: cout << "·¡"; break;
        case 3: cout << "Èş"; break;
        case 4: cout << "ËÁ"; break;
        case 5: cout << "Îé"; break;
        case 6: cout << "Â½"; break;
        case 7: cout << "Æâ"; break;
        case 8: cout << "°Æ"; break;
        case 9: cout << "¾Á"; break;
        }
        cout << "·Ö";
    }
    else if (decimalPart / 10 != 0) {
        cout << "Õû";
    }
    else {
        cout << "Õû";
    }

    return 0;
}