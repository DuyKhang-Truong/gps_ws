# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from gps_pkg/gps_msg.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class gps_msg(genpy.Message):
  _md5sum = "cbc61f5430d101edd8000fb728a64c35"
  _type = "gps_pkg/gps_msg"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """uint32 msg_counter
bool isObject
float32 distance
"""
  __slots__ = ['msg_counter','isObject','distance']
  _slot_types = ['uint32','bool','float32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       msg_counter,isObject,distance

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(gps_msg, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.msg_counter is None:
        self.msg_counter = 0
      if self.isObject is None:
        self.isObject = False
      if self.distance is None:
        self.distance = 0.
    else:
      self.msg_counter = 0
      self.isObject = False
      self.distance = 0.

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_IBf().pack(_x.msg_counter, _x.isObject, _x.distance))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      _x = self
      start = end
      end += 9
      (_x.msg_counter, _x.isObject, _x.distance,) = _get_struct_IBf().unpack(str[start:end])
      self.isObject = bool(self.isObject)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_IBf().pack(_x.msg_counter, _x.isObject, _x.distance))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      _x = self
      start = end
      end += 9
      (_x.msg_counter, _x.isObject, _x.distance,) = _get_struct_IBf().unpack(str[start:end])
      self.isObject = bool(self.isObject)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_IBf = None
def _get_struct_IBf():
    global _struct_IBf
    if _struct_IBf is None:
        _struct_IBf = struct.Struct("<IBf")
    return _struct_IBf
