#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief suma dos variables
 *
 * \param float operando1
 * \param float operando2
 * \return float resultado
 *
 */
float sumar(float, float);

/** \brief resta 2 variables
 *
 * \param float operando1
 * \param float operando2
 * \return float resultado
 *
 */
float restar(float, float);

/** \brief multiplica 2 variables
 *
 * \param float operando1
 * \param float operando2
 * \return float resultado
 *
 */
float multiplicar(float, float);

/** \brief divide a la primera variable por la segunda
 *
 * \param float operando1
 * \param float operando2
 * \return float resultado
 *
 */
float dividir(float, float);

/** \brief calcula el factorial de una variable
 *
 * \param int operando
 * \return int resultado
 *
 */
int calcularFactorial(int);

/** \brief pide un numero tipo float y lo devuelve
 *
 * \param void
 * \return float dato
 *
 */
float pedirDato(void);

#endif // FUNCIONES_H_INCLUDED
