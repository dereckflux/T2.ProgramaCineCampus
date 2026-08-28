#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cmath>

using namespace std;

int main() {

    // Variables de entrada
    int opcion = 0, formato = 0, cantidad = 0;
    string nombre = "", respuesta = "";
    bool estudiante = false, matinee = false, compraEnLinea = false;
    double dinero = 0;

    // Variables de salida
    string nombreFormato = "", promocion = "";
    string advertenciaGeneral =
        "ADVERTENCIA GENERAL: si ingresa un dato incorrecto, debera repetirlo.";

    // Variables de proceso
    double precio = 0, subtotal = 0, porcentaje = 0;
    double descuento = 0, recargo = 0, total = 0, cambio = 0;

    // Variables de validacion
    bool datoValido;

    do {

        cout << "\n=== CINE UNIVERSITARIO ===" << endl;
        cout << "1. Comprar entradas" << endl;
        cout << "2. Consultar precios" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opcion (1-3): ";

        cin >> opcion;

        if (cin.fail() || opcion < 1 || opcion > 3) {
            cout << "Ingrese una opcion valida entre 1 y 3." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            datoValido = false;
        } else {
            datoValido = true;
        }

    } while (!datoValido);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (opcion != 3) {

        switch (opcion) {

            case 2:

                cout << "\n=== CONSULTAR PRECIOS ===" << endl;
                cout << "Lista de formatos disponibles:" << endl;
                cout << "1. Formato 2D - $4.00" << endl;
                cout << "2. Formato 3D - $6.00" << endl;
                cout << "3. Formato IMAX - $8.00" << endl;
                cout << "Promociones: estudiante 20%, grupo de 5 o mas 15%, matinee 10%." << endl;
                cout << "Se aplica solo la primera promocion disponible, en ese orden." << endl;
                cout << "La compra en linea agrega un recargo del 5%." << endl;

                break;

            case 1:

                cout << "\n=== COMPRA DE ENTRADAS ===" << endl;
                cout << advertenciaGeneral << endl;

                do {

                    cout << "Ingrese su nombre: ";
                    getline(cin, nombre);

                    if (nombre.empty()) {
                        cout << "El nombre no puede estar vacio." << endl;
                    }

                } while (nombre.empty());

                do {

                    cout << "\nLista de formatos disponibles:" << endl;
                    cout << "1. Formato 2D - $4.00" << endl;
                    cout << "2. Formato 3D - $6.00" << endl;
                    cout << "3. Formato IMAX - $8.00" << endl;
                    cout << "Seleccione un formato (1-3): ";

                    cin >> formato;

                    if (cin.fail() || formato < 1 || formato > 3) {
                        cout << "Ingrese un formato valido entre 1 y 3." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        datoValido = false;
                    } else {
                        datoValido = true;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                } while (!datoValido);

                do {

                    cout << "Cantidad de entradas (1-100): ";
                    cin >> cantidad;

                    if (cin.fail() || cantidad < 1 || cantidad > 100) {
                        cout << "La cantidad debe estar entre 1 y 100." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        datoValido = false;
                    } else {
                        datoValido = true;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                } while (!datoValido);

                do {

                    cout << "Es estudiante universitario? (s/n): ";
                    cin >> respuesta;

                    if (respuesta == "s" || respuesta == "n" ||
                        respuesta == "si" || respuesta == "no") {

                        datoValido = true;

                    } else {

                        cout << "Responda solamente s o n." << endl;
                        datoValido = false;
                    }

                } while (!datoValido);

                estudiante = respuesta == "s" || respuesta == "si";

                do {

                    cout << "La funcion es matinee? (s/n): ";
                    cin >> respuesta;

                    if (respuesta == "s" || respuesta == "n" ||
                        respuesta == "si" || respuesta == "no") {

                        datoValido = true;

                    } else {

                        cout << "Responda solamente s o n." << endl;
                        datoValido = false;
                    }

                } while (!datoValido);

                matinee = respuesta == "s" || respuesta == "si";

                do {

                    cout << "Compra en linea? (s/n): ";
                    cin >> respuesta;

                    if (respuesta == "s" || respuesta == "n" ||
                        respuesta == "si" || respuesta == "no") {

                        datoValido = true;

                    } else {

                        cout << "Responda solamente s o n." << endl;
                        datoValido = false;
                    }

                } while (!datoValido);

                compraEnLinea = respuesta == "s" || respuesta == "si";

                switch (formato) {

                    case 1:
                        precio = 4.00;
                        nombreFormato = "2D";
                        break;

                    case 2:
                        precio = 6.00;
                        nombreFormato = "3D";
                        break;

                    default:
                        precio = 8.00;
                        nombreFormato = "IMAX";
                }

                subtotal = precio * cantidad;

                if (estudiante) {

                    promocion = "Estudiante (20%)";
                    porcentaje = 0.20;

                } else if (cantidad >= 5) {

                    promocion = "Grupo (15%)";
                    porcentaje = 0.15;

                } else if (matinee) {

                    promocion = "Matinee (10%)";
                    porcentaje = 0.10;

                } else {

                    promocion = "Sin promocion";
                    porcentaje = 0.00;
                }

                descuento = subtotal * porcentaje;

                if (compraEnLinea) {
                    recargo = (subtotal - descuento) * 0.05;
                } else {
                    recargo = 0.00;
                }

                total = subtotal - descuento + recargo;

                do {

                    cout << fixed << setprecision(2);
                    cout << "Total a pagar: $" << total << endl;
                    cout << "Dinero entregado: $";
                    cin >> dinero;

                    if (cin.fail() || dinero < total) {

                        if (!cin.fail() && dinero >= 0 && dinero < total) {

                            cout << "El dinero no cubre el total. Falta: $"
                                 << total - dinero << endl;

                        } else {

                            cout << "Ingrese un monto valido." << endl;
                        }

                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        datoValido = false;

                    } else {

                        datoValido = true;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                } while (!datoValido);

                cambio = dinero - total;

                cout << "\n=== RESUMEN DE COMPRA ===" << endl;
                cout << "Cliente: " << nombre << endl;
                cout << "Formato: " << nombreFormato << endl;
                cout << "Cantidad: " << cantidad << endl;
                cout << fixed << setprecision(2);
                cout << "Precio unitario: $" << precio << endl;
                cout << "Subtotal: $" << subtotal << endl;
                cout << "Promocion aplicada: " << promocion << endl;
                cout << "Descuento: $" << descuento << endl;
                cout << "Recargo: $" << recargo << endl;
                cout << "Total a pagar: $" << total << endl;
                cout << "Cambio: $" << cambio << endl;

                break;

            default:
                break;
        }

        do {

            cout << "\n1. Comprar entradas" << endl;
            cout << "2. Consultar precios" << endl;
            cout << "3. Salir" << endl;
            cout << "Seleccione una opcion (1-3): ";

            cin >> opcion;

            if (cin.fail() || opcion < 1 || opcion > 3) {

                cout << "Ingrese una opcion valida entre 1 y 3." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                datoValido = false;

            } else {

                datoValido = true;
            }

        } while (!datoValido);

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Gracias por visitar el Cine Universitario." << endl;

    return 0;
}
