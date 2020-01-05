#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/gpio.h>
#include <linux/delay.h>

#define DRIVER_AUTHOR "Johnson Chiang"
#define DRIVER_DESC "RPi GPIO"
#define GPIO_PIN11 17
#define GPIO_DESC "GPIO17"
#define GPIO_DEVICE_DESC "GPIO17_Output"
#define BCM2835_BASE 0x3f000000
#define GPIO_OFFSET 0x200000


MODULE_LICENSE("GPL");
//MODULE_AUTHOR(DRIVER_AUTHOR)
//MODULE_DESCRIPTION(DRIVER_DESC)

int gpio_init(void){
	int i = 0;
	printk(KERN_NOTICE "GPIO init");
	if(gpio_request(GPIO_PIN11, GPIO_DESC)){
		printk("[%s] Request fail\n", GPIO_DESC);
		return -EIO;
	}
	printk(KERN_ALERT "[%s] Request Pin%d ... Success. \n",GPIO_DESC, GPIO_PIN11);
//	while(1){
		gpio_direction_output(GPIO_PIN11, 1);
//		msleep(1000);
//		gpio_direction_output(GPIO_PIN11, 0);
//		msleep(1000);
//		i++;
//		if(i == 10)
//			break;
//	}
	return 0;
}

void gpio_exit(void){
	printk("GPIO exit");
	gpio_direction_output(GPIO_PIN11, 0);
	gpio_free(GPIO_PIN11);
}

module_init(gpio_init);
module_exit(gpio_exit);
