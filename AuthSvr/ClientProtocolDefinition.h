#include "Constants.h"

#ifndef CLIENT_PROTOCOL_ENUM
#define CLIENT_PROTOCOL_ENUM(...)
#endif

#ifndef CLIENT_PROTOCOL_STRUCT
#define CLIENT_PROTOCOL_STRUCT(__NAME__, __BODY__)
#endif

#ifndef CLIENT_PROTOCOL
#define CLIENT_PROTOCOL(__NAMESPACE__, __NAME__, __COMMAND__, __VERSION__, __BODY__)
#endif

CLIENT_PROTOCOL(C2S, CONNECT, 101, 13133,
    C2S_DATA_SIGNATURE;
    UInt32 AuthKey;
)

CLIENT_PROTOCOL(S2C, CONNECT, 101, 13133,
    S2C_DATA_SIGNATURE;
    UInt32 XorKey;
	UInt32 AuthKey;
	UInt16 ConnectionID;
	UInt16 XorKeyIndex;
	UInt32 Unknown1;
	UInt32 Unknown2;
)

CLIENT_PROTOCOL(C2S, VERIFY_LINKS, 102, 13133,
	C2S_DATA_SIGNATURE;
	UInt32 AuthKey;
	UInt16 EntityID;
	UInt8 WorldID;
	UInt8 ServerID;
	UInt32 ClientMagicKey;
)

CLIENT_PROTOCOL(S2C, VERIFY_LINKS, 102, 13133,
	S2C_DATA_SIGNATURE;
	UInt8 WorldID;
	UInt8 ServerID;
	UInt8 Status;
)

CLIENT_PROTOCOL(C2S, AUTH_ACCOUNT, 103, 13133,
	C2S_DATA_SIGNATURE;
	UInt32 Unknown1;
)

CLIENT_PROTOCOL(S2C, AUTH_ACCOUNT, 103, 13133,
	S2C_DATA_SIGNATURE;
	UInt32 ServerStatus;
	UInt32 Unknown1;
	UInt32 Unknown2;
)

CLIENT_PROTOCOL(C2S, DISCONNECT, 110, 13133,
	C2S_DATA_SIGNATURE;
)

CLIENT_PROTOCOL_ENUM(
    SYSTEM_MESSAGE_NONE,
    SYSTEM_MESSAGE_DUAL_LOGIN,
    SYSTEM_MESSAGE_DISCONNECTED,
    SYSTEM_MESSAGE_LOGIN_SUCCESS = 0x09,
)

CLIENT_PROTOCOL(S2C, SYSTEM_MESSAGE, 120, 13133,
	S2C_DATA_SIGNATURE;
	UInt8 Message;
	UInt8 Unknown1;
	UInt8 Unknown2;
)

CLIENT_PROTOCOL_STRUCT(S2C_DATA_SERVER_LIST_WORLD,
	UInt8 ServerID;
	UInt8 WorldID;
	UInt16 PlayerCount;
	UInt16 LobbyPlayerCount;
	UInt16 Unknown1;
	UInt16 CapellaPlayerCount;
	UInt16 ProcyonPlayerCount;
	UInt32 Unknown2;
	UInt16 CapellaPlayerCount2;
	UInt16 ProcyonPlayerCount2;
	UInt16 Unknown3;
	UInt8 MinLevel;
	UInt8 MaxLevel;
	UInt8 MinRank;
	UInt8 MaxRank;
	UInt16 MaxPlayerCount;
	Char WorldHost[65];
	UInt16 WorldPort;
	UInt64 WorldType;
)

CLIENT_PROTOCOL_STRUCT(S2C_DATA_SERVER_FLAGS,
	UInt8 Unknown1 : 4;
	UInt8 IsHot : 1;
	UInt8 Unknown2 : 3;
)

CLIENT_PROTOCOL_STRUCT(S2C_DATA_SERVER_LIST_INDEX,
    UInt8 ServerID;
	S2C_DATA_SERVER_FLAGS Flags;
	UInt32 Language;
	UInt8 Unknown1[2];
	UInt8 WorldCount;
    // S2C_DATA_SERVER_LIST_WORLD Worlds[0]; /* [WorldCount] */
)

CLIENT_PROTOCOL(S2C, SERVER_LIST, 121, 13133,
	S2C_DATA_SIGNATURE;
	UInt8 ServerCount;
    // S2C_DATA_SERVER_LIST_INDEX Servers[0];
)

CLIENT_PROTOCOL(C2S, CHECK_VERSION, 122, 13133,
	C2S_DATA_SIGNATURE;
	UInt32 ClientVersion;
	UInt32 DebugVersion;
	UInt32 Reserved[2];
)

CLIENT_PROTOCOL(S2C, CHECK_VERSION, 122, 13133,
	S2C_DATA_SIGNATURE;
	UInt32 ClientVersion;
	UInt32 ServerMagicKey;
	UInt32 Reserved[2];
)

CLIENT_PROTOCOL(S2C, UNKNOWN_124, 124, 13133,
	S2C_DATA_SIGNATURE;
	UInt8 Unknown1;
	UInt32 Unknown2[4];
	UInt8 Unknown3;
	UInt32 Unknown4[4];
)

CLIENT_PROTOCOL_STRUCT(S2C_DATA_URL,
	UInt32 Length;
	// Char Data[0]; /* Char[Length] */
)

CLIENT_PROTOCOL(S2C, URL_LIST, 128, 13133,
	S2C_DATA_SIGNATURE;
	UInt16 PayloadLength[2];
	S2C_DATA_URL Urls[0];
)

CLIENT_PROTOCOL(C2S, PUBLIC_KEY, 2001, 13133,
	C2S_DATA_SIGNATURE;
)

CLIENT_PROTOCOL(S2C, PUBLIC_KEY, 2001, 13133,
	S2C_DATA_SIGNATURE;
	UInt8 Unknown1;
	UInt16 PublicKeyLength;
    UInt8 Payload[0]; /* UInt8[PublicKeyLength] */
)

CLIENT_PROTOCOL(C2S, SERVER_ENVIRONMENT, 2002, 13133,
	C2S_DATA_SIGNATURE;
	Char Username[129];
)

CLIENT_PROTOCOL(S2C, SERVER_ENVIRONMENT, 2002, 13133,
	S2C_DATA_SIGNATURE;
	UInt8 AuthCaptcha[4108];
)

CLIENT_PROTOCOL(S2C, DISCONNECT_TIMER, 2005, 13133,
    S2C_DATA_SIGNATURE;
	UInt64 Timeout;
	UInt8 Unknown1;
)

CLIENT_PROTOCOL(C2S, AUTHENTICATE, 2006, 13133,
	C2S_DATA_SIGNATURE;
	UInt32 SubMessageType;
	UInt8 Payload[0];
)

CLIENT_PROTOCOL_STRUCT(S2C_DATA_AUTHENTICATE_SERVER_INDEX,
    UInt8 ServerID;
    UInt8 CharacterCount;
)

CLIENT_PROTOCOL_STRUCT(S2C_DATA_AUTHENTICATE_EXTENSION,
	UInt8 Unknown1[55];
	Char AuthKey[32];
	UInt8 Unknown2[2];
	S2C_DATA_AUTHENTICATE_SERVER_INDEX Servers[MAX_SERVER_COUNT];
)

CLIENT_PROTOCOL_STRUCT(S2C_DATA_AUTHENTICATE_EXTENSION_UNKNOWN,
	UInt32 Unknown1;
	Timestamp UnknownTimestamp1;
	UInt32 Unknown2;
	Timestamp UnknownTimestamp2;
)

CLIENT_PROTOCOL(S2C, AUTHENTICATE, 2006, 13133,
	S2C_DATA_SIGNATURE;
	UInt8 KeepAlive;
	Int32 Unknown1;
	Int32 Unknown2;
	Int32 LoginStatus;
	UInt32 SubMessageType;
	Int32 AccountStatus;
    S2C_DATA_AUTHENTICATE_EXTENSION Extension[0];
)

CLIENT_PROTOCOL(S2C, AUTH_TIMER, 2009, 13133,
	S2C_DATA_SIGNATURE;
	UInt32 Timeout;
)

CLIENT_PROTOCOL(C2S, UNKNOWN_3383, 3383, 0000,
	C2S_DATA_SIGNATURE;
)

CLIENT_PROTOCOL(S2C, UNKNOWN_3383, 3383, 0000,
	S2C_DATA_SIGNATURE;
	UInt8 Unknown1[8];
)

CLIENT_PROTOCOL(C2S, UNKNOWN_5383, 5383, 13133,
	C2S_DATA_SIGNATURE;
)

CLIENT_PROTOCOL(S2C, UNKNOWN_5383, 5383, 13133,
	S2C_DATA_SIGNATURE;
	UInt8 Unknown1[8];
)

#undef CLIENT_PROTOCOL_ENUM
#undef CLIENT_PROTOCOL_STRUCT
#undef CLIENT_PROTOCOL
