// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: HeartbeatEvent.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "HeartbeatEvent.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace Proto {

namespace {

const ::google::protobuf::Descriptor* Hardware_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Hardware_reflection_ = NULL;
const ::google::protobuf::Descriptor* HeartbeatEvent_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  HeartbeatEvent_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_HeartbeatEvent_2eproto() {
  protobuf_AddDesc_HeartbeatEvent_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "HeartbeatEvent.proto");
  GOOGLE_CHECK(file != NULL);
  Hardware_descriptor_ = file->message_type(0);
  static const int Hardware_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Hardware, sysname_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Hardware, nodename_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Hardware, release_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Hardware, version_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Hardware, machine_),
  };
  Hardware_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Hardware_descriptor_,
      Hardware::default_instance_,
      Hardware_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Hardware, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Hardware, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Hardware));
  HeartbeatEvent_descriptor_ = file->message_type(1);
  static const int HeartbeatEvent_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeartbeatEvent, guid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeartbeatEvent, systemname_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeartbeatEvent, systemtype_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeartbeatEvent, systemmodel_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeartbeatEvent, hardware_),
  };
  HeartbeatEvent_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      HeartbeatEvent_descriptor_,
      HeartbeatEvent::default_instance_,
      HeartbeatEvent_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeartbeatEvent, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeartbeatEvent, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(HeartbeatEvent));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_HeartbeatEvent_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Hardware_descriptor_, &Hardware::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    HeartbeatEvent_descriptor_, &HeartbeatEvent::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_HeartbeatEvent_2eproto() {
  delete Hardware::default_instance_;
  delete Hardware_reflection_;
  delete HeartbeatEvent::default_instance_;
  delete HeartbeatEvent_reflection_;
}

void protobuf_AddDesc_HeartbeatEvent_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\024HeartbeatEvent.proto\022\005Proto\"`\n\010Hardwar"
    "e\022\017\n\007sysname\030\001 \002(\t\022\020\n\010nodename\030\002 \002(\t\022\017\n\007"
    "release\030\003 \002(\t\022\017\n\007version\030\004 \002(\t\022\017\n\007machin"
    "e\030\005 \002(\t\"~\n\016HeartbeatEvent\022\014\n\004guid\030\001 \002(\t\022"
    "\022\n\nsystemName\030\002 \002(\t\022\022\n\nsystemType\030\003 \002(\t\022"
    "\023\n\013systemModel\030\004 \002(\t\022!\n\010hardware\030\005 \002(\0132\017"
    ".Proto.Hardware", 255);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "HeartbeatEvent.proto", &protobuf_RegisterTypes);
  Hardware::default_instance_ = new Hardware();
  HeartbeatEvent::default_instance_ = new HeartbeatEvent();
  Hardware::default_instance_->InitAsDefaultInstance();
  HeartbeatEvent::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_HeartbeatEvent_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_HeartbeatEvent_2eproto {
  StaticDescriptorInitializer_HeartbeatEvent_2eproto() {
    protobuf_AddDesc_HeartbeatEvent_2eproto();
  }
} static_descriptor_initializer_HeartbeatEvent_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int Hardware::kSysnameFieldNumber;
const int Hardware::kNodenameFieldNumber;
const int Hardware::kReleaseFieldNumber;
const int Hardware::kVersionFieldNumber;
const int Hardware::kMachineFieldNumber;
#endif  // !_MSC_VER

Hardware::Hardware()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:Proto.Hardware)
}

void Hardware::InitAsDefaultInstance() {
}

Hardware::Hardware(const Hardware& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:Proto.Hardware)
}

void Hardware::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  sysname_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  nodename_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  release_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  version_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  machine_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Hardware::~Hardware() {
  // @@protoc_insertion_point(destructor:Proto.Hardware)
  SharedDtor();
}

void Hardware::SharedDtor() {
  if (sysname_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete sysname_;
  }
  if (nodename_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete nodename_;
  }
  if (release_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete release_;
  }
  if (version_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete version_;
  }
  if (machine_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete machine_;
  }
  if (this != default_instance_) {
  }
}

void Hardware::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Hardware::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Hardware_descriptor_;
}

const Hardware& Hardware::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_HeartbeatEvent_2eproto();
  return *default_instance_;
}

Hardware* Hardware::default_instance_ = NULL;

Hardware* Hardware::New() const {
  return new Hardware;
}

void Hardware::Clear() {
  if (_has_bits_[0 / 32] & 31) {
    if (has_sysname()) {
      if (sysname_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        sysname_->clear();
      }
    }
    if (has_nodename()) {
      if (nodename_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        nodename_->clear();
      }
    }
    if (has_release()) {
      if (release_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        release_->clear();
      }
    }
    if (has_version()) {
      if (version_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        version_->clear();
      }
    }
    if (has_machine()) {
      if (machine_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        machine_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Hardware::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Proto.Hardware)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string sysname = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_sysname()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->sysname().data(), this->sysname().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "sysname");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_nodename;
        break;
      }

      // required string nodename = 2;
      case 2: {
        if (tag == 18) {
         parse_nodename:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_nodename()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->nodename().data(), this->nodename().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "nodename");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_release;
        break;
      }

      // required string release = 3;
      case 3: {
        if (tag == 26) {
         parse_release:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_release()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->release().data(), this->release().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "release");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_version;
        break;
      }

      // required string version = 4;
      case 4: {
        if (tag == 34) {
         parse_version:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_version()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->version().data(), this->version().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "version");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_machine;
        break;
      }

      // required string machine = 5;
      case 5: {
        if (tag == 42) {
         parse_machine:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_machine()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->machine().data(), this->machine().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "machine");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Proto.Hardware)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Proto.Hardware)
  return false;
#undef DO_
}

void Hardware::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Proto.Hardware)
  // required string sysname = 1;
  if (has_sysname()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->sysname().data(), this->sysname().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "sysname");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->sysname(), output);
  }

  // required string nodename = 2;
  if (has_nodename()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->nodename().data(), this->nodename().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "nodename");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->nodename(), output);
  }

  // required string release = 3;
  if (has_release()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->release().data(), this->release().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "release");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->release(), output);
  }

  // required string version = 4;
  if (has_version()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->version().data(), this->version().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "version");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      4, this->version(), output);
  }

  // required string machine = 5;
  if (has_machine()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->machine().data(), this->machine().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "machine");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      5, this->machine(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:Proto.Hardware)
}

::google::protobuf::uint8* Hardware::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:Proto.Hardware)
  // required string sysname = 1;
  if (has_sysname()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->sysname().data(), this->sysname().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "sysname");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->sysname(), target);
  }

  // required string nodename = 2;
  if (has_nodename()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->nodename().data(), this->nodename().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "nodename");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->nodename(), target);
  }

  // required string release = 3;
  if (has_release()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->release().data(), this->release().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "release");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->release(), target);
  }

  // required string version = 4;
  if (has_version()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->version().data(), this->version().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "version");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->version(), target);
  }

  // required string machine = 5;
  if (has_machine()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->machine().data(), this->machine().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "machine");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        5, this->machine(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Proto.Hardware)
  return target;
}

int Hardware::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string sysname = 1;
    if (has_sysname()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->sysname());
    }

    // required string nodename = 2;
    if (has_nodename()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->nodename());
    }

    // required string release = 3;
    if (has_release()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->release());
    }

    // required string version = 4;
    if (has_version()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->version());
    }

    // required string machine = 5;
    if (has_machine()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->machine());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Hardware::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Hardware* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Hardware*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Hardware::MergeFrom(const Hardware& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_sysname()) {
      set_sysname(from.sysname());
    }
    if (from.has_nodename()) {
      set_nodename(from.nodename());
    }
    if (from.has_release()) {
      set_release(from.release());
    }
    if (from.has_version()) {
      set_version(from.version());
    }
    if (from.has_machine()) {
      set_machine(from.machine());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Hardware::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Hardware::CopyFrom(const Hardware& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Hardware::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000001f) != 0x0000001f) return false;

  return true;
}

void Hardware::Swap(Hardware* other) {
  if (other != this) {
    std::swap(sysname_, other->sysname_);
    std::swap(nodename_, other->nodename_);
    std::swap(release_, other->release_);
    std::swap(version_, other->version_);
    std::swap(machine_, other->machine_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Hardware::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Hardware_descriptor_;
  metadata.reflection = Hardware_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int HeartbeatEvent::kGuidFieldNumber;
const int HeartbeatEvent::kSystemNameFieldNumber;
const int HeartbeatEvent::kSystemTypeFieldNumber;
const int HeartbeatEvent::kSystemModelFieldNumber;
const int HeartbeatEvent::kHardwareFieldNumber;
#endif  // !_MSC_VER

HeartbeatEvent::HeartbeatEvent()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:Proto.HeartbeatEvent)
}

void HeartbeatEvent::InitAsDefaultInstance() {
  hardware_ = const_cast< ::Proto::Hardware*>(&::Proto::Hardware::default_instance());
}

HeartbeatEvent::HeartbeatEvent(const HeartbeatEvent& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:Proto.HeartbeatEvent)
}

void HeartbeatEvent::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  guid_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  systemname_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  systemtype_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  systemmodel_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  hardware_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

HeartbeatEvent::~HeartbeatEvent() {
  // @@protoc_insertion_point(destructor:Proto.HeartbeatEvent)
  SharedDtor();
}

void HeartbeatEvent::SharedDtor() {
  if (guid_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete guid_;
  }
  if (systemname_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete systemname_;
  }
  if (systemtype_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete systemtype_;
  }
  if (systemmodel_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete systemmodel_;
  }
  if (this != default_instance_) {
    delete hardware_;
  }
}

void HeartbeatEvent::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* HeartbeatEvent::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return HeartbeatEvent_descriptor_;
}

const HeartbeatEvent& HeartbeatEvent::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_HeartbeatEvent_2eproto();
  return *default_instance_;
}

HeartbeatEvent* HeartbeatEvent::default_instance_ = NULL;

HeartbeatEvent* HeartbeatEvent::New() const {
  return new HeartbeatEvent;
}

void HeartbeatEvent::Clear() {
  if (_has_bits_[0 / 32] & 31) {
    if (has_guid()) {
      if (guid_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        guid_->clear();
      }
    }
    if (has_systemname()) {
      if (systemname_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        systemname_->clear();
      }
    }
    if (has_systemtype()) {
      if (systemtype_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        systemtype_->clear();
      }
    }
    if (has_systemmodel()) {
      if (systemmodel_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        systemmodel_->clear();
      }
    }
    if (has_hardware()) {
      if (hardware_ != NULL) hardware_->::Proto::Hardware::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool HeartbeatEvent::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Proto.HeartbeatEvent)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string guid = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_guid()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->guid().data(), this->guid().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "guid");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_systemName;
        break;
      }

      // required string systemName = 2;
      case 2: {
        if (tag == 18) {
         parse_systemName:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_systemname()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->systemname().data(), this->systemname().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "systemname");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_systemType;
        break;
      }

      // required string systemType = 3;
      case 3: {
        if (tag == 26) {
         parse_systemType:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_systemtype()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->systemtype().data(), this->systemtype().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "systemtype");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_systemModel;
        break;
      }

      // required string systemModel = 4;
      case 4: {
        if (tag == 34) {
         parse_systemModel:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_systemmodel()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->systemmodel().data(), this->systemmodel().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "systemmodel");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_hardware;
        break;
      }

      // required .Proto.Hardware hardware = 5;
      case 5: {
        if (tag == 42) {
         parse_hardware:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_hardware()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Proto.HeartbeatEvent)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Proto.HeartbeatEvent)
  return false;
#undef DO_
}

void HeartbeatEvent::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Proto.HeartbeatEvent)
  // required string guid = 1;
  if (has_guid()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->guid().data(), this->guid().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "guid");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->guid(), output);
  }

  // required string systemName = 2;
  if (has_systemname()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->systemname().data(), this->systemname().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "systemname");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->systemname(), output);
  }

  // required string systemType = 3;
  if (has_systemtype()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->systemtype().data(), this->systemtype().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "systemtype");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->systemtype(), output);
  }

  // required string systemModel = 4;
  if (has_systemmodel()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->systemmodel().data(), this->systemmodel().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "systemmodel");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      4, this->systemmodel(), output);
  }

  // required .Proto.Hardware hardware = 5;
  if (has_hardware()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->hardware(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:Proto.HeartbeatEvent)
}

::google::protobuf::uint8* HeartbeatEvent::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:Proto.HeartbeatEvent)
  // required string guid = 1;
  if (has_guid()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->guid().data(), this->guid().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "guid");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->guid(), target);
  }

  // required string systemName = 2;
  if (has_systemname()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->systemname().data(), this->systemname().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "systemname");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->systemname(), target);
  }

  // required string systemType = 3;
  if (has_systemtype()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->systemtype().data(), this->systemtype().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "systemtype");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->systemtype(), target);
  }

  // required string systemModel = 4;
  if (has_systemmodel()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->systemmodel().data(), this->systemmodel().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "systemmodel");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->systemmodel(), target);
  }

  // required .Proto.Hardware hardware = 5;
  if (has_hardware()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        5, this->hardware(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Proto.HeartbeatEvent)
  return target;
}

int HeartbeatEvent::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string guid = 1;
    if (has_guid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->guid());
    }

    // required string systemName = 2;
    if (has_systemname()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->systemname());
    }

    // required string systemType = 3;
    if (has_systemtype()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->systemtype());
    }

    // required string systemModel = 4;
    if (has_systemmodel()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->systemmodel());
    }

    // required .Proto.Hardware hardware = 5;
    if (has_hardware()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->hardware());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void HeartbeatEvent::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const HeartbeatEvent* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const HeartbeatEvent*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void HeartbeatEvent::MergeFrom(const HeartbeatEvent& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_guid()) {
      set_guid(from.guid());
    }
    if (from.has_systemname()) {
      set_systemname(from.systemname());
    }
    if (from.has_systemtype()) {
      set_systemtype(from.systemtype());
    }
    if (from.has_systemmodel()) {
      set_systemmodel(from.systemmodel());
    }
    if (from.has_hardware()) {
      mutable_hardware()->::Proto::Hardware::MergeFrom(from.hardware());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void HeartbeatEvent::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void HeartbeatEvent::CopyFrom(const HeartbeatEvent& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool HeartbeatEvent::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000001f) != 0x0000001f) return false;

  if (has_hardware()) {
    if (!this->hardware().IsInitialized()) return false;
  }
  return true;
}

void HeartbeatEvent::Swap(HeartbeatEvent* other) {
  if (other != this) {
    std::swap(guid_, other->guid_);
    std::swap(systemname_, other->systemname_);
    std::swap(systemtype_, other->systemtype_);
    std::swap(systemmodel_, other->systemmodel_);
    std::swap(hardware_, other->hardware_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata HeartbeatEvent::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = HeartbeatEvent_descriptor_;
  metadata.reflection = HeartbeatEvent_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Proto

// @@protoc_insertion_point(global_scope)
