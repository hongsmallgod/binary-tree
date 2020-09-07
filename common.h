#ifndef _COMMON_H
#define _COMMON_H

/*
** 定义在linux/kernel.h中
** #define ARRAY_SIZE(arr) (sizeof(arr)/sizeof((arr)[0]) + __must_be_array(arr))
** __must_be_array(arr))作用：宏定义防止被误用，应该用在数组而不是指针上
*/
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])

#endif
