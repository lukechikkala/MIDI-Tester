void Execute(std::string device, int note, int velocity_1, int velocity_2)
{
	std::string cmd_on, cmd_off;

	int			packet_on_count		= 0,
				packet_off_count	= 0;

	std::cout << NC << std::endl;
	cmd_on	= "sendmidi.exe dev " + device + " on " + std::to_string(note) + " " + std::to_string(velocity_1);
	cmd_off	= "sendmidi.exe dev " + device + " off " + std::to_string(note) + " " + std::to_string(velocity_2);

	while ( true )
	{
		system("cls");
		Title();
		std::cout << NC "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"	<< std::endl;
		std::cout << "Device		: " << device		<< std::endl;
		std::cout << "Note		: "		<< note			<< std::endl;
		packet_on_count = packet_on_count + 1;
		std::cout << "Velocity On	: " << GRN << velocity_1 << NC << std::endl;
		system(cmd_on.c_str());
		Sleep(1000);

		system("cls");
		Title();
		std::cout << NC "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"	<< std::endl;
		std::cout << "Device		: " << device		<< std::endl;
		std::cout << "Note		: "		<< note			<< std::endl;
		packet_off_count = packet_off_count + 1;
		std::cout << "Velocity Off	: " << RED << velocity_2 << NC << std::endl;
		system(cmd_off.c_str());
		Sleep(1000);
	}
}