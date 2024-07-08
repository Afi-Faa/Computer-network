//
// Generated file, do not edit! Created by opp_msgtool 6.0 from packet.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "packet_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

applicationPacket::applicationPacket()
{
}

void __doPacking(omnetpp::cCommBuffer *b, const applicationPacket& a)
{
    doParsimPacking(b,a.data);
    doParsimPacking(b,a.protocol);
    doParsimPacking(b,a.ip);
    doParsimPacking(b,a.portNo);
}

void __doUnpacking(omnetpp::cCommBuffer *b, applicationPacket& a)
{
    doParsimUnpacking(b,a.data);
    doParsimUnpacking(b,a.protocol);
    doParsimUnpacking(b,a.ip);
    doParsimUnpacking(b,a.portNo);
}

class applicationPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_data,
        FIELD_protocol,
        FIELD_ip,
        FIELD_portNo,
    };
  public:
    applicationPacketDescriptor();
    virtual ~applicationPacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(applicationPacketDescriptor)

applicationPacketDescriptor::applicationPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(applicationPacket)), "")
{
    propertyNames = nullptr;
}

applicationPacketDescriptor::~applicationPacketDescriptor()
{
    delete[] propertyNames;
}

bool applicationPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<applicationPacket *>(obj)!=nullptr;
}

const char **applicationPacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *applicationPacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int applicationPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 4+base->getFieldCount() : 4;
}

unsigned int applicationPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_data
        FD_ISEDITABLE,    // FIELD_protocol
        FD_ISEDITABLE,    // FIELD_ip
        FD_ISEDITABLE,    // FIELD_portNo
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *applicationPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "data",
        "protocol",
        "ip",
        "portNo",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int applicationPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "data") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "protocol") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "ip") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "portNo") == 0) return baseIndex + 3;
    return base ? base->findField(fieldName) : -1;
}

const char *applicationPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_data
        "int",    // FIELD_protocol
        "int",    // FIELD_ip
        "int",    // FIELD_portNo
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **applicationPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *applicationPacketDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int applicationPacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    applicationPacket *pp = omnetpp::fromAnyPtr<applicationPacket>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void applicationPacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    applicationPacket *pp = omnetpp::fromAnyPtr<applicationPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'applicationPacket'", field);
    }
}

const char *applicationPacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    applicationPacket *pp = omnetpp::fromAnyPtr<applicationPacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string applicationPacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    applicationPacket *pp = omnetpp::fromAnyPtr<applicationPacket>(object); (void)pp;
    switch (field) {
        case FIELD_data: return long2string(pp->data);
        case FIELD_protocol: return long2string(pp->protocol);
        case FIELD_ip: return long2string(pp->ip);
        case FIELD_portNo: return long2string(pp->portNo);
        default: return "";
    }
}

void applicationPacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    applicationPacket *pp = omnetpp::fromAnyPtr<applicationPacket>(object); (void)pp;
    switch (field) {
        case FIELD_data: pp->data = string2long(value); break;
        case FIELD_protocol: pp->protocol = string2long(value); break;
        case FIELD_ip: pp->ip = string2long(value); break;
        case FIELD_portNo: pp->portNo = string2long(value); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'applicationPacket'", field);
    }
}

omnetpp::cValue applicationPacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    applicationPacket *pp = omnetpp::fromAnyPtr<applicationPacket>(object); (void)pp;
    switch (field) {
        case FIELD_data: return pp->data;
        case FIELD_protocol: return pp->protocol;
        case FIELD_ip: return pp->ip;
        case FIELD_portNo: return pp->portNo;
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'applicationPacket' as cValue -- field index out of range?", field);
    }
}

void applicationPacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    applicationPacket *pp = omnetpp::fromAnyPtr<applicationPacket>(object); (void)pp;
    switch (field) {
        case FIELD_data: pp->data = omnetpp::checked_int_cast<int>(value.intValue()); break;
        case FIELD_protocol: pp->protocol = omnetpp::checked_int_cast<int>(value.intValue()); break;
        case FIELD_ip: pp->ip = omnetpp::checked_int_cast<int>(value.intValue()); break;
        case FIELD_portNo: pp->portNo = omnetpp::checked_int_cast<int>(value.intValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'applicationPacket'", field);
    }
}

const char *applicationPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr applicationPacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    applicationPacket *pp = omnetpp::fromAnyPtr<applicationPacket>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void applicationPacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    applicationPacket *pp = omnetpp::fromAnyPtr<applicationPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'applicationPacket'", field);
    }
}

Register_Class(TcpIpPacket)

TcpIpPacket::TcpIpPacket(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

TcpIpPacket::TcpIpPacket(const TcpIpPacket& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

TcpIpPacket::~TcpIpPacket()
{
}

TcpIpPacket& TcpIpPacket::operator=(const TcpIpPacket& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void TcpIpPacket::copy(const TcpIpPacket& other)
{
    this->srcAdd = other.srcAdd;
    this->destAdd = other.destAdd;
    this->appHeader = other.appHeader;
    this->tcpHeader = other.tcpHeader;
    this->ipHeader = other.ipHeader;
    this->dllHeader = other.dllHeader;
    this->phyHeader = other.phyHeader;
}

void TcpIpPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->srcAdd);
    doParsimPacking(b,this->destAdd);
    doParsimPacking(b,this->appHeader);
    doParsimPacking(b,this->tcpHeader);
    doParsimPacking(b,this->ipHeader);
    doParsimPacking(b,this->dllHeader);
    doParsimPacking(b,this->phyHeader);
}

void TcpIpPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->srcAdd);
    doParsimUnpacking(b,this->destAdd);
    doParsimUnpacking(b,this->appHeader);
    doParsimUnpacking(b,this->tcpHeader);
    doParsimUnpacking(b,this->ipHeader);
    doParsimUnpacking(b,this->dllHeader);
    doParsimUnpacking(b,this->phyHeader);
}

int TcpIpPacket::getSrcAdd() const
{
    return this->srcAdd;
}

void TcpIpPacket::setSrcAdd(int srcAdd)
{
    this->srcAdd = srcAdd;
}

int TcpIpPacket::getDestAdd() const
{
    return this->destAdd;
}

void TcpIpPacket::setDestAdd(int destAdd)
{
    this->destAdd = destAdd;
}

const applicationPacket& TcpIpPacket::getAppHeader() const
{
    return this->appHeader;
}

void TcpIpPacket::setAppHeader(const applicationPacket& appHeader)
{
    this->appHeader = appHeader;
}

int TcpIpPacket::getTcpHeader() const
{
    return this->tcpHeader;
}

void TcpIpPacket::setTcpHeader(int tcpHeader)
{
    this->tcpHeader = tcpHeader;
}

const char * TcpIpPacket::getIpHeader() const
{
    return this->ipHeader.c_str();
}

void TcpIpPacket::setIpHeader(const char * ipHeader)
{
    this->ipHeader = ipHeader;
}

const char * TcpIpPacket::getDllHeader() const
{
    return this->dllHeader.c_str();
}

void TcpIpPacket::setDllHeader(const char * dllHeader)
{
    this->dllHeader = dllHeader;
}

const char * TcpIpPacket::getPhyHeader() const
{
    return this->phyHeader.c_str();
}

void TcpIpPacket::setPhyHeader(const char * phyHeader)
{
    this->phyHeader = phyHeader;
}

class TcpIpPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_srcAdd,
        FIELD_destAdd,
        FIELD_appHeader,
        FIELD_tcpHeader,
        FIELD_ipHeader,
        FIELD_dllHeader,
        FIELD_phyHeader,
    };
  public:
    TcpIpPacketDescriptor();
    virtual ~TcpIpPacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(TcpIpPacketDescriptor)

TcpIpPacketDescriptor::TcpIpPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(TcpIpPacket)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

TcpIpPacketDescriptor::~TcpIpPacketDescriptor()
{
    delete[] propertyNames;
}

bool TcpIpPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TcpIpPacket *>(obj)!=nullptr;
}

const char **TcpIpPacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *TcpIpPacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int TcpIpPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 7+base->getFieldCount() : 7;
}

unsigned int TcpIpPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_srcAdd
        FD_ISEDITABLE,    // FIELD_destAdd
        FD_ISCOMPOUND,    // FIELD_appHeader
        FD_ISEDITABLE,    // FIELD_tcpHeader
        FD_ISEDITABLE,    // FIELD_ipHeader
        FD_ISEDITABLE,    // FIELD_dllHeader
        FD_ISEDITABLE,    // FIELD_phyHeader
    };
    return (field >= 0 && field < 7) ? fieldTypeFlags[field] : 0;
}

const char *TcpIpPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srcAdd",
        "destAdd",
        "appHeader",
        "tcpHeader",
        "ipHeader",
        "dllHeader",
        "phyHeader",
    };
    return (field >= 0 && field < 7) ? fieldNames[field] : nullptr;
}

int TcpIpPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "srcAdd") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "destAdd") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "appHeader") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "tcpHeader") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "ipHeader") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "dllHeader") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "phyHeader") == 0) return baseIndex + 6;
    return base ? base->findField(fieldName) : -1;
}

const char *TcpIpPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_srcAdd
        "int",    // FIELD_destAdd
        "applicationPacket",    // FIELD_appHeader
        "int",    // FIELD_tcpHeader
        "string",    // FIELD_ipHeader
        "string",    // FIELD_dllHeader
        "string",    // FIELD_phyHeader
    };
    return (field >= 0 && field < 7) ? fieldTypeStrings[field] : nullptr;
}

const char **TcpIpPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *TcpIpPacketDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int TcpIpPacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    TcpIpPacket *pp = omnetpp::fromAnyPtr<TcpIpPacket>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void TcpIpPacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    TcpIpPacket *pp = omnetpp::fromAnyPtr<TcpIpPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'TcpIpPacket'", field);
    }
}

const char *TcpIpPacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    TcpIpPacket *pp = omnetpp::fromAnyPtr<TcpIpPacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TcpIpPacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    TcpIpPacket *pp = omnetpp::fromAnyPtr<TcpIpPacket>(object); (void)pp;
    switch (field) {
        case FIELD_srcAdd: return long2string(pp->getSrcAdd());
        case FIELD_destAdd: return long2string(pp->getDestAdd());
        case FIELD_appHeader: return "";
        case FIELD_tcpHeader: return long2string(pp->getTcpHeader());
        case FIELD_ipHeader: return oppstring2string(pp->getIpHeader());
        case FIELD_dllHeader: return oppstring2string(pp->getDllHeader());
        case FIELD_phyHeader: return oppstring2string(pp->getPhyHeader());
        default: return "";
    }
}

void TcpIpPacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    TcpIpPacket *pp = omnetpp::fromAnyPtr<TcpIpPacket>(object); (void)pp;
    switch (field) {
        case FIELD_srcAdd: pp->setSrcAdd(string2long(value)); break;
        case FIELD_destAdd: pp->setDestAdd(string2long(value)); break;
        case FIELD_tcpHeader: pp->setTcpHeader(string2long(value)); break;
        case FIELD_ipHeader: pp->setIpHeader((value)); break;
        case FIELD_dllHeader: pp->setDllHeader((value)); break;
        case FIELD_phyHeader: pp->setPhyHeader((value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TcpIpPacket'", field);
    }
}

omnetpp::cValue TcpIpPacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    TcpIpPacket *pp = omnetpp::fromAnyPtr<TcpIpPacket>(object); (void)pp;
    switch (field) {
        case FIELD_srcAdd: return pp->getSrcAdd();
        case FIELD_destAdd: return pp->getDestAdd();
        case FIELD_appHeader: return omnetpp::toAnyPtr(&pp->getAppHeader()); break;
        case FIELD_tcpHeader: return pp->getTcpHeader();
        case FIELD_ipHeader: return pp->getIpHeader();
        case FIELD_dllHeader: return pp->getDllHeader();
        case FIELD_phyHeader: return pp->getPhyHeader();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'TcpIpPacket' as cValue -- field index out of range?", field);
    }
}

void TcpIpPacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    TcpIpPacket *pp = omnetpp::fromAnyPtr<TcpIpPacket>(object); (void)pp;
    switch (field) {
        case FIELD_srcAdd: pp->setSrcAdd(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_destAdd: pp->setDestAdd(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_tcpHeader: pp->setTcpHeader(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_ipHeader: pp->setIpHeader(value.stringValue()); break;
        case FIELD_dllHeader: pp->setDllHeader(value.stringValue()); break;
        case FIELD_phyHeader: pp->setPhyHeader(value.stringValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TcpIpPacket'", field);
    }
}

const char *TcpIpPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_appHeader: return omnetpp::opp_typename(typeid(applicationPacket));
        default: return nullptr;
    };
}

omnetpp::any_ptr TcpIpPacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    TcpIpPacket *pp = omnetpp::fromAnyPtr<TcpIpPacket>(object); (void)pp;
    switch (field) {
        case FIELD_appHeader: return omnetpp::toAnyPtr(&pp->getAppHeader()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void TcpIpPacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    TcpIpPacket *pp = omnetpp::fromAnyPtr<TcpIpPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TcpIpPacket'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

