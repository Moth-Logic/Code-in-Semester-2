"""Segunda tarea de Python: una función por ejercicio.

Los ejercicios impares (1, 3, 5, ..., 21) son los que se entregaron en clase;
los pares (2, 4, 6, ..., 20) se resolvieron por cuenta propia.
Los comentarios y los nombres de variables están en español porque así lo pidió
la cátedra; el README del repositorio explica el resto.

Cada función lleva un docstring con la misma estructura:
    Entrada(s)      datos que recibe y supuestos sobre ellos
    Salida          qué devuelve, con el tipo y las claves exactas
    Estrategia      idea del algoritmo o la fórmula aplicada
    Restricción(es) lo que el código NO valida, salvo que se indique lo contrario

Contenido del archivo:
    Utilidades internas ... length, invertir
    Impares (entregados) .. 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21
    Pares (extra) ......... 2, 4, 6, 8, 10, 12, 14, 16, 18, 20
"""

PI = 3.141592653589793
NOMBRES_DIGITOS = (
    'cero', 'uno', 'dos', 'tres', 'cuatro',
    'cinco', 'seis', 'siete', 'ocho', 'nueve',
)


# ===========================================================================
# Utilidades internas
# ===========================================================================

def length(secuencia):
    """Cuenta los elementos de una secuencia sin usar len().

    Entrada: cualquier objeto iterable (str, tuple, list, ...).
    Salida: int con la cantidad de elementos.
    Estrategia: bucle for que incrementa un contador por cada elemento.
    """
    contador = 0

    for _ in secuencia:
        contador += 1

    return contador


def invertir(num):
    """Devuelve un número entero con sus dígitos en orden inverso.

    Entrada: num, entero mayor o igual a 0.
    Salida: int invertido; los ceros a la izquierda se pierden (100 -> 1).
    Estrategia: en cada iteración se toma el último dígito con % 10, se agrega
    al resultado multiplicándolo por 10, y el número se reduce con // 10.
    Restricción: con números negativos devuelve 0, porque el bucle no se ejecuta.

    Resuelve por sí sola el ejercicio 20 y sirve de apoyo a los ejercicios 15 y 21.
    """
    invertido = 0

    while num > 0:
        invertido = invertido * 10 + num % 10
        num //= 10

    return invertido


# ===========================================================================
# Ejercicios impares (entregados)
# ===========================================================================

def circulo(radio):
    """Área y circunferencia de un círculo.

    Entrada: radio, número real (no se valida que sea positivo).
    Salida: dict con claves 'Area' y 'Circunferencia', ambas en mayúscula
    inicial, a diferencia de esfera() y toro(), que usan minúsculas.
    Estrategia: area = PI * radio**2; circunferencia = 2 * PI * radio.
    """
    area = PI * radio**2
    circunferencia = 2 * PI * radio

    return {'Area': area, 'Circunferencia': circunferencia}


def esfera(radio):
    """Área superficial y volumen de una esfera.

    Entrada: radio, número real (no se valida que sea positivo).
    Salida: dict con claves 'area' y 'volumen'.
    Estrategia: area = 4 * PI * radio**2; volumen = (4/3) * PI * radio**3.
    """
    area = 4 * PI * radio**2
    volumen = 4 / 3 * PI * radio**3

    return {'area': area, 'volumen': volumen}


def bisiesto(anio):
    """Indica si un año es bisiesto.

    Entrada: anio, entero que representa un año.
    Salida: True si es divisible entre 4 y no entre 100, o si es divisible
    entre 400; False en cualquier otro caso.
    Estrategia: la regla gregoriana completa en una sola expresión booleana.
    Restricción: no se valida que el año sea positivo; los negativos dan False.
    """
    return (anio % 4 == 0 and anio % 100 != 0) or anio % 400 == 0


def mediano(a, b, c):
    """Devuelve el valor central de tres números.

    Entrada: a, b y c, números reales en cualquier orden.
    Salida: el número que queda en el medio al ordenar los tres.
    Estrategia: se comprueban los dos intervalos en los que cada número es el
    mediano; el que no cumple ninguno de los dos primeros casos es c.
    """
    if b <= a <= c or c <= a <= b:
        return a
    if a <= b <= c or c <= b <= a:
        return b
    return c


def disco(capacidad):
    """Convierte una capacidad de almacenamiento de gigabytes a bytes.

    Entrada: capacidad, número real en GB.
    Salida: float con la misma capacidad en bytes.
    Estrategia: cada GB son 1024**3 bytes, es decir 2**30.
    """
    return capacidad * 1024**3


def convertir(distancia, tipo):
    """Convierte una distancia en metros a otra unidad lineal.

    Entrada: distancia en metros (real) y tipo, entero que elige la unidad:
    1 = centímetros, 2 = pulgadas, 3 = pies, 4 = yardas.
    Salida: float con la distancia en la unidad elegida.
    Estrategia: se encadenan las conversiones (metros -> cm -> pulgadas ->
    pies -> yardas) y se devuelve la que corresponde al tipo.
    Restricción: no se valida el rango de tipo; cualquier valor distinto de
    1, 2 o 3 se interpreta como yardas.
    """
    centimetros = distancia * 100
    pulgadas = centimetros / 2.54
    pies = pulgadas / 12
    yardas = pies / 3

    if tipo == 1:
        return centimetros
    elif tipo == 2:
        return pulgadas
    elif tipo == 3:
        return pies
    else:
        return yardas


def aumento(salario):
    """Calcula el aumento de un salario según el tramo en que se encuentre.

    Entrada: salario actual, real mayor o igual a 0.
    Salida: tupla (salario_nuevo, porcentaje_aplicado) donde el porcentaje es
    20, 10, 5 o 0 según el tramo.
    Estrategia: tramos fijos de 0 a 1 000 000 (20%), de 1 000 001 a 1 500 000
    (10%), de 1 500 001 a 2 000 000 (5%) y más de 2 000 000 (sin aumento; se
    devuelve el salario intacto junto a 0).
    Restricción: no se valida el signo; un salario negativo cae en el último
    caso y se devuelve sin cambios.
    """
    if 0 <= salario <= 1_000_000:
        return (salario * 1.20, 20)
    elif 1_000_001 <= salario <= 1_500_000:
        return (salario * 1.10, 10)
    elif 1_500_001 <= salario <= 2_000_000:
        return (salario * 1.05, 5)
    else:
        return (salario, 0)


def palindromo(numero):
    """Indica si un número se lee igual de izquierda a derecha y al revés.

    Entrada: numero, entero mayor o igual a 0.
    Salida: True si el número coincide con su versión invertida; False si no.
    Estrategia: se reutiliza invertir() y se compara con el original.
    Restricción: los negativos siempre dan False, porque invertir() devuelve 0
    para ellos; el 0 se considera palíndromo.
    """
    return numero == invertir(numero)


def adjunto(num, dig):
    """Agrega un dígito a la derecha de un número.

    Entrada: num entero y dig, un único dígito (0 a 9).
    Salida: int formado por los dígitos de num seguidos de dig.
    Estrategia: correr num un lugar decimal (num * 10) y sumar dig.
    Restricción: con dig mayor que 9 el resultado ya no es una concatenación.
    """
    return num * 10 + dig


def toro(a, b):
    """Área y volumen de un toro a partir de sus dos radios.

    Entrada: a, radio interno, y b, radio externo, con b > a.
    Salida: dict con claves 'area' y 'volumen'.
    Estrategia: area = PI**2 * (b**2 - a**2);
    volumen = PI**2 * (a + b) * (b - a)**2 / 4.
    Restricción: no se valida que b sea mayor que a; si no lo es, el área puede
    salir negativa.
    """
    area = PI**2 * (b**2 - a**2)
    volumen = PI**2 * (a + b) * (b - a)**2 / 4

    return {'area': area, 'volumen': volumen}


def numLetras2(numero):
    """Escribe un número dígito por dígito, separados por guiones.

    Entrada: numero, entero mayor o igual a 0.
    Salida: str como 'dos-cero-dos-seis'; vacío si el número es 0 o negativo,
    porque al invertirlo no queda ningún dígito que recorrer.
    Estrategia: se invierte el número para poder extraer los dígitos desde el
    más significativo con % 10, se traduce cada uno con NOMBRES_DIGITOS y se
    unen los nombres con '-'.
    """
    invertido = invertir(numero)
    partes = []

    while invertido > 0:
        partes.append(NOMBRES_DIGITOS[invertido % 10])
        invertido //= 10

    return '-'.join(partes)


# ===========================================================================
# Ejercicios pares (extra)
# ===========================================================================

def numLetras(numero):
    """Traduce a letras un único dígito.

    Entrada: numero, entero entre 0 y 9.
    Salida: str con el nombre del dígito, o None si está fuera de ese rango.
    Estrategia: indexar NOMBRES_DIGITOS, que tiene un nombre por posición.
    Restricción: no se lanza una excepción para valores inválidos; se devuelve
    None, igual que hacía la versión con bucle.
    """
    if 0 <= numero <= 9:
        return NOMBRES_DIGITOS[numero]
    return None


def foo(op):
    """Divide un número entre 7.

    Entrada: op, número real.
    Salida: float con op / 7.
    Estrategia: división directa.
    """
    return op / 7


# Comprobación del orden de evaluación anidado:
# foo(14) = 14 / 7 = 2
# foo(20 + foo(7)) = (20 + 7 / 7) / 7 = (20 + 1) / 7 = 3

def desglose(dinero):
    """Descompone una cantidad de dinero en billetes y monedas.

    Entrada: dinero, entero mayor o igual a 0 (en la moneda de la clase).
    Salida: tupla de seis enteros con las cantidades de 100, 50, 20, 10, 5 y 1,
    en ese orden; las denominaciones que no se usan quedan en 0.
    Estrategia: divmod() sobre cada denominación en orden descendente, de modo
    que el resto de una división alimenta a la siguiente.
    Restricción: con números negativos divmod() devuelve restos no nulos y el
    resultado deja de representar un desglose.
    """
    cantidades = []

    for denominacion in (100, 50, 20, 10, 5, 1):
        cantidad, dinero = divmod(dinero, denominacion)
        cantidades.append(cantidad)

    return tuple(cantidades)


def orden(a, b, c):
    """Ordena tres números de mayor a menor.

    Entrada: a, b y c, números reales en cualquier orden.
    Salida: tupla (mayor, medio, menor).
    Estrategia: red de comparaciones e intercambios (a-b, b-c, a-b otra vez),
    la secuencia mínima que garantiza el orden de tres elementos.
    """
    if a < b:
        a, b = b, a
    if b < c:
        b, c = c, b
    if a < b:
        a, b = b, a

    return a, b, c


def misterio(a, c):
    """Devuelve el cuadrado de a más 10; c no se usa para el cálculo.

    Entrada: a y c, números reales.
    Salida: float o int con a**2 + 10.
    Estrategia: se crea una lambda que eleva a al cuadrado, se la invoca con c
    (el argumento x se ignora dentro del cuerpo) y al resultado se le suma 10.
    El parámetro c existe en el ejercicio para mostrar las funciones internas,
    no porque influya en el resultado.
    """
    b = lambda x: a**2  # La lambda captura a del ámbito externo e ignora x.
    d = b(c) + 10

    return d


def calcSalario(horas, tarifa):
    """Calcula el salario semanal de un trabajador con horas extra.

    Entrada: horas trabajadas y tarifa por hora, reales y positivos.
    Salida: salario total como float.
    Estrategia: las primeras 40 horas se pagan a la tarifa base; cada hora por
    encima de 40 se paga a la mitad de esa tarifa (0.5 * tarifa), no a 1.5.
    """
    horas_extra = max(0, horas - 40)
    salario_normal = (horas - horas_extra) * tarifa
    salario_extra = horas_extra * tarifa * 0.5

    return salario_normal + salario_extra


def faltante(horas, minutos, segundos):
    """Indica cuánto falta para terminar el día.

    Entrada: horas (0 a 23), minutos (0 a 59) y segundos (0 a 59), enteros.
    Salida: minutos restantes hasta la medianoche, con decimales si los segundos
    no son múltiplos de 60.
    Estrategia: convertir todo a minutos y restarlo de los 1440 minutos del día.
    Restricción: no se validan los rangos; valores mayores suman minutos de más.
    """
    minutos_transcurridos = horas * 60 + minutos + segundos / 60

    return 1440 - minutos_transcurridos


def significativo(num):
    """Devuelve el dígito más significativo de un número de tres cifras.

    Entrada: num, entero entre 100 y 999.
    Salida: el dígito de las centenas, o el str 'Error en numero de entrada' si
    el número está fuera de rango (se conserva el mensaje pedido en clase).
    Estrategia: división entera entre 100.
    """
    if num < 100 or num > 999:
        return 'Error en numero de entrada'
    return num // 100


def interesCompuesto(P, i, n):
    """Calcula el capital acumulado con interés compuesto.

    Entrada: P, capital inicial; i, interés del período en decimal (0.05 = 5%);
    n, número de períodos.
    Salida: float con el capital final, P * (1 + i)**n.
    Estrategia: aplicación directa de la fórmula, sin redondeos.
    """
    return P * (1 + i)**n


if __name__ == '__main__':
    # Muestra rápida de algunas funciones; ejecutar con: python 1stPY_HW.py
    print('circulo(2):', circulo(2))
    print('esfera(1):', esfera(1))
    print('bisiesto(2024), bisiesto(1900):', bisiesto(2024), bisiesto(1900))
    print('mediano(3, 2, 1):', mediano(3, 2, 1))
    print('convertir(1, 3):', convertir(1, 3))
    print('aumento(1200000):', aumento(1_200_000))
    print('palindromo(12321):', palindromo(12321))
    print('numLetras2(2026):', numLetras2(2026))
    print('desglose(388):', desglose(388))
    print('calcSalario(45, 10):', calcSalario(45, 10))
