#ifndef ZAP_MSGHELPERSPECTATOR_HPP
# define ZAP_MSGHELPERSPECTATOR_HPP

# include <string>

namespace zap
{
	
class SocketW;
class CellContent; /* Depends on World implementation */
class InventoryContent; /* Depends on Player implementation */
	
class MsgServerSpectator
{
		public:
	static int Welcome(SocketW& client);
	static int WorldSize(SocketW& client, unsigned int width, unsigned int height);
	static int CellContent(SocketW& client, unsigned int x, unsigned int y /*, const CellContent& */);
	static int TeamName(SocketW& client, const std::string& teamName);
	static int PlayerConnected(SocketW& client, unsigned int playerNum, unsigned int x, unsigned int y, int orient, unsigned int level, const std::string& teamName);
	static int PlayerPosition(SocketW& client, unsigned int playerNum, unsigned int x, unsigned int y, int orient);
	static int PlayerLevel(SocketW& client, unsigned int playerNum, unsigned int level);
	static int PlayerInventory(SocketW& client, unsigned int playerNum, unsigned int x, unsigned int y /* const InventoryContent& */);
	static int PlayerKick(SocketW& client, unsigned int playerNum);
	static int PlayerBroadcast(SocketW& client, unsigned int playerNum, const std::string& message);
	static int PlayerIncantation(SocketW& client, unsigned int x, unsigned int y, unsigned int level, unsigned int playerNum /* List of playerNum*/);
	static int IncantationDone(SocketW& client, unsigned int x, unsigned int y, int result);
	static int PlayerLayEgg(SocketW& client, unsigned int playerNum);
	static int PlayerPlace(SocketW& client, unsigned int playerNum, unsigned int resourceId);
	static int PlayerPick(SocketW& client, unsigned int playerNum, unsigned int resourceId);
	static int PlayerStarved(SocketW& client, unsigned int playerNum);
	static int PlayerLayEggDone(SocketW& client, unsigned int eggNum, unsigned int playerNum, unsigned int x, unsigned int y);
	static int EggHatched(SocketW& client, unsigned int eggNum);
	static int EggConnected(SocketW& client, unsigned int eggNum);
	static int EggStarved(SocketW& client, unsigned int eggNum);
	static int TimeUnit(SocketW& client, unsigned int timeUnit);
	static int GameEnd(SocketW& client, const std::string& teamName);
	static int ServerMessage(SocketW& client, const std::string& message);
	static int UnknownCmd(SocketW& client);
	static int InvalidCmdArg(SocketW& client);
};

class MsgSpectatorServer
{
		public:
	static int JoinSpectate(SocketW& client);
	static int AskWorldSize(SocketW& client);
	static int AskCell(SocketW& client, unsigned int x, unsigned int y);
	static int AskWorld(SocketW& client);
	static int AskTeamNames(SocketW& client);
	static int AskPlayerPosition(SocketW& client, unsigned int playerNum);
	static int AskPlayerLevel(SocketW& client, unsigned int playerNum);
	static int AskPlayerInventory(SocketW& client, unsigned int playerNum);
	static int AskTimeUnit(SocketW& client);
	static int ChangeTimeUnit(SocketW& client, unsigned int timeUnit);
};

}; /* namespace zap */

#endif