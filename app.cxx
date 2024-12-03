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

        // Error si selecciona la misma moneda como moneda para convertir
        // y como moneda objetivo
        if(current == target){
            cout << "Error. Ha seleccionado la misma moneda dos veces.\n";
        }else{
            cout << "**********************\n";

            cout << setprecision(2) << fixed <<
            getAmount(currencyNames[current]) * (currencies[current] * currencies[target]) << " " << currencyNames[target] << '\n';
        }   // Este codigo multiplica la cantidad por la moneda que el usuario eligio.
            // Estamos multiplicando una moneda por la otra, asi que el numero es especulativo.
            // No cambiar esto

        cout << "\nPresione cualquier tecla para continuar\n";
        getch();


    }while(true);

    return 0;
}

// Esta funcion es para seleccionar una moneda
int selectCurrency(int size){
    int currencySelect;
    
    // El programa va a seguir funcionando siempre que el usuario
    // no escriba un numero mayor que la cantidad de monedas que hay
    // o 0, para salir del programa
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
            // Error si el usuario selecciona un numero menor que 0
            // o mayor que la cantidad de monedas
            cout << "Error. Seleccione un numero (1-" << size << ")\n";
        }

        fflush(stdin);
        cin.clear();
    }while(currencySelect < 0 || currencySelect > size);
    
    // Restar 1 para que no haya un error con el array
    return currencySelect - 1;
}

// Mostrar una lista de las monedas que el usuario puede seleccionar
void showCurrencies(int size, const string currencyNames[]){
    // i + 1 es el numero que el usuario debe presionar para seleccionar
    // la moneda. Currency names es el nombre de la moneda que puede
    // seleccionar.
    // Deberia salir en caso de 1 "1 para USD"
    for(int i = 0; i < size; i++){
        cout << i + 1 << " para " << currencyNames[i] << '\n';
    }

    cout << "0 para salir\n";
}

// Funcion para obtener la cantidad que el usuario quiere convertir
double getAmount(string currency){
    double amount;
    
    cout << "Digite una cantidad en " << currency << ": ";
    cin >> amount;

    //la funcion se repite hasta que sea un numero y no una letra
    if(cin.fail()){
        fflush(stdin);
        cin.clear();

        cout << "Error. Digite una cantidad valida\n";
        amount = getAmount(currency);
    }
    
    // Devuelve la cantidad si el usuario no pone una letra.
    return amount;
}
