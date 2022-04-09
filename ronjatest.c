#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

MODULE_AUTHOR("Ronja Koistinen <ronja.koistinen@kapsi.fi>");
MODULE_DESCRIPTION("Demo module");
MODULE_LICENSE("GPL");

static char *init_message = "Hello!";
static char *exit_message = "Goodbye!";

module_param(init_message, charp, 0444);
module_param(exit_message, charp, 0444);

static int __init demo_init(void)
{
    printk(KERN_INFO "Module says: %s\n", init_message);
    return 0;
}

static void __exit demo_exit(void)
{
    printk(KERN_INFO "Module says: %s\n", exit_message);
}

module_init(demo_init);
module_exit(demo_exit);
