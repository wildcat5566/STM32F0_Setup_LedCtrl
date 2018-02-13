# STM32F0_Setup_LedCtrl
Implemented on STM32F072C8T6.

## Hardware setup
![alt text](src/wiring.jpg)
 <br />
An STM32F429I-Discovery board (with STM32F429ZIT core) serves as flash loader. <br />
The SWD tag is connected to that of the STM32F072C8T6 as shown in diagram above. <br />
VCC of the latter should be connected to 3V3 instead of 5V, else flashing might fail. <br />
Connect the LED to pin C14. <br />
 <br />
## Software downloads
- MDK-Arm & Keil uVision <br />
We download and install MDK-Arm from official website, the Keil uVision IDE would be installed as well. <br /> 
https://www.keil.com/download/product/ <br />

## Firmware downloads
- Firmware package for stm32f0 series (cmsis, peripheral libraries, ...) <br />
http://www.st.com/en/embedded-software/stm32cubef0.html <br />

- ST-Link debugger <br />
http://www.st.com/content/st_com/en/products/development-tools/hardware-development-tools/development-tool-hardware-for-mcus/debug-hardware-for-mcus/debug-hardware-for-stm32-mcus/st-link-v2.html <br />

![alt text](src/firmware.jpg) <br />
 <br />
## Project setup
### Generate uVision Project
![alt text](src/1-1.jpg) <br />
 <br />
Here we generate a project directory, containing the uVision project file, libraries, build files, etc. <br />
>Project > New uVision Project
Create project directory > create uVision project file <br />
 <br />
 
### Select device
![alt text](src/1-2.jpg) <br />
Select corresponding device. <br />
>STMicroelectronics > STM32F072 > STM32F072C8
 <br />
 
### Categorize files
![alt text](src/2-1.jpg) <br />
>Target 1 > [Right click] > Add group
- Startup (click twice to rename 1st one): contains startup file(*.s).
- User: contains user-generated source files & header files.
- CMSIS: contains system files.
- StdPeriph: contains peripheral library includes.

### Download peripheral libraries
- Download from official website:  <br />
http://www.st.com/content/st_com/en/products/embedded-software/mcus-embedded-software/stm32-embedded-software/stm32-standard-peripheral-libraries/stsw-stm32048.html <br />

- Extract archive. <br />

![alt text](src/3-1.jpg) <br />

### Include peripheral libraries
>Archive > Libraries > copy CMSIS and STM32F0xx_StdPeriph_Driver <br />

![alt text](src/4-1.jpg) <br />

>cd Project directory > paste <br />

![alt text](src/4-2.jpg) <br />

### Add source files (*.c)
- Startup group <br />
>cp .\CMSIS\Device\ST\STM32F0xx\Source\Templates\arm\startup_stm32f072.s (project_directory) <br />
>click on 'Startup' > add existing item <br />
- User group <br />
>click on 'User' > add new item > c source file (main.c) <br />
- CMSIS group <br />
>add existing item > .\CMSIS\Device\ST\STM32F0xx\Source\Templates\system_stm32f0xx.c <br />
- StdPeriph group <br />
Here we add all required c source files in current project. <br />
For example, 'misc.c', 'rcc.c', and 'gpio.c'. <br />
>add existing item > .\STM32F0xx_StdPeriph_Driver\src\XXXX.c <br />

![alt text](src/5-1.jpg) <br />

![alt text](src/5-2.jpg) <br />

### Include conf.h
Search for 'stm32f0xx_conf.h' in ORIGINAL ARCHIVE\Projects\STM32F0xx_StdPeriph_Examples folder. <br />

![alt text](src/6-1.jpg) <br />

Copy random one as a template and paste it to StdPeriph driver subfolder of current project. <br /> 

![alt text](src/6-2.jpg) <br />

### Setup preprocessor & include paths
- Define preprocessor <br />
>Flash > Configure flash tools > [tab] C/C++ <br />
>[Prepressor symbols] Define: USE_STD_PERIPH_DRIVER <br />

![alt text](src/7-1.jpg) <br />

- Configure include paths
>[Include paths] click on [...] <br />

Set include paths as shown in following screenshot. <br />

![alt text](src/7-2.jpg) <br />

Details of each path are listed in following table:  <br />

![alt text](src/7-3.jpg) <br />

### Modify header files (*.h)
- stm32f0xx.h <br />
>stm32f0xx.h > [Right click] Properties > disable "read-only" and apply

Open stm32f0xx.h in the IDE and uncomment following (also shown in screenshot below):
>#define STM32F072 (or whichever that matches your device) <br />
>#define USE_STDPERIPH_DRIVER <br />

![alt text](src/8-1.jpg) <br />

- stm32f0xx_conf.h <br />
Open file in IDE and uncomment the header files we wish to include in our project. <br />

![alt text](src/8-2.jpg) <br />
 
### Modify target flash options
>Flash > Configure flash tools > Debug <br />
>Select ST-Link Debugger <br />
>Click on [Settings] <br />

![alt text](src/9-1.jpg) <br />

- [Debug] tab  <br />
>[Unit]: ST-LINK/V2 <br />
>[port]: SW <br />

![alt text](src/9-2.jpg) <br />

- [Flash download] tab  <br />
>[Reset and run]: enable <br />
>[Programming Algorithm]: add settings as shown in following screenshot. <br />

![alt text](src/9-3.jpg) <br />

## Run example code
Finally we can test the example code (main.c) provided in this repo. <br />
>F7 (Build target) <br />
>F8 (Download) <br />

Good luck! :)

## REFERENCES
https://www.youtube.com/watch?v=_QXoTNP9GIw <br />
http://www.electronics-homemade.com/STM32F4-SettingUp-FirstProject-stm32f4.html <br />
