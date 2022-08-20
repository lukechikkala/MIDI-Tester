#include <iostream>
#include <windows.h>
#include "prints.h"
#include "userinputs.h"
#include "execute.h"

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

int Run()
{
	int				userinput_note,
					userinput_velocity_1,
					userinput_velocity_2;

	std::string		userinput_device,
					cmd;

	Title();
	userinput_device		= Get_Device_List();
	userinput_note			= Get_Note();
	userinput_velocity_1	= Get_Velocity_1();
	userinput_velocity_2	= Get_Velocity_2();

	Execute(userinput_device, userinput_note, userinput_velocity_1, userinput_velocity_2);
}