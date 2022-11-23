import RPi.GPIO as GPIO
import dht11
import time

# initialize GPIO
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(12,GPIO.OUT)
#GPIO.cleanup()

# read data using Pin GPIO21 
instance = dht11.DHT11(40) 

while True:
    result = instance.read()
    if result.is_valid():
        print("Temp: %d C" % result.temperature +' '+"Humid: %d %%" % result.humidity)
        if result.temperature >30:#threshold is applied
            GPIO.output(12,True)
        else:
            GPIO.output(12,False)  
    time.sleep(1)
