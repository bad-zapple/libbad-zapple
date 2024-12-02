#ifndef MSGHELPERCLIENT_HPP
# define MSGHELPERCLIENT_HPP

class SocketW;
class CellContent; /* Depends on World implementation */
class InventoryContent; /* Depends on Player implementation */

# include <string>

class MsgServerClient
{
		public:
	static void Welcome(SocketW& client);
	static void Result(SocketW& client, bool state);
	static void See(SocketW& client, const CellContent& content); /* Should probably be a vector of CellContent */
	static void Inventory(SocketW& client, const InventoryContent& inventory);
	static void IncantationStart(SocketW& client);
	static void IncantationDone(SocketW& client, unsigned int level);
	static void TeamCount(SocketW& client, int teamClients);
	static void WorldSize(SocketW& client, unsigned int width, unsigned int height);
	static void Death(SocketW& client);
};

class MsgClientServer
{
		public:
	static void JoinTeam(SocketW& client, const std::string& teamName);
	static void Forward(SocketW& client);
	static void Right(SocketW& client);
	static void Left(SocketW& client);
	static void See(SocketW& client);
	static void Inventory(SocketW& client);
	static void Take(SocketW& client, const std::string& itemName);
	static void Place(SocketW& client, const std::string& itemName);
	static void Kick(SocketW& client);
	static void Broadcast(SocketW& client, const std::string& message);
	static void Incantation(SocketW& client);
	static void Fork(SocketW& client);
	static void TeamCount(SocketW& client);
};

#endif