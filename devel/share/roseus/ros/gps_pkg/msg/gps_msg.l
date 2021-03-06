;; Auto-generated. Do not edit!


(when (boundp 'gps_pkg::gps_msg)
  (if (not (find-package "GPS_PKG"))
    (make-package "GPS_PKG"))
  (shadow 'gps_msg (find-package "GPS_PKG")))
(unless (find-package "GPS_PKG::GPS_MSG")
  (make-package "GPS_PKG::GPS_MSG"))

(in-package "ROS")
;;//! \htmlinclude gps_msg.msg.html


(defclass gps_pkg::gps_msg
  :super ros::object
  :slots (_msg_counter _isObject _distance ))

(defmethod gps_pkg::gps_msg
  (:init
   (&key
    ((:msg_counter __msg_counter) 0)
    ((:isObject __isObject) nil)
    ((:distance __distance) 0.0)
    )
   (send-super :init)
   (setq _msg_counter (round __msg_counter))
   (setq _isObject __isObject)
   (setq _distance (float __distance))
   self)
  (:msg_counter
   (&optional __msg_counter)
   (if __msg_counter (setq _msg_counter __msg_counter)) _msg_counter)
  (:isObject
   (&optional __isObject)
   (if __isObject (setq _isObject __isObject)) _isObject)
  (:distance
   (&optional __distance)
   (if __distance (setq _distance __distance)) _distance)
  (:serialization-length
   ()
   (+
    ;; uint32 _msg_counter
    4
    ;; bool _isObject
    1
    ;; float32 _distance
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint32 _msg_counter
       (write-long _msg_counter s)
     ;; bool _isObject
       (if _isObject (write-byte -1 s) (write-byte 0 s))
     ;; float32 _distance
       (sys::poke _distance (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint32 _msg_counter
     (setq _msg_counter (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; bool _isObject
     (setq _isObject (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; float32 _distance
     (setq _distance (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get gps_pkg::gps_msg :md5sum-) "cbc61f5430d101edd8000fb728a64c35")
(setf (get gps_pkg::gps_msg :datatype-) "gps_pkg/gps_msg")
(setf (get gps_pkg::gps_msg :definition-)
      "uint32 msg_counter
bool isObject
float32 distance

")



(provide :gps_pkg/gps_msg "cbc61f5430d101edd8000fb728a64c35")


