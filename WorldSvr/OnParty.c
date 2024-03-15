#include "ClientProtocol.h"
#include "ClientProcedures.h"
#include "ClientSocket.h"
#include "IPCProcs.h"
#include "Notification.h"
#include "Server.h"

CLIENT_PROCEDURE_BINDING(PARTY_INVITE) {
    if (!Character) goto error;

	// TODO: Implementation missing

	S2C_DATA_PARTY_INVITE* Response = PacketInit(S2C_DATA_PARTY_INVITE);
	Response->Command = S2C_PARTY_INVITE;
	return SocketSend(Socket, Connection, Response);

error:
	return SocketDisconnect(Socket, Connection);
}

CLIENT_PROCEDURE_BINDING(PARTY_INVITE_CONFIRM) {
	if (!Character) goto error;

	// TODO: Implementation missing

	S2C_DATA_PARTY_INVITE_CONFIRM* Response = PacketInit(S2C_DATA_PARTY_INVITE_CONFIRM);
	Response->Command = S2C_PARTY_INVITE_CONFIRM;
	return SocketSend(Socket, Connection, Response);

error:
	return SocketDisconnect(Socket, Connection);
}

CLIENT_PROCEDURE_BINDING(PARTY_INVITE_CANCEL) {
	if (!Character) goto error;

	// TODO: Implementation missing

	S2C_DATA_PARTY_INVITE_CANCEL* Response = PacketInit(S2C_DATA_PARTY_INVITE_CANCEL);
	Response->Command = S2C_PARTY_INVITE_CANCEL;
	return SocketSend(Socket, Connection, Response);

error:
	return SocketDisconnect(Socket, Connection);
}

CLIENT_PROCEDURE_BINDING(PARTY_LEAVE) {
	if (!Character) goto error;

	// TODO: Implementation missing

	S2C_DATA_PARTY_LEAVE* Response = PacketInit(S2C_DATA_PARTY_LEAVE);
	Response->Command = S2C_PARTY_LEAVE;
	return SocketSend(Socket, Connection, Response);

error:
	return SocketDisconnect(Socket, Connection);
}

CLIENT_PROCEDURE_BINDING(PARTY_EXPEL_MEMBER) {
	if (!Character) goto error;

	// TODO: Implementation missing

	S2C_DATA_PARTY_EXPEL_MEMBER* Response = PacketInit(S2C_DATA_PARTY_EXPEL_MEMBER);
	Response->Command = S2C_PARTY_EXPEL_MEMBER;
	return SocketSend(Socket, Connection, Response);

error:
	return SocketDisconnect(Socket, Connection);
}

CLIENT_PROCEDURE_BINDING(PARTY_CHANGE_LEADER) {
	if (!Character) goto error;

	// TODO: Implementation missing

	S2C_DATA_PARTY_CHANGE_LEADER* Response = PacketInit(S2C_DATA_PARTY_CHANGE_LEADER);
	Response->Command = S2C_PARTY_CHANGE_LEADER;
	return SocketSend(Socket, Connection, Response);

error:
	return SocketDisconnect(Socket, Connection);
}
