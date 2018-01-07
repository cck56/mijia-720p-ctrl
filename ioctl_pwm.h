#ifndef _FTPWMTMR010_API_H_
#define _FTPWMTMR010_API_H_

#include <linux/ioctl.h>

//============================================================================
// data struct
//============================================================================

enum pwm_set_mode {
	PWM_ONESHOT,
	PWM_INTERVAL,
	PWM_REPEAT,
	PWM_PATTERN,
};
typedef struct pwm_info {
	unsigned int id;
	unsigned int clksrc;
	enum pwm_set_mode mode;
	unsigned int freq;
	unsigned int duty_steps;
	unsigned int duty_ratio;
	unsigned int pattern[4];
	int intr_cnt;
	unsigned short repeat_cnt;
	unsigned char pattern_len;
} pwm_info_t;

//============================================================================
// I/O control ID
//============================================================================
/* Use 'p' as magic number */
#define PWM_IOC_MAGIC			'p'
#define PWM_IOCTL_REQUEST		_IOW(PWM_IOC_MAGIC, 1, int)
#define PWM_IOCTL_START			_IOW(PWM_IOC_MAGIC, 2, int)
#define PWM_IOCTL_STOP			_IOW(PWM_IOC_MAGIC, 3, int)
#define PWM_IOCTL_GET_INFO		_IOWR(PWM_IOC_MAGIC, 4, pwm_info_t)
#define PWM_IOCTL_SET_CLKSRC		_IOW(PWM_IOC_MAGIC, 5, pwm_info_t)
#define PWM_IOCTL_SET_FREQ		_IOW(PWM_IOC_MAGIC, 6, pwm_info_t)
#define PWM_IOCTL_SET_DUTY_STEPS	_IOW(PWM_IOC_MAGIC, 7, pwm_info_t)
#define PWM_IOCTL_SET_DUTY_RATIO	_IOW(PWM_IOC_MAGIC, 8, pwm_info_t)
#define PWM_IOCTL_SET_MODE		_IOW(PWM_IOC_MAGIC, 9, pwm_info_t)
#define PWM_IOCTL_ENABLE_INTERRUPT	_IOW(PWM_IOC_MAGIC, 10, int)
#define PWM_IOCTL_DISABLE_INTERRUPT	_IOW(PWM_IOC_MAGIC, 11, int)
#define PWM_IOCTL_ALL_START		_IO(PWM_IOC_MAGIC, 12)
#define PWM_IOCTL_ALL_STOP		_IO(PWM_IOC_MAGIC, 13)
#define PWM_IOCTL_UPDATE		_IOW(PWM_IOC_MAGIC, 14, int)
#define PWM_IOCTL_ALL_UPDATE		_IO(PWM_IOC_MAGIC, 15)
#define PWM_IOCTL_RELEASE		_IOW(PWM_IOC_MAGIC, 16, int)
#define PWM_IOC_MAXNR			16

#endif /*_FTPWMTMR010_API_H_*/
