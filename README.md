# Dancing Flame Lamp Reverse Enginering
**This is still a WIP document**


Product: https://www.amazon.com/gp/product/B07Z4TDPDP/ref=ox_sc_act_title_1?smid=A1CDFPK1SDU9TK&psc=1

IR Library (Must be 2.8.0): https://github.com/Arduino-IRremote/Arduino-IRremote/releases/tag/2.8.0

## IR Codes
NEC Protocol is used
|    Remote Action    	| IR Code    	|
|:-------------------:	|------------	|
| OFF                 	| 0xFFA25D   	|
| ON                  	| 0xFFE21D   	|
| FLAME               	| 0xFF906F   	|
| LAMP                	| 0xFFE01F   	|
| Repeat Last Command 	| 0xFFFFFFFF 	|