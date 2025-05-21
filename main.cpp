#include "MySQLConexion.h"
#include "EloquentORM.h"
#include <iostream>
#include <string>

using namespace std;

// ================= ENTIDADES ====================
/*
@brief Clase que representa un estudiante
*
* Permite realizar operaciones CRUD sobre la tabla de estudiantes.
*/
class Estudiante {
    MySQLConexion& conn;
    EloquentORM orm;
public:
    /*
     * @brief Constructor de la clase Estudiante.
     *
     * Inicializa la conexión a la base de datos y la tabla de estudiantes.
     *
     * @param conexion Referencia a la conexión MySQL.
     */
    Estudiante(MySQLConexion& conexion)
        : conn(conexion), orm(conexion, "ESTUDIANTES", {"ID_ESTUDIANTE", "NOMBRE", "APELLIDO", "CORREO", "FECHA_NACIMIENTO"}) {}

    /*
     * @brief Crea un nuevo estudiante.
     *
     * Solicita al usuario los datos del estudiante y lo inserta en la base de datos.
     */
    void crear_estudiante() {
        // Crear un nuevo objeto EloquentORM para la tabla estudiantes
        EloquentORM alumno(conn, "estudiantes", {"id", "NOMBRE", "APELLIDO", "CORREO", "FECHA_NACIMIENTO"});
        // Solicitar datos al usuario
        int idEstudiante;
        // Variables para almacenar los datos
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
    /*
     * @brief Lee todos los estudiantes de la base de datos.
     *
     * Muestra en pantalla los datos de todos los estudiantes registrados.
     */
    void leer_estudiantes() {
        // Obtener todos los registros de la tabla estudiantes
        auto lista = orm.getAll();
        for (auto& reg : lista) {
            cout << "ID: " << reg["id"] << ", Nombre: " << reg["NOMBRE"] 
                 << ", Apellido: " << reg["APELLIDO"] << ", Correo: " << reg["CORREO"]
                 << ", Fecha: " << reg["FECHA_NACIMIENTO"] << endl;
        }
    }
    /*
     * @brief Actualiza los datos de un estudiante.
     *
     * Solicita al usuario el ID del estudiante y los nuevos datos, y actualiza la base de datos.
     */
    void actualizar_estudiante() {
        EloquentORM orm(conn, "estudiantes", {"id", "NOMBRE", "APELLIDO", "CORREO", "FECHA_NACIMIENTO"});
        // Solicitar el ID del estudiante a actualizar
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
    /*
     * @brief Elimina un estudiante de la base de datos.
     *
     * Solicita al usuario el ID del estudiante a eliminar y lo elimina de la base de datos.
     */
    void eliminar_estudiante() {
        EloquentORM alumno(conn,"estudiantes",{"NOMBRE", "APELLIDO", "CORREO","FECHA_NACIMIENTO"});
        // Solicitar el ID del estudiante a eliminar
        int id;
        cout << "Ingrese el id de estudiante que desea eliminar: \n"; 
        cin >> id;
        alumno.find(id);
        cout << "Se elimino al alumno: " << alumno.get("NOMBRE") << endl;
        alumno.remove(); 
    }
};  
/*
* @brief Clase que representa un docente
*/
class Docente {
    MySQLConexion& conn;
    EloquentORM orm;
public:
    Docente(MySQLConexion& conexion)
        : conn(conexion), orm(conexion, "DOCENTES", {"ID_DOCENTE", "NOMBRE", "ESPECIALIDAD"}) {}
    
    /*
     * @brief Crea un nuevo docente.
     *
     * Solicita al usuario los datos del docente y lo inserta en la base de datos.
     */
    void crear_docente() {
        EloquentORM profesor(conn, "DOCENTES", {"id", "NOMBRE", "APELLIDO", "ESPECIALIDAD"});
        // Solicitar datos al usuario
        int idDocente;
        string nombre, apellido, especialidad;
        cout << "ID Docente: "; cin >> idDocente;
        cout << "Nombre: "; cin.ignore(); getline(cin, nombre);
        cout << "Apellido: "; cin.ignore(); getline(cin, apellido);
        cout << "Especialidad: "; cin >> especialidad;

        profesor.set("id", to_string(idDocente));
        profesor.set("NOMBRE", nombre);
        profesor.set("APELLIDO", apellido);
        profesor.set("ESPECIALIDAD", especialidad);

        cout << (profesor.create() ? "Docente creado.\n" : "Error al crear docente.\n");
    }
    /*
     * @brief Lee todos los docentes de la base de datos.
     *
     * Muestra en pantalla los datos de todos los docentes registrados.
     */
    void leer_docentes() {
        // Obtener todos los registros de la tabla docentes
        auto lista = orm.getAll();
        for (auto& reg : lista) {
            cout << "ID: " << reg["id"] << ", Nombre: " << reg["NOMBRE"] 
                 << ", Apellido: " << reg["APELLIDO"]
                 << ", Especialidad: " << reg["ESPECIALIDAD"] << endl;
        }
    }
    /*
     * @brief Actualiza los datos de un docente.
     *
     * Solicita al usuario el ID del docente y los nuevos datos, y actualiza la base de datos.
     */
    void actualizar_docente() {
        EloquentORM orm(conn, "docentes", {"id", "NOMBRE", "APELLIDO", "ESPECIALIDAD"});
        // Solicitar el ID del docente a actualizar
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
    /*
     * @brief Elimina un docente de la base de datos.
     *
     * Solicita al usuario el ID del docente a eliminar y lo elimina de la base de datos.
     */
    void eliminar_docente() {
        EloquentORM profesor(conn,"docentes",{"NOMBRE", "APELLIDO", "ESPECIALIDAD"});
        // Solicitar el ID del docente a eliminar
        int id;
        cout << "Ingrese el id de docente que desea eliminar: \n"; 
        cin >> id;
        profesor.find(id);
        cout << "Se elimino al docente: " << profesor.get("NOMBRE") << endl;
        profesor.remove(); 
    }
};
/*
*
* @brief Clase que representa un curso
*/
class Curso {
    MySQLConexion& conn;
    EloquentORM orm;
public:
    /*
     * @brief Constructor de la clase Curso.
     *
     * Inicializa la conexión a la base de datos y la tabla de cursos.
     *
     * @param conexion Referencia a la conexión MySQL.
     */
    Curso(MySQLConexion& conexion)
        : conn(conexion), orm(conexion, "CURSOS", {"ID_CURSO", "NOMBRE", "CREDITOS", "ID_DOCENTE"}) {}
    /*
     * @brief Crea un nuevo curso.
     *
     * Solicita al usuario los datos del curso y lo inserta en la base de datos.
     */
    void crear_curso() {
        EloquentORM materia(conn, "cursos", {"id", "NOMBRE_CURSO", "CREDITOS", "DESCRIPCION", "ID_DOCENTE"});
        // Solicitar datos al usuario
        string nombre, descripcion;
        int creditos, idDocente, idCurso;
        cout << "ID Curso: "; cin >> idCurso;
        cout << "Nombre del curso: "; cin.ignore(); getline(cin, nombre);
        cout << "Créditos: "; cin >> creditos;
        cout << "Descripcion: "; cin.ignore(); getline(cin, descripcion);
        cout << "ID del docente: "; cin >> idDocente;

        materia.set("id", to_string(idCurso));
        materia.set("NOMBRE_CURSO", nombre);
        materia.set("CREDITOS", to_string(creditos));
        materia.set("DESCRIPCION", descripcion);
        materia.set("ID_DOCENTE", to_string(idDocente));

        cout << (materia.create() ? "Curso creado.\n" : "Error al crear curso.\n");
    }
    /*
     * @brief Lee todos los cursos de la base de datos.
     *
     * Muestra en pantalla los datos de todos los cursos registrados.
     */
    void leer_cursos() {
        // Obtener todos los registros de la tabla cursos
        auto lista = orm.getAll();
        for (auto& reg : lista) {
            cout << "ID: " << reg["id"] << ", Nombre: " << reg["NOMBRE_CURSO"]
                 << ", Créditos: " << reg["CREDITOS"]
                 << ", Descripción: " << reg["DESCRIPCION"]
                 << ", ID Docente: " << reg["ID_DOCENTE"] << endl;
        }
    }
    /*
     * @brief Actualiza los datos de un curso.
     *
     * Solicita al usuario el ID del curso y los nuevos datos, y actualiza la base de datos.
     */
    void actualizar_curso() {
        EloquentORM orm(conn, "cursos", {"id", "NOMBRE_CURSO", "CREDITOS", "DESCRIPCION", "ID_DOCENTE"});
        // Solicitar el ID del curso a actualizar
        int id;
        cout << "ID del curso: "; cin >> id;
        string nombre;
        int creditos, idDocente;
        cout << "Nuevo Nombre: "; cin.ignore(); getline(cin, nombre);
        cout << "Créditos: "; cin >> creditos;
        cout << "ID Docente: "; cin >> idDocente;

        orm.set("id", to_string(id));
        orm.set("NOMBRE_CURSO", nombre);
        orm.set("CREDITOS", to_string(creditos));
        orm.set("ID_DOCENTE", to_string(idDocente));

        cout << (orm.update() ? "Curso actualizado.\n" : "Error al actualizar curso.\n");
    }
    /*
     * @brief Elimina un curso de la base de datos.
     *
     * Solicita al usuario el ID del curso a eliminar y lo elimina de la base de datos.
     */
    void eliminar_curso() {
        EloquentORM materia(conn,"cursos",{"NOMBRE_CURSO", "CREDITOS", "DESCRIPCION", "ID_DOCENTE"});
        int id;
        cout << "Ingrese el id de curso que desea eliminar: \n"; 
        cin >> id;
        materia.find(id);
        cout << "Se elimino el curso: " << materia.get("NOMBRE_CURSO") << endl;
        materia.remove();
    }
};
/*    
*
* @brief Clase que representa una nota  
*/
class Nota {
    MySQLConexion& conn;
    EloquentORM orm;
public:
    Nota(MySQLConexion& conexion)
        : conn(conexion), orm(conexion, "NOTAS", {"ID_NOTA", "ID_ESTUDIANTE", "ID_CURSO", "CALIFICACION"}) {}
    /*
     * @brief Crea una nueva nota.
     *
     * Solicita al usuario los datos de la nota y lo inserta en la base de datos.
     */
    void crear_nota() {
        // Crear un nuevo objeto EloquentORM para la tabla notas
        EloquentORM orm(conn, "NOTAS", {"id", "ID_ESTUDIANTE", "ID_CURSO", "TIPO", "NOTA", "FECHA_REGISTRO"});
        // Solicitar datos al usuario
        int idEstudiante, idCurso, idNota;
        double calificacion;
        string fecha, tipo;
        cout << "ID Nota: "; cin >> idNota;
        cout << "ID Estudiante: "; cin >> idEstudiante;
        cout << "ID Curso: "; cin >> idCurso;
        cout << "Tipo: "; cin >> tipo;
        cout << "Calificación: "; cin >> calificacion;
        cout << "Fecha de registro (YYYY-MM-DD): "; cin >> fecha;

        orm.set("id", to_string(idNota));
        orm.set("ID_ESTUDIANTE", to_string(idEstudiante));
        orm.set("ID_CURSO", to_string(idCurso));
        orm.set("NOTA", to_string(calificacion));
        orm.set("TIPO", tipo);
        orm.set("FECHA_REGISTRO", fecha);

        cout << (orm.create() ? "Nota registrada.\n" : "Error al registrar nota.\n");
    }
    /*
     * @brief Lee todas las notas de la base de datos.
     *
     * Muestra en pantalla los datos de todas las notas registradas.
     */
    void leer_notas() {
        // Obtener todos los registros de la tabla notas
        auto lista = orm.getAll();
        for (auto& reg : lista) {
            cout << "ID: " << reg["id"] << ", Estudiante: " << reg["ID_ESTUDIANTE"]
                 << ", Curso: " << reg["ID_CURSO"]
                 << ", Calificación: " << reg["NOTA"] << endl
                 << "Tipo: " << reg["TIPO"] << ", Fecha: " << reg["FECHA_REGISTRO"] << endl;
        }
    }
    /*
     * @brief Actualiza los datos de una nota.
     *
     * Solicita al usuario el ID de la nota y los nuevos datos, y actualiza la base de datos.
     */
    void actualizar_nota() {
        EloquentORM orm(conn, "NOTAS", {"id", "ID_ESTUDIANTE", "ID_CURSO", "TIPO", "NOTA", "FECHA_REGISTRO"}); 
        // Solicitar el ID de la nota a actualizar   
        int id;
        cout << "ID de la nota: "; cin >> id;
        // Solicitar nuevos datos
        int idEstudiante, idCurso;
        double calificacion;
        string fecha, tipo;
        cout << "Nuevo ID Estudiante: "; cin >> idEstudiante;
        cout << "Nuevo ID Curso: "; cin >> idCurso;
        cout << "Nuevo Tipo: "; cin.ignore(); getline(cin, tipo);
        cout << "Nueva Calificación: "; cin >> calificacion;
        cout << "Nueva Fecha (YYYY-MM-DD): "; cin >> fecha;

        orm.set("id", to_string(id));
        orm.set("ID_ESTUDIANTE", to_string(idEstudiante));
        orm.set("ID_CURSO", to_string(idCurso));
        orm.set("TIPO", tipo);
        orm.set("NOTA", to_string(calificacion));
        orm.set("FECHA_REGISTRO", fecha);

        cout << (orm.update() ? "Nota actualizada.\n" : "Error al actualizar nota.\n");
    }
    /*
     * @brief Elimina una nota de la base de datos.
     *
     * Solicita al usuario el ID de la nota a eliminar y lo elimina de la base de datos.
     */
    void eliminar_nota() {
        EloquentORM orm(conn, "NOTAS", {"id", "ID_ESTUDIANTE", "ID_CURSO", "TIPO", "NOTA", "FECHA_REGISTRO"});
        // Solicitar el ID de la nota a eliminar
        int id;
        cout << "ID de la nota: "; cin >> id;
        orm.find(id);
        cout << "Se elimino la nota: " << orm.get("TIPO") << endl;
        cout << (orm.remove() ? "Nota eliminada.\n" : "Error al eliminar nota.\n");
    }
};

// ================= MENU PRINCIPAL ====================

/*
 * @brief Muestra el menú de opciones para cada entidad.
 *
 * @param nombreEntidad Nombre de la entidad (Estudiantes, Docentes, Cursos, Notas).
 */
void mostrar_menu_entidad(const string& nombreEntidad) {
    cout << "\n--- " << nombreEntidad << " ---\n";
    cout << "1. Crear\n";
    cout << "2. Leer\n";
    cout << "3. Actualizar\n";
    cout << "4. Eliminar\n";
    cout << "5. Volver al menú principal\n";
}

// ================= MAIN ====================
/*
 * @brief Función principal del programa.
 *
 * Crea una conexión a la base de datos y permite al usuario interactuar con el sistema de gestión de estudiantes.
 *
 * @return int Código de salida del programa.
 */
int main() {
    // Crear una conexión a la base de datos
    MySQLConexion conn("root", "2020", "sistema_de_estudiantes");

    // Conectar a la base de datos
    if (!conn.open()) {
        cerr << "No se pudo conectar a la base de datos." << endl;
        return 1;
    }

    // Crear instancias de las entidades
    Estudiante estudiante(conn);
    Docente docente(conn);
    Curso curso(conn);
    Nota nota(conn);

    // Mostrar el menú principal
    cout << "Bienvenido al sistema de gestión de estudiantes.\n";
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

        mostrar_menu_entidad(
            opcionEntidad == 1 ? "Estudiantes" :
            opcionEntidad == 2 ? "Docentes" :
            opcionEntidad == 3 ? "Cursos" : "Notas"
        );

        cin >> opcionAccion;

        switch (opcionEntidad) {
            case 1:
                if (opcionAccion == 1) estudiante.crear_estudiante();
                else if (opcionAccion == 2) estudiante.leer_estudiantes();
                else if (opcionAccion == 3) estudiante.actualizar_estudiante();
                else if (opcionAccion == 4) estudiante.eliminar_estudiante();
                break;
            case 2:
                if (opcionAccion == 1) docente.crear_docente();
                else if (opcionAccion == 2) docente.leer_docentes();
                else if (opcionAccion == 3) docente.actualizar_docente();
                else if (opcionAccion == 4) docente.eliminar_docente();
                break;
            case 3:
                if (opcionAccion == 1) curso.crear_curso();
                else if (opcionAccion == 2) curso.leer_cursos();
                else if (opcionAccion == 3) curso.actualizar_curso();
                else if (opcionAccion == 4) curso.eliminar_curso();
                break;
            case 4:
                if (opcionAccion == 1) nota.crear_nota();
                else if (opcionAccion == 2) nota.leer_notas();
                else if (opcionAccion == 3) nota.actualizar_nota();
                else if (opcionAccion == 4) nota.eliminar_nota();
                break;
        }

    } while (true);

    // Cerrar la conexión a la base de datos
    conn.close();
    cout << "Conexión cerrada. Saliendo del sistema...\n";
    return 0;
}
// FIN DE CÓDIGO
