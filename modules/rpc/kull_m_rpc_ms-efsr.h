/*	Benjamin DELPY `gentilkiwi`
	https://blog.gentilkiwi.com
	benjamin@gentilkiwi.com
	Licence : https://creativecommons.org/licenses/by/4.0/
*/
#pragma once
#include "kull_m_rpc.h"

extern const UUID EFSR_ObjectUUID;

typedef void *PEXIMPORT_CONTEXT_HANDLE;

typedef struct pipe_EFS_EXIM_PIPE {
	void (__RPC_USER* pull) (CHAR* state, UCHAR* buf, ULONG esize, ULONG* ecount);
	void (__RPC_USER* push) (CHAR* state, UCHAR* buf, ULONG ecount);
	void (__RPC_USER* alloc) (CHAR* state, ULONG bsize, UCHAR** buf, ULONG* bcount);
	char* state;
} EFS_EXIM_PIPE;

long EfsRpcOpenFileRaw(handle_t binding_h, PEXIMPORT_CONTEXT_HANDLE* hContext, wchar_t* FileName, long Flags);
long EfsRpcReadFileRaw(PEXIMPORT_CONTEXT_HANDLE hContext, EFS_EXIM_PIPE* EfsOutPipe);
long EfsRpcWriteFileRaw(PEXIMPORT_CONTEXT_HANDLE hContext, EFS_EXIM_PIPE* EfsInPipe);
void EfsRpcCloseRaw(PEXIMPORT_CONTEXT_HANDLE* hContext);
long EfsRpcEncryptFileSrv(handle_t binding_h, wchar_t* FileName);
long EfsRpcDecryptFileSrv(handle_t binding_h, wchar_t* FileName, unsigned long OpenFlag);
extern long StubEfsRpcOpenFileRaw(PMIDL_STUB_DESC stub, handle_t binding_h, PEXIMPORT_CONTEXT_HANDLE* hContext, wchar_t* FileName, long Flags);
extern long StubEfsRpcReadFileRaw(PMIDL_STUB_DESC stub, PEXIMPORT_CONTEXT_HANDLE hContext, EFS_EXIM_PIPE* EfsOutPipe);
extern long StubEfsRpcWriteFileRaw(PMIDL_STUB_DESC stub, PEXIMPORT_CONTEXT_HANDLE hContext, EFS_EXIM_PIPE* EfsInPipe);
extern void StubEfsRpcCloseRaw(PMIDL_STUB_DESC stub, PEXIMPORT_CONTEXT_HANDLE* hContext);
extern long StubEfsRpcEncryptFileSrv(PMIDL_STUB_DESC stub, handle_t binding_h, wchar_t* FileName);
extern long StubEfsRpcDecryptFileSrv(PMIDL_STUB_DESC stub, handle_t binding_h, wchar_t* FileName, unsigned long OpenFlag);

extern PMIDL_STUB_DESC GetLsaRpcStub();
extern PMIDL_STUB_DESC GetEfsRpcStub();

RPC_IF_HANDLE efsrpc_v1_0_c_ifspec;
