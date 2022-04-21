# Proyecto1-DatosII-Target-Oh
 
	Problemas o bugs encontrados

◆Algunas veces al hacer falta una pareja a completar puede que las imágenes no coincidan, haciendo así que el juego no se pueda finalizar por este método.
◆Si se presiona la ventaja de disminuir el tiempo cuando este es inferior a 15 segundos el timer se bugea y muestra un tiempo erróneo.
◆Error con los métodos remove() y erase() para eliminar los targets e images del array causaban problemas de duplicación , “index out of range” , eliminación incorrecta y más . (solucionado) 
◆Error al enviar datos sobre el update del estado actual del juego en el server-socket.
◆Juego no compila debido a varios bugs de manejo de información entre cliente-servidor.
◆Al eliminar las imágenes del array estas no se actualizan correctamente, por lo que en pocas ocasiones se puede presentar en el tablero una imagen de una ya pareja encontrada.
◆En ciertas partes se repite código, por ende, hace que el programa sea menos eficiente, esto se podría solucionar mediante condiciones o bucles.
◆Algunos punteros no mandaban la señal esperada, por ende, se veían errores dentro de la ejecución (solucionado)
◆Al finalizar el juego el restart game no genera de nuevo las imágenes, por ende, al clickear una tarjeta esta aparece sin background (solucionado)
