/*****************************************/
/* Author  : Mohamed Abdel Hamid         */
/* Date    : 14 / 9 / 2023               */
/* Version : V02                         */
/*****************************************/
#ifndef STD_TYPES_H
#define STD_TYPES_H

/* unsigned */
typedef unsigned char            u8  ;
typedef unsigned short int       u16 ;
typedef unsigned long int        u32 ;

typedef unsigned long int*    	 pu32;

/* signed */
typedef signed char              s8  ;
typedef signed short int         s16 ;
typedef signed long int          s32 ;

/* Floating Point */
/*  Float Type  */

typedef float               f32;
typedef double              f64;
typedef long double         f128;


/* Init Func */
#define NULL		(void * )0
#endif
