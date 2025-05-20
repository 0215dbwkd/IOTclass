 ##dustInfluxdb

import time
import requests, json
from influxdb import InfluxDBClient as influxdb
import serial

seri = serial.Serial('/dev/ttyACN1', baudrate = 9600, timeout = None)

while(True):
  time.sleep(2)
  if seri.in_waiting != 1:
    content = seri.readline()
    a = float(content.decode())
    data = [{
      'measurement' : 'dust',
      'tags':{
        'InhaUni' : '2223',
      },
      'fields':{
        'dust' : a,
      }
    }]

    client = None
    try:
      client = influxdb('localhost',8086,'root','root','dust')
    except Exception as e:
      print("Exception write " + str(e))
    finally:
      client.close()
    print(a)
    print("running influxdb OK")

