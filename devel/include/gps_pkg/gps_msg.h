// Generated by gencpp from file gps_pkg/gps_msg.msg
// DO NOT EDIT!


#ifndef GPS_PKG_MESSAGE_GPS_MSG_H
#define GPS_PKG_MESSAGE_GPS_MSG_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace gps_pkg
{
template <class ContainerAllocator>
struct gps_msg_
{
  typedef gps_msg_<ContainerAllocator> Type;

  gps_msg_()
    : msg_counter(0)
    , isObject(false)
    , distance(0.0)  {
    }
  gps_msg_(const ContainerAllocator& _alloc)
    : msg_counter(0)
    , isObject(false)
    , distance(0.0)  {
  (void)_alloc;
    }



   typedef uint32_t _msg_counter_type;
  _msg_counter_type msg_counter;

   typedef uint8_t _isObject_type;
  _isObject_type isObject;

   typedef float _distance_type;
  _distance_type distance;





  typedef boost::shared_ptr< ::gps_pkg::gps_msg_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::gps_pkg::gps_msg_<ContainerAllocator> const> ConstPtr;

}; // struct gps_msg_

typedef ::gps_pkg::gps_msg_<std::allocator<void> > gps_msg;

typedef boost::shared_ptr< ::gps_pkg::gps_msg > gps_msgPtr;
typedef boost::shared_ptr< ::gps_pkg::gps_msg const> gps_msgConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::gps_pkg::gps_msg_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::gps_pkg::gps_msg_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::gps_pkg::gps_msg_<ContainerAllocator1> & lhs, const ::gps_pkg::gps_msg_<ContainerAllocator2> & rhs)
{
  return lhs.msg_counter == rhs.msg_counter &&
    lhs.isObject == rhs.isObject &&
    lhs.distance == rhs.distance;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::gps_pkg::gps_msg_<ContainerAllocator1> & lhs, const ::gps_pkg::gps_msg_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace gps_pkg

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::gps_pkg::gps_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::gps_pkg::gps_msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::gps_pkg::gps_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::gps_pkg::gps_msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::gps_pkg::gps_msg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::gps_pkg::gps_msg_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::gps_pkg::gps_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cbc61f5430d101edd8000fb728a64c35";
  }

  static const char* value(const ::gps_pkg::gps_msg_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xcbc61f5430d101edULL;
  static const uint64_t static_value2 = 0xd8000fb728a64c35ULL;
};

template<class ContainerAllocator>
struct DataType< ::gps_pkg::gps_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "gps_pkg/gps_msg";
  }

  static const char* value(const ::gps_pkg::gps_msg_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::gps_pkg::gps_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint32 msg_counter\n"
"bool isObject\n"
"float32 distance\n"
;
  }

  static const char* value(const ::gps_pkg::gps_msg_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::gps_pkg::gps_msg_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.msg_counter);
      stream.next(m.isObject);
      stream.next(m.distance);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct gps_msg_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::gps_pkg::gps_msg_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::gps_pkg::gps_msg_<ContainerAllocator>& v)
  {
    s << indent << "msg_counter: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.msg_counter);
    s << indent << "isObject: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.isObject);
    s << indent << "distance: ";
    Printer<float>::stream(s, indent + "  ", v.distance);
  }
};

} // namespace message_operations
} // namespace ros

#endif // GPS_PKG_MESSAGE_GPS_MSG_H
