#ifndef _SUBMARINE_H_
#define _SUBMARINE_H_

#define SUCCESS	0
#define FAILURE	-1

#define IOC_MAGIC1  's'
#define IOC_MAGIC2  'r'

#define BUF_LEN 1024

#define IOCTL_SET_CHAR _IOW(IOC_MAGIC1, 1, int)
#define IOCTL_GET_CHAR _IOW(IOC_MAGIC2, 1, int)

#endif
