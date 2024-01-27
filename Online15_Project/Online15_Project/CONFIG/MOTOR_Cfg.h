
#ifndef MOTOR_CFG_H_
#define MOTOR_CFG_H_
#include "MOTOR_Int.h"

#define TOTAL_MOTORS				4

static const motor_control_t motor_arr[TOTAL_MOTORS] = {{PINB0,PINB1},
														{PINB2,PINB3},
														{PINB4,PINB5},
														{PINB6,PINB7}
														};



#endif /* MOTOR_CFG_H_ */