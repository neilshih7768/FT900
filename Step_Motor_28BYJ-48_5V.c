/**
  @file
  @brief
  GPIO Example 1

  Toggle a pin on and off.
*/
/*
 * ============================================================================
 * History
 * =======
 * 19 Nov 2014 : Created
 *
 * (C) Copyright 2016, Future Technology Devices International Ltd.
 * ============================================================================
 *
 * This source code ("the Software") is provided by Future Technology Devices
 * International Limited ("FTDI") subject to the licence terms set out
 * http://www.ftdichip.com/FTSourceCodeLicenceTerms.htm ("the Licence Terms").
 * You must read the Licence Terms before downloading or using the Software.
 * By installing or using the Software you agree to the Licence Terms. If you
 * do not agree to the Licence Terms then do not download or use the Software.
 *
 * Without prejudice to the Licence Terms, here is a summary of some of the key
 * terms of the Licence Terms (and in the event of any conflict between this
 * summary and the Licence Terms then the text of the Licence Terms will
 * prevail).
 *
 * The Software is provided "as is".
 * There are no warranties (or similar) in relation to the quality of the
 * Software. You use it at your own risk.
 * The Software should not be used in, or for, any medical device, system or
 * appliance. There are exclusions of FTDI liability for certain types of loss
 * such as: special loss or damage; incidental loss or damage; indirect or
 * consequential loss or damage; loss of income; loss of business; loss of
 * profits; loss of revenue; loss of contracts; business interruption; loss of
 * the use of money or anticipated savings; loss of information; loss of
 * opportunity; loss of goodwill or reputation; and/or loss of, damage to or
 * corruption of data.
 * There is a monetary cap on FTDI's liability.
 * The Software may have subsequently been amended by another user and then
 * distributed by that other user ("Adapted Software").  If so that user may
 * have additional licence terms that apply to those amendments. However, FTDI
 * has no liability in relation to those amendments.
 * ============================================================================
 */

#include <stdio.h>
#include <stdint.h>
#include <ft900.h>

#define STR(a) STR_(a)
#define STR_(a) #a

#define GPIO_PIN_13 13
#define GPIO_PIN_15 15
#define GPIO_PIN_17 17
#define GPIO_PIN_18 18

void setup(void);
void loop(void);
int _step = 0;
bool dir = true;

int main(void)
{
    setup();
    loop();
    return 0;
}

void setup()
{
    /* Set up the pin */
    gpio_dir(GPIO_PIN_13, pad_dir_output);
    gpio_dir(GPIO_PIN_15, pad_dir_output);
    gpio_dir(GPIO_PIN_17, pad_dir_output);
    gpio_dir(GPIO_PIN_18, pad_dir_output);

    gpio_pull(GPIO_PIN_13, pad_pull_none);
    gpio_pull(GPIO_PIN_15, pad_pull_none);
    gpio_pull(GPIO_PIN_17, pad_pull_none);
    gpio_pull(GPIO_PIN_18, pad_pull_none);
}

void loop()
{
	switch(_step){
		case 0:
			gpio_write(GPIO_PIN_13, 0);
			gpio_write(GPIO_PIN_15, 0);
			gpio_write(GPIO_PIN_17, 0);
			gpio_write(GPIO_PIN_18, 1);
			break;
		case 1:
			gpio_write(GPIO_PIN_13, 0);
			gpio_write(GPIO_PIN_15, 0);
			gpio_write(GPIO_PIN_17, 1);
			gpio_write(GPIO_PIN_18, 1);
			break;
		case 2:
			gpio_write(GPIO_PIN_13, 0);
			gpio_write(GPIO_PIN_15, 0);
			gpio_write(GPIO_PIN_17, 1);
			gpio_write(GPIO_PIN_18, 0);
			break;
		case 3:
			gpio_write(GPIO_PIN_13, 0);
			gpio_write(GPIO_PIN_15, 1);
			gpio_write(GPIO_PIN_17, 1);
			gpio_write(GPIO_PIN_18, 0);
			break;
		case 4:
			gpio_write(GPIO_PIN_13, 0);
			gpio_write(GPIO_PIN_15, 1);
			gpio_write(GPIO_PIN_17, 0);
			gpio_write(GPIO_PIN_18, 0);
			break;
		case 5:
			gpio_write(GPIO_PIN_13, 1);
			gpio_write(GPIO_PIN_15, 1);
			gpio_write(GPIO_PIN_17, 0);
			gpio_write(GPIO_PIN_18, 0);
			break;
		case 6:
			gpio_write(GPIO_PIN_13, 1);
			gpio_write(GPIO_PIN_15, 0);
			gpio_write(GPIO_PIN_17, 0);
			gpio_write(GPIO_PIN_18, 0);
			break;
		case 7:
			gpio_write(GPIO_PIN_13, 1);
			gpio_write(GPIO_PIN_15, 0);
			gpio_write(GPIO_PIN_17, 0);
			gpio_write(GPIO_PIN_18, 1);
			break;
		default:
			gpio_write(GPIO_PIN_13, 0);
			gpio_write(GPIO_PIN_15, 0);
			gpio_write(GPIO_PIN_17, 0);
			gpio_write(GPIO_PIN_18, 0);
			break;
	 }

	 if(dir){
	   _step++;
	 }
	 else{
	   _step--;
	 }
	 if(_step > 7){
	   _step = 0;
	 }
	 if(_step < 0){
	   _step = 7;
	 }

	 //delayms(1);
	 printf("_step = %d\n", _step);
}
