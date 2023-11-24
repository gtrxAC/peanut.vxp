
#undef DEF_METHOD0
#undef DEF_METHOD1
#undef DEF_METHOD2
#undef DEF_METHOD3
#undef DEF_METHOD4
#undef DEF_METHOD5
#undef DEF_METHOD6
#undef DEF_METHOD7
#undef DEF_METHOD8
#undef DEF_METHOD9
#undef DEF_METHOD10
#undef DEF_METHOD11
#undef DEF_METHOD12
#undef DEF_METHOD13
#undef DEF_METHOD14


#undef DEF_METHOD_RELEASE
#undef DEF_METHOD_ADDREF
#undef DEF_INTERFACE
#undef DEF_INTERFACE_END

// Define GS_IBase DEF
#define DEF_METHODS_GS_IBase(IOBJ) \
    DEF_METHOD_ADDREF(IOBJ, int, addRef)\
    DEF_METHOD_RELEASE(IOBJ, int, release)\
    DEF_METHOD2(IOBJ, int, queryInterface, int, iid, GS_IBase**, pptr)


// Following macro will output such like follows code:
/*
class GS_IBase
{
public:
    virtual int addRef() = 0;
    virtual int release() = 0;
    virtual int queryInterface(int iid, GS_IBase** pptr) = 0;
};
GS_IBase* GS_IBaseProxy_bind(GS_IBase* ptr);

*/

#if defined(__cplusplus) && defined(GS_GEN_INTERFACE)

//#pragma message("Define GS_GEN_INTERFACE")

#define DEF_INTERFACE(IOBJ, IPARENT) \
class IOBJ : public IPARENT \
{ \
public:

#define DEF_INTERFACE_END(IOBJ) \
};\
IOBJ* IOBJ##Proxy_bind(IOBJ* ptr);

#define DEF_METHOD0(IOBJ, _RTYPE, _NAME) \
    virtual _RTYPE CALLCC _NAME () = 0;

#define DEF_METHOD1(IOBJ, _RTYPE, _NAME, _T1, _A1) \
    virtual _RTYPE CALLCC _NAME (_T1 _A1) = 0;

#define DEF_METHOD2(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2) \
    virtual _RTYPE CALLCC _NAME (_T1 _A1, _T2 _A2) = 0;

#define DEF_METHOD3(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3) \
    virtual _RTYPE CALLCC _NAME (_T1 _A1, _T2 _A2, _T3 _A3) = 0;

#define DEF_METHOD4(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4) \
    virtual _RTYPE CALLCC _NAME (_T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4) = 0;

#define DEF_METHOD5(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5, _A5) \
    virtual _RTYPE CALLCC _NAME (_T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4,_T5 _A5) = 0;

#define DEF_METHOD6(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6) \
    virtual _RTYPE CALLCC _NAME (_T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4, _T5 _A5, _T6 _A6) = 0;

#define DEF_METHOD7(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4, _T5, _A5, _T6, _A6, _T7, _A7) \
    virtual _RTYPE CALLCC _NAME (_T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4, _T5 _A5, _T6 _A6, _T7 _A7) = 0;

#define DEF_METHOD8(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4, _T5, _A5, _T6, _A6, _T7, _A7, _T8, _A8) \
    virtual _RTYPE CALLCC _NAME (_T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4, _T5 _A5, _T6 _A6, _T7 _A7, _T8 _A8) = 0;

#define DEF_METHOD9(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4, _T5, _A5, _T6, _A6, _T7, _A7, _T8, _A8, _T9, _A9) \
    virtual _RTYPE CALLCC _NAME (_T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4, _T5 _A5, _T6 _A6, _T7 _A7, _T8 _A8, _T9 _A9) = 0;

#define DEF_METHOD10(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4, _T5, _A5, _T6, _A6, _T7, _A7, _T8, _A8, _T9, _A9, _T10, _A10) \
    virtual _RTYPE CALLCC _NAME (_T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4, _T5 _A5, _T6 _A6, _T7 _A7, _T8 _A8, _T9 _A9, _T10 _A10) = 0;

#define DEF_METHOD11(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4, _T5, _A5, _T6, _A6, _T7, _A7, _T8, _A8, _T9, _A9, _T10, _A10, _T11, _A11) \
    virtual _RTYPE CALLCC _NAME (_T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4, _T5 _A5, _T6 _A6, _T7 _A7, _T8 _A8, _T9 _A9, _T10 _A10,_T11 _A11) = 0;

#define DEF_METHOD12(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4, _T5, _A5, _T6, _A6, _T7, _A7, _T8, _A8, _T9, _A9, _T10, _A10, _T11, _A11, _T12, _A12) \
    virtual _RTYPE CALLCC _NAME (_T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4, _T5 _A5, _T6 _A6, _T7 _A7, _T8 _A8, _T9 _A9, _T10 _A10,_T11 _A11,_T12 _A12) = 0;

#define DEF_METHOD13(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4, _T5, _A5, _T6, _A6, _T7, _A7, _T8, _A8, _T9, _A9, _T10, _A10, _T11, _A11, _T12, _A12, _T13, _A13) \
    virtual _RTYPE CALLCC _NAME (_T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4, _T5 _A5, _T6 _A6, _T7 _A7, _T8 _A8, _T9 _A9, _T10 _A10, _T11 _A11, _T12 _A12, _T13 _A13) = 0;

#define DEF_METHOD14(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4, _T5, _A5, _T6, _A6, _T7, _A7, _T8, _A8, _T9, _A9, _T10, _A10, _T11, _A11, _T12, _A12, _T13, _A13, _T14, _A14) \
    virtual _RTYPE CALLCC _NAME (_T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4, _T5 _A5, _T6 _A6, _T7 _A7, _T8 _A8, _T9 _A9, _T10 _A10, _T11 _A11, _T12 _A12, _T13 _A13, _T14 _A14) = 0;


#define DEF_METHOD_RELEASE   DEF_METHOD0
#define DEF_METHOD_ADDREF    DEF_METHOD0

#endif // __cplusplus && GS_GEN_INTERFACE



// Following macro will output such like follows code:
/*
struct GS_IBaseProxy;
struct GS_IBaseVT
{
    int (CALLCC *addRef)(GS_IBaseProxy* self);
    int (CALLCC *release)(GS_IBaseProxy* self);
    int (CALLCC *queryInterface)(GS_IBaseProxy* self, int iid, GS_IBase** pptr);
};

struct GS_IBaseProxy : public GS_IBaseProxyBase
{
    const GS_IBaseVT*      vt;
    GS_IBase*              obj;

    GS_IBaseProxy(GS_IBase* ptr);
};
*/

#if defined(__cplusplus) && defined(GS_GEN_PROXY_HEADER)

//#pragma message("Define GS_GEN_PROXY_HEADER")

#define DEF_INTERFACE(IOBJ, IPARENT) \
struct IOBJ##Proxy; \
struct IOBJ##VT \
{

#define DEF_INTERFACE_END(IOBJ) \
};\
struct IOBJ##Proxy : public GS_IBaseProxyBase\
{ \
    const IOBJ##VT*     vt; \
    IOBJ*               obj; \
    int                 refCount; \
    IOBJ##Proxy(IOBJ* ptr); \
};

#define DEF_METHOD0(IOBJ, _RTYPE, _NAME) \
    _RTYPE (CALLCC *_NAME) (IOBJ##Proxy* self);

#define DEF_METHOD1(IOBJ, _RTYPE, _NAME, _T1, _A1) \
    _RTYPE (CALLCC *_NAME) (IOBJ##Proxy* self, _T1 _A1);

#define DEF_METHOD2(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2) \
    _RTYPE (CALLCC *_NAME) (IOBJ##Proxy* self, _T1 _A1, _T2 _A2);

#define DEF_METHOD3(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3) \
    _RTYPE (CALLCC *_NAME) (IOBJ##Proxy* self, _T1 _A1, _T2 _A2, _T3 _A3);

#define DEF_METHOD4(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4) \
    _RTYPE (CALLCC *_NAME) (IOBJ##Proxy* self, _T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4);

#define DEF_METHOD5(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5) \
    _RTYPE (CALLCC *_NAME) (IOBJ##Proxy* self, _T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4,_T5 _A5);

#define DEF_METHOD6(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6) \
    _RTYPE (CALLCC *_NAME) (IOBJ##Proxy* self, _T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4,_T5 _A5,_T6 _A6);

#define DEF_METHOD7(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6,_T7,_A7) \
    _RTYPE (CALLCC *_NAME) (IOBJ##Proxy* self, _T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4, _T5 _A5, _T6 _A6, _T7 _A7);

#define DEF_METHOD8(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6,_T7,_A7,_T8,_A8) \
    _RTYPE (CALLCC *_NAME) (IOBJ##Proxy* self, _T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4, _T5 _A5, _T6 _A6, _T7 _A7, _T8 _A8);

#define DEF_METHOD9(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6,_T7,_A7,_T8,_A8,_T9,_A9) \
    _RTYPE (CALLCC *_NAME) (IOBJ##Proxy* self, _T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4, _T5 _A5, _T6 _A6, _T7 _A7, _T8 _A8, _T9 _A9);

#define DEF_METHOD10(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6,_T7,_A7,_T8,_A8,_T9,_A9,_T10,_A10) \
        _RTYPE (CALLCC *_NAME) (IOBJ##Proxy* self, _T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4, _T5 _A5, _T6 _A6, _T7 _A7, _T8 _A8, _T9 _A9, _T10 _A10);

#define DEF_METHOD11(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6,_T7,_A7,_T8,_A8,_T9,_A9,_T10,_A10, _T11,_A11) \
        _RTYPE (CALLCC *_NAME) (IOBJ##Proxy* self, _T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4, _T5 _A5, _T6 _A6, _T7 _A7, _T8 _A8, _T9 _A9, _T10 _A10, _T11 _A11);

#define DEF_METHOD12(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6,_T7,_A7,_T8,_A8,_T9,_A9,_T10,_A10, _T11,_A11, _T12,_A12) \
        _RTYPE (CALLCC *_NAME) (IOBJ##Proxy* self, _T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4, _T5 _A5, _T6 _A6, _T7 _A7, _T8 _A8, _T9 _A9, _T10 _A10, _T11 _A11, _T12 _A12);

#define DEF_METHOD13(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4, _T5, _A5, _T6, _A6, _T7, _A7, _T8, _A8, _T9, _A9, _T10, _A10, _T11, _A11,_T12, _A12, _T13, _A13) \
        _RTYPE (CALLCC *_NAME) (IOBJ##Proxy* self, _T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4, _T5 _A5, _T6 _A6, _T7 _A7, _T8 _A8, _T9 _A9, _T10 _A10, _T11 _A11, _T12 _A12, _T13 _A13);

#define DEF_METHOD14(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4, _T5, _A5, _T6, _A6, _T7, _A7, _T8, _A8, _T9, _A9, _T10, _A10, _T11, _A11, _T12, _A12, _T13, _A13, _T14, _A14) \
        _RTYPE (CALLCC *_NAME) (IOBJ##Proxy* self, _T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4, _T5 _A5, _T6 _A6, _T7 _A7, _T8 _A8, _T9 _A9, _T10 _A10, _T11 _A11, _T12 _A12, _T13 _A13, _T14 _A14);


#define DEF_METHOD_RELEASE   DEF_METHOD0
#define DEF_METHOD_ADDREF    DEF_METHOD0

#endif


// Following macro will output such like follows code:
/*
int CALLCC GS_IBaseProxy_addRef(GS_IBaseProxy* self)
{
    self->obj->refCount++;
    return self->obj->addRef();
}

int CALLCC GS_IBaseProxy_release(GS_IBaseProxy* self)
{
    self->obj->refCount--;
    int r = self->obj->release();
    if (self->obj->refCount == 0)
    {
        delete self;
    }
    return r;
}

int CALLCC GS_IBaseProxy_queryInterface(GS_IBaseProxy* self, int iid, GS_IBase** pptr)
{
    return self->obj->queryInterface(iid, pptr);
}
*/

#if defined(__cplusplus) && defined(GS_GEN_PROXY_IMPL)

//#pragma message("Define GS_GEN_PROXY_IMPL")

#define DEF_INTERFACE(IOBJ, IPARENT)
#define DEF_INTERFACE_END(IOBJ)


#define DEF_METHOD0(IOBJ, _RTYPE, _NAME) \
_RTYPE CALLCC IOBJ##Proxy_##_NAME(IOBJ##Proxy* self) \
{ \
    return self->obj->_NAME(); \
}

#define DEF_METHOD1(IOBJ, _RTYPE, _NAME, _T1, _A1) \
_RTYPE CALLCC IOBJ##Proxy_##_NAME(IOBJ##Proxy* self, _T1 _A1) \
{ \
    return self->obj->_NAME(_A1); \
}

#define DEF_METHOD2(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2) \
_RTYPE CALLCC IOBJ##Proxy_##_NAME(IOBJ##Proxy* self, _T1 _A1, _T2 _A2) \
{ \
    return self->obj->_NAME(_A1, _A2); \
}

#define DEF_METHOD3(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3) \
_RTYPE CALLCC IOBJ##Proxy_##_NAME(IOBJ##Proxy* self, _T1 _A1, _T2 _A2, _T3 _A3) \
{ \
    return self->obj->_NAME(_A1, _A2, _A3); \
}

#define DEF_METHOD4(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4) \
_RTYPE CALLCC IOBJ##Proxy_##_NAME(IOBJ##Proxy* self, _T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4) \
{ \
    return self->obj->_NAME(_A1, _A2, _A3, _A4); \
}

#define DEF_METHOD5(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5) \
_RTYPE CALLCC IOBJ##Proxy_##_NAME(IOBJ##Proxy* self, _T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4,_T5 _A5) \
{ \
    return self->obj->_NAME(_A1, _A2, _A3, _A4,_A5); \
}

#define DEF_METHOD6(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6) \
_RTYPE CALLCC IOBJ##Proxy_##_NAME(IOBJ##Proxy* self, _T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4,_T5 _A5,_T6 _A6) \
{ \
    return self->obj->_NAME(_A1, _A2, _A3, _A4,_A5,_A6); \
}

#define DEF_METHOD7(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6,_T7,_A7) \
_RTYPE CALLCC IOBJ##Proxy_##_NAME(IOBJ##Proxy* self, _T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4,_T5 _A5,_T6 _A6,_T7 _A7) \
{ \
    return self->obj->_NAME(_A1, _A2, _A3, _A4,_A5,_A6,_A7); \
}

#define DEF_METHOD8(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6,_T7,_A7,_T8,_A8) \
_RTYPE CALLCC IOBJ##Proxy_##_NAME(IOBJ##Proxy* self, _T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4, _T5 _A5, _T6 _A6, _T7 _A7, _T8 _A8) \
{ \
    return self->obj->_NAME(_A1, _A2, _A3, _A4,_A5,_A6,_A7,_A8); \
}

#define DEF_METHOD9(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6,_T7,_A7,_T8,_A8,_T9,_A9) \
_RTYPE CALLCC IOBJ##Proxy_##_NAME(IOBJ##Proxy* self, _T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4,_T5 _A5,_T6 _A6,_T7 _A7,_T8 _A8,_T9 _A9) \
{ \
    return self->obj->_NAME(_A1, _A2, _A3, _A4,_A5,_A6,_A7,_A8,_A9); \
}

#define DEF_METHOD10(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6,_T7,_A7,_T8,_A8,_T9,_A9,_T10,_A10) \
_RTYPE CALLCC IOBJ##Proxy_##_NAME(IOBJ##Proxy* self, _T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4,_T5 _A5,_T6 _A6,_T7 _A7,_T8 _A8,_T9 _A9,_T10 _A10) \
{ \
    return self->obj->_NAME(_A1, _A2, _A3, _A4,_A5,_A6,_A7,_A8,_A9,_A10); \
}

#define DEF_METHOD11(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6,_T7,_A7,_T8,_A8,_T9,_A9,_T10,_A10,_T11,_A11) \
_RTYPE CALLCC IOBJ##Proxy_##_NAME(IOBJ##Proxy* self, _T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4,_T5 _A5,_T6 _A6,_T7 _A7,_T8 _A8,_T9 _A9,_T10 _A10,_T11 _A11) \
{ \
    return self->obj->_NAME(_A1, _A2, _A3, _A4,_A5,_A6,_A7,_A8,_A9,_A10,_A11); \
}

#define DEF_METHOD12(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6,_T7,_A7,_T8,_A8,_T9,_A9,_T10,_A10,_T11,_A11,_T12,_A12) \
_RTYPE CALLCC IOBJ##Proxy_##_NAME(IOBJ##Proxy* self, _T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4,_T5 _A5,_T6 _A6,_T7 _A7,_T8 _A8,_T9 _A9,_T10 _A10,_T11 _A11,_T12 _A12) \
{ \
    return self->obj->_NAME(_A1, _A2, _A3, _A4,_A5,_A6,_A7,_A8,_A9,_A10,_A11,_A12); \
}

#define DEF_METHOD13(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6,_T7,_A7,_T8,_A8,_T9,_A9,_T10,_A10,_T11,_A11,_T12,_A12,_T13,_A13) \
_RTYPE CALLCC IOBJ##Proxy_##_NAME(IOBJ##Proxy* self, _T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4,_T5 _A5,_T6 _A6,_T7 _A7,_T8 _A8,_T9 _A9,_T10 _A10,_T11 _A11,_T12 _A12,_T13 _A13) \
{ \
    return self->obj->_NAME(_A1, _A2, _A3, _A4,_A5,_A6,_A7,_A8,_A9,_A10,_A11,_A12,_A13); \
}

#define DEF_METHOD14(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6,_T7,_A7,_T8,_A8,_T9, _A9,_T10, _A10, _T11, _A11, _T12, _A12,_T13,_A13,_T14,_A14) \
_RTYPE CALLCC IOBJ##Proxy_##_NAME(IOBJ##Proxy* self, _T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4,_T5 _A5,_T6 _A6,_T7 _A7,_T8 _A8,_T9 _A9,_T10 _A10, _T11 _A11, _T12 _A12,_T13 _A13,_T14 _A14) \
{ \
    return self->obj->_NAME(_A1, _A2, _A3, _A4,_A5,_A6,_A7,_A8,_A9,_A10,_A11,_A12,_A13,_A14); \
}

#define DEF_METHOD_RELEASE(IOBJ, _RTYPE, _NAME) \
_RTYPE CALLCC IOBJ##Proxy_##_NAME(IOBJ##Proxy* self) \
{ \
    IOBJ * obj = self->obj;\
    self->refCount--; \
    obj->addRef();\
    obj->release();\
    if (self->refCount == 0) \
    { \
        delete self; \
    } \
    int r = obj->_NAME(); \
    return r; \
}

#define DEF_METHOD_ADDREF(IOBJ, _RTYPE, _NAME) \
_RTYPE CALLCC IOBJ##Proxy_##_NAME(IOBJ##Proxy* self) \
{ \
    self->refCount++; \
    return self->obj->_NAME(); \
}

#endif // __cplusplus && GS_GEN_PROXY_IMPL


// Following macro will output such like follows code:
/*
const GS_IBaseVT g_GS_IBaseVT = {
    &GS_IBaseProxy_addRef,
    &GS_IBaseProxy_release,
    &GS_IBaseProxy_queryInterface
};

GS_IBaseProxy::GS_IBaseProxy(GS_IBase* ptr)
{
    vt = &g_GS_IBaseVT;
    obj = ptr;
    refCount = 1;
}

GS_IBase* GS_IBaseProxy_bind(GS_IBase* ptr)
{
    GS_IBase* p = NULL;
    GS_NEW_EX(p, GS_IBaseProxy, ptr);
    return p;
}

*/

#if defined(__cplusplus) && defined(GS_GEN_PROXY_VT)

//#pragma message("Define GS_GEN_PROXY_VT")

#define DEF_INTERFACE(IOBJ, IPARENT) \
const IOBJ##VT g_##IOBJ##VT = {

#define DEF_INTERFACE_END(IOBJ) \
}; \
IOBJ##Proxy::IOBJ##Proxy(IOBJ* ptr) \
{ \
    vt = &g_##IOBJ##VT; \
    obj = ptr; \
    refCount = 1; \
} \
IOBJ* IOBJ##Proxy_bind(IOBJ* ptr) \
{ \
    IOBJ##Proxy* p = NULL; \
    GS_NEW_EX(p, IOBJ##Proxy, (ptr)); \
    return (IOBJ*)p; \
}

#define DEF_METHOD0(IOBJ, _RTYPE, _NAME)                       &IOBJ##Proxy_##_NAME,   
#define DEF_METHOD1(IOBJ, _RTYPE, _NAME, _T1, _A1)             &IOBJ##Proxy_##_NAME,
#define DEF_METHOD2(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2)   &IOBJ##Proxy_##_NAME,
#define DEF_METHOD3(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3)   &IOBJ##Proxy_##_NAME,
#define DEF_METHOD4(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4)   &IOBJ##Proxy_##_NAME,
#define DEF_METHOD5(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5)   &IOBJ##Proxy_##_NAME,
#define DEF_METHOD6(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6)   &IOBJ##Proxy_##_NAME,
#define DEF_METHOD7(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6,_T7,_A7)   &IOBJ##Proxy_##_NAME,
#define DEF_METHOD8(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6,_T7,_A7,_T8,_A8)   &IOBJ##Proxy_##_NAME,
#define DEF_METHOD9(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6,_T7,_A7,_T8,_A8,_T9,_A9)   &IOBJ##Proxy_##_NAME,
#define DEF_METHOD10(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6,_T7,_A7,_T8,_A8,_T9, _A9,_T10, _A10)   &IOBJ##Proxy_##_NAME,
#define DEF_METHOD11(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6,_T7,_A7,_T8,_A8,_T9, _A9,_T10, _A10, _T11, _A11)   &IOBJ##Proxy_##_NAME,
#define DEF_METHOD12(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6,_T7,_A7,_T8,_A8,_T9, _A9,_T10, _A10, _T11, _A11, _T12, _A12)   &IOBJ##Proxy_##_NAME,
#define DEF_METHOD13(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6,_T7,_A7,_T8,_A8,_T9, _A9,_T10, _A10, _T11, _A11, _T12, _A12, _T13, _A13_)   &IOBJ##Proxy_##_NAME,
#define DEF_METHOD14(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6,_T7,_A7,_T8,_A8,_T9, _A9,_T10, _A10, _T11, _A11, _T12, _A12, _T13, _A13, _T14, _A14)   &IOBJ##Proxy_##_NAME,



#define DEF_METHOD_RELEASE   DEF_METHOD0
#define DEF_METHOD_ADDREF    DEF_METHOD0

#endif // __cplusplus && GS_GEN_PROXY_VT





// Following macro will output such like follows code:
/*
struct GS_IBase;
struct GS_IBaseVT;
typedef struct GS_IBase GS_IBase;
typedef struct GS_IBaseVT GS_IBaseVT;
struct GS_IBaseVT
{
    int (CALLCC *addRef)(GS_IBase* self);
    int (CALLCC *release)(GS_IBase* self);
    int (CALLCC *queryInterface)(GS_IBase* self, int iid, GS_IBase** pptr);
};

struct GS_IBase
{
    const GS_IBaseVT*      vt;
};
*/

#if defined(GS_C_INTERFACE)

//#pragma message("Define GS_C_INTERFACE")

#define DEF_INTERFACE(IOBJ, IPARENT) \
struct IOBJ##Proxy; \
struct IOBJ##VT; \
typedef struct IOBJ IOBJ; \
typedef struct IOBJ##VT IOBJ##VT; \
struct IOBJ##VT \
{

#define DEF_INTERFACE_END(IOBJ) \
};\
struct IOBJ \
{ \
    const IOBJ##VT*     vt; \
};

#define DEF_METHOD0(IOBJ, _RTYPE, _NAME) \
    _RTYPE (CALLCC *_NAME) (IOBJ* self);

#define DEF_METHOD1(IOBJ, _RTYPE, _NAME, _T1, _A1) \
    _RTYPE (CALLCC *_NAME) (IOBJ* self, _T1 _A1);

#define DEF_METHOD2(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2) \
    _RTYPE (CALLCC *_NAME) (IOBJ* self, _T1 _A1, _T2 _A2);

#define DEF_METHOD3(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3) \
    _RTYPE (CALLCC *_NAME) (IOBJ* self, _T1 _A1, _T2 _A2, _T3 _A3);

#define DEF_METHOD4(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4) \
    _RTYPE (CALLCC *_NAME) (IOBJ* self, _T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4);

#define DEF_METHOD5(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5) \
    _RTYPE (CALLCC *_NAME) (IOBJ* self, _T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4,_T5 _A5);

#define DEF_METHOD6(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6) \
    _RTYPE (CALLCC *_NAME) (IOBJ* self, _T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4,_T5 _A5,_T6 _A6);

#define DEF_METHOD7(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6,_T7,_A7) \
    _RTYPE (CALLCC *_NAME) (IOBJ* self, _T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4,_T5 _A5,_T6 _A6,_T7 _A7);

#define DEF_METHOD8(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6,_T7,_A7,_T8,_A8) \
    _RTYPE (CALLCC *_NAME) (IOBJ* self, _T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4, _T5 _A5, _T6 _A6, _T7 _A7, _T8 _A8);

#define DEF_METHOD9(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6,_T7,_A7,_T8,_A8,_T9,_A9) \
    _RTYPE (CALLCC *_NAME) (IOBJ* self, _T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4,_T5 _A5,_T6 _A6,_T7 _A7,_T8 _A8,_T9 _A9);

#define DEF_METHOD10(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6,_T7,_A7,_T8,_A8,_T9,_A9,_T10,_A10) \
    _RTYPE (CALLCC *_NAME) (IOBJ* self, _T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4,_T5 _A5,_T6 _A6,_T7 _A7,_T8 _A8,_T9 _A9,_T10 _A10);

#define DEF_METHOD11(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6,_T7,_A7,_T8,_A8,_T9,_A9,_T10,_A10,_T11,_A11) \
    _RTYPE (CALLCC *_NAME) (IOBJ* self, _T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4,_T5 _A5,_T6 _A6,_T7 _A7,_T8 _A8,_T9 _A9,_T10 _A10,_T11 _A11);

#define DEF_METHOD12(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6,_T7,_A7,_T8,_A8,_T9,_A9,_T10,_A10,_T11,_A11,_T12,_A12) \
    _RTYPE (CALLCC *_NAME) (IOBJ* self, _T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4,_T5 _A5,_T6 _A6,_T7 _A7,_T8 _A8,_T9 _A9,_T10 _A10,_T11 _A11,_T12 _A12);

#define DEF_METHOD13(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6,_T7,_A7,_T8,_A8,_T9,_A9,_T10,_A10,_T11,_A11,_T12,_A12,_T13,_A13) \
    _RTYPE (CALLCC *_NAME) (IOBJ* self, _T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4,_T5 _A5,_T6 _A6,_T7 _A7,_T8 _A8,_T9 _A9,_T10 _A10,_T11 _A11,_T12 _A12,_T13 _A13);

#define DEF_METHOD14(IOBJ, _RTYPE, _NAME, _T1, _A1, _T2, _A2, _T3, _A3, _T4, _A4,_T5,_A5,_T6,_A6,_T7,_A7,_T8,_A8,_T9, _A9,_T10, _A10, _T11, _A11, _T12, _A12,_T13,_A13,_T14,_A14) \
    _RTYPE (CALLCC *_NAME) (IOBJ* self, _T1 _A1, _T2 _A2, _T3 _A3, _T4 _A4,_T5 _A5,_T6 _A6,_T7 _A7,_T8 _A8,_T9 _A9,_T10 _A10,_T11 _A11,_T12 _A12,_T13 _A13,_T14 _A14);


#define DEF_METHOD_RELEASE   DEF_METHOD0
#define DEF_METHOD_ADDREF    DEF_METHOD0

#endif // GS_C_INTERFACE

