#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

int selectCurrency(int size);
double getAmount(string currency);
void showCurrencies(int size, const string currencyNames[]);

int main(){
    //En orden: USD, CAD, GBP, EUR, COP, JPY.
    //El precio debe estar en el mismo orden que la moneda
    const double currencies[] = {1, 1.40, 0.79, .95, 4479.00, 154.68};
    const string currencyNames[] = {"USD","CAD","GBP","EUR","COP","JPY"};
    int size = sizeof(currencyNames) / sizeof(currencyNames[0]);

    do{
        cout << "----------------------\n";
        cout << "Convertidor de Monedas\n"<< "Proyecto por: Anthony, Dakota, Lindsay, Lus y Jesus\n";
        cout << "----------------------\n";

        cout << "Seleccione la moneda que quiere convertir\n" << "**********************\n";

        showCurrencies(size, currencyNames);
        int current = selectCurrency(size);

        cout << currencyNames[current] << " Seleccionado\n"<< "Seleccione la moneda a la que quiere convertir\n";

        showCurrencies(size, currencyNames);
        int target = selectCurrency(size);
        cout << currencyNames[target] << " Seleccionado\n";

        if(current == target){
            cout << "Error. Ha seleccionado la misma moneda dos veces.\n";
        }else{
            cout << "**********************\n";

            cout << setprecision(2) << fixed <<
            getAmount(currencyNames[current]) * currencies[current] * currencies[target] << " " << currencyNames[target] << '\n';
        }

        cout << "\nPresione cualquier tecla para continuar\n";
        getch();


    }while(true);

    return 0;
}

int selectCurrency(int size){
    int currencySelect;
    
    do{
        cin >> currencySelect;

        // Comprobar que sea un numero y no una letra
        if(!cin){
            currencySelect = -1;
        }

        cout << "**********************\n";

        //Usar 0 para salir del programa
        if(currencySelect == 0){
            cout << "Gracias por usar el Convertidor de Monedas\n" << "Presione cualquier tecla para salir";
            getch();

            exit(0);
        }else if(currencySelect < 1 || currencySelect > size){
            // Error si el usuario pone un numero o letra
            cout << "Error. Seleccione un numero (1-" << size << ")\n";
        }

        fflush(stdin);
        cin.clear();
    }while(currencySelect < 0 || currencySelect > size);
    
    return currencySelect - 1;
}

void showCurrencies(int size, const string currencyNames[]){
    for(int i = 0; i < size; i++){
        cout << i + 1 << " para " << currencyNames[i] << '\n';
    }
    cout << "0 para salir\n";
}

double getAmount(string currency){
    double amount;
    
    cout << "Digite una cantidad en " << currency << ": ";
    cin >> amount;

    //la funcion se repite hasta que sea un numero y no una letra
    if(cin.fail()){
        cout << "Error. Digite una cantidad valida\n";
        amount = getAmount(currency);
    }
    
    return amount;
}
