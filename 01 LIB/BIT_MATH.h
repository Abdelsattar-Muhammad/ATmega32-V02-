/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 20 Feb 2024             */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(Reg,BitN)        Reg |= (1U<<BitN)

#define CLR_BIT(Reg,BitN)        Reg &= (~(1U<<BitN))

#define TOGGLE_BIT(Reg,BitN)     Reg ^= (1U<<BitN)

#define GET_BIT(Reg,BitN)       ((Reg>>BitN)&1U)

#endif /* BIT_MATH_H_ */