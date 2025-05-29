-- --------------------------------------------------------
-- Host:                         127.0.0.1
-- Versión del servidor:         8.0.41 - MySQL Community Server - GPL
-- SO del servidor:              Win64
-- HeidiSQL Versión:             12.10.0.7000
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;


-- Volcando estructura de base de datos para sistema_de_estudiantes
DROP DATABASE IF EXISTS `sistema_de_estudiantes`;
CREATE DATABASE IF NOT EXISTS `sistema_de_estudiantes` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `sistema_de_estudiantes`;

-- Volcando estructura para tabla sistema_de_estudiantes.cursos
DROP TABLE IF EXISTS `cursos`;
CREATE TABLE IF NOT EXISTS `cursos` (
  `id` int NOT NULL AUTO_INCREMENT,
  `NOMBRE_CURSO` varchar(100) DEFAULT NULL,
  `DESCRIPCION` text,
  `CREDITOS` int DEFAULT NULL,
  `ID_DOCENTE` int DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE,
  KEY `ID_DOCENTE` (`ID_DOCENTE`),
  CONSTRAINT `cursos_ibfk_1` FOREIGN KEY (`ID_DOCENTE`) REFERENCES `docentes` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Volcando datos para la tabla sistema_de_estudiantes.cursos: ~7 rows (aproximadamente)
INSERT INTO `cursos` (`id`, `NOMBRE_CURSO`, `DESCRIPCION`, `CREDITOS`, `ID_DOCENTE`) VALUES
	(1, 'CALCULO I', 'INTRODUCCION AL CALCULO DIFERENCIAL', 5, 2),
	(2, 'FISICA I', 'VECTORIAL Y CINEMATICA', 5, 3),
	(3, 'PROCESO ADM', 'FASES DEL PROCESO ADM', 4, 5),
	(4, 'DERECHO INF.', 'REGULACION DE LA INFORMATICA', 4, 4),
	(5, 'PROGRAMACION I', 'POO Y BASES DE DATOS', 5, 1),
	(6, 'MATEMATICA_DISCRETA', 'DESARROLLO DE LA LOGICA', 5, 6),
	(7, 'OGICA DE SISTEMAS', 'Desarrolla tu mente', 5, 1);

-- Volcando estructura para tabla sistema_de_estudiantes.docentes
DROP TABLE IF EXISTS `docentes`;
CREATE TABLE IF NOT EXISTS `docentes` (
  `id` int NOT NULL AUTO_INCREMENT,
  `NOMBRE` varchar(100) DEFAULT NULL,
  `APELLIDO` varchar(100) DEFAULT NULL,
  `ESPECIALIDAD` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Volcando datos para la tabla sistema_de_estudiantes.docentes: ~8 rows (aproximadamente)
INSERT INTO `docentes` (`id`, `NOMBRE`, `APELLIDO`, `ESPECIALIDAD`) VALUES
	(1, 'LUIS', 'GARCIA', 'INFORMATICA'),
	(2, 'CESAR', 'LOPEZ', 'MECATRONICA'),
	(3, 'CARLOS', 'MATUS', 'FISICO'),
	(4, 'MARCOS', 'BARILLAS', 'ABOGADO'),
	(5, 'ESDRAS', 'AGUIRRE', 'QUIMICO'),
	(6, 'MANUEL', 'SALVADOR', 'INDUSTRIAL'),
	(7, 'Azucena', NULL, 'Administrador'),
	(8, 'MARIO', 'CORTEZ', 'INFORMATICO');

-- Volcando estructura para tabla sistema_de_estudiantes.estudiantes
DROP TABLE IF EXISTS `estudiantes`;
CREATE TABLE IF NOT EXISTS `estudiantes` (
  `id` int NOT NULL AUTO_INCREMENT,
  `NOMBRE` varchar(100) DEFAULT NULL,
  `APELLIDO` varchar(100) DEFAULT NULL,
  `CORREO` varchar(100) DEFAULT NULL,
  `FECHA_NACIMIENTO` date DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Volcando datos para la tabla sistema_de_estudiantes.estudiantes: ~5 rows (aproximadamente)
INSERT INTO `estudiantes` (`id`, `NOMBRE`, `APELLIDO`, `CORREO`, `FECHA_NACIMIENTO`) VALUES
	(1, 'Antonio', 'Ramirez', 'AtRamirez@gmail.edu.mx', '2006-02-14'),
	(2, 'ELIAN', 'RAMOS', 'Elianmoran2019@gmial.com', '2006-11-28'),
	(3, 'ARIEL', 'GARCIA', 'ARIEDECORTEZ@MIUMG.EDU.MX', '1950-02-18'),
	(4, 'Wilson', 'Ortiz', 'wilson@miumg.edu.gt', '2006-10-15'),
	(5, 'Benjamin', 'Recinos', 'Ben@miumg.edu.gt', '2005-03-12');

-- Volcando estructura para tabla sistema_de_estudiantes.notas
DROP TABLE IF EXISTS `notas`;
CREATE TABLE IF NOT EXISTS `notas` (
  `id` int NOT NULL AUTO_INCREMENT,
  `ID_ESTUDIANTE` int DEFAULT NULL,
  `ID_CURSO` int DEFAULT NULL,
  `TIPO` varchar(50) DEFAULT NULL,
  `NOTA` decimal(5,2) DEFAULT NULL,
  `FECHA_REGISTRO` date DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE,
  KEY `ID_ESTUDIANTE` (`ID_ESTUDIANTE`),
  KEY `ID_CURSO` (`ID_CURSO`),
  CONSTRAINT `notas_ibfk_1` FOREIGN KEY (`ID_ESTUDIANTE`) REFERENCES `estudiantes` (`id`),
  CONSTRAINT `notas_ibfk_2` FOREIGN KEY (`ID_CURSO`) REFERENCES `cursos` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Volcando datos para la tabla sistema_de_estudiantes.notas: ~5 rows (aproximadamente)
INSERT INTO `notas` (`id`, `ID_ESTUDIANTE`, `ID_CURSO`, `TIPO`, `NOTA`, `FECHA_REGISTRO`) VALUES
	(1, 3, 1, 'PRESENCIAL', 78.00, '2025-05-14'),
	(2, 3, 4, 'PRESENCIAL', 90.00, '2025-05-14'),
	(3, 3, 2, 'PRESENCIAL', 86.00, '2025-05-14'),
	(4, 3, 3, 'PRESENCIAL', 90.00, '2025-05-14'),
	(5, 3, 5, 'PRESENCIAL', 99.00, '2025-05-14');

/*!40103 SET TIME_ZONE=IFNULL(@OLD_TIME_ZONE, 'system') */;
/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;
