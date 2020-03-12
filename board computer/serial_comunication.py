import serial
import logging
import threading
import time

port = "/dev/ttyACM0"
speed = 9600
conected = serial.Serial(port, speed)

opcao = 0

def thread_data(conected):
    print("---------------------------DADOS--------------------------")
    arduino = conected.readline().decode('utf-8').split('\r\n')
    print(arduino[0])
    arduino = conected.readline().decode('utf-8').split('\r\n')
    print(arduino[0])
    arduino = conected.readline().decode('utf-8').split('\r\n')
    print(arduino[0])
    print("==========================================================")
def thread_time():
    while True:
        time.sleep(100)
        thread_data()




while opcao != "100":
    print("==========================================================")
    print("--------------------COMPUADOR DE BORDO--------------------")
    print("==========================================================")


    opcao = input("Digite 0 para desligar farol\n Digite 1 para ligar farol\n"
                  "Digite 2 para ligar pisca esquerda\n Digite 3 para ligar pisca direita\n"
                  "Digite 100 para parar\n:")
    if opcao == "1":
        conected.write(b'1')
    elif opcao == "0":
        conected.write(b'0')
    elif opcao == "2":
        conected.write(b'2')
    elif opcao == "3":
        conected.write(b'3')
    threading.Thread(target=thread_time(), args=(1,))
    threading.Thread(target=thread_data(conected), args=(1,))

conected.close()
