import java.util.Scanner;

public class cineUniversidad {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        // Variables de entrada
        int opcion = 0, formato = 0, cantidad = 0;
        String nombre = "", respuesta = "";
        boolean estudiante = false, matinee = false, compraEnLinea = false;
        double dinero = 0;

        // Variables de salida
        String nombreFormato = "", promocion = "";
            String advertenciaGeneral = "ADVERTENCIA GENERAL: si ingresa un dato incorrecto, debera repetirlo.";

        // Variables de proceso
        double precio = 0, subtotal = 0, porcentaje = 0;
        double descuento = 0, recargo = 0, total = 0, cambio = 0;

        // Variables de validacion
        boolean datoValido;

        do {
            System.out.println("\n=== CINE UNIVERSITARIO ===");
            System.out.println("1. Comprar entradas");
            System.out.println("2. Consultar precios");
            System.out.println("3. Salir");
            System.out.print("Seleccione una opcion (1-3): ");
            respuesta = scan.nextLine().trim();
            datoValido = respuesta.matches("[1-3]");
            if (datoValido) {
                opcion = Integer.parseInt(respuesta);
            } else {
                System.out.println("Ingrese una opcion valida entre 1 y 3.");
            }
        } while (!datoValido);

        while (opcion != 3) {
            switch (opcion) {
            case 2:
                System.out.println("\n=== CONSULTAR PRECIOS ===");
                System.out.println("Lista de formatos disponibles:");
                System.out.println("1. Formato 2D - $4.00");
                System.out.println("2. Formato 3D - $6.00");
                System.out.println("3. Formato IMAX - $8.00");
                System.out.println("Promociones: estudiante 20%, grupo de 5 o mas 15%, matinee 10%.");
                System.out.println("Se aplica solo la primera promocion disponible, en ese orden.");
                System.out.println("La compra en linea agrega un recargo del 5%.");
                break;
            case 1:
                System.out.println("\n=== COMPRA DE ENTRADAS ===");
                System.out.println(advertenciaGeneral);

                do {
                    System.out.print("Ingrese su nombre: ");
                    nombre = scan.nextLine().trim();
                    if (nombre.isEmpty()) System.out.println("El nombre no puede estar vacio.");
                } while (nombre.isEmpty());

                do {
                    System.out.println("\nLista de formatos disponibles:");
                    System.out.println("1. Formato 2D - $4.00");
                    System.out.println("2. Formato 3D - $6.00");
                    System.out.println("3. Formato IMAX - $8.00");
                    System.out.print("Seleccione un formato (1-3): ");
                    respuesta = scan.nextLine().trim();
                    datoValido = respuesta.matches("[1-3]");
                    if (datoValido) formato = Integer.parseInt(respuesta);
                    else System.out.println("Ingrese un formato valido entre 1 y 3.");
                } while (!datoValido);

                do {
                    System.out.print("Cantidad de entradas (1-100): ");
                    respuesta = scan.nextLine().trim();
                    datoValido = respuesta.matches("[0-9]+")
                            && Integer.parseInt(respuesta) >= 1
                            && Integer.parseInt(respuesta) <= 100;
                    if (datoValido) cantidad = Integer.parseInt(respuesta);
                    else System.out.println("La cantidad debe estar entre 1 y 100.");
                } while (!datoValido);

                do {
                    System.out.print("Es estudiante universitario? (s/n): ");
                    respuesta = scan.nextLine().trim().toLowerCase();
                    datoValido = respuesta.equals("s") || respuesta.equals("n")
                            || respuesta.equals("si") || respuesta.equals("no");
                    if (!datoValido) System.out.println("Responda solamente s o n.");
                } while (!datoValido);
                estudiante = respuesta.equals("s") || respuesta.equals("si");

                do {
                    System.out.print("La funcion es matinee? (s/n): ");
                    respuesta = scan.nextLine().trim().toLowerCase();
                    datoValido = respuesta.equals("s") || respuesta.equals("n")
                            || respuesta.equals("si") || respuesta.equals("no");
                    if (!datoValido) System.out.println("Responda solamente s o n.");
                } while (!datoValido);
                matinee = respuesta.equals("s") || respuesta.equals("si");

                do {
                    System.out.print("Compra en linea? (s/n): ");
                    respuesta = scan.nextLine().trim().toLowerCase();
                    datoValido = respuesta.equals("s") || respuesta.equals("n")
                            || respuesta.equals("si") || respuesta.equals("no");
                    if (!datoValido) System.out.println("Responda solamente s o n.");
                } while (!datoValido);
                compraEnLinea = respuesta.equals("s") || respuesta.equals("si");

                switch (formato) {
                    case 1:
                        precio = 4.00;
                        nombreFormato = "2D";
                        break;
                    case 2:
                        precio = 6.00;
                        nombreFormato = "3D";
                        break;
                    default:
                        precio = 8.00;
                        nombreFormato = "IMAX";
                }
                subtotal = precio * cantidad;

                switch (estudiante ? 1 : cantidad >= 5 ? 2 : matinee ? 3 : 4) {
                    case 1:
                        promocion = "Estudiante (20%)";
                        porcentaje = 0.20;
                        break;
                    case 2:
                        promocion = "Grupo (15%)";
                        porcentaje = 0.15;
                        break;
                    case 3:
                        promocion = "Matinee (10%)";
                        porcentaje = 0.10;
                        break;
                    default:
                        promocion = "Sin promocion";
                        porcentaje = 0.00;
                }

                descuento = subtotal * porcentaje;
                recargo = (subtotal - descuento) * (compraEnLinea ? 0.05 : 0.00);
                total = subtotal - descuento + recargo;

                do {
                    System.out.printf("Total a pagar: $%.2f%n", total);
                    System.out.print("Dinero entregado: $");
                    respuesta = scan.nextLine().trim().replace(',', '.');
                    try {
                        dinero = Double.parseDouble(respuesta);
                        datoValido = Double.isFinite(dinero) && dinero >= total;
                    } catch (NumberFormatException error) {
                        dinero = 0;
                        datoValido = false;
                    }
                    if (!datoValido) {
                        if (dinero >= 0 && dinero < total) {
                            System.out.printf("El dinero no cubre el total. Falta: $%.2f%n", total - dinero);
                        } else {
                            System.out.println("Ingrese un monto valido.");
                        }
                    }
                } while (!datoValido);

                cambio = dinero - total;
                System.out.println("\n=== RESUMEN DE COMPRA ===");
                System.out.println("Cliente: " + nombre);
                System.out.println("Formato: " + nombreFormato);
                System.out.println("Cantidad: " + cantidad);
                System.out.printf("Precio unitario: $%.2f%n", precio);
                System.out.printf("Subtotal: $%.2f%n", subtotal);
                System.out.println("Promocion aplicada: " + promocion);
                System.out.printf("Descuento: $%.2f%n", descuento);
                System.out.printf("Recargo: $%.2f%n", recargo);
                System.out.printf("Total a pagar: $%.2f%n", total);
                System.out.printf("Cambio: $%.2f%n", cambio);
                break;
            default:
                break;
            }

            do {
                System.out.println("\n1. Comprar entradas");
                System.out.println("2. Consultar precios");
                System.out.println("3. Salir");
                System.out.print("Seleccione una opcion (1-3): ");
                respuesta = scan.nextLine().trim();
                datoValido = respuesta.matches("[1-3]");
                if (datoValido) opcion = Integer.parseInt(respuesta);
                else System.out.println("Ingrese una opcion valida entre 1 y 3.");
            } while (!datoValido);
        }

        System.out.println("Gracias por visitar el Cine Universitario.");
        scan.close();
    }
}
