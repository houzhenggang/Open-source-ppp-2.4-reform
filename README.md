# Open-source-ppp-2.4-reform
开源ppp优化改造，增加网络带宽

本代码是对开源ppp-2.4.4版本进行改造，改造原因如下:
1. 原始ppp源码中满篇幅的全局变量，一个通道对应一份全局变量，不利于阅读。
2. 原有代码没起一个通道来利用带宽都需要起一个进程，如果要使用32通道，则需要启动进程32次，使用及其不便，启动方法如下:
	pppd -detach debug crtscts lock 31.1.1.2:1.1.1.1 /dev/ttyS0 115200
	pppd -detach debug crtscts lock 13.1.1.1:1.1.1.2 /dev/ttyS1 115200
	......
	pppd -detach debug crtscts lock 31.1.1.1:1.1.1.2 /dev/ttyS16 115200
3. 原始代码使用tty设备传输数据包，传输距离短。同时带宽不够。


改造后结果:
1. 改造代码，利用结构封装之前的全局变量配置，使得可以一个接口通道一份配置，有利于阅读。
2. 只需要启动一次进程就可以利用所有ppp功能，无需为每个接口通道启动一个进程。
3. 配置方式增加网络接口配置
4. 配置方式同时支持cli在线配置以及配置文件配置，利用cli功能，可以实时查看系统运行过程中内存参数信息，有利于代码诊断。
5. 改造后的ppp能更加快速实习LCP IPCP协商，以及CHAP PAP认真。
5. 改造内核PPP模块，使其从原有的tty设备发送数据包，改造为从网络接口利用TCP/IP内核网络协议栈发送数据包，从而利用网卡接口的带宽特性，
   实时更加网络带宽。配置方便，使用灵活。
6. 改造后的代码从串口设备变成了TCP/IP网络协议栈对应的网络接口，可以通过cli或者网络接口配置使原始PPP接口链路带宽由2M，快速增加到实际需要的64M。
   如果还需要继续增加带宽(超过64M)，只需要修改接口宏定义即可。


注：本改造代码只是把主要功能该站点提取出来，由于部分内容涉密，所以涉密部分内容的源码已经剔除，但是本份代码能够结合原始PPP源码，能够快速查看到
    改造点，不影响阅读。 该改造代码的原始PPP版本是2.4.4，相关头文件等可以参考原始版本