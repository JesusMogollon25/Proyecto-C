#include <iostream>
#include <iomanip>

using namespace std;

int selectCurrency();
double getAmount(string currency);

int main(){
    const double currencies[] = {
        1, //1 because its the standard. USD
        1.40, //cad
        0.79, //gbp
        .95, //eur
        4479.00, //cop
        154.68 //jpy
    };

    const string currencyNames[] = {
        "USD",
        "CAD",
        "GBP",
        "EUR",
        "COP",
        "JPY"
    };

    cout << "Convertidor de divisas\n";

    cout << "Seleccione la moneda que quiere cambiar\n";
    int current = selectCurrency() - 1;
    cout << currencyNames[current] << " Seleccionado\n";

    cout << "Seleccione la moneda a la que quiere convertir\n";
    int target = selectCurrency() - 1;
    cout << currencyNames[target] << " Seleccionado\n";

    cout << setprecision(2) << fixed << getAmount(currencyNames[current]) * currencies[current] * currencies[target] << " " << currencyNames[target];
    return 0;
}

int selectCurrency(){
    cout << "1 para USD\n";
    cout << "2 para CAD\n";
    cout << "3 para EUR\n";
    cout << "4 para GBP\n";
    cout << "5 para COP\n";
    cout << "6 para JPY\n";

    int currencySelect;
    cin >> currencySelect;
    cout << "*********\n";
    return currencySelect;
}

double getAmount(string currency){
    double amount;

    cout << "Digite una cantidad en: " << currency << ": ";
    cin >> amount;

    return amount;
}
