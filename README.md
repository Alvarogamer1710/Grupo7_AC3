# 🎬 Proyecto AC3 – Sistema de Gestión de Streaming y Música
**Universidad Europea**  
**Asignatura:** Programación / Ingeniería del Software  
**Entrega:** Actividad Colaborativa 3

---

## 👥 Integrantes del Grupo
- Álvaro Hernández Villarreal
- Juan Labajo Lorenzana
- Iván Sanz López
- Esteban Damián Laguinge

**Grupo 7**

---

## 📦 Estructura del Proyecto

El proyecto se entrega en un archivo comprimido con el nombre:

```
Grupo7_AC3.zip
```

Dentro del archivo `.zip` se incluirán:

```
├── Proyecto_Musica/
│   ├── main.cpp
│   ├── clases_musica.h
│   ├── clases_musica.cpp
│   ├── biblioteca_musica.txt
│   └── README.md
│
├── Proyecto_Peliculas/
│   ├── main.cpp
│   ├── clases_peliculas.h
│   ├── clases_peliculas.cpp
│   ├── catalogo_peliculas.txt
│   └── README.md
│
└── Grupo7_AC2.pdf   ← Memoria del proyecto
```

---

## 🧩 Descripción General del Proyecto

El objetivo del proyecto es desarrollar **una aplicación sencilla** que permita gestionar una biblioteca multimedia compuesta por **música, películas y series**, simulando el funcionamiento de una plataforma de streaming y un servicio de música.

El proyecto se divide en **dos módulos independientes**:

### 🎵 Recurso 1 – Módulo de Música
Permite almacenar y gestionar títulos musicales, con los siguientes datos:
- **Título de la canción**
- **Álbum**
- **Grupo o artista**
- **Género musical**

📌 El sistema debe:
- Permitir búsquedas por **título**, **álbum**, **género** o **grupo**.
- Mostrar resultados en consola.
- Mostrar un mensaje si no se encuentra el elemento.
- Almacenar la información en un **Vector o Dinarray** (según la elección del grupo).

### 🎥 Recurso 2 – Módulo de Películas y Series
Permite gestionar contenido audiovisual para streaming, con la siguiente información:
- **Título**
- **Tipo:** Película o Serie
- **Género**
- **Calidad:** FHD o UHD
- **Disponibilidad:** Incluido en tarifa estándar o de pago adicional
- **Precio de alquiler (si aplica)**

📌 El sistema debe:
- Permitir búsquedas por **título**, **género** o **calidad**.
- Mostrar resultados en consola.
- Permitir cambiar el estado de un producto de “no disponible” a “disponible” al alquilarlo.
- Usar **Vector o Dinarray** (el opuesto al utilizado en el módulo anterior).

---

## ⚙️ Requisitos Técnicos

- Lenguaje de programación: **C++**
- Se deben reutilizar y adaptar las **clases plantilla** vistas en clase.
- No se deben usar funciones innecesarias fuera del contexto del diseño orientado a objetos.
- Se recomienda mantener una estructura modular del código.
- Generar una pequeña **biblioteca inicial** de elementos multimedia para realizar pruebas.

---

## 🧠 Diseño y Arquitectura

El proyecto se basa en una arquitectura **orientada a objetos (POO)**, aplicando conceptos vistos en clase:

- **Clases base:**
    - `Cancion`
    - `Pelicula` / `Serie`

- **Estructuras de almacenamiento:**
    - `Vector` o `Dinarray` (dependiendo del módulo)

- **Funciones principales:**
    - Cargar biblioteca multimedia
    - Buscar elementos por distintos criterios
    - Mostrar resultados
    - Modificar disponibilidad en caso de alquiler

📘 En la memoria PDF se incluye:
- Explicación de la teoría aplicada (Vectores, Dinarrays, Clases, Métodos).
- Diseño UML del sistema.
- Explicación del funcionamiento del código.
- Manual de uso del programa.

---

## ▶️ Ejecución del Programa

1. Compilar los programas con un compilador C++ (por ejemplo, `g++`):
   ```bash
   g++ main.cpp clases_musica.cpp -o musica
   g++ main.cpp clases_peliculas.cpp -o peliculas
   ```
2. Ejecutar desde la terminal:
   ```bash
   ./musica
   ./peliculas
   ```
3. Seguir las instrucciones del menú que se mostrará en pantalla para realizar búsquedas o gestionar alquileres.

---

## 🧾 Entrega Final

- Archivo comprimido: `Grupo7_AC3.zip`
- Contenido:
    - Carpeta del proyecto de música
    - Carpeta del proyecto de películas
    - Documento PDF con memoria y diseño (`Grupo7_AC2.pdf`)
- Entrega mediante el **Campus Virtual** en la tarea correspondiente.

---

## 🏁 Conclusión

Este proyecto busca poner en práctica los conocimientos adquiridos sobre:
- Programación orientada a objetos
- Uso de estructuras dinámicas y estáticas
- Manipulación de datos y búsquedas
- Diseño y documentación de software

Constituye además una base conceptual para el desarrollo de sistemas de gestión multimedia en entornos reales.
