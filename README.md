# 2025D_Freertos_LVGL



2026.3.21.19

**ADC_DMA_TIM** 参考：  [STM32HAL ADC+TIM+DMA采集交流信号 基于cubemx_tim+adc+dma-CSDN博客](https://blog.csdn.net/qq_34022877/article/details/121941236)

3.28：

使用可视化工具进行设计LVGL的界面，再把界面工程移植回STM32    

工具：1.[GUI Guider | NXP 半导体](https://www.nxp.com.cn/design/design-center/software/development-software/gui-guider:GUI-GUIDER) 

2. [最新发布 | anyui](https://anyui.tech/zh/release/release-latest.html)

推荐用第一个，资料多点



3.29：

LVGL界面基本设置完成，与32通信基本完善。

DDS还没加进去。试了一下电阻分压测电阻值，不太准。

衰减，线长还没试。



4.11

加进去了dds9834，可产生30MHz的正弦波。

加入了读取内部flash，碰到的问题：代码存在 Flash 里，擦除操作**把程序自己给删了**。第一次能跑是因为烧录后直接运行，复位后 CPU 找不到代码就死机了。解决办法：把测试地址改到 Flash **最后面的扇区**，离代码区远一点。

发现STM32F407VET6的内部flash只有512k，我的代码就占了349k，有六个片区，第六个片区占了256k，所以，要想在flash里面读写数据就得压缩程序，可是这样可能会阉割功能，所以放弃在内部flash里面读写数据。

4.12

画了块板子，加了AT24C和W25Q,程序加进去了，还加了5933，但是都没测试。
