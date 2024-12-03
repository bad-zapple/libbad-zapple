#ifndef MSGHELPERCLIENT_HPP
# define MSGHELPERCLIENT_HPP

class SocketW;
class CellContent; /* Depends on World implementation */
class InventoryContent; /* Depends on Player implementation */

# include <string>

class MsgServerClient
{
		public:
	static int Welcome(SocketW& client);
	static int Result(SocketW& client, bool state);
	static int See(SocketW& client, const CellContent& content); /* Should probably be a vector of CellContent */
	static int Inventory(SocketW& client, const InventoryContent& inventory);
	static int IncantationStart(SocketW& client);
	static int IncantationDone(SocketW& client, unsigned int level);
	static int TeamCount(SocketW& client, int teamClients);
	static int WorldSize(SocketW& client, unsigned int width, unsigned int height);
	static int Death(SocketW& client);
};

class MsgClientServer
{
		public:
	static int JoinTeam(SocketW& client, const std::string& teamName);
	static int Forward(SocketW& client);
	static int Right(SocketW& client);
	static int Left(SocketW& client);
	static int See(SocketW& client);
	static int Inventory(SocketW& client);
	static int Take(SocketW& client, const std::string& itemName);
	static int Place(SocketW& client, const std::string& itemName);
	static int Kick(SocketW& client);
	static int Broadcast(SocketW& client, const std::string& message);
	static int Incantation(SocketW& client);
	static int Fork(SocketW& client);
	static int TeamCount(SocketW& client);
};

#endif