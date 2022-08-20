#include <iostream>
#include <fstream>
#include <regex>

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

std::string Get_Device_List()
{
	std::fstream	Temp_MIDI_Device_List;

	std::string		line,
					Available_MIDI_Devices,
					Selected_MIDI_Device,
					MIDI_Devices[10];

	std::regex		RegularExpression(" .*");
	
	int				i,
					MIDI_ID,
					selected_interface;

	system("sendmidi.exe dev list > MIDI_Devices.txt");

	MIDI_ID = 1;

	Temp_MIDI_Device_List.open("MIDI_Devices.txt", std::ios::in);
	if ( Temp_MIDI_Device_List.is_open() )
	{
		while(getline(Temp_MIDI_Device_List, line))
		{
			Available_MIDI_Devices	= line;
			MIDI_Devices[MIDI_ID]	= Available_MIDI_Devices;
			MIDI_ID					= MIDI_ID + 1;
		}
		Temp_MIDI_Device_List.close();
	}

	system("del MIDI_Devices.txt");

	std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"	<< std::endl;
	std::cout << "\tAvailable MIDI Interfaces:" << std::endl;
	std::cout << "\t━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;
	for ( i = 1 ; i < MIDI_ID ; i++ )
		std::cout << "\t[" << i << "]\t" << MIDI_Devices[i] << std::endl;

	std::cout << "\nSelect MIDI Interface\t: " GRN;
	std::cin  >> selected_interface;
	Selected_MIDI_Device = std::regex_replace( MIDI_Devices[selected_interface] , RegularExpression, "");
	return Selected_MIDI_Device;
}

int Get_Note()
{
	int		Note;

	std::cout << NC "Set Note		: " GRN;
	std::cin  >> Note;

	if ( Note > 127 || Note < 0 )
	{
		std::cout << "Note value must be between 0 - 127" << std::endl;
		return Get_Note();
	}
	else if ( Note < 128 || Note > 0 )
	{
		return Note;
	}
	else
	{
		std::cout << "ERROR" << std::endl;
	}

}

int Get_Velocity_1()
{
	int		Velocity;

	std::cout << NC "Set Velocity On		: " GRN;
	std::cin  >> Velocity;

	if ( Velocity > 127 || Velocity < 0 )
	{
		std::cout << "Velocity value must be between 0 - 127" << std::endl;
		return Get_Velocity_1();
	}
	else if ( Velocity < 128 || Velocity > 0 )
	{
		return Velocity;
	}
	else
	{
		std::cout << "ERROR" << std::endl;
	}
}

int Get_Velocity_2()
{
	int		Velocity;

	std::cout << NC "Set Velocity Off	: " GRN;
	std::cin  >> Velocity;

	if ( Velocity > 127 || Velocity < -1 )
	{
		std::cout << NC "Velocity value must be between 0 - 127" << std::endl;
		return Get_Velocity_2();
	}
	else if ( Velocity < 128 || Velocity > -1 )
	{
		return Velocity;
	}
	else
	{
		std::cout << "ERROR" << std::endl;
	}

	std::cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"	<< std::endl;
}