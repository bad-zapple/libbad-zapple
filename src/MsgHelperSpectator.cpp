#include <MsgHelperSpectator.hpp>
#include <SocketW.hpp>

void MsgServerSpectator::Welcome(SocketW& client)
{
	client << "BIENVENUE";
	client.Send();
}

/* TODO: the rest */

void MsgServerSpectator::UnknownCmd(SocketW& client)
{
	client << "suc";
	client.Send();
}

void MsgServerSpectator::InvalidCmdArg(SocketW& client)
{
	client << "sbp";
	client.Send();
}