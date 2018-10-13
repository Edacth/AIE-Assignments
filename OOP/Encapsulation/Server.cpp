#include "Server.h"
#include <iostream>

bool ServerBrowserService::registerServer(ServerInfo newServer)
{
	if (currentServerCount <= 50)
	{
		servers[currentServerCount].regionID = newServer.regionID;
		servers[currentServerCount].currentPlayerCount = newServer.currentPlayerCount;
		servers[currentServerCount].maxPlayers = newServer.maxPlayers;
		servers[currentServerCount].ping = newServer.ping;
		currentServerCount++;
		return true;
	}
	return false;
}

int ServerBrowserService::getServers(ServerInfo *dstArray, size_t dstSize, int maxResults,
	int pingLimit, int regionSpecifier, bool allowEmpty, bool allowFull)
{
	int totalServers = 0;
	int j = 0;
	for (int i = 0; i < dstSize; i++)
	{
		
			if (servers[i].ping <= pingLimit && servers[i].regionID == regionSpecifier)
			{
				dstArray[j].regionID = servers[i].regionID;
				dstArray[j].currentPlayerCount = servers[i].currentPlayerCount;
				dstArray[j].maxPlayers = servers[i].maxPlayers;
				dstArray[j].ping = servers[i].ping;
				totalServers++;
				j++;
				if (totalServers >= maxResults)
				{
					break;
				}
			

		}
		
		
		

		
	}
	return totalServers;
}

int ServerBrowserService::serverCount()
{
	return currentServerCount;
}

bool checkPing()
{

}