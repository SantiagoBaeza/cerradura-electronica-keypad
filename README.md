[⬅️ Volver a "Arduino"](https://github.com/SantiagoBaeza/-Portfolio-de-proyectos-Arduino-Embebidos)
# Cerradura electrónica con teclado 4x4 y pantalla LCD

Simulación de una cerradura electrónica usando Arduino UNO, teclado matricial 4x4 y display LCD 16x2.  
Proyecto realizado en Tinkercad.

---

## Vista del circuito

![imagen](https://github.com/SantiagoBaeza/cerradura-electronica-keypad/blob/main/cerradura%20electronica%20.jpg)

---

## Objetivo

Permitir el acceso solo a quienes ingresen el código correcto desde el teclado. Al ingresar "*", el sistema solicita una clave de 4 dígitos y la compara con la contraseña establecida (`3519`).

---

## Componentes utilizados

- Arduino UNO
- Teclado matricial 4x4
- Pantalla LCD 16x2
- Potenciómetro (para contraste del LCD)
- LEDs (simulan pestillo o estados)
- Resistencias
- Protoboard y cables

---

## Funcionalidad

- ✅ Muestra mensaje inicial en LCD
- ✅ Al presionar `*`, solicita ingreso de clave
- ✅ Si la clave es correcta (`3519`), activa la salida (LED o pestillo simulado)
- ❌ Si es incorrecta, deniega el acceso y lo indica en pantalla

---

## Lógica implementada

- Uso de librerías `Keypad.h` y `LiquidCrystal.h`
- Manejo de `String` para construir la clave
- Lógica de control con condicionales
- Lectura por polling del teclado matricial
- Interacción visual con usuario (pantalla LCD)

---

## Código fuente

El archivo principal es: https://github.com/SantiagoBaeza/cerradura-electronica-keypad/blob/main/cerradura_electronica_1.ino  
Escrito en C++ para Arduino con estructura sencilla, sin comentarios.

---

## Simulación en Tinkercad

> https://www.tinkercad.com/things/dqUuVWItVk6-cerradura-electronica-

