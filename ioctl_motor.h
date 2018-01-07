#ifndef _IOCTL_MOTOR_H_
#define _IOCTL_MOTOR_H_

#include <linux/ioctl.h>

//============================================================================
// data struct
//============================================================================

//============================================================================
// I/O control ID
//============================================================================
/* Use 'M' as magic number */
#define MOTOR_IOC_MAGIC			'M'
#define MOTOR_IOCTL_H_SET_DIR   _IOW(MOTOR_IOC_MAGIC, 3, int)
#define MOTOR_IOCTL_H_MOVE_REL  _IOW(MOTOR_IOC_MAGIC, 4, int)
#define MOTOR_IOCTL_H_GET_POS   _IOW(MOTOR_IOC_MAGIC, 5, int)
#define MOTOR_IOCTL_H_SET_POS   _IOW(MOTOR_IOC_MAGIC, 6, int)
#define MOTOR_IOCTL_V_SET_DIR   _IOW(MOTOR_IOC_MAGIC, 23, int)
#define MOTOR_IOCTL_V_MOVE_REL  _IOW(MOTOR_IOC_MAGIC, 24, int)
#define MOTOR_IOCTL_V_GET_POS   _IOW(MOTOR_IOC_MAGIC, 25, int)
#define MOTOR_IOCTL_V_SET_POS   _IOW(MOTOR_IOC_MAGIC, 26, int)


#endif /*_IOCTL_MOTOR_H_*/
