// Segunda tarea de Python, versión C++: una función por ejercicio.
//
// Los ejercicios impares (1, 3, 5, ..., 21) son los que se entregaron en clase;
// los pares (2, 4, 6, ..., 20) se resolvieron por cuenta propia.
// Los comentarios y los nombres de variables están en español porque así lo pidió
// la cátedra; el README del repositorio explica el resto.
//
// Cada función lleva un comentario con la misma estructura:
//     Entrada(s)      datos que recibe y supuestos sobre ellos
//     Salida          qué devuelve, con el tipo y los campos exactos
//     Estrategia      idea del algoritmo o la fórmula aplicada
//     Restricción(es) lo que el código NO valida, salvo que se indique lo contrario
//
// Contenido del archivo:
//     Utilidades internas ... length, invertir
//     Impares (entregados) .. 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21
//     Pares (extra) ......... 2, 4, 6, 8, 10, 12, 14, 16, 18, 20
//
// Diferencias con la versión de Python (misma lógica, otra forma de devolver):
// los dict se representan con structs (ResultadoCirculo, AreaVolumen, Aumento),
// las tuplas con std::array y el None de numLetras() con std::optional.

#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <optional>
#include <string>
#include <utility>
#include <variant>

constexpr double PI = 3.141592653589793;

const std::array<std::string, 10> NOMBRES_DIGITOS{
    "cero", "uno", "dos", "tres", "cuatro",
    "cinco", "seis", "siete", "ocho", "nueve",
};

// ===========================================================================
// Utilidades internas
// ===========================================================================

/**
 * Cuenta los elementos de una secuencia sin usar .size().
 *
 * Entrada: cualquier contenedor o cadena que se pueda recorrer con range-for.
 * Salida: std::size_t con la cantidad de elementos.
 * Estrategia: bucle for que incrementa un contador por cada elemento.
 */
template <typename Secuencia>
std::size_t length(const Secuencia& secuencia) {
    std::size_t contador = 0;

    for ([[maybe_unused]] const auto& elemento : secuencia) {
        ++contador;
    }

    return contador;
}

/**
 * Devuelve un número entero con sus dígitos en orden inverso.
 *
 * Entrada: num, entero mayor o igual a 0.
 * Salida: long long invertido; los ceros a la izquierda se pierden (100 -> 1).
 * Estrategia: en cada iteración se toma el último dígito con % 10, se agrega
 * al resultado multiplicándolo por 10, y el número se reduce con / 10.
 * Restricción: con números negativos devuelve 0, porque el bucle no se ejecuta.
 *
 * Resuelve por sí sola el ejercicio 20 y sirve de apoyo a los ejercicios 15 y 21.
 */
long long invertir(long long num) {
    long long invertido = 0;

    while (num > 0) {
        invertido = invertido * 10 + num % 10;
        num /= 10;
    }

    return invertido;
}

// ===========================================================================
// Ejercicios impares (entregados)
// ===========================================================================

struct ResultadoCirculo {
    double area;
    double circunferencia;
};

/**
 * Área y circunferencia de un círculo.
 *
 * Entrada: radio, número real (no se valida que sea positivo).
 * Salida: ResultadoCirculo con los campos area y circunferencia. En la versión
 * de Python el dict usaba las claves 'Area' y 'Circunferencia' con mayúscula,
 * a diferencia de esfera() y toro(); aquí los campos son minúsculas.
 * Estrategia: area = PI * radio²; circunferencia = 2 * PI * radio.
 */
ResultadoCirculo circulo(double radio) {
    ResultadoCirculo resultado;
    resultado.area = PI * std::pow(radio, 2);
    resultado.circunferencia = 2 * PI * radio;

    return resultado;
}

struct AreaVolumen {
    double area;
    double volumen;
};

/**
 * Área superficial y volumen de una esfera.
 *
 * Entrada: radio, número real (no se valida que sea positivo).
 * Salida: AreaVolumen con los campos area y volumen.
 * Estrategia: area = 4 * PI * radio²; volumen = (4/3) * PI * radio³.
 */
AreaVolumen esfera(double radio) {
    AreaVolumen resultado;
    resultado.area = 4 * PI * std::pow(radio, 2);
    resultado.volumen = 4.0 / 3.0 * PI * std::pow(radio, 3);

    return resultado;
}

/**
 * Indica si un año es bisiesto.
 *
 * Entrada: anio, entero que representa un año.
 * Salida: true si es divisible entre 4 y no entre 100, o si es divisible
 * entre 400; false en cualquier otro caso.
 * Estrategia: la regla gregoriana completa en una sola expresión booleana.
 * Restricción: no se valida que el año sea positivo; los negativos dan false.
 */
bool bisiesto(int anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;
}

/**
 * Devuelve el valor central de tres números.
 *
 * Entrada: a, b y c, números reales en cualquier orden.
 * Salida: el número que queda en el medio al ordenar los tres.
 * Estrategia: se comprueban los dos intervalos en los que cada número es el
 * mediano; el que no cumple ninguno de los dos primeros casos es c.
 */
double mediano(double a, double b, double c) {
    if ((b <= a && a <= c) || (c <= a && a <= b)) {
        return a;
    }
    if ((a <= b && b <= c) || (c <= b && b <= a)) {
        return b;
    }
    return c;
}

/**
 * Convierte una capacidad de almacenamiento de gigabytes a bytes.
 *
 * Entrada: capacidad, número real en GB.
 * Salida: double con la misma capacidad en bytes.
 * Estrategia: cada GB son 1024³ bytes, es decir 2³⁰.
 */
double disco(double capacidad) {
    return capacidad * std::pow(1024, 3);
}

/**
 * Convierte una distancia en metros a otra unidad lineal.
 *
 * Entrada: distancia en metros (real) y tipo, entero que elige la unidad:
 * 1 = centímetros, 2 = pulgadas, 3 = pies, 4 = yardas.
 * Salida: double con la distancia en la unidad elegida.
 * Estrategia: se encadenan las conversiones (metros -> cm -> pulgadas ->
 * pies -> yardas) y se devuelve la que corresponde al tipo.
 * Restricción: no se valida el rango de tipo; cualquier valor distinto de
 * 1, 2 o 3 se interpreta como yardas.
 */
double convertir(double distancia, int tipo) {
    const double centimetros = distancia * 100;
    const double pulgadas = centimetros / 2.54;
    const double pies = pulgadas / 12;
    const double yardas = pies / 3;

    if (tipo == 1) {
        return centimetros;
    } else if (tipo == 2) {
        return pulgadas;
    } else if (tipo == 3) {
        return pies;
    } else {
        return yardas;
    }
}

struct Aumento {
    double salario;
    int porcentaje;
};

/**
 * Calcula el aumento de un salario según el tramo en que se encuentre.
 *
 * Entrada: salario actual, real mayor o igual a 0.
 * Salida: Aumento con el salario nuevo y el porcentaje aplicado, que es 20,
 * 10, 5 o 0 según el tramo.
 * Estrategia: tramos fijos de 0 a 1 000 000 (20%), de 1 000 001 a 1 500 000
 * (10%), de 1 500 001 a 2 000 000 (5%) y más de 2 000 000 (sin aumento; se
 * devuelve el salario intacto junto a 0).
 * Restricción: no se valida el signo; un salario negativo cae en el último
 * caso y se devuelve sin cambios.
 */
Aumento aumento(double salario) {
    if (salario >= 0 && salario <= 1'000'000) {
        return {salario * 1.20, 20};
    } else if (salario >= 1'000'001 && salario <= 1'500'000) {
        return {salario * 1.10, 10};
    } else if (salario >= 1'500'001 && salario <= 2'000'000) {
        return {salario * 1.05, 5};
    } else {
        return {salario, 0};
    }
}

/**
 * Indica si un número se lee igual de izquierda a derecha y al revés.
 *
 * Entrada: numero, entero mayor o igual a 0.
 * Salida: true si el número coincide con su versión invertida; false si no.
 * Estrategia: se reutiliza invertir() y se compara con el original.
 * Restricción: los negativos siempre dan false, porque invertir() devuelve 0
 * para ellos; el 0 se considera palíndromo.
 */
bool palindromo(long long numero) {
    return numero == invertir(numero);
}

/**
 * Agrega un dígito a la derecha de un número.
 *
 * Entrada: num entero y dig, un único dígito (0 a 9).
 * Salida: long long formado por los dígitos de num seguidos de dig.
 * Estrategia: correr num un lugar decimal (num * 10) y sumar dig.
 * Restricción: con dig mayor que 9 el resultado ya no es una concatenación.
 */
long long adjunto(long long num, int dig) {
    return num * 10 + dig;
}

/**
 * Área y volumen de un toro a partir de sus dos radios.
 *
 * Entrada: a, radio interno, y b, radio externo, con b > a.
 * Salida: AreaVolumen con los campos area y volumen.
 * Estrategia: area = PI² * (b² - a²);
 * volumen = PI² * (a + b) * (b - a)² / 4.
 * Restricción: no se valida que b sea mayor que a; si no lo es, el área puede
 * salir negativa.
 */
AreaVolumen toro(double a, double b) {
    AreaVolumen resultado;
    resultado.area = std::pow(PI, 2) * (std::pow(b, 2) - std::pow(a, 2));
    resultado.volumen = std::pow(PI, 2) * (a + b) * std::pow(b - a, 2) / 4;

    return resultado;
}

/**
 * Escribe un número dígito por dígito, separados por guiones.
 *
 * Entrada: numero, entero mayor o igual a 0.
 * Salida: std::string como "dos-cero-dos-seis"; vacío si el número es 0 o
 * negativo, porque al invertirlo no queda ningún dígito que recorrer.
 * Estrategia: se invierte el número para poder extraer los dígitos desde el
 * más significativo con % 10, se traduce cada uno con NOMBRES_DIGITOS y se
 * unen los nombres con '-'.
 */
std::string numLetras2(long long numero) {
    long long invertido = invertir(numero);
    std::string resultado;

    while (invertido > 0) {
        if (!resultado.empty()) {
            resultado += '-';
        }
        resultado += NOMBRES_DIGITOS[invertido % 10];
        invertido /= 10;
    }

    return resultado;
}

// ===========================================================================
// Ejercicios pares (extra)
// ===========================================================================

/**
 * Traduce a letras un único dígito.
 *
 * Entrada: numero, entero entre 0 y 9.
 * Salida: std::optional con el nombre del dígito, o std::nullopt si está
 * fuera de ese rango (equivale al None de la versión de Python).
 * Estrategia: indexar NOMBRES_DIGITOS, que tiene un nombre por posición.
 * Restricción: no se lanza una excepción para valores inválidos.
 */
std::optional<std::string> numLetras(int numero) {
    if (numero >= 0 && numero <= 9) {
        return NOMBRES_DIGITOS[numero];
    }
    return std::nullopt;
}

/**
 * Divide un número entre 7.
 *
 * Entrada: op, número real.
 * Salida: double con op / 7.
 * Estrategia: división directa.
 */
double foo(double op) {
    return op / 7;
}

// Comprobación del orden de evaluación anidado:
// foo(14) = 14 / 7 = 2
// foo(20 + foo(7)) = (20 + 7 / 7) / 7 = (20 + 1) / 7 = 3

/**
 * Descompone una cantidad de dinero en billetes y monedas.
 *
 * Entrada: dinero, entero mayor o igual a 0 (en la moneda de la clase).
 * Salida: std::array de seis enteros con las cantidades de 100, 50, 20, 10, 5
 * y 1, en ese orden; las denominaciones que no se usan quedan en 0.
 * Estrategia: división y resto sobre cada denominación en orden descendente,
 * de modo que el resto de una división alimenta a la siguiente.
 * Restricción: con números negativos la división de C++ trunca hacia cero y
 * los restos no son los de Python, así que el resultado deja de representar
 * un desglose.
 */
std::array<long long, 6> desglose(long long dinero) {
    std::array<long long, 6> cantidades{};
    const std::array<long long, 6> denominaciones{100, 50, 20, 10, 5, 1};

    for (std::size_t i = 0; i < denominaciones.size(); ++i) {
        cantidades[i] = dinero / denominaciones[i];
        dinero %= denominaciones[i];
    }

    return cantidades;
}

/**
 * Ordena tres números de mayor a menor.
 *
 * Entrada: a, b y c, números reales en cualquier orden.
 * Salida: std::array (mayor, medio, menor).
 * Estrategia: red de comparaciones e intercambios (a-b, b-c, a-b otra vez),
 * la secuencia mínima que garantiza el orden de tres elementos.
 */
std::array<double, 3> orden(double a, double b, double c) {
    if (a < b) {
        std::swap(a, b);
    }
    if (b < c) {
        std::swap(b, c);
    }
    if (a < b) {
        std::swap(a, b);
    }

    return {a, b, c};
}

/**
 * Devuelve el cuadrado de a más 10; c no se usa para el cálculo.
 *
 * Entrada: a y c, números reales.
 * Salida: double con a² + 10.
 * Estrategia: se crea una lambda que eleva a al cuadrado, se la invoca con c
 * (el parámetro se ignora dentro del cuerpo) y al resultado se le suma 10.
 * El parámetro c existe en el ejercicio para mostrar las funciones internas,
 * no porque influya en el resultado.
 */
double misterio(double a, double c) {
    auto b = [a](double) { return a * a; };  // Captura a; ignora el argumento.
    return b(c) + 10;
}

/**
 * Calcula el salario semanal de un trabajador con horas extra.
 *
 * Entrada: horas trabajadas y tarifa por hora, reales y positivos.
 * Salida: salario total como double.
 * Estrategia: las primeras 40 horas se pagan a la tarifa base; cada hora por
 * encima de 40 se paga a la mitad de esa tarifa (0.5 * tarifa), no a 1.5.
 */
double calcSalario(double horas, double tarifa) {
    const double horas_extra = std::max(0.0, horas - 40);
    const double salario_normal = (horas - horas_extra) * tarifa;
    const double salario_extra = horas_extra * tarifa * 0.5;

    return salario_normal + salario_extra;
}

/**
 * Indica cuánto falta para terminar el día.
 *
 * Entrada: horas (0 a 23), minutos (0 a 59) y segundos (0 a 59), enteros.
 * Salida: minutos restantes hasta la medianoche, con decimales si los segundos
 * no son múltiplos de 60.
 * Estrategia: convertir todo a minutos y restarlo de los 1440 minutos del día.
 * Restricción: no se validan los rangos; valores mayores suman minutos de más.
 */
double faltante(int horas, int minutos, int segundos) {
    const double minutos_transcurridos =
        horas * 60 + minutos + static_cast<double>(segundos) / 60;

    return 1440 - minutos_transcurridos;
}

/**
 * Devuelve el dígito más significativo de un número de tres cifras.
 *
 * Entrada: num, entero entre 100 y 999.
 * Salida: std::variant con el dígito de las centenas, o con el mensaje
 * "Error en numero de entrada" si el número está fuera de rango (se conserva
 * el comportamiento pedido en clase, que devolvía un texto).
 * Estrategia: división entera entre 100.
 */
std::variant<int, std::string> significativo(int num) {
    if (num < 100 || num > 999) {
        return std::string("Error en numero de entrada");
    }
    return num / 100;
}

/**
 * Calcula el capital acumulado con interés compuesto.
 *
 * Entrada: P, capital inicial; i, interés del período en decimal (0.05 = 5%);
 * n, número de períodos.
 * Salida: double con el capital final, P * (1 + i)^n.
 * Estrategia: aplicación directa de la fórmula, sin redondeos.
 */
double interesCompuesto(double P, double i, double n) {
    return P * std::pow(1 + i, n);
}

void mostrarDesglose(const std::array<long long, 6>& cantidades) {
    std::cout << '(';
    for (std::size_t i = 0; i < cantidades.size(); ++i) {
        if (i > 0) {
            std::cout << ", ";
        }
        std::cout << cantidades[i];
    }
    std::cout << ')';
}

int main() {
    // Muestra rápida de algunas funciones.
    std::cout << std::setprecision(10);

    const ResultadoCirculo c = circulo(2);
    std::cout << "circulo(2): area=" << c.area
              << " circunferencia=" << c.circunferencia << '\n';

    const AreaVolumen e = esfera(1);
    std::cout << "esfera(1): area=" << e.area << " volumen=" << e.volumen << '\n';

    std::cout << "bisiesto(2024), bisiesto(1900): " << std::boolalpha
              << bisiesto(2024) << ' ' << bisiesto(1900) << '\n';

    std::cout << "mediano(3, 2, 1): " << mediano(3, 2, 1) << '\n';
    std::cout << "convertir(1, 3): " << convertir(1, 3) << '\n';

    const Aumento a = aumento(1'200'000);
    std::cout << "aumento(1200000): salario=" << a.salario
              << " porcentaje=" << a.porcentaje << '\n';

    std::cout << "palindromo(12321): " << std::boolalpha << palindromo(12321)
              << '\n';
    std::cout << "numLetras2(2026): " << numLetras2(2026) << '\n';

    std::cout << "desglose(388): ";
    mostrarDesglose(desglose(388));
    std::cout << '\n';

    std::cout << "calcSalario(45, 10): " << calcSalario(45, 10) << '\n';

    return 0;
}
