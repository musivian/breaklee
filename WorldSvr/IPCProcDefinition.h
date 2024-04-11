#ifndef IPC_MASTER_PROCEDURE
#define IPC_MASTER_PROCEDURE(__NAME__, __COMMAND__, __PROTOCOL__)
#endif

IPC_MASTER_PROCEDURE(OnWorldConnect, IPC_WORLD_ACKCONNECT, IPC_DATA_WORLD_ACKCONNECT)
IPC_MASTER_PROCEDURE(OnWorldVerifyLinks, IPC_WORLD_VERIFYLINKS, IPC_DATA_WORLD_VERIFYLINKS)
IPC_MASTER_PROCEDURE(OnWorldGetCharacters, IPC_WORLD_ACKGETCHARACTERS, IPC_DATA_WORLD_ACKGETCHARACTERS)
IPC_MASTER_PROCEDURE(OnWorldGetPremiumService, IPC_WORLD_ACKPREMIUMSERVICE, IPC_DATA_WORLD_ACKPREMIUMSERVICE)
IPC_MASTER_PROCEDURE(OnWorldCreateCharacter, IPC_WORLD_ACKCREATECHARACTER, IPC_DATA_WORLD_ACKCREATECHARACTER)
IPC_MASTER_PROCEDURE(OnWorldGetCharacter, IPC_WORLD_ACKGETCHARACTER, IPC_DATA_WORLD_ACKGETCHARACTER)
IPC_MASTER_PROCEDURE(OnWorldDBSync, IPC_WORLD_ACKDBSYNC, IPC_DATA_WORLD_ACKDBSYNC)
IPC_MASTER_PROCEDURE(OnWorldVerifyPassword, IPC_WORLD_ACKVERIFYPASSWORD, IPC_DATA_WORLD_ACKVERIFYPASSWORD)
IPC_MASTER_PROCEDURE(OnWorldRequestPartyInvite, IPC_WORLD_REQPARTYINVITE, IPC_DATA_WORLD_REQPARTYINVITE)
IPC_MASTER_PROCEDURE(OnWorldRespondPartyInvite, IPC_WORLD_ACKPARTYINVITE, IPC_DATA_WORLD_ACKPARTYINVITE)

#undef IPC_MASTER_PROCEDURE
