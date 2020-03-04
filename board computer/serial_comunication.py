import serial

port = "/dev/ttyACM0"
speed = 9600
conected = serial.Serial(port, speed)
print(b'helllo')
opcao = 0

while opcao != "2":
    opcao = input("Digite 1 para ligar\n  Digite 2 para parar \n Digite 0 para desligar")
    if opcao == "1":
        conected.write(b'1')
    elif opcao == "0":
        conected.write(b'0')
conected.close()