// **********************************************************************
// This file was generated by a TARS parser!
// TARS version 1.1.0.
// **********************************************************************

#ifndef __BSERVANT_H_
#define __BSERVANT_H_

#include <map>
#include <string>
#include <vector>
#include "tup/Tars.h"
using namespace std;
#include "servant/ServantProxy.h"
#include "servant/Servant.h"
#include "promise/promise.h"


namespace TarsTest
{

    /* callback of async proxy for client */
    class BServantPrxCallback: public tars::ServantProxyCallback
    {
    public:
        virtual ~BServantPrxCallback(){}
        virtual void callback_test(tars::Int32 ret)
        { throw std::runtime_error("callback_test() override incorrect."); }
        virtual void callback_test_exception(tars::Int32 ret)
        { throw std::runtime_error("callback_test_exception() override incorrect."); }

        virtual void callback_testHello(tars::Int32 ret,  const std::string& sRsp)
        { throw std::runtime_error("callback_testHello() override incorrect."); }
        virtual void callback_testHello_exception(tars::Int32 ret)
        { throw std::runtime_error("callback_testHello_exception() override incorrect."); }

    public:
        virtual const map<std::string, std::string> & getResponseContext() const
        {
            CallbackThreadData * pCbtd = CallbackThreadData::getData();
            assert(pCbtd != NULL);

            if(!pCbtd->getContextValid())
            {
                throw TC_Exception("cann't get response context");
            }
            return pCbtd->getResponseContext();
        }

    public:
        virtual int onDispatch(tars::ReqMessagePtr msg)
        {
            static ::std::string __BServant_all[]=
            {
                "test",
                "testHello"
            };
            pair<string*, string*> r = equal_range(__BServant_all, __BServant_all+2, string(msg->request.sFuncName));
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __BServant_all)
            {
                case 0:
                {
                    if (msg->response.iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_test_exception(msg->response.iRet);

                        return msg->response.iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(msg->response.sBuffer);
                    tars::Int32 _ret;
                    _is.read(_ret, 0, true);

                    CallbackThreadData * pCbtd = CallbackThreadData::getData();
                    assert(pCbtd != NULL);

                    pCbtd->setResponseContext(msg->response.context);

                    callback_test(_ret);

                    pCbtd->delResponseContext();

                    return tars::TARSSERVERSUCCESS;

                }
                case 1:
                {
                    if (msg->response.iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_testHello_exception(msg->response.iRet);

                        return msg->response.iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(msg->response.sBuffer);
                    tars::Int32 _ret;
                    _is.read(_ret, 0, true);

                    std::string sRsp;
                    _is.read(sRsp, 2, true);
                    CallbackThreadData * pCbtd = CallbackThreadData::getData();
                    assert(pCbtd != NULL);

                    pCbtd->setResponseContext(msg->response.context);

                    callback_testHello(_ret, sRsp);

                    pCbtd->delResponseContext();

                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }

    };
    typedef tars::TC_AutoPtr<BServantPrxCallback> BServantPrxCallbackPtr;

    /* callback of promise async proxy for client */
    class BServantPrxCallbackPromise: public tars::ServantProxyCallback
    {
    public:
        virtual ~BServantPrxCallbackPromise(){}
    public:
        struct Promisetest: virtual public TC_HandleBase
        {
        public:
            tars::Int32 _ret;
            map<std::string, std::string> _mRspContext;
        };
        
        typedef tars::TC_AutoPtr< BServantPrxCallbackPromise::Promisetest > PromisetestPtr;

        BServantPrxCallbackPromise(const promise::Promise< BServantPrxCallbackPromise::PromisetestPtr > &promise)
        : _promise_test(promise)
        {}
        
        virtual void callback_test(const BServantPrxCallbackPromise::PromisetestPtr &ptr)
        {
            _promise_test.setValue(ptr);
        }
        virtual void callback_test_exception(tars::Int32 ret)
        {
            std::string str("");
            str += "Function:test_exception|Ret:";
            str += TC_Common::tostr(ret);
            _promise_test.setException(promise::copyException(str, ret));
        }

    protected:
        promise::Promise< BServantPrxCallbackPromise::PromisetestPtr > _promise_test;

    public:
        struct PromisetestHello: virtual public TC_HandleBase
        {
        public:
            tars::Int32 _ret;
            std::string sRsp;
            map<std::string, std::string> _mRspContext;
        };
        
        typedef tars::TC_AutoPtr< BServantPrxCallbackPromise::PromisetestHello > PromisetestHelloPtr;

        BServantPrxCallbackPromise(const promise::Promise< BServantPrxCallbackPromise::PromisetestHelloPtr > &promise)
        : _promise_testHello(promise)
        {}
        
        virtual void callback_testHello(const BServantPrxCallbackPromise::PromisetestHelloPtr &ptr)
        {
            _promise_testHello.setValue(ptr);
        }
        virtual void callback_testHello_exception(tars::Int32 ret)
        {
            std::string str("");
            str += "Function:testHello_exception|Ret:";
            str += TC_Common::tostr(ret);
            _promise_testHello.setException(promise::copyException(str, ret));
        }

    protected:
        promise::Promise< BServantPrxCallbackPromise::PromisetestHelloPtr > _promise_testHello;

    public:
        virtual int onDispatch(tars::ReqMessagePtr msg)
        {
            static ::std::string __BServant_all[]=
            {
                "test",
                "testHello"
            };

            pair<string*, string*> r = equal_range(__BServant_all, __BServant_all+2, string(msg->request.sFuncName));
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __BServant_all)
            {
                case 0:
                {
                    if (msg->response.iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_test_exception(msg->response.iRet);

                        return msg->response.iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(msg->response.sBuffer);

                    BServantPrxCallbackPromise::PromisetestPtr ptr = new BServantPrxCallbackPromise::Promisetest();

                    try
                    {
                        _is.read(ptr->_ret, 0, true);

                    }
                    catch(std::exception &ex)
                    {
                        callback_test_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }
                    catch(...)
                    {
                        callback_test_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }

                    ptr->_mRspContext = msg->response.context;

                    callback_test(ptr);

                    return tars::TARSSERVERSUCCESS;

                }
                case 1:
                {
                    if (msg->response.iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_testHello_exception(msg->response.iRet);

                        return msg->response.iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(msg->response.sBuffer);

                    BServantPrxCallbackPromise::PromisetestHelloPtr ptr = new BServantPrxCallbackPromise::PromisetestHello();

                    try
                    {
                        _is.read(ptr->_ret, 0, true);

                        _is.read(ptr->sRsp, 2, true);
                    }
                    catch(std::exception &ex)
                    {
                        callback_testHello_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }
                    catch(...)
                    {
                        callback_testHello_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }

                    ptr->_mRspContext = msg->response.context;

                    callback_testHello(ptr);

                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }

    };
    typedef tars::TC_AutoPtr<BServantPrxCallbackPromise> BServantPrxCallbackPromisePtr;

    /* callback of coroutine async proxy for client */
    class BServantCoroPrxCallback: public BServantPrxCallback
    {
    public:
        virtual ~BServantCoroPrxCallback(){}
    public:
        virtual const map<std::string, std::string> & getResponseContext() const { return _mRspContext; }

        virtual void setResponseContext(const map<std::string, std::string> &mContext) { _mRspContext = mContext; }

    public:
        int onDispatch(tars::ReqMessagePtr msg)
        {
            static ::std::string __BServant_all[]=
            {
                "test",
                "testHello"
            };

            pair<string*, string*> r = equal_range(__BServant_all, __BServant_all+2, string(msg->request.sFuncName));
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __BServant_all)
            {
                case 0:
                {
                    if (msg->response.iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_test_exception(msg->response.iRet);

                        return msg->response.iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(msg->response.sBuffer);
                    try
                    {
                        tars::Int32 _ret;
                        _is.read(_ret, 0, true);

                        setResponseContext(msg->response.context);

                        callback_test(_ret);

                    }
                    catch(std::exception &ex)
                    {
                        callback_test_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }
                    catch(...)
                    {
                        callback_test_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }

                    return tars::TARSSERVERSUCCESS;

                }
                case 1:
                {
                    if (msg->response.iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_testHello_exception(msg->response.iRet);

                        return msg->response.iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(msg->response.sBuffer);
                    try
                    {
                        tars::Int32 _ret;
                        _is.read(_ret, 0, true);

                        std::string sRsp;
                        _is.read(sRsp, 2, true);
                        setResponseContext(msg->response.context);

                        callback_testHello(_ret, sRsp);

                    }
                    catch(std::exception &ex)
                    {
                        callback_testHello_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }
                    catch(...)
                    {
                        callback_testHello_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }

                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }

    protected:
        map<std::string, std::string> _mRspContext;
    };
    typedef tars::TC_AutoPtr<BServantCoroPrxCallback> BServantCoroPrxCallbackPtr;

    /* proxy for client */
    class BServantProxy : public tars::ServantProxy
    {
    public:
        typedef map<string, string> TARS_CONTEXT;
        tars::Int32 test(const map<string, string> &context = TARS_CONTEXT(),map<string, string> * pResponseContext = NULL)
        {
            tars::TarsOutputStream<tars::BufferWriter> _os;
            tars::ResponsePacket rep;
            std::map<string, string> _mStatus;
            tars_invoke(tars::TARSNORMAL,"test", _os.getByteBuffer(), context, _mStatus, rep);
            if(pResponseContext)
            {
                *pResponseContext = rep.context;
            }

            tars::TarsInputStream<tars::BufferReader> _is;
            _is.setBuffer(rep.sBuffer);
            tars::Int32 _ret;
            _is.read(_ret, 0, true);
            return _ret;
        }

        void async_test(BServantPrxCallbackPtr callback,const map<string, string>& context = TARS_CONTEXT())
        {
            tars::TarsOutputStream<tars::BufferWriter> _os;
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"test", _os.getByteBuffer(), context, _mStatus, callback);
        }
        
        promise::Future< BServantPrxCallbackPromise::PromisetestPtr > promise_async_test(const map<string, string>& context)
        {
            promise::Promise< BServantPrxCallbackPromise::PromisetestPtr > promise;
            BServantPrxCallbackPromisePtr callback = new BServantPrxCallbackPromise(promise);

            tars::TarsOutputStream<tars::BufferWriter> _os;
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"test", _os.getByteBuffer(), context, _mStatus, callback);

            return promise.getFuture();
        }

        void coro_test(BServantCoroPrxCallbackPtr callback,const map<string, string>& context = TARS_CONTEXT())
        {
            tars::TarsOutputStream<tars::BufferWriter> _os;
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"test", _os.getByteBuffer(), context, _mStatus, callback, true);
        }

        tars::Int32 testHello(const std::string & sReq,std::string &sRsp,const map<string, string> &context = TARS_CONTEXT(),map<string, string> * pResponseContext = NULL)
        {
            tars::TarsOutputStream<tars::BufferWriter> _os;
            _os.write(sReq, 1);
            _os.write(sRsp, 2);
            tars::ResponsePacket rep;
            std::map<string, string> _mStatus;
            tars_invoke(tars::TARSNORMAL,"testHello", _os.getByteBuffer(), context, _mStatus, rep);
            if(pResponseContext)
            {
                *pResponseContext = rep.context;
            }

            tars::TarsInputStream<tars::BufferReader> _is;
            _is.setBuffer(rep.sBuffer);
            tars::Int32 _ret;
            _is.read(_ret, 0, true);
            _is.read(sRsp, 2, true);
            return _ret;
        }

        void async_testHello(BServantPrxCallbackPtr callback,const std::string &sReq,const map<string, string>& context = TARS_CONTEXT())
        {
            tars::TarsOutputStream<tars::BufferWriter> _os;
            _os.write(sReq, 1);
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"testHello", _os.getByteBuffer(), context, _mStatus, callback);
        }
        
        promise::Future< BServantPrxCallbackPromise::PromisetestHelloPtr > promise_async_testHello(const std::string &sReq,const map<string, string>& context)
        {
            promise::Promise< BServantPrxCallbackPromise::PromisetestHelloPtr > promise;
            BServantPrxCallbackPromisePtr callback = new BServantPrxCallbackPromise(promise);

            tars::TarsOutputStream<tars::BufferWriter> _os;
            _os.write(sReq, 1);
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"testHello", _os.getByteBuffer(), context, _mStatus, callback);

            return promise.getFuture();
        }

        void coro_testHello(BServantCoroPrxCallbackPtr callback,const std::string &sReq,const map<string, string>& context = TARS_CONTEXT())
        {
            tars::TarsOutputStream<tars::BufferWriter> _os;
            _os.write(sReq, 1);
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"testHello", _os.getByteBuffer(), context, _mStatus, callback, true);
        }

        BServantProxy* tars_hash(int64_t key)
        {
            return (BServantProxy*)ServantProxy::tars_hash(key);
        }

        BServantProxy* tars_consistent_hash(int64_t key)
        {
            return (BServantProxy*)ServantProxy::tars_consistent_hash(key);
        }

        BServantProxy* tars_set_timeout(int msecond)
        {
            return (BServantProxy*)ServantProxy::tars_set_timeout(msecond);
        }

    };
    typedef tars::TC_AutoPtr<BServantProxy> BServantPrx;

    /* servant for server */
    class BServant : public tars::Servant
    {
    public:
        virtual ~BServant(){}
        virtual tars::Int32 test(tars::TarsCurrentPtr current) = 0;
        static void async_response_test(tars::TarsCurrentPtr current, tars::Int32 _ret)
        {
            if (current->getRequestVersion() == TUPVERSION )
            {
                UniAttribute<tars::BufferWriter, tars::BufferReader>  tarsAttr;
                tarsAttr.setVersion(current->getRequestVersion());
                tarsAttr.put("", _ret);

                vector<char> sTupResponseBuffer;
                tarsAttr.encode(sTupResponseBuffer);
                current->sendResponse(tars::TARSSERVERSUCCESS, sTupResponseBuffer);
            }
            else
            {
                tars::TarsOutputStream<tars::BufferWriter> _os;
                _os.write(_ret, 0);

                current->sendResponse(tars::TARSSERVERSUCCESS, _os.getByteBuffer());
            }
        }

        virtual tars::Int32 testHello(const std::string & sReq,std::string &sRsp,tars::TarsCurrentPtr current) = 0;
        static void async_response_testHello(tars::TarsCurrentPtr current, tars::Int32 _ret, const std::string &sRsp)
        {
            if (current->getRequestVersion() == TUPVERSION )
            {
                UniAttribute<tars::BufferWriter, tars::BufferReader>  tarsAttr;
                tarsAttr.setVersion(current->getRequestVersion());
                tarsAttr.put("", _ret);
                tarsAttr.put("sRsp", sRsp);

                vector<char> sTupResponseBuffer;
                tarsAttr.encode(sTupResponseBuffer);
                current->sendResponse(tars::TARSSERVERSUCCESS, sTupResponseBuffer);
            }
            else
            {
                tars::TarsOutputStream<tars::BufferWriter> _os;
                _os.write(_ret, 0);

                _os.write(sRsp, 2);

                current->sendResponse(tars::TARSSERVERSUCCESS, _os.getByteBuffer());
            }
        }

    public:
        int onDispatch(tars::TarsCurrentPtr _current, vector<char> &_sResponseBuffer)
        {
            static ::std::string __TarsTest__BServant_all[]=
            {
                "test",
                "testHello"
            };

            pair<string*, string*> r = equal_range(__TarsTest__BServant_all, __TarsTest__BServant_all+2, _current->getFuncName());
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __TarsTest__BServant_all)
            {
                case 0:
                {
                    tars::TarsInputStream<tars::BufferReader> _is;
                    _is.setBuffer(_current->getRequestBuffer());
                    if (_current->getRequestVersion() == TUPVERSION)
                    {
                        UniAttribute<tars::BufferWriter, tars::BufferReader>  tarsAttr;
                        tarsAttr.setVersion(_current->getRequestVersion());
                        tarsAttr.decode(_current->getRequestBuffer());
                    }
                    else
                    {
                    }
                    tars::Int32 _ret = test(_current);
                    if(_current->isResponse())
                    {
                        if (_current->getRequestVersion() == TUPVERSION )
                        {
                            UniAttribute<tars::BufferWriter, tars::BufferReader>  tarsAttr;
                            tarsAttr.setVersion(_current->getRequestVersion());
                            tarsAttr.put("", _ret);
                            tarsAttr.encode(_sResponseBuffer);
                        }
                        else
                        {
                            tars::TarsOutputStream<tars::BufferWriter> _os;
                            _os.write(_ret, 0);
                            _os.swap(_sResponseBuffer);
                        }
                    }
                    return tars::TARSSERVERSUCCESS;

                }
                case 1:
                {
                    tars::TarsInputStream<tars::BufferReader> _is;
                    _is.setBuffer(_current->getRequestBuffer());
                    std::string sReq;
                    std::string sRsp;
                    if (_current->getRequestVersion() == TUPVERSION)
                    {
                        UniAttribute<tars::BufferWriter, tars::BufferReader>  tarsAttr;
                        tarsAttr.setVersion(_current->getRequestVersion());
                        tarsAttr.decode(_current->getRequestBuffer());
                        tarsAttr.get("sReq", sReq);
                        tarsAttr.getByDefault("sRsp", sRsp, sRsp);
                    }
                    else
                    {
                        _is.read(sReq, 1, true);
                        _is.read(sRsp, 2, false);
                    }
                    tars::Int32 _ret = testHello(sReq,sRsp, _current);
                    if(_current->isResponse())
                    {
                        if (_current->getRequestVersion() == TUPVERSION )
                        {
                            UniAttribute<tars::BufferWriter, tars::BufferReader>  tarsAttr;
                            tarsAttr.setVersion(_current->getRequestVersion());
                            tarsAttr.put("", _ret);
                            tarsAttr.put("sRsp", sRsp);
                            tarsAttr.encode(_sResponseBuffer);
                        }
                        else
                        {
                            tars::TarsOutputStream<tars::BufferWriter> _os;
                            _os.write(_ret, 0);
                            _os.write(sRsp, 2);
                            _os.swap(_sResponseBuffer);
                        }
                    }
                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }
    };


}



#endif
