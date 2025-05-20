#include "MySQLConexion.h"
#include "EloquentORM.h"
#include <iostream>
#include <string>

using namespace std;

// ================= ENTIDADES ====================

class Estudiante {
    MySQLConexion& conn;
    EloquentORM orm;
public:
    Estudiante(MySQLConexion& conexion)
        : conn(conexion), orm(conexion, "ESTUDIANTES", {"ID_ESTUDIANTE", "NOMBRE", "APELLIDO", "CORREO", "FECHA_NACIMIENTO"}) {}

    void crear() {
        string nombre, apellido, correo, fecha;
        int id_estudiante;
        cout << "ID Estudiante: "; cin >> id_estudiante;
        cout << "Nombre: "; cin >> nombre;
        cout << "Apellido: "; cin >> apellido;
        cout << "Correo: "; cin >> correo;
        cout << "Fecha de nacimiento (YYYY-MM-DD): "; cin >> fecha;

        orm.set("ID_ESTUDIANTE", to_string(id_estudiante));
        orm.set("NOMBRE", nombre);
        orm.set("APELLIDO", apellido);
        orm.set("CORREO", correo);
        orm.set("FECHA_NACIMIENTO", fecha);

        cout << (orm.create() ? "Estudiante creado.\n" : "Error al crear estudiante.\n");
    }

    void leer() {
        auto lista = orm.getAll();
        for (auto& reg : lista) {
            cout << "ID: " << reg["ID_ESTUDIANTE"] << ", Nombre: " << reg["NOMBRE"] 
                 << ", Apellido: " << reg["APELLIDO"] << ", Correo: " << reg["CORREO"]
                 << ", Fecha: " << reg["FECHA_NACIMIENTO"] << endl;
        }
    }

    void actualizar() {
        int id;
        cout << "ID del estudiante: "; cin >> id;
        string nombre, apellido, correo, fecha;
        cout << "Nuevo Nombre: "; cin >> nombre;
        cout << "Nuevo Apellido: "; cin >> apellido;
        cout << "Nuevo Correo: "; cin >> correo;
        cout << "Nueva Fecha (YYYY-MM-DD): "; cin >> fecha;

        orm.set("ID_ESTUDIANTE", to_string(id));
        orm.set("NOMBRE", nombre);
        orm.set("APELLIDO", apellido);
        orm.set("CORREO", correo);
        orm.set("FECHA_NACIMIENTO", fecha);

        cout << (orm.update() ? "Estudiante actualizado.\n" : "Error al actualizar estudiante.\n");
    }

    void eliminar() {
        int id;
        cout << "ID del estudiante: "; cin >> id;
        orm.set("ID_ESTUDIANTE", to_string(id));
        orm.find(id);
        cout << (orm.remove() ? "Estudiante eliminado.\n" : "Error al eliminar estudiante.\n");
    }
};  

class Docente {
    MySQLConexion& conn;
    EloquentORM orm;
public:
    Docente(MySQLConexion& conexion)
        : conn(conexion), orm(conexion, "DOCENTES", {"ID_DOCENTE", "NOMBRE", "ESPECIALIDAD"}) {}

    void crear() {
        int id_docente;
        string nombre, especialidad;
        cout << "ID Docente: "; cin >> id_docente;
        cout << "Nombre: "; cin >> nombre;
        cout << "Especialidad: "; cin >> especialidad;

        orm.set("ID_DOCENTE", to_string(id_docente));
        orm.set("NOMBRE", nombre);
        orm.set("ESPECIALIDAD", especialidad);

        cout << (orm.create() ? "Docente creado.\n" : "Error al crear docente.\n");
    }

    void leer() {
        auto lista = orm.getAll();
        for (auto& reg : lista) {
            cout << "ID: " << reg["ID_DOCENTE"] << ", Nombre: " << reg["NOMBRE"] 
                 << ", Especialidad: " << reg["ESPECIALIDAD"] << endl;
        }
    }

    void actualizar() {
        int id;
        cout << "ID del docente: "; cin >> id;
        string nombre, especialidad;
        cout << "Nuevo Nombre: "; cin >> nombre;
        cout << "Nueva Especialidad: "; cin >> especialidad;

        orm.set("ID_DOCENTE", to_string(id));
        orm.set("NOMBRE", nombre);
        orm.set("ESPECIALIDAD", especialidad);

        cout << (orm.update() ? "Docente actualizado.\n" : "Error al actualizar docente.\n");
    }

    void eliminar() {
        int id;
        cout << "ID del docente: "; cin >> id;
        orm.set("ID_DOCENTE", to_string(id));
        cout << (orm.remove() ? "Docente eliminado.\n" : "Error al eliminar docente.\n");
    }
};

class Curso {
    MySQLConexion& conn;
    EloquentORM orm;
public:
    Curso(MySQLConexion& conexion)
        : conn(conexion), orm(conexion, "CURSOS", {"ID_CURSO", "NOMBRE", "CREDITOS", "ID_DOCENTE"}) {}

    void crear() {
        string nombre;
        int creditos, id_docente, id_curso;
        cout << "ID Curso: "; cin >> id_curso;
        cout << "Nombre del curso: "; cin >> nombre;
        cout << "Créditos: "; cin >> creditos;
        cout << "ID del docente: "; cin >> id_docente;

        orm.set("ID_CURSO", to_string(id_curso));
        orm.set("NOMBRE", nombre);
        orm.set("CREDITOS", to_string(creditos));
        orm.set("ID_DOCENTE", to_string(id_docente));

        cout << (orm.create() ? "Curso creado.\n" : "Error al crear curso.\n");
    }

    void leer() {
        auto lista = orm.getAll();
        for (auto& reg : lista) {
            cout << "ID: " << reg["ID_CURSO"] << ", Nombre: " << reg["NOMBRE"]
                 << ", Créditos: " << reg["CREDITOS"]
                 << ", ID Docente: " << reg["ID_DOCENTE"] << endl;
        }
    }

    void actualizar() {
        int id;
        cout << "ID del curso: "; cin >> id;
        string nombre;
        int creditos, id_docente;
        cout << "Nuevo Nombre: "; cin >> nombre;
        cout << "Créditos: "; cin >> creditos;
        cout << "ID Docente: "; cin >> id_docente;

        orm.set("ID_CURSO", to_string(id));
        orm.set("NOMBRE", nombre);
        orm.set("CREDITOS", to_string(creditos));
        orm.set("ID_DOCENTE", to_string(id_docente));

        cout << (orm.update() ? "Curso actualizado.\n" : "Error al actualizar curso.\n");
    }

    void eliminar() {
        int id;
        cout << "ID del curso: "; cin >> id;
        orm.set("ID_CURSO", to_string(id));
        cout << (orm.remove() ? "Curso eliminado.\n" : "Error al eliminar curso.\n");
    }
};

class Nota {
    MySQLConexion& conn;
    EloquentORM orm;
public:
    Nota(MySQLConexion& conexion)
        : conn(conexion), orm(conexion, "NOTAS", {"ID_NOTA", "ID_ESTUDIANTE", "ID_CURSO", "CALIFICACION"}) {}

    void crear() {
        int id_estudiante, id_curso, id_nota;
        double calificacion;
        cout << "ID Nota: "; cin >> id_nota;
        cout << "ID Estudiante: "; cin >> id_estudiante;
        cout << "ID Curso: "; cin >> id_curso;
        cout << "Calificación: "; cin >> calificacion;

        orm.set("ID_NOTA", to_string(id_nota));
        orm.set("ID_ESTUDIANTE", to_string(id_estudiante));
        orm.set("ID_CURSO", to_string(id_curso));
        orm.set("CALIFICACION", to_string(calificacion));

        cout << (orm.create() ? "Nota registrada.\n" : "Error al registrar nota.\n");
    }

    void leer() {
        auto lista = orm.getAll();
        for (auto& reg : lista) {
            cout << "ID: " << reg["ID_NOTA"] << ", Estudiante: " << reg["ID_ESTUDIANTE"]
                 << ", Curso: " << reg["ID_CURSO"]
                 << ", Calificación: " << reg["CALIFICACION"] << endl;
        }
    }

    void actualizar() {
        int id;
        cout << "ID de la nota: "; cin >> id;
        int id_estudiante, id_curso;
        double calificacion;
        cout << "Nuevo ID Estudiante: "; cin >> id_estudiante;
        cout << "Nuevo ID Curso: "; cin >> id_curso;
        cout << "Nueva Calificación: "; cin >> calificacion;

        orm.set("ID_NOTA", to_string(id));
        orm.set("ID_ESTUDIANTE", to_string(id_estudiante));
        orm.set("ID_CURSO", to_string(id_curso));
        orm.set("CALIFICACION", to_string(calificacion));

        cout << (orm.update() ? "Nota actualizada.\n" : "Error al actualizar nota.\n");
    }

    void eliminar() {
        int id;
        cout << "ID de la nota: "; cin >> id;
        orm.set("ID_NOTA", to_string(id));
        cout << (orm.remove() ? "Nota eliminada.\n" : "Error al eliminar nota.\n");
    }
};

// ================= MENU PRINCIPAL ====================

void mostrarMenuEntidad(const string& nombreEntidad) {
    cout << "\n--- " << nombreEntidad << " ---\n";
    cout << "1. Crear\n";
    cout << "2. Leer\n";
    cout << "3. Actualizar\n";
    cout << "4. Eliminar\n";
    cout << "5. Volver al menú principal\n";
}

int main() {
    MySQLConexion conn("root", "2020", "sistema_de_estudiantes");

    if (!conn.open()) {
        cerr << "No se pudo conectar a la base de datos." << endl;
        return 1;
    }

    Estudiante estudiante(conn);
    Docente docente(conn);
    Curso curso(conn);
    Nota nota(conn);

    int opcionEntidad = 0, opcionAccion = 0;

    do {
        cout << "\n==== MENÚ PRINCIPAL ====\n";
        cout << "1. Estudiantes\n";
        cout << "2. Docentes\n";
        cout << "3. Cursos\n";
        cout << "4. Notas\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcionEntidad;

        if (opcionEntidad == 5) break;

        mostrarMenuEntidad(
            opcionEntidad == 1 ? "Estudiantes" :
            opcionEntidad == 2 ? "Docentes" :
            opcionEntidad == 3 ? "Cursos" : "Notas"
        );

        cin >> opcionAccion;

        switch (opcionEntidad) {
            case 1:
                if (opcionAccion == 1) estudiante.crear();
                else if (opcionAccion == 2) estudiante.leer();
                else if (opcionAccion == 3) estudiante.actualizar();
                else if (opcionAccion == 4) estudiante.eliminar();
                break;
            case 2:
                if (opcionAccion == 1) docente.crear();
                else if (opcionAccion == 2) docente.leer();
                else if (opcionAccion == 3) docente.actualizar();
                else if (opcionAccion == 4) docente.eliminar();
                break;
            case 3:
                if (opcionAccion == 1) curso.crear();
                else if (opcionAccion == 2) curso.leer();
                else if (opcionAccion == 3) curso.actualizar();
                else if (opcionAccion == 4) curso.eliminar();
                break;
            case 4:
                if (opcionAccion == 1) nota.crear();
                else if (opcionAccion == 2) nota.leer();
                else if (opcionAccion == 3) nota.actualizar();
                else if (opcionAccion == 4) nota.eliminar();
                break;
        }

    } while (true);

    conn.close();
    cout << "Conexión cerrada. Saliendo del sistema...\n";
    return 0;
}
