// SPDX-License-Identifier: MIT

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/utsname.h>
#include <linux/timekeeping.h>
#include <linux/moduleparam.h>

static int mivar = 10;
static time64_t tstamp;

static int __init helloworld_init(void)
{
	tstamp = ktime_get_seconds();
	pr_info("Hola Mundo! Estas usando Linux version %s. Numero ingresado: %d\n", utsname()->release, mivar);
	return 0;
}

static void __exit helloworld_exit(void)
{
	pr_info("Fin del mundo. Tiempo activo del modulo: %d segundos\n", (int)(ktime_get_seconds() - tstamp));
}

module_init(helloworld_init);
module_exit(helloworld_exit);
module_param(mivar, int, 0660);

MODULE_AUTHOR("Lucas Constantino");
MODULE_LICENSE("GPL");
MODULE_PARM_DESC(mivar, "Un numero entero cualquiera");
