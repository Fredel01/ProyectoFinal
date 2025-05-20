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
    cout << "5. Salir" << endl;
}

void crear(MySQLConexion& conn) {
    int opcion;
    string nombre, apellido, correo, fecha, especialidad, descripcion, tipo;
    int creditos, id_docente, id_estudiante, id_curso;
    float nota;

    cout << "------ Crear ------" << endl;
    cout << "1. Estudiante" << endl;
    cout << "2. Docente" << endl;
    cout << "3. Curso" << endl;
    cout << "4. Nota" << endl;
    cout << "5. Salir" << endl;
    cin >> opcion;

    switch (opcion) {
        case 1: {
            EloquentORM estudiantes(conn, "ESTUDIANTES", { "NOMBRE", "APELLIDO", "CORREO", "FECHA_NACIMIENTO" });
            cout << "Nombre: "; cin >> nombre;
            cout << "Apellido: "; cin >> apellido;
            cout << "Correo: "; cin >> correo;
            cout << "Fecha de nacimiento (YYYY-MM-DD): "; cin >> fecha;
            estudiantes.set("NOMBRE", nombre);
            estudiantes.set("APELLIDO", apellido);
            estudiantes.set("CORREO", correo);
            estudiantes.set("FECHA_NACIMIENTO", fecha);
            cout << (estudiantes.create() ? "Estudiante creado.\n" : "Error al crear.\n");
            break;
        }
        case 2: {
            EloquentORM docentes(conn, "DOCENTES", { "NOMBRE", "APELLIDO", "ESPECIALIDAD" });
            cout << "Nombre: "; cin >> nombre;
            cout << "Apellido: "; cin >> apellido;
            cout << "Especialidad: "; cin >> especialidad;
            docentes.set("NOMBRE", nombre);
            docentes.set("APELLIDO", apellido);
            docentes.set("ESPECIALIDAD", especialidad);
            cout << (docentes.create() ? "Docente creado.\n" : "Error al crear.\n");
            break;
        }
        case 3: {
            EloquentORM cursos(conn, "CURSOS", { "NOMBRE_CURSO", "DESCRIPCION", "CREDITOS", "ID_DOCENTE" });
            cout << "Nombre del curso: "; cin >> nombre;
            cout << "Descripción: "; cin >> descripcion;
            cout << "Créditos: "; cin >> creditos;
            cout << "ID del docente: "; cin >> id_docente;
            cursos.set("NOMBRE_CURSO", nombre);
            cursos.set("DESCRIPCION", descripcion);
            cursos.set("CREDITOS", to_string(creditos));
            cursos.set("ID_DOCENTE", to_string(id_docente));
            cout << (cursos.create() ? "Curso creado.\n" : "Error al crear.\n");
            break;
        }
        case 4: {
            EloquentORM notas(conn, "NOTAS", { "ID_ESTUDIANTE", "ID_CURSO", "TIPO", "NOTA", "FECHA_REGISTRO" });
            cout << "ID Estudiante: "; cin >> id_estudiante;
            cout << "ID Curso: "; cin >> id_curso;
            cout << "Tipo (PRESENCIAL/ONLINE): "; cin >> tipo;
            cout << "Nota: "; cin >> nota;
            cout << "Fecha (YYYY-MM-DD): "; cin >> fecha;
            notas.set("ID_ESTUDIANTE", to_string(id_estudiante));
            notas.set("ID_CURSO", to_string(id_curso));
            notas.set("TIPO", tipo);
            notas.set("NOTA", to_string(nota));
            notas.set("FECHA_REGISTRO", fecha);
            cout << (notas.create() ? "Nota registrada.\n" : "Error al registrar.\n");
            break;
        }
        case 5:
            return;
        default:
            cout << "Opción no válida.\n";
    }
}

void leer(MySQLConexion& conn) {
    int opcion;
    cout << "------ Leer ------" << endl;
    cout << "1. Estudiantes" << endl;
    cout << "2. Docentes" << endl;
    cout << "3. Cursos" << endl;
    cout << "4. Notas" << endl;
    cout << "5. Salir" << endl;
    cin >> opcion;

    switch (opcion) {
        case 1: {
            EloquentORM estudiantes(conn, "ESTUDIANTES", { "ID_ESTUDIANTE", "NOMBRE", "APELLIDO", "CORREO", "FECHA_NACIMIENTO" });
            auto lista = estudiantes.getAll();
            for (auto& reg : lista) {
                cout << "ID: " << reg["ID_ESTUDIANTE"]
                     << ", Nombre: " << reg["NOMBRE"]
                     << ", Apellido: " << reg["APELLIDO"]
                     << ", Correo: " << reg["CORREO"]
                     << ", Fecha Nac.: " << reg["FECHA_NACIMIENTO"] << endl;
            }
            break;
        }
        case 2: {
            EloquentORM docentes(conn, "DOCENTES", { "ID_DOCENTE", "NOMBRE", "APELLIDO", "ESPECIALIDAD" });
            auto lista = docentes.getAll();
            for (auto& reg : lista) {
                cout << "ID: " << reg["ID_DOCENTE"]
                     << ", Nombre: " << reg["NOMBRE"]
                     << ", Apellido: " << reg["APELLIDO"]
                     << ", Especialidad: " << reg["ESPECIALIDAD"] << endl;
            }
            break;
        }
        case 3: {
            EloquentORM cursos(conn, "CURSOS", { "ID_CURSO", "NOMBRE_CURSO", "DESCRIPCION", "CREDITOS", "ID_DOCENTE" });
            auto lista = cursos.getAll();
            for (auto& reg : lista) {
                cout << "ID: " << reg["ID_CURSO"]
                     << ", Curso: " << reg["NOMBRE_CURSO"]
                     << ", Descripción: " << reg["DESCRIPCION"]
                     << ", Créditos: " << reg["CREDITOS"]
                     << ", ID Docente: " << reg["ID_DOCENTE"] << endl;
            }
            break;
        }
        case 4: {
            EloquentORM notas(conn, "NOTAS", { "ID_NOTA", "ID_ESTUDIANTE", "ID_CURSO", "TIPO", "NOTA", "FECHA_REGISTRO" });
            auto lista = notas.getAll();
            for (auto& reg : lista) {
                cout << "ID Nota: " << reg["ID_NOTA"]
                     << ", ID Estudiante: " << reg["ID_ESTUDIANTE"]
                     << ", ID Curso: " << reg["ID_CURSO"]
                     << ", Tipo: " << reg["TIPO"]
                     << ", Nota: " << reg["NOTA"]
                     << ", Fecha: " << reg["FECHA_REGISTRO"] << endl;
            }
            break;
        }
        case 5:
            return;
        default:
            cout << "Opción no válida.\n";
    }
}

void actualizar(MySQLConexion& conn) {
    int opcion;
    cout << "------ Actualizar ------\n";
    cout << "1. Estudiante" << endl;
    cout << "2. Docente" << endl;
    cout << "3. Curso" << endl;
    cout << "4. Nota" << endl;
    cout << "5. Salir" << endl;
    cin >> opcion;

    switch (opcion) {
        case 1: {
            int id;
            string nombre, apellido, correo, fecha;
            cout << "ID del estudiante a actualizar: "; cin >> id;
            cout << "Nuevo Nombre: "; cin >> nombre;
            cout << "Nuevo Apellido: "; cin >> apellido;
            cout << "Nuevo Correo: "; cin >> correo;
            cout << "Nueva Fecha de nacimiento (YYYY-MM-DD): "; cin >> fecha;

            EloquentORM estudiantes(conn, "ESTUDIANTES", { "NOMBRE", "APELLIDO", "CORREO", "FECHA_NACIMIENTO" });
            estudiantes.set("ID_ESTUDIANTE", to_string(id));
            estudiantes.set("NOMBRE", nombre);
            estudiantes.set("APELLIDO", apellido);
            estudiantes.set("CORREO", correo);
            estudiantes.set("FECHA_NACIMIENTO", fecha);
            cout << (estudiantes.update() ? "Estudiante actualizado.\n" : "Error al actualizar.\n");
            break;
        }
        case 2: {
            int id;
            string nombre, apellido, especialidad;
            cout << "ID del docente a actualizar: "; cin >> id;
            cout << "Nuevo Nombre: "; cin >> nombre;
            cout << "Nuevo Apellido: "; cin >> apellido;
            cout << "Nueva Especialidad: "; cin >> especialidad;
            EloquentORM docentes(conn, "DOCENTES", { "NOMBRE", "APELLIDO", "ESPECIALIDAD" });
            docentes.set("ID_DOCENTE", to_string(id));
            docentes.set("NOMBRE", nombre);
            docentes.set("APELLIDO", apellido);
            docentes.set("ESPECIALIDAD", especialidad);
            cout << (docentes.update() ? "Docente actualizado.\n" : "Error al actualizar.\n");
            break;
        }
        case 3: {
            int id, creditos, id_docente;
            string nombre, descripcion;
            cout << "ID del curso a actualizar: "; cin >> id;
            cout << "Nuevo Nombre del curso: "; cin >> nombre;
            cout << "Nueva Descripción: "; cin >> descripcion;
            cout << "Nuevos Créditos: "; cin >> creditos;
            cout << "Nuevo ID del docente: "; cin >> id_docente;
            EloquentORM cursos(conn, "CURSOS", { "NOMBRE_CURSO", "DESCRIPCION", "CREDITOS", "ID_DOCENTE" });
            cursos.set("ID_CURSO", to_string(id));
            cursos.set("NOMBRE_CURSO", nombre);
            break;
        }
        case 4: {
            int id_estudiante, id_curso;
            string tipo;
            float nota;
            cout << "ID de la nota a actualizar: "; cin >> id_estudiante;
            cout << "Nuevo ID del estudiante: "; cin >> id_estudiante;
            cout << "Nuevo ID del curso: "; cin >> id_curso;
            cout << "Nuevo Tipo (PRESENCIAL/ONLINE): "; cin >> tipo;
            cout << "Nueva Nota: "; cin >> nota;
            cout << "Nueva Fecha (YYYY-MM-DD): "; cin >> fecha;
            EloquentORM notas(conn, "NOTAS", { "ID_ESTUDIANTE", "ID_CURSO", "TIPO", "NOTA", "FECHA_REGISTRO" });
            notas.set("ID_NOTA", to_string(id_estudiante));
            notas.set("ID_ESTUDIANTE", to_string(id_estudiante));
            break;
        }
        case 5:
            return;
        default:
            cout << "Opción no válida.\n";
    }
    {
    case constant expression:
        /* code */
        break;
    
    default:
        break;
    }
}

void eliminar(MySQLConexion& conn) {
    int opcion;
    cout << "------ Eliminar ------\n";
    cout << "1. Estudiante" << endl;
    cout << "2. Docente" << endl;
    cout << "3. Curso" << endl;
    cout << "4. Nota" << endl;
    cout << "5. Salir" << endl;
    cin >> opcion;

    switch (opcion) {
        case 1: {
            int id;
            cout << "ID del estudiante a eliminar: "; cin >> id;
            EloquentORM estudiantes(conn, "ESTUDIANTES", { "ID_ESTUDIANTE" });
            estudiantes.set("ID_ESTUDIANTE", to_string(id));
            cout << (estudiantes.remove() ? "Estudiante eliminado.\n" : "Error al eliminar.\n");
            break;
        }
        case 2: {
            int id;
            cout << "ID del docente a eliminar: "; cin >> id;
            EloquentORM docentes(conn, "DOCENTES", { "ID_DOCENTE" });
            docentes.set("ID_DOCENTE", to_string(id));
            cout << (docentes.remove() ? "Docente eliminado.\n" : "Error al eliminar.\n");
            break;
        }
        case 3: {
            int id;
            cout << "ID del curso a eliminar: "; cin >> id;
            EloquentORM cursos(conn, "CURSOS", { "ID_CURSO" });
            cursos.set("ID_CURSO", to_string(id));
            cout << (cursos.remove() ? "Curso eliminado.\n" : "Error al eliminar.\n");
            break;
        }
        case 4: {
            int id_estudiante, id_curso;
            cout << "ID de la nota a eliminar: "; cin >> id_estudiante;
            EloquentORM notas(conn, "NOTAS", { "ID_NOTA" });
            notas.set("ID_NOTA", to_string(id_estudiante));
            cout << (notas.remove() ? "Nota eliminada.\n" : "Error al eliminar.\n");
            break;
        }
        case 5:
            return;
        default:
            cout << "Opción no válida.\n";
    }
}

int main() {
    MySQLConexion conn("root", "2020", "sistema_de_estudiantes");

    if (!conn.open()) {
        cerr << "No se pudo conectar a la base de datos." << endl;
        return 1;
    }

    int opcion;
    do {
        menu();
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: crear(conn); break;
            case 2: leer(conn); break;
            case 3: actualizar(conn); break;
            case 4: eliminar(conn); break;
            case 5: cout << "Saliendo del sistema...\n"; break;
            default: cout << "Opción no válida.\n";
        }

    } while (opcion != 5);

    return 0;
}