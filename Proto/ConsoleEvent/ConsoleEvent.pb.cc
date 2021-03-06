// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ConsoleEvent.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "ConsoleEvent.pb.h"

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

const ::google::protobuf::Descriptor* ConsoleSignal_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ConsoleSignal_reflection_ = NULL;
const ::google::protobuf::Descriptor* ConsoleEvent_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ConsoleEvent_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_ConsoleEvent_2eproto() {
  protobuf_AddDesc_ConsoleEvent_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "ConsoleEvent.proto");
  GOOGLE_CHECK(file != NULL);
  ConsoleSignal_descriptor_ = file->message_type(0);
  static const int ConsoleSignal_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConsoleSignal, signal_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConsoleSignal, value_),
  };
  ConsoleSignal_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ConsoleSignal_descriptor_,
      ConsoleSignal::default_instance_,
      ConsoleSignal_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConsoleSignal, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConsoleSignal, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ConsoleSignal));
  ConsoleEvent_descriptor_ = file->message_type(1);
  static const int ConsoleEvent_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConsoleEvent, event_),
  };
  ConsoleEvent_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ConsoleEvent_descriptor_,
      ConsoleEvent::default_instance_,
      ConsoleEvent_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConsoleEvent, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConsoleEvent, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ConsoleEvent));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_ConsoleEvent_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ConsoleSignal_descriptor_, &ConsoleSignal::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ConsoleEvent_descriptor_, &ConsoleEvent::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_ConsoleEvent_2eproto() {
  delete ConsoleSignal::default_instance_;
  delete ConsoleSignal_reflection_;
  delete ConsoleEvent::default_instance_;
  delete ConsoleEvent_reflection_;
}

void protobuf_AddDesc_ConsoleEvent_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\022ConsoleEvent.proto\022\005Proto\".\n\rConsoleSi"
    "gnal\022\016\n\006signal\030\001 \002(\t\022\r\n\005value\030\002 \001(\001\"3\n\014C"
    "onsoleEvent\022#\n\005event\030\001 \003(\0132\024.Proto.Conso"
    "leSignal", 128);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "ConsoleEvent.proto", &protobuf_RegisterTypes);
  ConsoleSignal::default_instance_ = new ConsoleSignal();
  ConsoleEvent::default_instance_ = new ConsoleEvent();
  ConsoleSignal::default_instance_->InitAsDefaultInstance();
  ConsoleEvent::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_ConsoleEvent_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_ConsoleEvent_2eproto {
  StaticDescriptorInitializer_ConsoleEvent_2eproto() {
    protobuf_AddDesc_ConsoleEvent_2eproto();
  }
} static_descriptor_initializer_ConsoleEvent_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int ConsoleSignal::kSignalFieldNumber;
const int ConsoleSignal::kValueFieldNumber;
#endif  // !_MSC_VER

ConsoleSignal::ConsoleSignal()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:Proto.ConsoleSignal)
}

void ConsoleSignal::InitAsDefaultInstance() {
}

ConsoleSignal::ConsoleSignal(const ConsoleSignal& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:Proto.ConsoleSignal)
}

void ConsoleSignal::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  signal_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  value_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ConsoleSignal::~ConsoleSignal() {
  // @@protoc_insertion_point(destructor:Proto.ConsoleSignal)
  SharedDtor();
}

void ConsoleSignal::SharedDtor() {
  if (signal_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete signal_;
  }
  if (this != default_instance_) {
  }
}

void ConsoleSignal::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ConsoleSignal::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ConsoleSignal_descriptor_;
}

const ConsoleSignal& ConsoleSignal::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_ConsoleEvent_2eproto();
  return *default_instance_;
}

ConsoleSignal* ConsoleSignal::default_instance_ = NULL;

ConsoleSignal* ConsoleSignal::New() const {
  return new ConsoleSignal;
}

void ConsoleSignal::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_signal()) {
      if (signal_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        signal_->clear();
      }
    }
    value_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ConsoleSignal::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Proto.ConsoleSignal)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string signal = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_signal()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->signal().data(), this->signal().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "signal");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(17)) goto parse_value;
        break;
      }

      // optional double value = 2;
      case 2: {
        if (tag == 17) {
         parse_value:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &value_)));
          set_has_value();
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
  // @@protoc_insertion_point(parse_success:Proto.ConsoleSignal)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Proto.ConsoleSignal)
  return false;
#undef DO_
}

void ConsoleSignal::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Proto.ConsoleSignal)
  // required string signal = 1;
  if (has_signal()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->signal().data(), this->signal().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "signal");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->signal(), output);
  }

  // optional double value = 2;
  if (has_value()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(2, this->value(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:Proto.ConsoleSignal)
}

::google::protobuf::uint8* ConsoleSignal::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:Proto.ConsoleSignal)
  // required string signal = 1;
  if (has_signal()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->signal().data(), this->signal().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "signal");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->signal(), target);
  }

  // optional double value = 2;
  if (has_value()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(2, this->value(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Proto.ConsoleSignal)
  return target;
}

int ConsoleSignal::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string signal = 1;
    if (has_signal()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->signal());
    }

    // optional double value = 2;
    if (has_value()) {
      total_size += 1 + 8;
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

void ConsoleSignal::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ConsoleSignal* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ConsoleSignal*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ConsoleSignal::MergeFrom(const ConsoleSignal& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_signal()) {
      set_signal(from.signal());
    }
    if (from.has_value()) {
      set_value(from.value());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ConsoleSignal::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ConsoleSignal::CopyFrom(const ConsoleSignal& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ConsoleSignal::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void ConsoleSignal::Swap(ConsoleSignal* other) {
  if (other != this) {
    std::swap(signal_, other->signal_);
    std::swap(value_, other->value_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ConsoleSignal::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ConsoleSignal_descriptor_;
  metadata.reflection = ConsoleSignal_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ConsoleEvent::kEventFieldNumber;
#endif  // !_MSC_VER

ConsoleEvent::ConsoleEvent()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:Proto.ConsoleEvent)
}

void ConsoleEvent::InitAsDefaultInstance() {
}

ConsoleEvent::ConsoleEvent(const ConsoleEvent& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:Proto.ConsoleEvent)
}

void ConsoleEvent::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ConsoleEvent::~ConsoleEvent() {
  // @@protoc_insertion_point(destructor:Proto.ConsoleEvent)
  SharedDtor();
}

void ConsoleEvent::SharedDtor() {
  if (this != default_instance_) {
  }
}

void ConsoleEvent::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ConsoleEvent::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ConsoleEvent_descriptor_;
}

const ConsoleEvent& ConsoleEvent::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_ConsoleEvent_2eproto();
  return *default_instance_;
}

ConsoleEvent* ConsoleEvent::default_instance_ = NULL;

ConsoleEvent* ConsoleEvent::New() const {
  return new ConsoleEvent;
}

void ConsoleEvent::Clear() {
  event_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ConsoleEvent::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Proto.ConsoleEvent)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .Proto.ConsoleSignal event = 1;
      case 1: {
        if (tag == 10) {
         parse_event:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_event()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_event;
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
  // @@protoc_insertion_point(parse_success:Proto.ConsoleEvent)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Proto.ConsoleEvent)
  return false;
#undef DO_
}

void ConsoleEvent::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Proto.ConsoleEvent)
  // repeated .Proto.ConsoleSignal event = 1;
  for (int i = 0; i < this->event_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->event(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:Proto.ConsoleEvent)
}

::google::protobuf::uint8* ConsoleEvent::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:Proto.ConsoleEvent)
  // repeated .Proto.ConsoleSignal event = 1;
  for (int i = 0; i < this->event_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->event(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Proto.ConsoleEvent)
  return target;
}

int ConsoleEvent::ByteSize() const {
  int total_size = 0;

  // repeated .Proto.ConsoleSignal event = 1;
  total_size += 1 * this->event_size();
  for (int i = 0; i < this->event_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->event(i));
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

void ConsoleEvent::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ConsoleEvent* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ConsoleEvent*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ConsoleEvent::MergeFrom(const ConsoleEvent& from) {
  GOOGLE_CHECK_NE(&from, this);
  event_.MergeFrom(from.event_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ConsoleEvent::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ConsoleEvent::CopyFrom(const ConsoleEvent& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ConsoleEvent::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->event())) return false;
  return true;
}

void ConsoleEvent::Swap(ConsoleEvent* other) {
  if (other != this) {
    event_.Swap(&other->event_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ConsoleEvent::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ConsoleEvent_descriptor_;
  metadata.reflection = ConsoleEvent_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Proto

// @@protoc_insertion_point(global_scope)
