
"""
    Práctica desarrollada por Juan José López Gómez y Álvaro García Sánchez
    -----------------------------------------------------------------------

    main.py
    Archivo de python que es el encargado de realizar el envío del correo electrónico cuando se detecte el movimiento
"""

# Importación de las librerías necesarias
    # Para el envío del email
import smtplib
from email.message import EmailMessage
    # Para obtener la fecha y la hora exacta
from datetime import date
from datetime import datetime
    # Para la comunicación con arduino y demás cosas
import time
import serial
import os

# Constantes para el envío del email
EMAIL = "" # Email de la cuenta desde la que se va a envíar el email
PWD = "" # La contraseña del email
DEF_EMAIL = "" # El email al que se le va a envíar el correo

opener = True # Variable bandera

s = serial.Serial() # Instanciación del puerto serie

# Función que se va a encargar del envío del email
def email_sender(text, flag):
    email = EmailMessage()  # Instanciación del objeto que se enviará mediante el protocolo smtp

    # Settear los campos del objeto el nombre del que lo envía, al que se le envía y el asunto del correo
    email["from"] = "Movement Sensor Arduino"  
    email["to"] = DEF_EMAIL 
    email["subject"] = "Log from the movement Sensor"

    # Dependiendo del valor del flag se va a enviar un contendido del mensaje distinto
    if flag:
        email.set_content("A subject has been detected by the sensor at {}".format(text)) 
    else:
        email.set_content("The movement has stopped at {}".format(text))

    # Se abre el protocolo smtp hacia el servidor de smtp de gmail con el puerto 587
    with smtplib.SMTP(host="smtp.gmail.com", port=587) as smtp:
        smtp.ehlo()
        smtp.starttls()  
        smtp.login(EMAIL, PWD)
        smtp.send_message(email)


# Función que se encarga de abrir el puerto serie
def get_serial(opener):
    if  opener: # Para que solo se ejecute en la primera iteración
        s.baudrate = 9600 # Se asigna la velocidad, la misma que en el código de arduino 9600 baudios
        s.port = "COM3" # Se asigna el puerto por el que va a ir la información, en este caso es el COM3
        opener = False
    if s.isOpen():
        pass
    else:
        s.open() # y se abre el puerto


def wait_info(ser):
   while True: # Bucle infinito para la espera del mensaje de parte del arduino
    if s.in_waiting: # Misma funcion que en arduino Serial.avaliable()
        line = s.readline() # Una vez se ha comprobado que va a llegar información se lee la línea
        line = line.decode("utf") # Para poder mostrarlo por consola se tiene que decodificar con el formato utf, ya que por el puerto serie llega en binario
        print(line)
        if "detected" in line: # Dependiendo del mensaje se envía una cosa u otra
            return True
        else:
            return False


# Función que obtiene la fecha y la hora para mandarla en el email
def set_dates():
    year = date.today()
    time = "{}:{}:{}".format(datetime.now().hour, datetime.now().minute, datetime.now().second)
    return "{} {}".format(year, time)


# Función que dependiendo del mensaje que le haya llegado se envía devuelta como confirmación para el arduino
def send_back(ser, flag):
    print("Email sent")
    if flag:
        s.write(b"Initial email sent")
    else:
        s.write(b"Stopped email sent")


# Función main en el que se llaman a las funciones anteriores para realizar el proceso bien
def main():
    while 1:
        print("Stablishing connection to the serial port")
        get_serial(opener)

        print("Waiting for the input at the serial port")
        flag = wait_info(s)

        time.sleep(5)

        prompt = set_dates()

        print("Sending email to the default one")
        email_sender(prompt, flag)

        print("Sending confim to the arduino by the serial port")
        send_back(s, flag)

        time.sleep(5)
        os.system('cls||clear')


if __name__ == '__main__':
    main()





