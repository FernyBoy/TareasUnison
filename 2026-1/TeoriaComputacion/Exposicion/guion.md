
Claro, aquí tienes un guión fluido para exponer estas diapositivas. Está pensado para que no leas exactamente todo lo que aparece en pantalla, sino que lo expliques de forma natural mientras avanzas. Me basé en las diapositivas que compartiste sobre (L_{012}), la idea de marcado con (X,Y,Z), el algoritmo, los ejemplos de aceptación y rechazo. 

---

## Guión de exposición

### Diapositiva 1: **Ejemplo final: (L_{012}) es recursivo**

“Para cerrar esta parte de la presentación, vamos a resolver un ejemplo concreto.

El lenguaje que vamos a analizar es:

[
L_{012}={0^n1^n2^n:n>0}
]

Esto significa que las cadenas válidas tienen primero cierta cantidad de ceros, después la misma cantidad de unos y finalmente la misma cantidad de doses.

Por ejemplo, cadenas como (012), (001122) o (000111222) pertenecen al lenguaje.

El ejercicio nos pide verificar que este lenguaje es recursivo. Entonces, lo que debemos demostrar es que existe una Máquina de Turing que pueda decidir este lenguaje.

Es decir, necesitamos una máquina que acepte todas las cadenas que sí tienen la forma (0^n1^n2^n), que rechace todas las cadenas que no tienen esa forma y, lo más importante, que siempre se detenga.

Si logramos describir una máquina con esas características, entonces podemos concluir que (L_{012}) es recursivo.”

---

### Diapositiva 2: **Idea de la Máquina de Turing**

“Ahora, la idea principal de la máquina es bastante intuitiva.

Una cadena pertenece a (L_{012}) si tiene la forma:

[
0^n1^n2^n
]

Esto quiere decir que por cada cero debe existir exactamente un uno y exactamente un dos.

Entonces, la Máquina de Turing puede verificar esto agrupando símbolos. La idea es tomar un cero, buscar un uno correspondiente y después buscar un dos correspondiente.

Para llevar control de los símbolos que ya fueron usados, la máquina los va marcando.

Por ejemplo, cada cero procesado se reemplaza por (X), cada uno procesado se reemplaza por (Y), y cada dos procesado se reemplaza por (Z).

Así, las marcas (X,Y,Z) no son símbolos nuevos del lenguaje original, sino una forma de que la máquina recuerde qué símbolos ya fueron emparejados.

Entonces, si al final todos los ceros, unos y doses pudieron ser marcados correctamente, la cadena pertenece al lenguaje.”

---

### Diapositiva 3: **Algoritmo de la Máquina de Turing**

“Antes de empezar a marcar símbolos, la máquina hace una primera revisión de la cadena.

Primero verifica que la cadena tenga la forma general:

[
0^+1^+2^+
]

Esto significa que deben aparecer primero uno o más ceros, después uno o más unos, y finalmente uno o más doses.

Esta revisión es importante porque no basta con que haya la misma cantidad de símbolos. También deben estar en el orden correcto.

Por ejemplo, una cadena como (010122) tiene ceros, unos y doses, pero no está ordenada correctamente, porque aparece un cero después de que ya apareció un uno.

Lo mismo pasa con (001212), donde los unos y doses están mezclados.

Y en (120), el orden está completamente incorrecto porque empieza con uno.

Entonces, si durante esta primera revisión la máquina encuentra un símbolo fuera de orden, rechaza inmediatamente.

Si la cadena sí tiene el orden correcto, entonces pasa a la etapa de marcado.”

---

### Diapositiva 4: **Marcado de símbolos**

“Después de confirmar que la cadena tiene el orden adecuado, la máquina regresa al inicio de la cinta.

A partir de ahí, empieza un proceso repetitivo.

Primero busca el primer cero que todavía no haya sido marcado. Cuando lo encuentra, lo cambia por (X).

Después se mueve hacia la derecha y busca el primer uno sin marcar. Si lo encuentra, lo cambia por (Y).

Luego sigue avanzando hacia la derecha y busca el primer dos sin marcar. Si lo encuentra, lo cambia por (Z).

Con esto, la máquina acaba de emparejar un cero con un uno y con un dos.

Después regresa nuevamente al inicio de la cinta y repite el mismo procedimiento.

La clave es que cada repetición procesa un grupo completo: un (0), un (1) y un (2).

Si en algún momento la máquina encuentra un cero, pero ya no encuentra un uno o ya no encuentra un dos disponible, entonces eso significa que las cantidades no coinciden y la cadena se rechaza.”

---

### Diapositiva 5: **Condición final de aceptación**

“Este proceso continúa hasta que la máquina ya no encuentra ceros sin marcar.

Cuando eso ocurre, la máquina no acepta inmediatamente. Todavía debe hacer una última revisión.

¿Por qué? Porque podría pasar que ya no queden ceros, pero sí queden unos o doses sin marcar.

Entonces, la máquina revisa la cinta una vez más.

Si todos los símbolos quedaron marcados, la cinta tendrá únicamente símbolos como (X), (Y) y (Z). En ese caso, significa que cada cero encontró su uno y su dos correspondiente.

Por eso, la cadena se acepta.

Pero si todavía queda algún (0), algún (1) o algún (2) sin marcar, entonces significa que hubo símbolos de más o que no se pudieron emparejar correctamente.

En ese caso, la máquina rechaza.

Esta condición final asegura que la cantidad de ceros, unos y doses era exactamente la misma.”

---

### Diapositiva 6: **Ejemplo de aceptación**

“Veamos ahora un ejemplo donde la cadena sí debe ser aceptada.

Tomemos la cadena:

[
000111222
]

Esta cadena tiene tres ceros, tres unos y tres doses, y además están en el orden correcto.

La máquina empieza marcando el primer cero, el primer uno y el primer dos. Entonces la cadena pasa de:

[
000111222
]

a:

[
X00Y11Z22
]

Aquí ya se marcó un grupo completo.

Después la máquina regresa al inicio y repite el proceso. Marca otro cero, otro uno y otro dos:

[
X00Y11Z22 \Rightarrow XX0YY1ZZ2
]

Luego repite una tercera vez:

[
XX0YY1ZZ2 \Rightarrow XXXYYYZZZ
]

En este punto ya no quedan ceros sin marcar.

Además, al hacer la revisión final, tampoco quedan unos ni doses sin marcar. Todo quedó emparejado correctamente.

Por lo tanto, la máquina acepta la cadena.

Entonces podemos decir que:

[
000111222 \in L_{012}
]”

---

### Diapositiva 7: **Ejemplo de rechazo**

“Ahora veamos un caso donde la cadena debe rechazarse.

Consideremos:

[
0011222
]

Esta cadena sí tiene el orden correcto: primero ceros, luego unos y luego doses. Pero el problema está en las cantidades.

Hay dos ceros, dos unos y tres doses.

La máquina empieza igual que antes. Marca un cero, un uno y un dos:

[
0011222 \Rightarrow X0Y1Z22
]

Después marca otro grupo completo:

[
X0Y1Z22 \Rightarrow XXYYZZ2
]

Ahora ya no quedan ceros sin marcar.

Pero cuando la máquina hace la revisión final, encuentra que todavía quedó un (2) sin marcar.

Eso significa que hay un dos extra, es decir, no existe la misma cantidad de ceros, unos y doses.

Por lo tanto, la cadena se rechaza.

Entonces:

[
0011222 \notin L_{012}
]

Este ejemplo muestra que no basta con que la cadena esté ordenada. También es necesario que las cantidades coincidan exactamente.”

---

### Cierre después de la última diapositiva

“Con estos ejemplos podemos justificar por qué (L_{012}) es recursivo.

La máquina que describimos siempre toma una decisión: acepta cuando todos los símbolos se pueden emparejar correctamente y rechaza cuando el orden es incorrecto o cuando sobran símbolos sin marcar.

Además, la máquina siempre se detiene, porque la cadena de entrada es finita y en cada repetición se marca al menos un cero. Como no puede haber infinitos ceros en una cadena finita, el proceso no puede continuar para siempre.

Por lo tanto, existe una Máquina de Turing que decide (L_{012}).

Y como existe una máquina que decide el lenguaje y siempre se detiene, concluimos que:

[
\boxed{L_{012}\text{ es un lenguaje recursivo}}
]”

---

## Versión breve para recordar mientras expones

Puedes pensarlo así:

| Diapositiva | Qué decir                                                                     |
| ----------- | ----------------------------------------------------------------------------- |
| 1           | Presentar el lenguaje y el objetivo: demostrar que es recursivo.              |
| 2           | Explicar la idea: emparejar cada (0) con un (1) y un (2).                     |
| 3           | Revisar primero que la cadena tenga el orden (0^+1^+2^+).                     |
| 4           | Explicar el marcado repetitivo con (X,Y,Z).                                   |
| 5           | Explicar cuándo acepta y cuándo rechaza al final.                             |
| 6           | Mostrar el ejemplo aceptado (000111222).                                      |
| 7           | Mostrar el ejemplo rechazado (0011222).                                       |
| Cierre      | Recalcar que la máquina siempre se detiene, por eso el lenguaje es recursivo. |