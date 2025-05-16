#include "MySQLConexion.h"
#include "EloquentORM.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void menu() {
    cout << "------------------Sistema de Estudiantes-------------------" << endl;
    cout << "1. Crear" << endl;
    cout << "2. Leer" << endl; 
    cout << "3. Actualizar" << endl;
    cout << "4. Eliminar" << endl; 
}
void crear() {
    int opcion; 
    string ID_ESTUDIANTE, NOMBRE, APELLIDO, CORREO, FECHA_NACIMIENTO;
    cout << "1. Estudiante" << endl;
    cout << "2. Docente" << endl;   
    cout << "3. Curso" << endl;
    cout << "4. Notas" << endl;
    cout << "5. Salir" << endl;
    cin >> opcion;
    switch (opcion) {
        case 1:
            EloquentORM ESTUDIANTES(conn, "ESTUDIANTES", {"ID_ESTUDIANTE", "NOMBRE", "APELLIDO", "CORREO", "FECHA_NACIMIENTO"});
            cout << "Ingrese el ID del estudiante: ";
            cin >> ID_ESTUDIANTE;
            cout << "Ingrese el nombre del estudiante: ";
            cin >> NOMBRE;  
            cout << "Ingrese el apellido del estudiante: ";
            cin >> APELLIDO;        
            cout << "Ingrese el correo del estudiante: ";
            cin >> CORREO;
            cout << "Ingrese la fecha de nacimiento del estudiante (YYYY-MM-DD): ";
            cin >> FECHA_NACIMIENTO;
            ESTUDIANTES.set("NOMBRE", NOMBRE);
            ESTUDIANTES.set("APELLIDO", APELLIDO);
            ESTUDIANTES.set("CORREO", CORREO);
            ESTUDIANTES.set("FECHA_NACIMIENTO", FECHA_NACIMIENTO);
            if (ESTUDIANTES.create()) {
                cout << "Estudiante creado exitosamente." << endl;
            } else {
                cout << "Error al crear el estudiante." << endl;
            }
            break;
        case 2:
            cout << "Crear Docente" << endl;
            break;
        case 3:
            cout << "Crear Curso" << endl;
            break;
        case 4:
            cout << "Crear Notas" << endl;
            break;
        case 5:
            cout << "Salir" << endl;
            break;
        default:
            cout << "Opción no válida." << endl;
    }
}

int main() {
    // Crear la conexión a la base de datos
    MySQLConexion conn("root", "2020", "sistema_de_estudiantes");

    // Verificar si la conexión fue exitosa
    if (!conn.open()) {
        cerr << "No se pudo conectar a la base de datos." << endl;
        return 1;
    }

    int opcion;
    menu();
    cout << "Seleccione una opción: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            crear();
            break;
        case 2:
            cout << "Leer" << endl;
            break;
        case 3:
            cout << "Actualizar" << endl;
            break;
        case 4:
            cout << "Eliminar" << endl;
            break;
        default:
            cout << "Opción no válida." << endl;
    }


    // Crear la conexión a la base de datos
    MySQLConexion conn("root", "2020", "sistema_de_estudiantes");

    // Verificar si la conexión fue exitosa
    if (!conn.open()) {
        cerr << "No se pudo conectar a la base de datos." << endl;
        return 1;
    }

    // Definir las columnas que se quieren obtener de la tabla 'estudiantes'
    vector<string> columnas = { "NOMBRE", "APELLIDO", "CORREO","FECHA_NACIMIENTO"};

    // Crear una instancia del ORM para la tabla 'personas'
    EloquentORM ESTUDIANTES(conn, "ESTUDIANTES", columnas);

    // Obtener todos los registros
    auto lista = ESTUDIANTES.getAll();

    // Mostrar los registros en consola
    for (auto& reg : lista) {
        cout << "ID: " << reg["ID_ESTUDIANTE"]
             << ", NOMBRE: " << reg["NOMBRE"]
             << ", APELLIDO: " << reg["APELLIDO"]
             << ", CORREO: " << reg["CORREO"] 
             << ", FECHA_NACIMIENTO: " << reg["FECHA_NACIMIENTO"]
             << endl;
    }

    return 0;
}
