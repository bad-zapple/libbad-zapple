#include <MsgHelperClient.hpp>
#include <SocketW.hpp>

namespace zap
{

int MsgServerClient::Welcome(SocketW& client)
{
	client << "BIENVENUE";
	return (client.Send());
}

int MsgServerClient::Result(SocketW& client, bool state)
{
	client << ((state) ? "ok" : "ko");
	return (client.Send());
}

int MsgServerClient::See(SocketW& client, const CellContent& content)
{
	(void)content;
	client << "{";
	/*
		TODO: Implement after Cell class is done
	*/
	client << "}";
	return (client.Send());
}

int MsgServerClient::Inventory(SocketW& client, const InventoryContent& inventory)
{
	(void)inventory;
	client << "{";
	/*
		TODO: Implement after Player class is done

		client << "itemname " << quantity << ", "; // don't output , on the last one
	*/
	client << "}";
	return (client.Send());
}

int MsgServerClient::IncantationStart(SocketW& client)
{
	client << "elevation en cours";
	return (client.Send());
}

int MsgServerClient::IncantationDone(SocketW& client, unsigned int level)
{
	client << "niveau actuel : " << level;
	return (client.Send());
}

int MsgServerClient::TeamCount(SocketW& client, int teamClients)
{
	client << teamClients;
	return (client.Send());
}

int MsgServerClient::WorldSize(SocketW& client, unsigned int width, unsigned int height)
{
	client << width << " " << height;
	return (client.Send());
}

int MsgServerClient::Death(SocketW& client)
{
	client << "mort";
	return (client.Send());
}



int MsgClientServer::JoinTeam(SocketW& client, const std::string& teamName)
{
	client << teamName;
	return (client.Send());
}

int MsgClientServer::Forward(SocketW& client)
{
	client << "avance";
	return (client.Send());
}

int MsgClientServer::Right(SocketW& client)
{
	client << "droite";
	return (client.Send());
}

int MsgClientServer::Left(SocketW& client)
{
	client << "gauche";
	return (client.Send());
}

int MsgClientServer::See(SocketW& client)
{
	client << "voir";
	return (client.Send());
}

int MsgClientServer::Inventory(SocketW& client)
{
	client << "inventaire";
	return (client.Send());
}

int MsgClientServer::Take(SocketW& client, const std::string& itemName)
{
	client << "prend " << itemName;
	return (client.Send());
}

int MsgClientServer::Place(SocketW& client, const std::string& itemName)
{
	client << "pose " << itemName;
	return (client.Send());
}

int MsgClientServer::Kick(SocketW& client)
{
	client << "expulse";
	return (client.Send());
}

int MsgClientServer::Broadcast(SocketW& client, const std::string& message)
{
	client << "broadcast " << message;
	return (client.Send());
}

int MsgClientServer::Incantation(SocketW& client)
{
	client << "incantation";
	return (client.Send());
}

int MsgClientServer::Fork(SocketW& client)
{
	client << "fork";
	return (client.Send());
}

int MsgClientServer::TeamCount(SocketW& client)
{
	client << "connect_nbr";
	return (client.Send());
}

}; /* namespace zap */