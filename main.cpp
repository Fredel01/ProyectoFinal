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
        EloquentORM alumno(conn, "estudiantes", {"id", "NOMBRE", "APELLIDO", "CORREO", "FECHA_NACIMIENTO"});
        int idEstudiante;
        string nombre, apellido, correo, fecha;
        cout << "ID Estudiante: "; cin >> idEstudiante;
        cout << "Nombre: "; cin >> nombre;
        cout << "Apellido: "; cin >> apellido;
        cout << "Correo: "; cin >> correo;
        cout << "Fecha de nacimiento (YYYY-MM-DD): "; cin >> fecha;

        alumno.set("id", to_string(idEstudiante));
        alumno.set("NOMBRE", nombre);
        alumno.set("APELLIDO", apellido);
        alumno.set("CORREO", correo);
        alumno.set("FECHA_NACIMIENTO", fecha);

        cout << (alumno.create() ? "Alumno creado.\n" : "Error al crear el alumno.\n");
    }

    void leer() {
        auto lista = orm.getAll();
        for (auto& reg : lista) {
            cout << "ID: " << reg["id"] << ", Nombre: " << reg["NOMBRE"] 
                 << ", Apellido: " << reg["APELLIDO"] << ", Correo: " << reg["CORREO"]
                 << ", Fecha: " << reg["FECHA_NACIMIENTO"] << endl;
        }
    }

    void actualizar() {
        EloquentORM orm(conn, "estudiantes", {"id", "NOMBRE", "APELLIDO", "CORREO", "FECHA_NACIMIENTO"});
        int id;
        cout << "ID del estudiante: "; cin >> id;
        string nombre, apellido, correo, fecha;
        cout << "Nuevo Nombre: "; cin >> nombre;
        cout << "Nuevo Apellido: "; cin >> apellido;
        cout << "Nuevo Correo: "; cin >> correo;
        cout << "Nueva Fecha (YYYY-MM-DD): "; cin >> fecha;

        orm.set("id", to_string(id));
        orm.set("NOMBRE", nombre);
        orm.set("APELLIDO", apellido);
        orm.set("CORREO", correo);
        orm.set("FECHA_NACIMIENTO", fecha);

        cout << (orm.update() ? "Estudiante actualizado.\n" : "Error al actualizar estudiante.\n");
    }

    void eliminar() {
        EloquentORM alumno(conn,"estudiantes",{"NOMBRE", "APELLIDO", "CORREO","FECHA_NACIMIENTO"});
        int id;
        cout << "Ingrese el id de estudiante que desea eliminar: \n"; 
        cin >> id;
        alumno.find(id);
        cout << "Se elimino al alumno: " << alumno.get("NOMBRE") << endl;
        alumno.remove(); 
    }
};  

class Docente {
    MySQLConexion& conn;
    EloquentORM orm;
public:
    Docente(MySQLConexion& conexion)
        : conn(conexion), orm(conexion, "DOCENTES", {"ID_DOCENTE", "NOMBRE", "ESPECIALIDAD"}) {}

    void crear() {
        EloquentORM profesor(conn, "DOCENTES", {"id", "NOMBRE", "APELLIDO", "ESPECIALIDAD"});
        int id_docente;
        string nombre, apellido, especialidad;
        cout << "ID Docente: "; cin >> id_docente;
        cout << "Nombre: "; cin.ignore(); getline(cin, nombre);
        cout << "Apellido: "; cin.ignore(); getline(cin, apellido);
        cout << "Especialidad: "; cin >> especialidad;

        profesor.set("id", to_string(id_docente));
        profesor.set("NOMBRE", nombre);
        profesor.set("APELLIDO", apellido);
        profesor.set("ESPECIALIDAD", especialidad);

        cout << (profesor.create() ? "Docente creado.\n" : "Error al crear docente.\n");
    }

    void leer() {
        auto lista = orm.getAll();
        for (auto& reg : lista) {
            cout << "ID: " << reg["id"] << ", Nombre: " << reg["NOMBRE"] 
                 << ", Apellido: " << reg["APELLIDO"]
                 << ", Especialidad: " << reg["ESPECIALIDAD"] << endl;
        }
    }

    void actualizar() {
        EloquentORM orm(conn, "docentes", {"id", "NOMBRE", "APELLIDO", "ESPECIALIDAD"});
        int id;
        cout << "ID del docente: "; cin >> id;
        string nombre, apellido, especialidad;
        cout << "Nuevo Nombre: "; cin >> nombre;
        cout << "Nuevo Apellido: "; cin >> apellido;
        cout << "Nueva Especialidad: "; cin.ignore(); getline(cin, especialidad);

        orm.set("id", to_string(id));
        orm.set("NOMBRE", nombre);
        orm.set("APELLIDO", apellido);
        orm.set("ESPECIALIDAD", especialidad);

        cout << (orm.update() ? "Docente actualizado.\n" : "Error al actualizar docente.\n");
    }

    void eliminar() {
        EloquentORM profesor(conn,"docentes",{"NOMBRE", "APELLIDO", "ESPECIALIDAD"});
        int id;
        cout << "Ingrese el id de docente que desea eliminar: \n"; 
        cin >> id;
        profesor.find(id);
        cout << "Se elimino al docente: " << profesor.get("NOMBRE") << endl;
        profesor.remove(); 
    }
};

class Curso {
    MySQLConexion& conn;
    EloquentORM orm;
public:
    Curso(MySQLConexion& conexion)
        : conn(conexion), orm(conexion, "CURSOS", {"ID_CURSO", "NOMBRE", "CREDITOS", "ID_DOCENTE"}) {}

    void crear() {
        EloquentORM materia(conn, "cursos", {"id", "NOMBRE_CURSO", "CREDITOS", "DESCRIPCION", "ID_DOCENTE"});
        string nombre, descripcion;
        int creditos, id_docente, id_curso;
        cout << "ID Curso: "; cin >> id_curso;
        cout << "Nombre del curso: "; cin.ignore(); getline(cin, nombre);
        cout << "Créditos: "; cin >> creditos;
        cout << "Descripcion: "; cin.ignore(); getline(cin, descripcion);
        cout << "ID del docente: "; cin >> id_docente;

        materia.set("id", to_string(id_curso));
        materia.set("NOMBRE_CURSO", nombre);
        materia.set("CREDITOS", to_string(creditos));
        materia.set("DESCRIPCION", descripcion);
        materia.set("ID_DOCENTE", to_string(id_docente));

        cout << (materia.create() ? "Curso creado.\n" : "Error al crear curso.\n");
    }

    void leer() {
        auto lista = orm.getAll();
        for (auto& reg : lista) {
            cout << "ID: " << reg["id"] << ", Nombre: " << reg["NOMBRE_CURSO"]
                 << ", Créditos: " << reg["CREDITOS"]
                 << ", Descripción: " << reg["DESCRIPCION"]
                 << ", ID Docente: " << reg["ID_DOCENTE"] << endl;
        }
    }

    void actualizar() {
        EloquentORM orm(conn, "cursos", {"id", "NOMBRE_CURSO", "CREDITOS", "DESCRIPCION", "ID_DOCENTE"});
        int id;
        cout << "ID del curso: "; cin >> id;
        string nombre;
        int creditos, id_docente;
        cout << "Nuevo Nombre: "; cin.ignore(); getline(cin, nombre);
        cout << "Créditos: "; cin >> creditos;
        cout << "ID Docente: "; cin >> id_docente;

        orm.set("id", to_string(id));
        orm.set("NOMBRE_CURSO", nombre);
        orm.set("CREDITOS", to_string(creditos));
        orm.set("ID_DOCENTE", to_string(id_docente));

        cout << (orm.update() ? "Curso actualizado.\n" : "Error al actualizar curso.\n");
    }

    void eliminar() {
        EloquentORM materia(conn,"cursos",{"NOMBRE_CURSO", "CREDITOS", "DESCRIPCION", "ID_DOCENTE"});
        int id;
        cout << "Ingrese el id de curso que desea eliminar: \n"; 
        cin >> id;
        materia.find(id);
        cout << "Se elimino el curso: " << materia.get("NOMBRE_CURSO") << endl;
        materia.remove();
    }
};

class Nota {
    MySQLConexion& conn;
    EloquentORM orm;
public:
    Nota(MySQLConexion& conexion)
        : conn(conexion), orm(conexion, "NOTAS", {"ID_NOTA", "ID_ESTUDIANTE", "ID_CURSO", "CALIFICACION"}) {}

    void crear() {
        EloquentORM orm(conn, "NOTAS", {"id", "ID_ESTUDIANTE", "ID_CURSO", "TIPO", "NOTA", "FECHA_REGISTRO"});
        int id_estudiante, id_curso, id_nota;
        double calificacion;
        string fecha, tipo;
        cout << "ID Nota: "; cin >> id_nota;
        cout << "ID Estudiante: "; cin >> id_estudiante;
        cout << "ID Curso: "; cin >> id_curso;
        cout << "Tipo: "; cin >> tipo;
        cout << "Calificación: "; cin >> calificacion;
        cout << "Fecha de registro (YYYY-MM-DD): "; cin >> fecha;

        orm.set("id", to_string(id_nota));
        orm.set("ID_ESTUDIANTE", to_string(id_estudiante));
        orm.set("ID_CURSO", to_string(id_curso));
        orm.set("NOTA", to_string(calificacion));
        orm.set("TIPO", tipo);
        orm.set("FECHA_REGISTRO", fecha);

        cout << (orm.create() ? "Nota registrada.\n" : "Error al registrar nota.\n");
    }

    void leer() {
        auto lista = orm.getAll();
        for (auto& reg : lista) {
            cout << "ID: " << reg["id"] << ", Estudiante: " << reg["ID_ESTUDIANTE"]
                 << ", Curso: " << reg["ID_CURSO"]
                 << ", Calificación: " << reg["NOTA"] << endl
                 << "Tipo: " << reg["TIPO"] << ", Fecha: " << reg["FECHA_REGISTRO"] << endl;
        }
    }

    void actualizar() {
        EloquentORM orm(conn, "NOTAS", {"id", "ID_ESTUDIANTE", "ID_CURSO", "TIPO", "NOTA", "FECHA_REGISTRO"});    
        int id;
        cout << "ID de la nota: "; cin >> id;
        int id_estudiante, id_curso;
        double calificacion;
        string fecha, tipo;
        cout << "Nuevo ID Estudiante: "; cin >> id_estudiante;
        cout << "Nuevo ID Curso: "; cin >> id_curso;
        cout << "Nuevo Tipo: "; cin.ignore(); getline(cin, tipo);
        cout << "Nueva Calificación: "; cin >> calificacion;
        cout << "Nueva Fecha (YYYY-MM-DD): "; cin >> fecha;

        orm.set("id", to_string(id));
        orm.set("ID_ESTUDIANTE", to_string(id_estudiante));
        orm.set("ID_CURSO", to_string(id_curso));
        orm.set("TIPO", tipo);
        orm.set("NOTA", to_string(calificacion));
        orm.set("FECHA_REGISTRO", fecha);

        cout << (orm.update() ? "Nota actualizada.\n" : "Error al actualizar nota.\n");
    }

    void eliminar() {
        EloquentORM orm(conn, "NOTAS", {"id", "ID_ESTUDIANTE", "ID_CURSO", "TIPO", "NOTA", "FECHA_REGISTRO"});
        int id;
        cout << "ID de la nota: "; cin >> id;
        orm.find(id);
        cout << "Se elimino la nota: " << orm.get("TIPO") << endl;
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
