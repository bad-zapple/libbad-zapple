#ifndef MSGHELPERSPECTATOR_HPP
# define MSGHELPERSPECTATOR_HPP

class MsgServerSpectator
{
		public:
	static void Welcome(SocketW& client);
	static void WorldSize(SocketW& client, unsigned int width, unsigned int height);
	static void CellContent(SocketW& client /*, const CellContent& */);
	static void TeamName(SocketW& client, const std::string& teamName);
	static void PlayerConnected(SocketW& client, unsigned int playerNum, unsigned int x, unsigned int y, int orient, unsigned int level, const std::string& teamName);
	static void PlayerPosition(SocketW& client, unsigned int playerNum, unsigned int x, unsigned int y, int orient);
	static void PlayerLevel(SocketW& client, unsigned int playerNum, unsigned int level);
	static void PlayerInventory(SocketW& client, unsigned int playerNum /* const InventoryContent& */);
	static void PlayerKick(SocketW& client, unsigned int playerNum);
	static void PlayerBroadcast(SocketW& client, unsigned int playerNum, const std::string& message);
	static void PlayerIncantation(SocketW& client, unsigned int width, unsigned int height, unsigned int playerNum /* List of playerNum*/);
	static void IncantationDone(SocketW& client, unsigned int width, unsigned int height, int result);
	static void PlayerLayEgg(SocketW& client, unsigned int playerNum);
	static void PlayerPlace(SocketW& client, unsigned int playerNum, unsigned int resourceId);
	static void PlayerPick(SocketW& client, unsigned int playerNum, unsigned int resourceId);
	static void PlayerStarved(SocketW& client, unsigned int playerNum);
	static void PlayerLayEggDone(SocketW& client, unsigned int eggNum, unsigned int playerNum, unsigned int x, unsigned int y);
	static void EggHatched(SocketW& client, unsigned int eggNum);
	static void EggConnected(SocketW& client, unsigned int eggNum);
	static void EggStarved(SocketW& client, unsigned int eggNum);
	static void TimeUnit(SocketW& client, unsigned int timeUnit);
	static void GameEnd(SocketW& client);
	static void ServerMessage(SocketW& client);
	static void UnknownCmd(SocketW& client);
	static void InvalidCmdArg(SocketW& client);
};

class MsgSpectatorServer
{
		public:
	static void JoinSpectate(SocketW& client);
	static void AskCell(SocketW& client, unsigned int x, unsigned int y);
	static void AskWorld(SocketW& client);
	static void AskTeamNames(SocketW& client);
	static void AskPlayerPosition(SocketW& client, unsigned int playerNum);
	static void AskPlayerLevel(SocketW& client, unsigned int playerNum);
	static void AskTimeUnit(SocketW& client);
	static void ChangeTimeUnit(SocketW& client, unsigned int timeUnit);
};

#endif