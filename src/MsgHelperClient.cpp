#include <MsgHelperClient.hpp>
#include <SocketW.hpp>

void MsgServerClient::Welcome(SocketW& client)
{
	client << "BIENVENUE";
	client.Send();
}

void MsgServerClient::Result(SocketW& client, bool state)
{
	client << (state) ? "ok" : "ko";
	client.Send();
}

void MsgServerClient::See(SocketW& client, const CellContent& content)
{
	client << "{";
	/*
		TODO: Implement after Cell class is done
	*/
	client << "}";
	client.Send();
}

void MsgServerClient::Inventory(SocketW& client, const InventoryContent& inventory)
{
	client << "{";
	/*
		TODO: Implement after Player class is done

		client << "itemname " << quantity << ", "; // don't output , on the last one
	*/
	client << "}";
	client.Send();
}

void MsgServerClient::IncantationStart(SocketW& client)
{
	client << "elevation en cours";
	client.Send();
}

void MsgServerClient::IncantationDone(SocketW& client, unsigned int level)
{
	client << "niveau actuel : " << level;
	client.Send();
}

void MsgServerClient::TeamCount(SocketW& client, int teamClients)
{
	client << teamClients;
	client.Send();
}

void MsgServerClient::WorldSize(SocketW& client, unsigned int width, unsigned int height)
{
	client << width << " " << height;
	client.Send();
}

void MsgServerClient::Death(SocketW& client)
{
	client << "mort";
	client.Send();
}



void MsgClientServer::JoinTeam(SocketW& client, const std::string& teamName)
{
	client << teamName;
	client.Send();
}

void MsgClientServer::Forward(SocketW& client)
{
	client << "avance";
	client.Send();
}

void MsgClientServer::Right(SocketW& client)
{
	client << "droite";
	client.Send();
}

void MsgClientServer::Left(SocketW& client)
{
	client << "gauche";
	client.Send();
}

void MsgClientServer::See(SocketW& client)
{
	client << "voir";
	client.Send();
}

void MsgClientServer::Inventory(SocketW& client)
{
	client << "inventaire";
	client.Send();
}

void MsgClientServer::Take(SocketW& client, const std::string& itemName)
{
	client << "prend " << itemName;
	client.Send();
}

void MsgClientServer::Place(SocketW& client, const std::string& itemName)
{
	client << "pose " << itemName;
	client.Send();
}

void MsgClientServer::Kick(SocketW& client)
{
	client << "expulse";
	client.Send();
}

void MsgClientServer::Broadcast(SocketW& client, const std::string& message)
{
	client << "broadcast " << message;
	client.Send();
}

void MsgClientServer::Incantation(SocketW& client)
{
	client << "incantation";
	client.Send();
}

void MsgClientServer::Fork(SocketW& client)
{
	client << "fork";
	client.Send();
}

void MsgClientServer::TeamCount(SocketW& client)
{
	client << "connect_nbr";
	client.Send();
}