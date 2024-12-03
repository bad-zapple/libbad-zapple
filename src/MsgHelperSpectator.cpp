#include <MsgHelperSpectator.hpp>
#include <SocketW.hpp>

int MsgServerSpectator::Welcome(SocketW& client)
{
	client << "BIENVENUE";
	return (client.Send());
}

/* TODO: the rest */

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