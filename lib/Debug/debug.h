 

#ifndef APP_PERIPHERALS_INC_DEBUG_H_
#define APP_PERIPHERALS_INC_DEBUG_H_
#include <Arduino.h>
#include <stdint.h>  

#define DEBUG_ENABLED             0     // ! SimpleCLI interface,  consume ~10Kb of flash

#define CLI_ENABLED                1    // ! Custom interface, consume ~4Kb of flash
 
#define DEBUG_SKETCH            Serial
#define DEBUG_BAUDRATE          115200
 
#define DEBUG_BOARD_INIT                0
#define DEBUG_CLI                       0
#define DEBUG_EnergyIC				          0
#define DEBUG_CALIB                     0
#define DEBUG_MDI                       0
#define DEBUG_PKL                       0
#define DEBUG_OFFDAY                    0
#define DEBUG_LDO_DAC  					        0 
#define DEBUG_USER_DATA 				        0
#define DEBUG_I2C_HANDLER				        0
#define DEBUG_PF_RELAYS		              0
#define DEBUG_RELAYS	                  0
#define DEBUG_UARTComm  		            0
#define DEBUG_RADIO_UART		            0
#define DEBUG_MENU					            0 
#define DEBUG_GPIOS					            0
#define DEBUG_EXT_EEPROM			          0
#define DEBUG_NVM_FLASH                 0
#define DEBUG_BUTTON                    0
#define DEBUG_RTC                       0


#define DBG_PRINTF(x, y,...)                    if(x) DEBUG_SKETCH.printf((y), ##__VA_ARGS__)
#define DBG_PRINT(x, y)                         if(x) DEBUG_SKETCH.print(y)
#define DBG_PRINTLN(x, y)                       if(x) DEBUG_SKETCH.println(y)
#define DBG_PRINTFL(x, y, z)                    if(x) DEBUG_SKETCH.println(y, z)



#if  defined(DEBUG_ENABLED) &&  DEBUG_ENABLED == 1  
#define MAXMESG  ( 200 )

#define MAXCALLBACKS        50   // The maximum number of commands   (default: 50)
#define MESSENGERBUFFERSIZE 64   // The length of the commandbuffer  (default: 64)
#define MAXSTREAMBUFFERSIZE 50  // The length of the streambuffer   (default: 64)
#define DEFAULT_TIMEOUT     5000 // Time out on unanswered messages. (default: 5s)
 

#define white_space(c) ((c) == ' ' || (c) == '\t')
#define valid_digit(c) ((c) >= '0' && (c) <= '9') 




  void debugEnergyIC_loop();
  void debugEnergyIC_SetMode(bool flag);
  bool debugEnergyIC_ReadMode();
  void debugcli_setup();
  void debugcli_process();  
  void debugCLI_Parse(String input);  
#else  
 
#endif //DEBUG_ENABLED

#if defined(CLI_ENABLED) && CLI_ENABLED == 1
 
  void cli_setup();
  void cli_loop();
#endif //DEBUG_CLI_ENABLED



#endif /* APP_PERIPHERALS_INC_DEBUG_H_ */
