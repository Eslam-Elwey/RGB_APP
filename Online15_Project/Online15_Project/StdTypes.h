
#ifndef STDTYPES_H_
#define STDTYPES_H_

typedef unsigned char  u8;
typedef signed char  s8;

typedef unsigned int u16;
typedef signed int s16;

typedef unsigned long u32;
typedef signed long  s32;

#define NULLPTR  ((void*)0)

typedef enum{
	FALSE,
	TRUE
}bool_t;

typedef enum{
	OK,
	NOK,
	NULL_PTR,
	OUT_OF_RANGE
}error_t;

#define MAX_U8   ((u8)255)
#define MIN_U8   ((u8)0)

#define MAX_S8   ((s8)127)
#define MIN_S8   ((s8)-128)
#define ZERO_S8   ((s8)0)

#define MAX_U16   ((u16)65535)
#define MIN_U16   ((u16)0)

#define MAX_S16   ((s16)32767)
#define MIN_S16  ((s16)-32768)


#endif /* STDTYPES_H_ */