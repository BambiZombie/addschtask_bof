

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Mon Sep 10 04:29:28 2018
 */
/* Compiler settings for rpc.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __rpc_h_h__
#define __rpc_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

///* header files for imported files */
//#include "oaidl.h"
//#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ExpIFName_INTERFACE_DEFINED__
#define __ExpIFName_INTERFACE_DEFINED__

/* interface ExpIFName */
/* [version][uuid] */ 

typedef struct _TASK_USER_CRED
    {
    /* [string] */ const wchar_t *userId;
    /* [string] */ const wchar_t *password;
    DWORD flags;
    } 	TASK_USER_CRED;

typedef struct _TASK_XML_ERROR_INFO
    {
    DWORD line;
    DWORD column;
    /* [string] */ wchar_t *node;
    /* [string] */ wchar_t *value;
    } 	TASK_XML_ERROR_INFO;

typedef struct _TASK_XML_ERROR_INFO *PTASK_XML_ERROR_INFO;

typedef /* [string] */ wchar_t **TASK_NAMES;

HRESULT SchRpcRegisterTask( 
    /* [in] */ handle_t IDL_handle,
    /* [unique][string][in] */ const wchar_t *path,
    /* [string][in] */ const wchar_t *xml,
    /* [in] */ DWORD flags,
    /* [unique][string][in] */ const wchar_t *sddl,
    /* [in] */ DWORD logonType,
    /* [in] */ DWORD cCreds,
    /* [unique][size_is][in] */ const TASK_USER_CRED *pCreds,
    /* [string][out] */ wchar_t **pActualPath,
    /* [out] */ PTASK_XML_ERROR_INFO *pErrorInfo);

HRESULT SchRpcRun( 
    /* [in] */ handle_t IDL_handle,
    /* [string][in] */ const wchar_t *path,
    /* [in] */ DWORD cArgs,
    /* [unique][size_is][string][in] */ const wchar_t **pArgs,
    /* [in] */ DWORD flags,
    /* [in] */ DWORD sessionId,
    /* [string][unique][in] */ const wchar_t *user,
    /* [out] */ GUID *pGuid);

extern RPC_IF_HANDLE ExpIFName_v1_0_c_ifspec;
extern RPC_IF_HANDLE ExpIFName_v1_0_s_ifspec;
#endif /* __ExpIFName_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


