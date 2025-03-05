#include <MsgHelperSpectator.hpp>
#include <SocketW.hpp>

namespace zap
{

int MsgServerSpectator::Welcome(SocketW& client)
{
	client << "BIENVENUE";
	return (client.Send());
}

int MsgServerSpectator::WorldSize(SocketW& client, unsigned int width, unsigned int height)
{
	client << "msz " << width << " " << height;
	return (client.Send());
}

int MsgServerSpectator::CellContent(SocketW& client, unsigned int x, unsigned int y /*, const CellContent& */)
{
	client << "bct " << x << " " << y << " "; /* << a b c d e f*/
	return (client.Send());
}

int MsgServerSpectator::TeamName(SocketW& client, const std::string& teamName)
{
	client << "tna " << teamName;
	return (client.Send());
}

int MsgServerSpectator::PlayerConnected(SocketW& client, unsigned int playerNum, unsigned int x, unsigned int y, int orient, unsigned int level, const std::string& teamName)
{
	client << "pnw " << playerNum << " " << x << " " << y << " " << orient << " " << level << " " << teamName;
	return (client.Send());
}

int MsgServerSpectator::PlayerPosition(SocketW& client, unsigned int playerNum, unsigned int x, unsigned int y, int orient)
{
	client << "ppo " << playerNum << " " << x << " " << y << " " << orient;
	return (client.Send());
}

int MsgServerSpectator::PlayerLevel(SocketW& client, unsigned int playerNum, unsigned int level)
{
	client << "plv " << playerNum << " " << level;
	return (client.Send());
}

int MsgServerSpectator::PlayerInventory(SocketW& client, unsigned int playerNum, unsigned int x, unsigned int y /* const InventoryContent& */)
{
	client << "pin " << playerNum << " " << x << " " << y;
	return (client.Send());
}

int MsgServerSpectator::PlayerKick(SocketW& client, unsigned int playerNum)
{
	client << "pex " << playerNum;
	return (client.Send());
}

int MsgServerSpectator::PlayerBroadcast(SocketW& client, unsigned int playerNum, const std::string& message)
{
	client << "pbc " << playerNum << " " << message;
	return (client.Send());
}

int MsgServerSpectator::PlayerIncantation(SocketW& client, unsigned int x, unsigned int y, unsigned int level, unsigned int playerNum /* List of playerNum*/)
{
	client << "pic " << x << " " << y << " " << level << " " << playerNum; /* foreach (plr in players) client << " " << plr.id(); */
	return (client.Send());
}

int MsgServerSpectator::IncantationDone(SocketW& client, unsigned int x, unsigned int y, int result)
{
	client << "pie " << x << " " << y << " " << result;
	return (client.Send());
}

int MsgServerSpectator::PlayerLayEgg(SocketW& client, unsigned int playerNum)
{
	client << "pfk " << playerNum;
	return (client.Send());
}

int MsgServerSpectator::PlayerPlace(SocketW& client, unsigned int playerNum, unsigned int resourceId)
{
	client << "pdr " << playerNum << " " << resourceId;
	return (client.Send());
}

int MsgServerSpectator::PlayerPick(SocketW& client, unsigned int playerNum, unsigned int resourceId)
{
	client << "pgt" << playerNum << " " << resourceId;
	return (client.Send());
}

int MsgServerSpectator::PlayerStarved(SocketW& client, unsigned int playerNum)
{
	client << "pdi " << playerNum;
	return (client.Send());
}

int MsgServerSpectator::PlayerLayEggDone(SocketW& client, unsigned int eggNum, unsigned int playerNum, unsigned int x, unsigned int y)
{
	client << "enw " << eggNum << " " << playerNum << " " << x << " " << y;
	return (client.Send());
}

int MsgServerSpectator::EggHatched(SocketW& client, unsigned int eggNum)
{
	client << "eht " << eggNum;
	return (client.Send());
}

int MsgServerSpectator::EggConnected(SocketW& client, unsigned int eggNum)
{
	client << "ebo " << eggNum;
	return (client.Send());
}

int MsgServerSpectator::EggStarved(SocketW& client, unsigned int eggNum)
{
	client << "edi " << eggNum;
	return (client.Send());
}

int MsgServerSpectator::TimeUnit(SocketW& client, unsigned int timeUnit)
{
	client << "sgt " << timeUnit;
	return (client.Send());
}

int MsgServerSpectator::GameEnd(SocketW& client, const std::string& teamName)
{
	client << "seg " << teamName;
	return (client.Send());
}

int MsgServerSpectator::ServerMessage(SocketW& client, const std::string& message)
{
	client << "smg " << message;
	return (client.Send());
}

int MsgServerSpectator::UnknownCmd(SocketW& client)
{
	client << "suc";
	return (client.Send());
}

int MsgServerSpectator::InvalidCmdArg(SocketW& client)
{
	client << "sbp";
	return (client.Send());
}


int MsgSpectatorServer::JoinSpectate(SocketW& client)
{
	client << "GRAPHIC";
	return (client.Send());
}

int MsgSpectatorServer::AskWorldSize(SocketW& client)
{
	client << "msz";
	return (client.Send());
}

int MsgSpectatorServer::AskCell(SocketW& client, unsigned int x, unsigned int y)
{
	client << "bct " << x << " " << y;
	return (client.Send());
}

int MsgSpectatorServer::AskWorld(SocketW& client)
{
	client << "mct";
	return (client.Send());
}

int MsgSpectatorServer::AskTeamNames(SocketW& client)
{
	client << "tna";
	return (client.Send());
}

int MsgSpectatorServer::AskPlayerPosition(SocketW& client, unsigned int playerNum)
{
	client << "ppo " << playerNum;
	return (client.Send());
}

int MsgSpectatorServer::AskPlayerLevel(SocketW& client, unsigned int playerNum)
{
	client << "plv " << playerNum;
	return (client.Send());
}

int MsgSpectatorServer::AskPlayerInventory(SocketW& client, unsigned int playerNum)
{
	client << "pin " << playerNum;
	return (client.Send());
}

int MsgSpectatorServer::AskTimeUnit(SocketW& client)
{
	client << "sgt";
	return (client.Send());
}

int MsgSpectatorServer::ChangeTimeUnit(SocketW& client, unsigned int timeUnit)
{
	client << "sst " << timeUnit;
	return (client.Send());
}

}; /* namespace zap */