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

#-----------------
