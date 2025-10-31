from picamera import PiCamera
from time import time, sleep
#--------------RECORDING FOR A SPECIFIED TIME------------------
with PiCamera() as cam:
  sleep(2) # camera warmup time
  file = f"/home/pi/Pictures/video_{int(time())}.h264"
  print("Recording...")
  cam.start_recording(file)
  cam.wait_recording(5)
  cam.stop_recording()
  print("Saved: ", file)

# Additional functions to enhance video output
''' Resolution:
cam.resolution = (1280, 720) 
by default: (640, 480) '''
''' Flip:
cam.vflip = True
cam.hflip = True
'''
''' Contrast
cam.contrast = 10
default contrast = 0
range: -100 to 100 '''

#--------------CAPTURING SPECIFIED NUMBER OF PHOTOS-------------------
# PiCamera2 API - modern replacement for PiCamera, based on libcamera module
# libcamera - modern linux camera framework
from picamera2 import Picamera2
from libcamera import Transform
from time import time, sleep

cam = Picamera2()
n = int(input("How many photos? "))

cam.start(show_preview=True, transform=Transform(vflip=True, hflip=True))

for i in range(n):
  cam.capture_file(f"/home/project/Pictures/image_{int(time())}.jpg")
  sleep(2)
  
cam.close()

#----------------CAPTURE PHOTO ON OBJECT DETECTION---------------------
from picamera2 import Picamera2
from libcamera import Transform
from time import time, sleep
from gpizero import MotionSensor

cam = Picamera2()
cam.configure
cam.start()

pir = MotionSensor(17) # BCM pin 17 = BOARD pin 11
# event-driven style -- no infinite while loop 
def capture_image():
    filename = f"/home/project/Pictures/img_{int(time())}.jpg"
    print("Motion detected! Capturing...")
    picam2.capture_file(filename)
    print("Saved:", filename)

pir.when_motion = capture_image
# The camera only captures when motion occurs -- non-blocking and elegant

#----------------CAPTURE VIDEO ON OBJECT DETECTION---------------------
