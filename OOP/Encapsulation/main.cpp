#include <iostream>
#include "Person.h"
#include "tv.h"
#include "Piggy.h"
#include "Server.h"

int main() {
	
	/*
	Person dave;
	dave.Greet();

	std::cout << "I am " << dave.getAge() << " years old." << std::endl;
	
	*/

	/*
	tv tv1;
	std::cout << (tv1.volume()) << std::endl;
	tv1.increaseVolume();
	std::cout << (tv1.volume()) << std::endl;

	std::cout << (tv1.channel()) << std::endl;
	tv1.increaseChannel();
	std::cout << (tv1.channel()) << std::endl;
	*/

	/*
	Piggy myBank;
	myBank.deposit(10.1);
	std::cout << (myBank.Balance()) << std::endl;
	myBank.deposit(220.1);
	std::cout << (myBank.Balance()) << std::endl;
	myBank.withdrawl();
	std::cout << (myBank.Balance()) << std::endl;
	*/

	ServerBrowserService myBrowser;
	ServerInfo server1 = {2, 22, 100, 200};
	ServerInfo server2 = { 2, 11, 100, 18 };
	ServerInfo server3 = { 2, 0, 100, 150 };
	ServerInfo server4 = { 2, 0, 100, 150 };
	ServerInfo server5 = { 5, 0, 100, 150 };
	
	myBrowser.registerServer(server1);
	myBrowser.registerServer(server2);
	myBrowser.registerServer(server3);
	myBrowser.registerServer(server4);
	myBrowser.registerServer(server5);

	//ServerInfo serverArray[myBrowser.serverCount];
	ServerInfo* serverArray = new ServerInfo[myBrowser.serverCount()];
	int ServerCount = myBrowser.getServers(serverArray, myBrowser.serverCount(), 5, 150,
		2, true, true);
	std::cout << "Server Count: " << ServerCount << std::endl;

	for (size_t i = 0; i < ServerCount; i++)
	{
		std::cout << "Server: " << serverArray[i].regionID << " ";
		std::cout << serverArray[i].currentPlayerCount << " ";
		std::cout << serverArray[i].maxPlayers << " ";
		std::cout << serverArray[i].ping << std::endl;
	}

	delete[] serverArray;

	return 0;

}