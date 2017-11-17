#ifndef __CONFIG_ZYNQ_MICROZED_CRYPTOTRONIX_H
#define __CONFIG_ZYNQ_MICROZED_CRYPTOTRONIX_H

/* Define ZYBO Z7 PS Clock Frequency to 33.3333MHz */
#define CONFIG_ZYNQ_PS_CLK_FREQ 33333333UL

#define CONFIG_EXTRA_ENV_SETTINGS   \
    "autoload=no\0" \
    "serverip=192.168.1.200\0" \
    "ethaddr=00:0a:35:00:01:22\0"   \
    "fit_load_address=0x2080000\0" \
    "fit_image=image.fit\0" \
    "sdboot=if mmcinfo; then " \
            "echo Copying Linux from SD to RAM... && " \
            "load mmc 0 ${kernel_load_address} ${kernel_image} && " \
            "load mmc 0 ${devicetree_load_address} ${devicetree_image} && " \
            "load mmc 0 ${ramdisk_load_address} ${ramdisk_image} && " \
            "bootm ${kernel_load_address} ${ramdisk_load_address} ${devicetree_load_address}; " \
        "fi\0" \
    "tftpboot=echo TFTPing FIT to RAM... && " \
        "dhcp && " \
        "tftpboot ${fit_load_address} ${fit_image} && " \
        "bootm ${fit_load_address}\0" \
        DFU_ALT_INFO

#include <configs/zynq-common.h>

#undef CONFIG_BOOTCOMMAND                   
#define CONFIG_BOOTCOMMAND "run tftpboot"

#endif /* __CONFIG_ZYNQ_MICROZED_CRYPTOTRONIX_H */
