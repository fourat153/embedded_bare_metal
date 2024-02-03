
#ifndef __platform_type_H__
#define __platform_type_H__
// Unsigned integer data types
typedef unsigned char               uint8_t;
typedef unsigned short              uint16_t;
typedef unsigned int                uint32;
typedef unsigned long long int      uint64_t;

// Signed integer data types
typedef signed char                 sint8_t;
typedef signed short                sint16_t;
typedef signed int                  sint32_t;
typedef signed long long int        sint64_t;

// volatile unsigned integer data types
typedef volatile unsigned char              vuint8_t;
typedef volatile unsigned short             vuint16_t;
typedef volatile unsigned int               vuint32;
typedef volatile unsigned long long int     vuint64_t;

// volatile signed integer data types
typedef volatile signed char                vsint8_t;
typedef volatile signed short               vsint16_t;
typedef volatile signed int                 vsint32_t;
typedef volatile signed long long int       vsint64_t;

// Float data types
typedef float       float32;
typedef double      float64;

// Boolean date types
typedef enum
{
	false,
	ture,
}bool;

// Error types which used in ErrorIndication Function in any Default Case in Switch
typedef enum
{
	InvalidArgument,    //in any configuration to Pins or Ports
	OverFlow            //in any configuration to LEDs For Example
}ErrorType;

#define NULL ((void *)0)
#endif